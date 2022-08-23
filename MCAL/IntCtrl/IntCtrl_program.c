/*
 * IntCtrl_program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: youssef
 */
#include"common_macros.h"
#include"std_types.h"
#include"IntCtrl_Configration.h"
#include"IntCtrl_Interface.h"
#include"IntCtrl_registers.h"

void IntCrtl_Init(void){

	/*enum forInterrupt Number (Bit in Interrupt Registers)*/
	IntCtrl_InterruptTypes iteratrigInt =0;
	uint32 IntEnableMask = 1;
	uint8 	RegNo = 0;
    uint8 	BitNo = 0;
    uint8	PrioValue = 0;
	uint8 	Prio_i =0;
	uint8 	PrioMask [4] = {4 , 12 , 20, 28};
	uint8  PRI_reg = 0;

	 APINT &=~(1<<0);
	 APINT &=~(1<<1);
	 APINT &=~(1<<2);
	 APINT|=(0x05FA<<16);
#if  PRIORITY_GROUPING_SUBGROUPING  == XXX
	    APINT &=~(1<<8);
    	APINT &=~(1<<9);
	    APINT &=~(1<<10);
#elif   PRIORITY_GROUPING_SUBGROUPING    ==    XXY
	    APINT |=(1<<8);
		APINT &=~(1<<9);
		APINT |=(1<<10);
#elif   PRIORITY_GROUPING_SUBGROUPING     ==    XYY
	    APINT &=~(1<<8);
		APINT |=(1<<9);
		APINT |=(1<<10);
#elif   PRIORITY_GROUPING_SUBGROUPING     ==    YYY
	    APINT |=(1<<8);
	    APINT |=(1<<9);
		APINT |=(1<<10);
#endif

#if  MEMORY_MANAGEMENT_EN  == DISABLE
		SYSHNDCTRL&=~(1<<16);
#endif

#if  MEMORY_MANAGEMENT_EN  == ENABLE
		SYSHNDCTRL|=(1<<16);
#endif
#if  BUS_FAULT_EN  == DISABLE
		SYSHNDCTRL&=~(1<<17);
#endif

#if  BUS_FAULT_EN == ENABLE
		SYSHNDCTRL|=(1<<17);
#endif

#if  USAGE_FAULT_EN	  == DISABLE
		SYSHNDCTRL&=~(1<<18);
#endif

#if  USAGE_FAULT_EN	  == ENABLE
		SYSHNDCTRL|=(1<<18);
#endif


		NVIC_SYSTEM_PRI1_REG|=(Memory_Management_Priority<<5);
		NVIC_SYSTEM_PRI1_REG|=(Bus_Fault_Priority<<13);
		NVIC_SYSTEM_PRI1_REG|=(Usage_Fault_Priority<<21);

		NVIC_SYSTEM_PRI2_REG |=(SVCall_Priority<<29);


		NVIC_SYSTEM_PRI3_REG|=(Debug_Monitor_Priority<<5);
		NVIC_SYSTEM_PRI3_REG|=(PendSV_Priority<<21);
		NVIC_SYSTEM_PRI3_REG|=(SysTick_Priority<<29);

		for(iteratrigInt = GPIO_Port_A ; iteratrigInt <= PWM1_Fault ; iteratrigInt++){
			/*reserved bits*/
			if(IntCtrl_InterruptCfg[iteratrigInt][IntName] < 0){

				/**If it is reserved keep iterating without assigning any values**/
							uint8 i = 0;
							for( i=0 ; i<= -(IntCtrl_InterruptCfg[iteratrigInt][IntName] ) ; i++)
							{
								IntEnableMask <<= 1;
								if(IntEnableMask == 0)
								{
									IntEnableMask = 1 ;
									RegNo++ ;
								}
								Prio_i 	== 3		?	Prio_i= 0, PRI_reg++ : Prio_i++;
								BitNo 	== 7 		?	BitNo = 0 : BitNo++ ;
								//PrioMask == 0xE0000000 ? (PrioMask = 0x000000E0) : (PrioMask <<= 8);
								iteratrigInt++;
							}
							iteratrigInt--;
							continue;

			}
   #if PRIORITY_GROUPING_SUBGROUPING == XXX
		PrioValue = IntCtrl_InterruptCfg[iteratrigInt][Grouping];
	#elif PRIORITY_GROUPING_SUBGROUPING  ==    XXY
		PrioValue = (IntCtrl_InterruptCfg[iteratrigInt][Grouping] << 1) + IntCtrl_InterruptCfg[iteratingInt].SubGrouping;
	#elif PRIORITY_GROUPING_SUBGROUPING  ==    XYY
		PrioValue = (IntCtrl_InterruptCfg[iteratrigInt][Grouping] << 2) + IntCtrl_InterruptCfg[iteratingInt].SubGrouping;
	#elif	PRIORITY_GROUPING_SUBGROUPING  ==    YYY
		PrioValue = IntCtrl_InterruptCfg[iteratrigInt][SubGrouping];
	#endif

		PRI(PRI_reg)  |=  (uint32)((PrioValue) << (PrioMask[Prio_i]) );
		if(IntCtrl_InterruptCfg[iteratrigInt][IntEnable] == ENABLE)
				{
					/*Set its bit in ENx*/
					if( RegNo ==0 ){
						SET_BIT(NVIC_EN0_REG  , BitNo);}
					else if ( RegNo == 1){
						SET_BIT(NVIC_EN1_REG  , BitNo);}
					else if ( RegNo == 2){
						SET_BIT(NVIC_EN2_REG  , BitNo);}
					else if ( RegNo == 3)
						{SET_BIT(NVIC_EN3_REG  , BitNo);}
					else if ( RegNo == 4)
					{	SET_BIT(NVIC_EN4_REG  , BitNo);}
				}

		IntEnableMask <<= 1;
				if(IntEnableMask == 0)
				{
					IntEnableMask = 1 ;
					RegNo++ ;
				}
				Prio_i 	== 3		?	Prio_i= 0, PRI_reg++ : Prio_i++;
				BitNo == 31 		?	BitNo = 0 : BitNo++ ;
				//PrioMask == 0xE0000000 ? (PrioMask = 0x000000E0) : (PrioMask <<= 8);
		}
}
