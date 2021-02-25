/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 14/2/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : SCB        *************************/
/*****************************************************************/
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H

enum IRQ_Priority{
	
	Group16_Sub0 = 3,
	Group8_Sub2,
	Group4_Sub4,
	Group2_Sub8,
	Group0_Sub16
};

u8 SCB_u8InitPriority(u8 Copy_u8GroupAndSubPriority);

#endif
