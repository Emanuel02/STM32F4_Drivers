/* Includes */
#include "GPIO_Driver.h"
#include "TCNT_Driver.h"


uint8 state = 0x00;

int main(void)
{
	GPIOD_Driver_Setup_type TestLedGPIO={0x00};

	TestLedGPIO.Mode	|=	GPIO_DRIVER_OUTPUT_MODE;
	TestLedGPIO.Pins	|=	GPIO_DRIVER_PIN_12|GPIO_DRIVER_PIN_13|GPIO_DRIVER_PIN_14|GPIO_DRIVER_PIN_15;
	TestLedGPIO.PuPd	|=	GPIO_DRIVER_PUPD_NOPULL;
	TestLedGPIO.Speed	|=	GPIO_DRIVER_VERY_HIGH_SPEED_100MHZ;
	TestLedGPIO.Type	|=	GPIO_DRIVER_OUTPUT_PP;

	GPIO_Driver_Init(GPIOD,&TestLedGPIO);


	TCNT_Driver_Init(TIM2);
	TCNT_Driver_SetPrescale(TIM2,(48-1));/* APB1_Clock = SystemCoreClock/4 => 48Mhz, prescaled will be 1Mhz */
	TCNT_Driver_SetPeriod(TIM2,(500000-1));/* the period will be  1Mhz/ARR=> 500ms */
	TCNT_Driver_Start(TIM2);

	while (1)
	{
		if((TCNT_Driver_GetStatus(TIM2,TCNT_DRIVER_UPDATE_INTERRUPT_FLAG))==SUCCES)
		{
			state = !state;
			TCNT_Driver_ClearStatus(TIM2);
		}
		if(state)
		{
			GPIO_Driver_SetPin(GPIOD,GPIO_DRIVER_PIN_13);
			GPIO_Driver_ClearPin(GPIOD,GPIO_DRIVER_PIN_12);
		}
		else
		{
			GPIO_Driver_SetPin(GPIOD,GPIO_DRIVER_PIN_12);
			GPIO_Driver_ClearPin(GPIOD,GPIO_DRIVER_PIN_13);
		}
	}
}
