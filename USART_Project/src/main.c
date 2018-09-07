/* Includes */
#include "GPIO_Driver.h"
#include "USART_Driver.h"


volatile uint32 TickCounter=0x00;
uint8 state = 0x00;
uint32 index = 0x00;
uint32 transmit_counter= 0x00;

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

	GPIOD_Driver_Setup_type TX_Pin_Setup = {0x00};
	GPIOD_Driver_Setup_type RX_Pin_Setup = {0x00};

	TX_Pin_Setup.Mode  = GPIO_DRIVER_ALTERNATE_FUNCTION_MODE;
	TX_Pin_Setup.Pins  = GPIO_DRIVER_PIN_6;
	TX_Pin_Setup.PuPd  = GPIO_DRIVER_PUPD_NOPULL;
	TX_Pin_Setup.Speed = GPIO_DRIVER_HIGH_SPEED_50MHZ;
	TX_Pin_Setup.Type  = GPIO_DRIVER_OUTPUT_PP;

	GPIO_Driver_Init(GPIOB,&TX_Pin_Setup);
	GPIO_Driver_SetAlternateFunction(GPIOB,GPIO_DRIVER_PIN_AFNR_6,GPIO_DRIVER_AF7_USART_1);

	RX_Pin_Setup.Mode  = GPIO_DRIVER_ALTERNATE_FUNCTION_MODE;
	RX_Pin_Setup.Pins  = GPIO_DRIVER_PIN_7;
	RX_Pin_Setup.PuPd  = GPIO_DRIVER_PUPD_NOPULL;
	RX_Pin_Setup.Speed = GPIO_DRIVER_HIGH_SPEED_50MHZ;
	RX_Pin_Setup.Type  = GPIO_DRIVER_OUTPUT_PP;

	GPIO_Driver_Init(GPIOB,&RX_Pin_Setup);
	GPIO_Driver_SetAlternateFunction(GPIOB,GPIO_DRIVER_PIN_AFNR_7,GPIO_DRIVER_AF7_USART_1);

	USART_Driver_Init(USART1);
	USART_Driver_Set_Baudrate(USART1);

	while (1)
	{
		USART_Driver_Start(USART1);
		USART_Driver_Send_Str(USART1,"Hello world\n\r");
		USART_Driver_Send_Char(USART1,'0'+transmit_counter);
		transmit_counter++;
		if(transmit_counter>0x09)
		{
			transmit_counter = 0x00;
		}
		USART_Driver_Stop(USART1);

		Delay(200);
	}
}
