/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Interface.h
 *       Module:  General Purpose Input Output 
 *
 *  Description:  This header file contains functions prototype and Macros user may use 
 *  
 *********************************************************************************************************************/
#ifndef		GPIO_INTERFACE_H
#define 	GPIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define  DISABLE		0
#define  ENABLE 		1


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} GPIO_PinNo;

typedef enum
{
	PA0=00, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
	PB0=10, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
	PC0=20, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
	PD0=30, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
	PE0=40, PE1, PE2, PE3, PE4, PE5, 	
	PF0=50, PF1, PF2, PF3, PF4 
} GPIO_ChannelType;

typedef enum
{
	PORTA, PORTB, PORTC, PORTD, PORTE, PORTF
} GPIO_PortType;

typedef enum
{
	Low, High
} GPIO_LevelType;

typedef enum
{
	PORT_LOW, PORT_INPUT=0, PORT_OUTPUT=255, PORT_HIGH=255
} GPIO_PortLevelType;




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

GPIO_LevelType GPIO_ReadChannel (GPIO_ChannelType ChannelId);
GPIO_PortLevelType GPIO_ReadPort (GPIO_PortType PortId);

void GPIO_WriteChannel (GPIO_ChannelType ChannelId, GPIO_LevelType Level);
void GPIO_WritePort (GPIO_PortType PortId, uint8 Level);

GPIO_LevelType GPIO_FlipChannel (GPIO_ChannelType ChannelId);


#endif		/* GPIO_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Interface.h
 *********************************************************************************************************************/

