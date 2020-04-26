/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F1825
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ENC_BUT aliases
#define ENC_BUT_TRIS                 TRISAbits.TRISA0
#define ENC_BUT_LAT                  LATAbits.LATA0
#define ENC_BUT_PORT                 PORTAbits.RA0
#define ENC_BUT_WPU                  WPUAbits.WPUA0
#define ENC_BUT_ANS                  ANSELAbits.ANSA0
#define ENC_BUT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ENC_BUT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ENC_BUT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ENC_BUT_GetValue()           PORTAbits.RA0
#define ENC_BUT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ENC_BUT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ENC_BUT_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ENC_BUT_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ENC_BUT_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define ENC_BUT_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set ENC_DIR aliases
#define ENC_DIR_TRIS                 TRISAbits.TRISA1
#define ENC_DIR_LAT                  LATAbits.LATA1
#define ENC_DIR_PORT                 PORTAbits.RA1
#define ENC_DIR_WPU                  WPUAbits.WPUA1
#define ENC_DIR_ANS                  ANSELAbits.ANSA1
#define ENC_DIR_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ENC_DIR_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ENC_DIR_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ENC_DIR_GetValue()           PORTAbits.RA1
#define ENC_DIR_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ENC_DIR_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ENC_DIR_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define ENC_DIR_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define ENC_DIR_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define ENC_DIR_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set ENC_PUL aliases
#define ENC_PUL_TRIS                 TRISAbits.TRISA2
#define ENC_PUL_LAT                  LATAbits.LATA2
#define ENC_PUL_PORT                 PORTAbits.RA2
#define ENC_PUL_WPU                  WPUAbits.WPUA2
#define ENC_PUL_ANS                  ANSELAbits.ANSA2
#define ENC_PUL_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define ENC_PUL_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define ENC_PUL_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define ENC_PUL_GetValue()           PORTAbits.RA2
#define ENC_PUL_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define ENC_PUL_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define ENC_PUL_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define ENC_PUL_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define ENC_PUL_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define ENC_PUL_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set channel_AN3 aliases
#define channel_AN3_TRIS                 TRISAbits.TRISA4
#define channel_AN3_LAT                  LATAbits.LATA4
#define channel_AN3_PORT                 PORTAbits.RA4
#define channel_AN3_WPU                  WPUAbits.WPUA4
#define channel_AN3_ANS                  ANSELAbits.ANSA4
#define channel_AN3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define channel_AN3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define channel_AN3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define channel_AN3_GetValue()           PORTAbits.RA4
#define channel_AN3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define channel_AN3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define channel_AN3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define channel_AN3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define channel_AN3_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define channel_AN3_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SR_DAT aliases
#define SR_DAT_TRIS                 TRISCbits.TRISC0
#define SR_DAT_LAT                  LATCbits.LATC0
#define SR_DAT_PORT                 PORTCbits.RC0
#define SR_DAT_WPU                  WPUCbits.WPUC0
#define SR_DAT_ANS                  ANSELCbits.ANSC0
#define SR_DAT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SR_DAT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SR_DAT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SR_DAT_GetValue()           PORTCbits.RC0
#define SR_DAT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SR_DAT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SR_DAT_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SR_DAT_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SR_DAT_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SR_DAT_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SR_CLK aliases
#define SR_CLK_TRIS                 TRISCbits.TRISC1
#define SR_CLK_LAT                  LATCbits.LATC1
#define SR_CLK_PORT                 PORTCbits.RC1
#define SR_CLK_WPU                  WPUCbits.WPUC1
#define SR_CLK_ANS                  ANSELCbits.ANSC1
#define SR_CLK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SR_CLK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SR_CLK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SR_CLK_GetValue()           PORTCbits.RC1
#define SR_CLK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SR_CLK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SR_CLK_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SR_CLK_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SR_CLK_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SR_CLK_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SR_LAT aliases
#define SR_LAT_TRIS                 TRISCbits.TRISC2
#define SR_LAT_LAT                  LATCbits.LATC2
#define SR_LAT_PORT                 PORTCbits.RC2
#define SR_LAT_WPU                  WPUCbits.WPUC2
#define SR_LAT_ANS                  ANSELCbits.ANSC2
#define SR_LAT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SR_LAT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SR_LAT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SR_LAT_GetValue()           PORTCbits.RC2
#define SR_LAT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SR_LAT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SR_LAT_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SR_LAT_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SR_LAT_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SR_LAT_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SPK aliases
#define SPK_TRIS                 TRISCbits.TRISC3
#define SPK_LAT                  LATCbits.LATC3
#define SPK_PORT                 PORTCbits.RC3
#define SPK_WPU                  WPUCbits.WPUC3
#define SPK_ANS                  ANSELCbits.ANSC3
#define SPK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SPK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SPK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SPK_GetValue()           PORTCbits.RC3
#define SPK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SPK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SPK_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SPK_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SPK_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SPK_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISCbits.TRISC4
#define LED0_LAT                  LATCbits.LATC4
#define LED0_PORT                 PORTCbits.RC4
#define LED0_WPU                  WPUCbits.WPUC4
#define LED0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED0_GetValue()           PORTCbits.RC4
#define LED0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED0_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF1 pin functionality
 * @Example
    IOCAF1_ISR();
 */
void IOCAF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_InterruptHandler);

*/
extern void (*IOCAF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_DefaultInterruptHandler);

*/
void IOCAF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF2 pin functionality
 * @Example
    IOCAF2_ISR();
 */
void IOCAF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_InterruptHandler);

*/
extern void (*IOCAF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);

*/
void IOCAF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/