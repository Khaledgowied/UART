/*
 * main.c
 *
 *  Created on: Jul 20, 2018
 *      Author: Sedra Frimware
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include<avr/io.h>
#include"UART_interface.h"
#include"DIO_interface.h"
#include<util/delay.h>



int main(void){

	/*
	// sending PIN 1 PORTD
	UART_voidInit();
	while(1){

		UART_voidSendByte('a');
		_delay_ms(1000);
		UART_voidSendByte('b');
		_delay_ms(1000);
	}
*/

	//receive  PIN0 PORTD
	UART_voidInit();
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN_7, DIO_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN_6, DIO_OUTPUT);


u8 x;
while(1){

	x=UART_u8ReceiveByte();
	if(x=='a'){
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN_7, DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN_6, DIO_LOW);

	}else{

		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN_7, DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN_6, DIO_HIGH);
	}

}
	return 0;

}
