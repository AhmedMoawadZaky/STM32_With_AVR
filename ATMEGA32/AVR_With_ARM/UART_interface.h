/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 21/1/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : UART       *************************/
/*****************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void 	UART_voidUARTInit(void);

void 	UART_vidSend(u8 data);

u8   	UART_u8Resive(void);

u8 		UART_u8SendBufferSynchronous(u8 * Copy_pu8Buffer,u8 Copy_u8BufferSize);

u8 		UART_u8SendBufferASynchronous(u8 * Copy_pu8Buffer ,u8 Copy_u8BufferSize, void (* Copy_pfunctionNotification)(void));

u8 		UART_u8ResiveBufferSynchronous(u8 * Copy_pu8Buffer,u8 Copy_u8BufferSize);

u8  	UART_u8ResiveBufferASynchronous(u8 * Copy_pu8Buffer ,u8 Copy_u8BufferSize, void (* Copy_pfunctionNotification)(void));

#endif
