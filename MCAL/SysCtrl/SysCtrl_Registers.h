/*
 *
 *
 *  Created on: Aug 21, 2022
 *      Author: user
 *

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  SysCtrl_Registers.h
 *
 *       Module:  System Control
 *
 *  Description:  This header file contains Registers definition
 *
 *********************************************************************************************************************/


#ifndef SYSCTRL_REGISTERS_H_
#define SYSCTRL_REGISTERS_H_

#include"std_types.h"

#define RCC							(*(volatile uint32*)		(0x400FE000 + 0x060) )

#define RCC2						(*(volatile uint32*)		(0x400FE000 + 0x070) )

#define	RCGC2						(*(volatile uint32*)		(0x400FE000 + 0x108) )

#define PLLSTAT						(*(volatile uint32*) 	    (0x400FE000 + 0x168) )

#define RCGCGPIO					(*(volatile uint32*)	    (0x400FE000 + 0x608) )


#endif /* SYSCTRL_REGISTERS_H_ */
