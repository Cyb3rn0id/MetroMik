[![GitHub license](https://img.shields.io/badge/License-CC%20BY--SA--NC%204.0-blue)](LICENSE)  

![MetroMik](images/MetroMik.jpg)

# MetroMik

**MetroMik** is a Digital Metronome I built for my son Michele, hence the name. It's based around a [PIC16F1825](https://www.microchip.com/en-us/product/pic16f1825). Project is made for [MPLAB X Ide]([MPLAB® X IDE | Microchip Technology](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)) using [XC8 compiler]([MPLAB® XC8 Compiler | Microchip Technology](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/xc8)) and [MPLAB Code Configurator]([MPLAB® Code Configurator | Microchip Technology](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator)).  

Characteristics:

- Powered by a 18650 LiPo Cell
- Charging circuit
- BPM selection from 10 to 999
- Tempo selections: 2/4, ¾, 4/4
- Menù navigation using a rotary encoder
- 3 digits, 7-Segments led display
- Beating led
- Low battery indication on display

Full project specs [are listed here](https://www.settorezero.com/wordpress/metromik-metronomo-digitale-con-microcontrollore-pic/).  

Here is a video showing how it works:  
[![MAX7219sz PIC Lib Demo](https://img.youtube.com/vi/ZK1omlZPCnY/maxresdefault.jpg)](https://www.youtube.com/watch?v=ZK1omlZPCnY)  

# Components used

Following are sponsored links: if you buy some items following those links, you can support my works and final price for you will remain exactly the same.

- [TP4056 Lipo Charging module with protection](https://amzn.to/3NlDQtt)
- [18650 LiPo cell](https://amzn.to/4qS0tnE)
- [SX1308 Boost Converter](https://amzn.to/4qEyoRn)
- [LM386 amplifier module](https://amzn.to/3LpSmzP)
- 74HC595 Static Driving 3-digits 7-segments led display [^1] 
- PIC16F1825
- [Rotary Encoder with pushbutton](https://amzn.to/4qXKPaG)
- [LM1117-3.3 or LD33 Voltage regulator](https://amzn.to/4qnIMwB)
- [4Ω 0.5W Speaker](https://amzn.to/3LtRrhS)

[^1] The one I used has 3 small 7-segment-displays (digit) on it and actually is out of production (I used the [OHO DY1](https://github.com/Cyb3rn0id/Display_OHO_DY1)). You can use a common [4-digits one](https://amzn.to/45bj7id) but it will require some code adjustement. That kind of display exists also in 3-digits format (but it will require code adjustement anyway)
  
  
