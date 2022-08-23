/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Private.h
 *       Module:  General Purpose Input Output 
 *
 *  Description:  This header file contains Registers definition 
 *  
 *********************************************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIBRARIES/Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef struct
{
	uint32	PMC0	:4;

	uint32	PMC1	:4;

	uint32	PMC2	:4;

	uint32	PMC3	:4;

	uint32	PMC4	:4;

	uint32	PMC5	:4;

	uint32	PMC6	:4;

	uint32	PMC7	:4;
}GPIOPCTL_BF;

typedef union
{
	uint32 R;
	GPIOPCTL_BF B;
} GPIOPCTL_Tag;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define 	GPIOA_APB_BASE_ADDRESS			0x40004000

#define 	GPIOB_APB_BASE_ADDRESS			0x40005000

#define 	GPIOC_APB_BASE_ADDRESS			0x40006000

#define 	GPIOD_APB_BASE_ADDRESS			0x40007000

#define 	GPIOE_APB_BASE_ADDRESS			0x40024000

#define 	GPIOF_APB_BASE_ADDRESS			0x40025000




#define 	GPIODATA_PA					(*( volatile uint8*)(  GPIOA_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )
#define 	GPIODATA_PB					(*( volatile uint8*)(  GPIOB_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )
#define 	GPIODATA_PC					(*( volatile uint8*)(  GPIOC_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )
#define 	GPIODATA_PD					(*( volatile uint8*)(  GPIOD_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )
#define 	GPIODATA_PE					(*( volatile uint8*)(  GPIOE_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )
#define 	GPIODATA_PF					(*( volatile uint8*)(  GPIOF_APB_BASE_ADDRESS+ 0x000 +0x3FC ) )

#define 	GPIOLOCK_PA					(*( volatile uint32*)(  GPIOA_APB_BASE_ADDRESS+ 0x520 ) )
#define 	GPIOLOCK_PB					(*( volatile uint32*)(  GPIOB_APB_BASE_ADDRESS+ 0x520 ) )
#define 	GPIOLOCK_PC					(*( volatile uint32*)(  GPIOC_APB_BASE_ADDRESS+ 0x520 ) )
#define 	GPIOLOCK_PD					(*( volatile uint32*)(  GPIOD_APB_BASE_ADDRESS+ 0x520 ) )
#define 	GPIOLOCK_PE					(*( volatile uint32*)(  GPIOE_APB_BASE_ADDRESS+ 0x520 ) )
#define 	GPIOLOCK_PF					(*( volatile uint32*)(  GPIOF_APB_BASE_ADDRESS+ 0x520 ) )

#define 	GPIOPCTL_PA					(*( volatile GPIOPCTL_Tag*)(  GPIOA_APB_BASE_ADDRESS+ 0x52C ) )
#define 	GPIOPCTL_PB					(*( volatile GPIOPCTL_Tag*)(  GPIOB_APB_BASE_ADDRESS+ 0x52C ) )
#define 	GPIOPCTL_PC					(*( volatile GPIOPCTL_Tag*)(  GPIOC_APB_BASE_ADDRESS+ 0x52C ) )
#define 	GPIOPCTL_PD					(*( volatile GPIOPCTL_Tag*)(  GPIOD_APB_BASE_ADDRESS+ 0x52C ) )
#define 	GPIOPCTL_PE					(*( volatile GPIOPCTL_Tag*)(  GPIOE_APB_BASE_ADDRESS+ 0x52C ) )
#define 	GPIOPCTL_PF					(*( volatile GPIOPCTL_Tag*)(  GPIOF_APB_BASE_ADDRESS+ 0x52C ) )

#define 	GPIOCR_PA					(*( volatile uint8*)(  GPIOA_APB_BASE_ADDRESS+ 0x524 ) )
#define 	GPIOCR_PB					(*( volatile uint8*)(  GPIOB_APB_BASE_ADDRESS+ 0x524 ) )
#define 	GPIOCR_PC					(*( volatile uint8*)(  GPIOC_APB_BASE_ADDRESS+ 0x524 ) )
#define 	GPIOCR_PD					(*( volatile uint8*)(  GPIOD_APB_BASE_ADDRESS+ 0x524 ) )
#define 	GPIOCR_PE					(*( volatile uint8*)(  GPIOE_APB_BASE_ADDRESS+ 0x524 ) )
#define 	GPIOCR_PF					(*( volatile uint8*)(  GPIOF_APB_BASE_ADDRESS+ 0x524 ) )


#define 	GPIOICR_PA					(*( volatile uint8*)(  GPIOA_APB_BASE_ADDRESS+ 0x41C ) )
#define 	GPIOICR_PB					(*( volatile uint8*)(  GPIOB_APB_BASE_ADDRESS+ 0x41C ) )
#define 	GPIOICR_PC					(*( volatile uint8*)(  GPIOC_APB_BASE_ADDRESS+ 0x41C ) )
#define 	GPIOICR_PD					(*( volatile uint8*)(  GPIOD_APB_BASE_ADDRESS+ 0x41C ) )
#define 	GPIOICR_PE					(*( volatile uint8*)(  GPIOE_APB_BASE_ADDRESS+ 0x41C ) )
#define 	GPIOICR_PF					(*( volatile uint8*)(  GPIOF_APB_BASE_ADDRESS+ 0x41C ) )

#define 	GPIOAFSEL_PA				(*( volatile uint8*)(  GPIOA_APB_BASE_ADDRESS+ 0x420 ) )
#define 	GPIOAFSEL_PB				(*( volatile uint8*)(  GPIOB_APB_BASE_ADDRESS+ 0x420 ) )
#define 	GPIOAFSEL_PC				(*( volatile uint8*)(  GPIOC_APB_BASE_ADDRESS+ 0x420 ) )
#define 	GPIOAFSEL_PD				(*( volatile uint8*)(  GPIOD_APB_BASE_ADDRESS+ 0x420 ) )
#define 	GPIOAFSEL_PE				(*( volatile uint8*)(  GPIOE_APB_BASE_ADDRESS+ 0x420 ) )
#define 	GPIOAFSEL_PF				(*( volatile uint8*)(  GPIOF_APB_BASE_ADDRESS+ 0x420 ) )

#define 	GPIODIR_PA					(*( volatile uint8*)(  GPIOA_APB_BASE_ADDRESS+ 0x400 ) )
#define 	GPIODIR_PB					(*( volatile uint8*)(  GPIOB_APB_BASE_ADDRESS+ 0x400 ) )
#define 	GPIODIR_PC					(*( volatile uint8*)(  GPIOC_APB_BASE_ADDRESS+ 0x400 ) )
#define 	GPIODIR_PD					(*( volatile uint8*)(  GPIOD_APB_BASE_ADDRESS+ 0x400 ) )
#define 	GPIODIR_PE					(*( volatile uint8*)(  GPIOE_APB_BASE_ADDRESS+ 0x400 ) )
#define 	GPIODIR_PF					(*( volatile uint8*)(  GPIOF_APB_BASE_ADDRESS+ 0x400 ) )

#define 	GPIODEN_PA					(*( volatile uint8*)(  GPIOA_APB_BASE_ADDRESS+ 0x51C ) )
#define 	GPIODEN_PB					(*( volatile uint8*)(  GPIOB_APB_BASE_ADDRESS+ 0x51C ) )
#define 	GPIODEN_PC					(*( volatile uint8*)(  GPIOC_APB_BASE_ADDRESS+ 0x51C ) )
#define 	GPIODEN_PD					(*( volatile uint8*)(  GPIOD_APB_BASE_ADDRESS+ 0x51C ) )
#define 	GPIODEN_PE					(*( volatile uint8*)(  GPIOE_APB_BASE_ADDRESS+ 0x51C ) )
#define 	GPIODEN_PF					(*( volatile uint8*)(  GPIOF_APB_BASE_ADDRESS+ 0x51C ) )


#endif 		/* GPIO_PRIVATE_H */
/**********************************************************************************************************************
 *  END OF FILE: GPIO_Private.h
 *********************************************************************************************************************/

