/*****************************************************************/
/****************** Name    : Ahmed Zaky *************************/
/****************** Date    : 14/2/2021  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : SCB        *************************/
/*****************************************************************/
#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H


//SCB
typedef struct{

	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;

}SCB_Type;

#define SCB ((volatile SCB_Type *) 0xE000ED00 )



#endif
