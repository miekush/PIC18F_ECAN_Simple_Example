/*
 * File:   main.c
 * Author: Mike Kushnerik
 * Description: Basic CAN bus example with LED and UART output using PIC18F26K80
 * Created on October 3, 2020, 6:44 PM
 */
#include "mcc_generated_files/mcc.h"
#include "config.h"
#include <xc.h>
#include <stdio.h>

#define _XTAL_FREQ 20000000 //20MHz external crystal

uCAN_MSG rxMessage;

void main(void) {
    
    SYSTEM_Initialize(); //init CAN and USART
    TRISC4 = 0; //set RC4 as output
    
    while(1){
        if (CAN_receive(&rxMessage)) {
            if (rxMessage.frame.idType == dSTANDARD_CAN_MSG_ID_2_0B && rxMessage.frame.id == 0xC4) {
                RC4 = rxMessage.frame.data0 & 0b00000001; //set LED to message state
//                printf("ID: %X ", rxMessage.frame.id); //print message id to serial terminal
//                printf("DATA: %02X ", rxMessage.frame.data0); //print message data 0 to serial terminal
//                printf("%02X ", rxMessage.frame.data1); //print message data 1 to serial terminal
//                printf("%02X ", rxMessage.frame.data2); //print message data 2 to serial terminal
//                printf("%02X ", rxMessage.frame.data3); //print message data 3 to serial terminal
//                printf("%02X ", rxMessage.frame.data4); //print message data 4 to serial terminal
//                printf("%02X ", rxMessage.frame.data5); //print message data 5 to serial terminal
//                printf("%02X ", rxMessage.frame.data6); //print message data 6 to serial terminal
//                printf("%02X\n", rxMessage.frame.data7); //print message data 7 to serial terminal
            }
        }
    }
}
