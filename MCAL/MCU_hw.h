/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_Private.h
 *       Module:  MicroController Unit 
 *
 *  Description:  This header file contains Registers definition 
 *  
 *********************************************************************************************************************/
#ifndef MCU_PRIVATE_H
#define MCU_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIBRARIES/Std_Types.h"

/**********************************************************************************************************************
 *  Base Addresses
 *********************************************************************************************************************/

#define 	SYSTEM_CONTROL_BASE				0x400FE000
#define 	M4_PERI_BASE_ADDRESS			0xE000E000

/**********************************************************************************************************************
 *  System Control Registers
 *********************************************************************************************************************/
#if 1
/************************************GLOBAL DATA TYPES AND STRUCTURES MACROS*******************************************/
typedef struct
{
	uint32 MOSCDIS			:1;
	uint32 				:3;
	uint32 OSCSRC			:2;
	uint32 XTAL			:5;
	uint32 BYPASS			:1;
	uint32 				:1;
	uint32 PWRDN			:1;
	uint32					:3;
	uint32 PWMDIV			:3;
	uint32 USEPWMDIV		:1;
	uint32 				:1;
	uint32 USESYSDIV		:1;
	uint32 SYSDIV			:4;
	uint32 ACG				:1;
	uint32 				:4;
}RCC_BF;

typedef union
{
	uint32 	R;
	RCC_BF  B;
}RCC_Tag;

typedef struct
{
	uint32 				:4;
	uint32 OSCSRC2			:3;
	uint32 				:4;
	uint32 BYPASS2			:1;
	uint32 				:1;
	uint32 PWRDN2			:1;
	uint32 USBPWRDN		:1;
	uint32					:7;
	uint32 SYSDIV2LSB		:1;
	uint32 SYSDIV2			:6;
	uint32 				:1;
	uint32 DIV400			:1;
	uint32 USERCC2			:1;
}RCC2_BF;

typedef union
{
	uint32 	R;
	RCC2_BF  B;
}RCC2_Tag;

typedef struct
{
	uint32		R0			:1;
	uint32		R1			:1;
	uint32		R2			:1;
	uint32		R3			:1;
	uint32		R4			:1;
	uint32		R5			:1;
	uint32 				:26;
}RCGCGPIO_BF;

typedef union 
{
	uint32 R;
	RCGCGPIO_BF B;
}RCGCGPIO_Tag;


typedef struct 
{
	uint32 GPIOA		:1;
	uint32 GPIOB		:1;
	uint32 GPIOC		:1;
	uint32 GPIOD		:1;
	uint32 GPIOE		:1;
	uint32 GPIOF		:1;
	uint32 			:7;
	uint32 UDMA		:1;
	uint32				:2;
	uint32	USB0		:1;
	uint32				:15;
}RCGC2_BF;
typedef union 
{
	uint32 R;
	RCGC2_BF B;
}RCGC2_Tag;

typedef struct
{
	uint32				:31;
	uint32 LOCK		:1;
}PLLSTAT_BF;

typedef union
{
	PLLSTAT_BF  B;
}PLLSTAT_Tag;

typedef struct
{
	uint32		R0			:1;
	uint32		R1			:1;
	uint32		R2			:1;
	uint32		R3			:1;
	uint32		R4			:1;
	uint32		R5			:1;
	uint32 				:26;
}RCGCWTIMER_BF;

typedef union 
{
	uint32 R;
	RCGCWTIMER_BF B;
}RCGCWTIMER_Tag;


typedef struct
{
	uint8		B0			:1;
	uint8		B1			:1;
	uint8		B2			:1;
	uint8		B3			:1;
	uint8		B4			:1;
	uint8		B5			:1;
	uint8		B6			:1;
	uint8		B7			:1;
}u8_BF;

typedef union 
{
	uint8 R;
	u8_BF B;
}u8_Tag;

typedef struct
{
	uint32 B0    	:1;
	uint32 B1    	:1;
	uint32 B2    	:1;
	uint32 B3    	:1;
	uint32 B4    	:1;
	uint32 B5    	:1;
	uint32 B6    	:1;
	uint32 B7    	:1;
	uint32 B8    	:1;
	uint32 B9    	:1;
	uint32 B10    	:1;
	uint32 B11    	:1;
	uint32 B12    	:1;
	uint32 B13    	:1;
	uint32 B14    	:1;
	uint32 B15    	:1;
	uint32 B16    	:1;
	uint32 B17    	:1;
	uint32 B18    	:1;
	uint32 B19    	:1;
	uint32 B20    	:1;
	uint32 B21    	:1;
	uint32 B22    	:1;
	uint32 B23    	:1;
	uint32 B24    	:1;
	uint32 B25    	:1;
	uint32 B26    	:1;
	uint32 B27    	:1;
	uint32 B28    	:1;
	uint32 B29    	:1;
	uint32 B30    	:1;
	uint32 B31    	:1;
	uint32 B32    	:1;
} u32_BF;

typedef union
{
	uint32 R;
	u32_BF B;
} u32_Tag ;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define 	BASE_ADDRESS(PORTx)				(PORTx<4 ? (0x40004000 + (PORTx*0x1000)) : (0x40024000 + (PORTx-4)*0x1000))

#define 	GPIOLOCK(PORTx)					(*( volatile uint32*)( (BASE_ADDRESS(PORTx))+ 0x520 ) )
#define 	GPIOCR(PORTx)					(*( volatile uint8*) ( (BASE_ADDRESS(PORTx))+ 0x524 ) )
#define 	GPIODEN(PORTx)					(*( volatile uint8*) ( (BASE_ADDRESS(PORTx))+ 0x51C ) )
#define 	GPIOAFSEL(PORTx)				(*( volatile uint8*) (  BASE_ADDRESS(PORTx) + 0x420 ) )
#define 	GPIODIR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x400 ) )
#define 	GPIOPUR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x510 ) )
#define 	GPIOODR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x50C ) )
#define 	GPIOPDR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x514 ) )
#define 	GPIOPCTL(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x52C ) )
#define 	GPIODATA(PORTx)					(*( volatile u8_Tag*)(  BASE_ADDRESS(PORTx) + 0x3FC ) )

/************************************GLOBAL CONSTANT MACROS************************************************************/

#define RCC							(*(volatile RCC_Tag*)		(SYSTEM_CONTROL_BASE + 0x060) )
#define RCC2						(*(volatile RCC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x070) )
#define	RCGC2						(*(volatile RCGC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x108) )
#define PLLSTAT						(*(volatile PLLSTAT_Tag*) 	(SYSTEM_CONTROL_BASE + 0x168) )
#define RCGCGPIO					(*(volatile RCGCGPIO_Tag*)	(SYSTEM_CONTROL_BASE + 0x608) )
#define RCGCWTIMER					(*(volatile RCGCWTIMER_Tag*)(SYSTEM_CONTROL_BASE + 0x65C) )
#define RCGCTIMER					(*(volatile RCGCWTIMER_Tag*)(SYSTEM_CONTROL_BASE + 0x604) )

#endif


/**********************************************************************************************************************
 *  GPIO Registers
 *********************************************************************************************************************/
#if 1

#define 	INTCTRL						(*(volatile INTCTRL_Tag*)( M4_PERI_BASE_ADDRESS + 0xD04) )

#endif





/**********************************************************************************************************************
 *  GPT Registers
 *********************************************************************************************************************/
#if 1	

#define		RCGC1


#endif


/**
*Port Initiatlization Configurations 2D Array
**/







#endif
