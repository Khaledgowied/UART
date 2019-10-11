/*
 * UART_interface.h
 *
 *  Created on: Jul 20, 2018
 *      Author: Sedra Frimware
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidSendByte(u8 Byte);
u8 UART_u8ReceiveByte(void);
void UART_voidInit(void);



#endif /* UART_INTERFACE_H_ */
