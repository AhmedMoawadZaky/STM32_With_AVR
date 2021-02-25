/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 14/2/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : SCB        *************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

u8 SCB_u8InitPriority(u8 Copy_u8GroupAndSubPriority){
	
	u8 Local_u8ErroreState = STD_TYPES_NOK;

	if(Copy_u8GroupAndSubPriority <= Group0_Sub16 ){

		SCB->AIRCR = ((0x05FA << 16) | (Copy_u8GroupAndSubPriority << 8)) ;
		Local_u8ErroreState = STD_TYPES_OK;
	}
	return Local_u8ErroreState;
}
