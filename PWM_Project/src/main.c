/* Includes */
#include "GPIO_Driver.h"
#include "TCNT_Driver.h"
#include "PWM_Driver.h"


volatile uint32 TickCounter=0x00;
uint8 state = 0x00;
uint32 index = 0x00;


void SysTick_Handler()
{
	if(TickCounter!=0x00)
	{
		TickCounter--;
	}
}

void Delay(uint32 DelayInterval)
{
	TickCounter = DelayInterval;
	while(TickCounter!=0x00){}
}

int main(void)
{
	GPIOD_Driver_Setup_type TestPWM={0x00};

	SysTick_Config(SystemCoreClock/1000);

	TestPWM.Mode        |=  GPIO_DRIVER_ALTERNATE_FUNCTION_MODE;
	TestPWM.Pins        |=  GPIO_DRIVER_PIN_1;
	TestPWM.PuPd        |=  GPIO_DRIVER_PUPD_NOPULL;
	TestPWM.Speed       |=  DEFAULT;

	GPIO_Driver_Init(GPIOA,&TestPWM);
	GPIO_Driver_SetAlternateFunction(GPIOA,GPIO_DRIVER_PIN_AFNR_1,GPIO_DRIVER_AF1_TIM_2);

	TCNT_Driver_Init(TIM2);
	TCNT_Driver_SetPrescale(TIM2,0x00);

	PWM_Driver_Init(TIM2);
	PWM_Driver_SetPeriod(TIM2,(8400));

	TCNT_Driver_Start(TIM2);

	while (1)
	{
		for(index = 0;index<84;index++)
		{
			PWM_Driver_SetDutyCylce(TIM2,(index*100),PWM_DRIVER_CC_2);
			Delay(20);
		}
		for(index = 84;index>=1;index--)
		{
			PWM_Driver_SetDutyCylce(TIM2,(index*100),PWM_DRIVER_CC_2);
			Delay(20);
		}
	}
}
