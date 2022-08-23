/*
 * IntCtrl_Interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: youssef
 */

#ifndef INTCTRL_INTERFACE_H_
#define INTCTRL_INTERFACE_H_
/*
 * Table 2-9. Interrupts types in datasheet in (exception types 2.5.2) section
 * */
typedef enum
{
	GPIO_Port_A =0,
	GPIO_Port_B,
	GPIO_Port_C,
	GPIO_Port_D,
	GPIO_Port_E,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator_0,
	PWM0_Generator_1,
	PWM0_Generator_2,
	QEI0,
	ADC0_Sequence_0,
	ADC0_Sequence_1,
	ADC0_Sequence_2,
	ADC0_Sequence_3,
	Watchdog_Timers,
	Timer_0A,
	Timer_0B,
	Timer_1A,
	Timer_1B,
	Timer_2A,
	Timer_2B,
	Analog_Comparator_0,
	Analog_Comparator_1,
	_Reserved1 = -1,
	System_Control=28,
	Flash_Memory_Control,
	EEPROM_Control,
	GPIO_Port_F,
	_Reserved2 = -2,
	UART2=33,
	SSI1,
	Timer_3A,
	Timer_3B,
	I2C1,
	QEI1,
	CAN0,
	CAN1,
	_Reserved3 = -2,
	Hibernation_Module=43,
	USB,
	PWM_Generator_3,
	uDMA_Software,
	uDMA_Error,
	ADC1_Sequence_0,
	ADC1_Sequence_1,
	ADC1_Sequence_2,
	ADC1_Sequence_3,
	_Reserved4 = -5,
	SSI2=57,
	SSI3,
  	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	_Reserved5 = -4,
	I2C2=68,
	I2C3,
	Timer_4A,
	Timer_4B,
	_Reserved6 = -20,
	Timer_5A=92,
	Timer_5B,
	Wide_Timer_0A,
	Wide_Timer_0B,
	Wide_Timer_1A,
	Wide_Timer_1B,
	Wide_Timer_2A,
	Wide_Timer_2B,
	Wide_Timer_3A,
	Wide_Timer_3B,
	Wide_Timer_4A,
	Wide_Timer_4B,
	Wide_Timer_5A,
	Wide_Timer_5B,
	System_Exception,
	_Reserved7 = -27,
	PWM1_Generator_0 =134,
	PWM1_Generator_1,
	PWM1_Generator_2,
	PWM1_Generator_3,
	PWM1_Fault

}IntCtrl_InterruptTypes;


/*
 * Priority Grouping Configuration
 * */
#define 			XXX						0
#define 			XXY						1
#define 			XYY						2
#define 			YYY						3
/********************************/
#define 			ENABLE					1
#define 			DISABLE					0
#define				RESERVED				99

/*
 *  GLOBAL FUNCTIONS PROTOTYPES
 */
void IntCrtl_Init(void);




#endif /* INTCTRL_INTERFACE_H_ */
