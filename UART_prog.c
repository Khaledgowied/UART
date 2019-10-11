/*
 * UART_prog.c
 *
 *  Created on: Jul 20, 2018
 *      Author: Sedra Frimware
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include<avr/io.h>
#include"UART_interface.h"
#include"DIO_interface.h"



void UART_voidInit(void){
	SET_BIT(UCSRB,4);  //ENABLE RECIEVE
	SET_BIT(UCSRB,3);  //ENABLE TRANSMIT

	CLEAR_BIT(UCSRC,6); // MODE ASYNSCHRONOUS
	CLEAR_BIT(UCSRC,5); //DISABLE PARITY MODE
	CLEAR_BIT(UCSRC,4); //DISABLE PARITY MODE
	CLEAR_BIT(UCSRC,3); // STOP BIT 1 BIT ONLY

	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,1);   //CHARACHTER SIZE  -> 8 BIT
	CLEAR_BIT(UCSRB,2);

UBRRH=0;   //BE EQUATION BOUD RATE 9615
UBRRL=77;

}
void UART_voidSendByte(u8 Byte){
	while(GET_BIT(UCSRA,5)==0); // DATA REGISTER EMPTY
    UDR=Byte;

}
u8 UART_u8ReceiveByte(void){
	while(GET_BIT(UCSRA,7)==0);  //recieve compelete , frame sent

	return UDR;

}
