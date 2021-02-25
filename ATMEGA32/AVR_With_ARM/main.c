#include"util/delay.h"
#define F_CPU   8000000UL

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include"DIO_interface.h"
#include"GINT_interface.h"
#include"UART_interface.h"

/* HAL Layer */
#include"LCD.h"

#define BUFFER_SIZE              1

u8 Global_RX_Buffer[BUFFER_SIZE];

void CallBackFunction(void);


int main(void){

	DIO_voidInit();
	LCD_vidInit();
	UART_voidUARTInit();

	/* We should Set Callback Function Before Enable UART*/

	/* Enable Global INT */
	GINT_voidEnable();
	LCD_vidClear();
	while(1){

		UART_u8ResiveBufferASynchronous( Global_RX_Buffer, BUFFER_SIZE , &CallBackFunction);

	}

	return 0;
}


void CallBackFunction(void){

	LCD_vidSetPosition(0 , 0);
	LCD_vidWriteString((u8 *) "TEMP = ");
	for(u8 i = 0 ; i < BUFFER_SIZE ;++i){
		LCD_vidWriteNumber(Global_RX_Buffer[i]);
		LCD_vidWriteString((u8 *) "   ");
	}
}
