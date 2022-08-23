/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Private.h
 *       Module:  Port  
 *
 *  Description:  This header file contains Registers definition 
 *  
 *********************************************************************************************************************/
#ifndef PORT_PRIVATE_H
#define PORT_PRIVATE_H

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
 *  GLOBAL DATA TYPES AND STRUCTURES MACROS
 *********************************************************************************************************************/
typedef struct 
{
	uint32 GPIOA		:1;
	uint32 GPIOB		:1;
	uint32 GPIOC		:1;
	uint32 GPIOD		:1;
	uint32 GPIOE		:1;
	uint32 GPIOF		:1;
	uint32 			    :7;
	uint32 UDMA		    :1;
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
	uint32	R0			:1;
	uint32	R1			:1;
	uint32	R2			:1;
	uint32	R3			:1;
	uint32	R4			:1;
	uint32	R5			:1;
	uint32 				:26;
}RCGCGPIO_BF;

typedef union 
{
	uint32 R;
	RCGCGPIO_BF B;
}RCGCGPIO_Tag;

typedef union 
{
	uint32 R;
}u32_Tag;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define 	BASE_ADDRESS(PORTx)				(PORTx<4 ? (0x40004000 + (PORTx*0x1000)) : (0x40024000 + (PORTx-4)*0x1000))

#define 	GPIOLOCK(PORTx)					(*( volatile uint32*)( (BASE_ADDRESS(PORTx))+ 0x520 ) )
#define 	GPIOCR(PORTx)					(*( volatile uint32*) ( (BASE_ADDRESS(PORTx))+ 0x524 ) )
#define 	GPIODEN(PORTx)					(*( volatile uint32*) ( (BASE_ADDRESS(PORTx))+ 0x51C ) )
#define 	GPIOAFSEL(PORTx)				(*( volatile uint32*) (  BASE_ADDRESS(PORTx) + 0x420 ) )
#define 	GPIODIR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x400 ) )
#define 	GPIOPUR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x510 ) )
#define 	GPIOODR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x50C ) )
#define 	GPIOPDR(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x514 ) )
#define 	GPIOPCTL(PORTx)					(*( volatile uint32*)(  BASE_ADDRESS(PORTx) + 0x52C ) )
#define 	GPIODATA(PORTx)					(*( volatile u32_Tag*)(  BASE_ADDRESS(PORTx) + 0x3FC ) )


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCGCGPIO					(*(volatile RCGCGPIO_Tag*)	(SYSTEM_CONTROL_BASE + 0x608) )
#define	RCGC2						(*(volatile RCGC2_Tag*)		(SYSTEM_CONTROL_BASE + 0x108) )





#endif		/* PORT_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Private.h
 *********************************************************************************************************************/

