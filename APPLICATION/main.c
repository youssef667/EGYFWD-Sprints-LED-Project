#include "GPIO_Interface.h"
#include "SysCtrl_Interface.h"
#include "GPT_Interface.h"
#include "PORT_Interface.h"
#include "IntCtrl_Interface.h"
#include "Std_Types.h"

void LED_Implementation (void);
void Blinking_LED (uint32 Ticks );

int main(void)
{	
	
	SysCtrl_MicrocontrollerInit();
	IntCrtl_Init();
	PORT_Init();
	GPT_Init();
	
	while(1)
	{
		Blinking_LED (16000000);//16Mhz - > 1sec
	}
	return 0;
}

void LED_Implementation (void)
{
	GPIO_FlipChannel( PF2 );
}
void Blinking_LED (uint32 Ticks )
{
	GPT_EnableNotification(T0);
	GPT_Notification_T0(LED_Implementation);
	GPT_StartTimer(T0 , Ticks);
}

