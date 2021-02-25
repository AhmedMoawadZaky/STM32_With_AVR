/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_Interface.h"
#include "SCB_Interface.h"
#include "ADC_Interface.h"
#include "USART_Interface.h"

void CallBack_USART2(u8 Resive);

int main(void)
{

	RCC_VidInit();

	RCC_VidEnablePeripheralClock(APB2_BUS, GPIOA_RCC);
	RCC_VidEnablePeripheralClock(APB2_BUS, ADC1_RCC);

	RCC_VidEnablePeripheralClock(APB1_BUS, USART2_RCC);

	MNVIC_u8EnablePeripheral(USART2);

	/* ADC FOR TEMP Sensor */
	GPIO_VidSetPinDirection(GPIOA ,  PIN0, INPUT_ANLOG);

	/*LED Control Through BL */
	GPIO_VidSetPinDirection(GPIOA ,  PIN7, OUTPUT_SPEED_2MHZ_PP);

	/* UART2 */
	/* TX1*/
	GPIO_VidSetPinDirection(GPIOA ,  PIN2, OUTPUT_SPEED_10MHZ_AFPP);
	/* UART2 */
	/* RX2*/
	GPIO_VidSetPinDirection(GPIOA ,  PIN3, INPUT_FLOATING);

	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidMode();
	ADC_voidResetCalAndCal();

	//MUSART1_voidInit();
	MUSART2_voidInit();
	u16 TEMP=0;

	MUSART2_VidSetCallBack(CallBack_USART2);

	/* Loop forever */
	while(1){

		TEMP = Adc_voidReadADC(CH0,ADC_SampleTime_Cycles_5);
		TEMP = (TEMP* 330) / 4096 ;

		MUSART2_voidTransmit(TEMP);

	}
	return 0;
}

void CallBack_USART2(u8 Resive){

	if(Resive == '1'){

		GPIO_VidSetPinValue(GPIOA, PIN7, 1);
	}
	else{
		GPIO_VidSetPinValue(GPIOA, PIN7, 0);
	}
}

