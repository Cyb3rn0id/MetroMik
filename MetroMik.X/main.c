/*
 * METROMIK
 * made for my son Michele
 * (C)Giovanni Bernardo (CyB3rn0id)
 * 09 FEB 2020
 * https://www.settorezero.com
 * Repository Url: https://github.com/Cyb3rn0id/MetroMik
 * Full article:   https://www.settorezero.com/wordpress/metromik-metronomo-digitale-con-microcontrollore-pic/
 * 
 * LICENSE
 * Attribution-NonCommercial-ShareAlike 4.0 International 
 * (CC BY-NC-SA 4.0)
 * 
 * This is a human-readable summary of (and not a substitute for) the license:
 * You are free to:
 * SHARE ? copy and redistribute the material in any medium or format
 * ADAPT ? remix, transform, and build upon the material
 * The licensor cannot revoke these freedoms as long as you follow the license terms.
 * Under the following terms:
 * ATTRIBUTION ? You must give appropriate credit, provide a link to the license, 
 * and indicate if changes were made. You may do so in any reasonable manner, 
 * but not in any way that suggests the licensor endorses you or your use.
 * NON COMMERCIAL ? You may not use the material for commercial purposes.
 * SHARE ALIKE ? If you remix, transform, or build upon the material,
 * you must distribute your contributions under the same license as the original.
 * NO ADDITIONAL RESTRICTIONS ? You may not apply legal terms or technological 
 * measures that legally restrict others from doing anything the license permits.
 * 
 * Warranties
 * The Licensor offers the Licensed Material as-is and as-available, and makes
 * no representations or warranties of any kind concerning the Licensed Material, 
 * whether express, implied, statutory, or other. This includes, without limitation, 
 * warranties of title, merchantability, fitness for a particular purpose, 
 * non-infringement, absence of latent or other defects, accuracy, or the presence
 * or absence of errors, whether or not known or discoverable. Where disclaimers 
 * of warranties are not allowed in full or in part, this disclaimer may not apply to You.
 * 
 * Please read the Full License text at the following link:
 * https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 *
 * Pins used:
 * Check Battery    => RA4 (analog)
 * Encoder DIR      => RC6
 * Encoder Pulse    => RC7
 * Shift Reg. Latch => RC3
 * Shift Reg. Data  => RC0
 * Shift Reg. Clock => RC1
 * LED (LED0)       => RA2
 * Button (SW0)     => RC2
 */

#pragma warning disable 520

#include "mcc_generated_files/mcc.h"
#include "7seg74HC595.h"

// BPM Management
#define MAXBPM  999
#define MINBPM  10
#define DEFAULTBPM 50
uint16_t bpm=DEFAULTBPM; // actual value
uint16_t prebpm=0; // previous value of bpm (used to refresh display once for avoiding EMI due to display clock)

// Encoder management
uint8_t cpVar=0;
uint8_t cnVar=0;
#define CCOUNT 2 // every CCOUNT tick I count 1 tick
bool EncoderState=false; // true when DIR and PULSE at same level
bool EncAntibounce=false; // antibounce routine in progress
uint8_t EncTimer=0;
#define ENCTIMERESTART  4 // ms antibounce for encoder rotation

// tempo management
#define DEFAULTTEMPO 4
bool SoundOn=false;
uint8_t tempo=DEFAULTTEMPO; // 2,3,4 => 2/4, 3/4, 4/4
uint8_t pretempo=0;
#define TEMPOMAX 4
#define TEMPOMIN 2
bool endtempo=false; // last beat of selected tempo

// menu management on encoder button press
uint8_t menupage=0; // actual page
#define PAGE_BPM    0
#define PAGE_TEMPO  1
#define PAGEMAX     1
uint8_t prepage=PAGEMAX+1; // (used to refresh display once for avoiding EMI duye to display clock)
#define MENUTIMEOUT     5000    // after this ms, menu returns to main page
#define SOUNDWAIT       1000    // after some parameter is changed, I'll wait first start sound again
bool youmuststopsound=false;   // true if you rotate encoder or press a button, this is used to stop sound for SOUNDWAIT mS
uint16_t youmuststopsoundCount=0; // ms Counter for above flag
uint16_t menuTimeOutCounter=0;

bool forcedDisplayUpdate=false; // used to force display update (such when you remain in page different than 1 without exiting)

// battery management
bool batteryLow=false; // when true, system will be halted
uint8_t batteryLowCount=0;
#define BATMINTIMES 5 // if battery is considered low for this times, batteryLow will raised
// with voltage divisor used (R1=1200, R2=1500), voltage to ADC will be
// Vbat*0.44. I'll consider battery discharged when voltage is 3.2V, so on the ADC
// will be 1408mV. Since I'm using the FVR at 2.048V, a 2048mV input will give me
// the value 1024 (ADC is 10bit). So the input voltage in mV is read as mV/2 (2048=>1024)
// then 1408mV are read as 704. I've put 700 since I've measured with tester
#define MINBAT 700

void Encoder_Pulse_ISR(void)
    {
    youmuststopsound=true;
    youmuststopsoundCount=0;
    menuTimeOutCounter=0;
    if (EncAntibounce) return;
    // disable interrupts on encoder pulse/dir 
    IOCANbits.IOCAN2 = 0;
    IOCAPbits.IOCAP2 = 0;
    IOCANbits.IOCAN1 = 0;
    IOCAPbits.IOCAP1 = 0;
      
    if (ENC_PUL_PORT==ENC_DIR_PORT) // encoder rotated clockwise (Pulse interrupt)
        {
        cnVar=0;
        if (!EncoderState)
            {
            cpVar++;
            if (cpVar==CCOUNT)
                {
                if (menupage==PAGE_BPM)
                    {
                    bpm++;
                    if (bpm>MAXBPM) bpm=MAXBPM;
                    }
                else
                    {
                    tempo++;
                    if (tempo>TEMPOMAX) tempo=TEMPOMAX;
                    }
                cpVar=0;
                }
            }
        EncoderState=true; 
        }
  else // encoder rotated anti-clockwise
        {
        cpVar=0;
        if (EncoderState) 
            {
            cnVar++;
            if (cnVar==CCOUNT)
                {
                if (menupage==PAGE_BPM)
                    {
                    if (bpm>MINBPM) bpm--; 
                    }
                else
                    {
                    if (tempo>TEMPOMIN) tempo--;
                    }
                cnVar=0;
                }
            }
        EncoderState=false;  
        }
    EncAntibounce=true;
    }

void Encoder_Dir_ISR(void)
    {
    youmuststopsound=true;
    youmuststopsoundCount=0;
    menuTimeOutCounter=0;
    // disable interrupts on encoder pulse/dir 
    if (EncAntibounce) return;
    IOCANbits.IOCAN2 = 0;
    IOCAPbits.IOCAP2 = 0;
    IOCANbits.IOCAN1 = 0;
    IOCAPbits.IOCAP1 = 0;
       
    if (ENC_PUL_PORT==ENC_DIR_PORT) // encoder rotated counter-clockwise (Pulse interrupt)
        {
        cpVar=0;
        if (!EncoderState)
            {
            cnVar++;
            if (cnVar==CCOUNT)
                {
                if (menupage==PAGE_BPM)
                    {
                    if (bpm>MINBPM) bpm--; 
                    }
                else
                    {
                    if (tempo>TEMPOMIN) tempo--;
                    }
                cnVar=0;
                }
            }
        EncoderState=true;    
        }
  else // encoder rotated clockwise
        {
        cnVar=0;
        if (EncoderState) 
            {
            cpVar++;
            if (cpVar==CCOUNT)
                {
                if (menupage==PAGE_BPM)
                    {
                    bpm++;
                    if (bpm>MAXBPM) bpm=MAXBPM;
                    }
                else
                    {
                    tempo++;
                    if (tempo>TEMPOMAX) tempo=TEMPOMAX;
                    }
                cpVar=0;
                }
            }
        EncoderState=false;   
        }
    EncAntibounce=true;
    }

void Timer0_ISR(void)
    {
    // BPM calculation
    // x BPM = 1 beat every = 60/x beat per second
    // == 60000/x beat per millisecond
    static uint16_t beat=DEFAULTBPM; // ms per beat
    static uint16_t prebeat=DEFAULTBPM; // previous ms per beat
    static uint16_t beattick=0; // ms counter
    static uint8_t msbeatled=0;
    static uint8_t tempotick=1;
        
    beat=(60000/bpm); // milliseconds
    
    // something changed=>stop sound for SOUNDWAIT mS
    if (youmuststopsound)
        {
        youmuststopsoundCount++;
        LED0_LAT=true; // turn off led
        beattick=0;
        SoundOn=false;
        tempotick=1;
        if (youmuststopsoundCount>=SOUNDWAIT)
            {
            youmuststopsound=false;
            youmuststopsoundCount=0;
            forcedDisplayUpdate=true;
            }
        }
    
    // bpm changed => reset all
    if (beat!=prebeat && !youmuststopsound)
        {
        LED0_LAT=true; // turn off led
        beattick=0;
        prebeat=beat;
        SoundOn=false;
        tempotick=1;
        }
    beattick++; // 1 millisecond passed
            
    // tick-second occurred => turn led and start sound
    if (beattick==beat && !youmuststopsound) // I moust do the sound
        {
        LED0_LAT=false; // turn on the led
        SoundOn=true; // routine for sound
        beattick=0;
        endtempo=false;        
        if (tempotick==tempo) 
            {
            endtempo=true; // last beat
            }
        tempotick++;
        // restart tempo
        if (tempotick>tempo)
            {
            tempotick=1;
            }
        } // tick
    
    // led is on, we must turn off after some millisecond
    if (LED0_LAT==false)
        {
        msbeatled++;
        if (msbeatled>=30)
            {
            msbeatled=0;
            LED0_LAT=true; // led off
            SoundOn=false; // sound off
            }
        }
    
    // antibounce for encoder rotation     
    if (EncAntibounce)
        {
        SoundOn=false;
        EncTimer++;
        if (EncTimer>=ENCTIMERESTART)
            {
            EncTimer=0;
            EncAntibounce=false;
            // re-enable interrupts
            IOCANbits.IOCAN2 = 1;
            IOCAPbits.IOCAP2 = 1;
            IOCANbits.IOCAN1 = 1;
            IOCAPbits.IOCAP1 = 1;
            if (ENC_PUL_PORT==ENC_DIR_PORT) EncoderState=true;
            if (ENC_PUL_PORT!=ENC_DIR_PORT) EncoderState=false;
            }
        }
    
    // menu timeout management
    if (menupage>0)
        {
        menuTimeOutCounter++;
        if (menuTimeOutCounter>=MENUTIMEOUT)
            {
            menupage=0;
            menuTimeOutCounter=0;
            }
        }
    }

// sound routine
void sound(bool low)
    {
    SPK_LAT=1;
    if (low)
        {
        __delay_us(200);
        SPK_LAT=0;
        __delay_us(200);
        }
    else
        {
        __delay_us(90);
        SPK_LAT=0;
        __delay_us(90);
        }
    }

// check battery
void checkBattery(void)
    {
    if (ADC_IsConversionDone())
        {
        static uint16_t res=0; // adc result
        static uint8_t convs=0; // number of conversions
        res += ADC_GetConversionResult();
        convs++;
        
        if (convs==32)
            {
            convs=0;
            res>>=5; // division by 32
            if (res<MINBAT) 
                {
                batteryLowCount++;
                }
            else
                {   
                batteryLowCount=0;
                }
            res=0;
            }
        
        if (batteryLowCount==BATMINTIMES)
            {
            // battery is effectively low!
            batteryLow=true;
            }
        else
            {
            ADC_StartConversion();
            }
        } // conversion done
    }

// routine for low battery
void lowBattery(void)
    {
    if (batteryLow)
        {
        // stop all operations
        INTERRUPT_GlobalInterruptDisable(); // turn off interrupts
        ADCON0bits.ADON=0; // turn off AD module
        FVRCONbits.FVREN=0; // turn off FVR
        LED0_LAT=true; // turn off led
        SPK_LAT=0; // turn off speaker
        OSCCONbits.IRCF=0b0111; // internal oscillator at 500KHz
        // stay in infinite loop
        while(1)
            {
            // now about 60mS are 1 second
            display_set(DIG_B,DIG_A,DIG_T); // bAt
            __delay_ms(70);
            display_set(DIG_OFF,DIG_L,DIG_O); // Lo
            __delay_ms(70);
            display_set(DIG_OFF,DIG_OFF,DIG_OFF);
            __delay_ms(150);
            }
        } // battery low
    }

void main(void)
    {
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    if (ENC_PUL_PORT==ENC_DIR_PORT) EncoderState=true;
    
    // attach interrupt routines
    IOCAF2_SetInterruptHandler(*Encoder_Pulse_ISR);
    IOCAF1_SetInterruptHandler(*Encoder_Dir_ISR);
    TMR0_SetInterruptHandler(*Timer0_ISR);
    // start first conversion
    ADC_StartConversion();
    
    while (1)
        {
        checkBattery();
        lowBattery();     

        // write current BPM on the display
        switch (menupage)
            {
            case PAGE_BPM:
                if ((bpm!=prebpm) || (menupage!=prepage) || (forcedDisplayUpdate))
                    {
                    display_write(bpm);
                    prebpm=bpm;
                    prepage=menupage;
                    forcedDisplayUpdate=false;
                    }
                break;
            
            case PAGE_TEMPO:
                if ((pretempo!=tempo) || (menupage!=prepage) || (forcedDisplayUpdate))
                    {
                    display_set(tempo,DIG_MINUS,4);
                    pretempo=tempo;
                    prepage=menupage;
                    forcedDisplayUpdate=false;
                    }
                break;
            }
              
        // sound routine
        while (SoundOn && !youmuststopsound) sound(endtempo);
        
        // check encoder button
        if (!ENC_BUT_PORT)
            {
            youmuststopsound=true;
            youmuststopsoundCount=0;
            __delay_ms(80);
            if (!ENC_BUT_PORT)
                {
                menupage++;
                if (menupage>PAGEMAX) menupage=0;
                while(!ENC_BUT_PORT) menuTimeOutCounter=0;
                }
            } // encoder button
        } // while 1
    } // main