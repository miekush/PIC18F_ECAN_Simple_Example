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

void printRxMessage(void); //function to print CAN message

uCAN_MSG rxMessage;

void main(void) {
    
    SYSTEM_Initialize(); //init CAN and USART
    TRISC4 = 0; //set RC4 as output
    
    while(1){
        if (CAN_receive(&rxMessage)) {
        printRxMessage();
        }
    }
}

void printRxMessage(void) {
    char canBuff[20]; //buffer for message data
    if (rxMessage.frame.idType == dSTANDARD_CAN_MSG_ID_2_0B && rxMessage.frame.id == 0xB4) {
        printf("DATA = %X\n", rxMessage.frame.data0); //print message data to serial terminal
        RC4 = (rxMessage.frame.data0); //set LED to message state
 }
}
