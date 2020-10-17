# PIC18F_ECAN_Simple_Example
Simple example using the integrated ECAN module for PIC18F using MPLABX IDE and MPLAB Code Configurator.

![Imgur](https://i.imgur.com/whX5ydn.jpg)

The PIC18F receives a message from another CAN device and, based on the state of Payload Byte #1, illuminates an LED on RC4.

Received message:

DLC | ID | D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7
--- | -- | -- | -- | -- | -- | -- | -- | -- | --
 8  | B4 | SW | 00 | 00 | 00 | 00 | 00 | 00 | 00

Schematic:
![Imgur](https://i.imgur.com/RZJDw0Z.png)
