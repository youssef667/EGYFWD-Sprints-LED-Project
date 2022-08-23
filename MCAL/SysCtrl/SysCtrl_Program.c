/*
 * SysCtrl_Program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: user
 */


#include "common_macros.h"
#include "std_types.h"

#include "SysCtrl_Interface.h"
#include "SysCtrl_Configure.h"
#include "SysCtrl_Registers.h"


void SysCtrl_MicrocontrollerInit (void)
{

	RCC	 |= ((!MAIN_OSCILLATOR)<<0);
	RCC	 |= (OSCILLATOR_SOURCE<<4);
	RCC	 |= (CRYSTAL_VALUE<<6);
	RCC	 |= (PLL_BYPASS<<11);

#if (PLL_BYPASS !=	ENABLE)   &&  (PLL_POWER_DOWN  == ENABLE)
	#warning "No other clock source is functioning"
#elif		PLL_BYPASS	== DISABLE
	while (BIT_IS_CLEAR(PLLSTAT,32));

#else

	RCC	 |= (PLL_POWER_DOWN<<13);
#endif


	    RCC	 |= (PWM_DIVISOR<<13);

		RCC	 &=~(PWM_DIVISOR_EN<<14);

		RCC|= (SYSCLOCK_DIVIDER_EN<<22);

		RCC|= ((SYSTEM_CLOCK_DIVIDER -1)<<23);

		RCC	 &=~(AUTO_CLOCK_GATING<<27);

		    RCC2  |= (OSCILLATOR_SOURCE_2<<4);


			RCC2  |= (PLL_BYPASS_2<<11);


			RCC2  |= (PLL_POWER_DOWN_2<<13);


			RCC2  |= (PWRDN_USB_PLL<<14);


			RCC2 &=~(DIVIDE_PLL_AS<<30);

			#if DIVIDE_PLL_AS	== _400_MHZ
				RCC2| = (GET_BIT( SYSTEM_CLOCK_DIVIDER_2 ,0)<<19);
				RCC2=( (SYSTEM_CLOCK_DIVIDER_2 >> 1)<<20) ;
			#else

				RCC2  |= ((SYSTEM_CLOCK_DIVIDER_2 -1)<<23);
			#endif

			RCC2 &=~(USE_RCC2<<31);

}
