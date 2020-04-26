[![GitHub license](https://img.shields.io/badge/License-CC%20BY--SA--NC%204.0-blue)](LICENSE)  

![MetroMik](images/MetroMik.jpg)

# MetroMik

MetroMik is a Digital Metronome I built for my son Michele, hence the name. It's based around a PIC16F1825.  
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
- TP4056 Lipo Charging module
- 18650 LiPo cell
- SX1308 DC-DC Booster module
- LM386 amplifier module
- 74HC595 Static Drivig 3-digits 7-segments led display
- PIC16F1825
- Rotary Encoder with pushbuttons
- LM1117-3.3 or LD33 Voltage regulator
- 4Ω 0.5W Speaker
- a bunch or resistors and capacitors [see schematic](documents/metromik_schematic.png)
- a Bahar Enclosures BMC-70012 enclosure
  
  
