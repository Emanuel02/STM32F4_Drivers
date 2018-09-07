/* Includes */
#include "GPIO_Driver.h"
#include "SPI_Driver.h"

#define DELAY_TIME 200

uint32 TestVAr=0x00;

#define _a                                       		 		0x01
#define _b                                        				0x02
#define _c                                        				0x04
#define _d                                        				0x08
#define _e                                        				0x10
#define _f                                        				0x20
#define _g                                        				0x40
#define _dp                                        				0x80

#define _H_						 	  				  _b|_c|_e|_f|_g
#define _E_ 						 	 			  _a|_d|_e|_f|_g
#define _L_ 							  	    			_d|_e|_f
#define _O_                       	   			   _a|_b|_c|_d|_e|_f

volatile uint32 TickCounter=0x00;

GPIOD_Driver_Setup_type SPI_Pins={0x00};
GPIOD_Driver_Setup_type SS_Pin={0x00};

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
	SPI_Pins.Mode = GPIO_DRIVER_ALTERNATE_FUNCTION_MODE;
	SPI_Pins.Pins = SPI_DRIVER_MISO_PIN|SPI_DRIVER_MOSI_PIN|SPI_DRIVER_SCK_PIN;
	SPI_Pins.PuPd = GPIO_DRIVER_PUPD_NOPULL;
	SPI_Pins.Speed = GPIO_DRIVER_HIGH_SPEED_50MHZ;
	SPI_Pins.Type = GPIO_DRIVER_OUTPUT_PP;

	GPIO_Driver_Init(SPI_DRIVER_COMMUNICATION_PORT,&SPI_Pins);
	GPIO_Driver_SetAlternateFunction(SPI_DRIVER_COMMUNICATION_PORT,5,GPIO_DRIVER_AF5_SPI_1);
	GPIO_Driver_SetAlternateFunction(SPI_DRIVER_COMMUNICATION_PORT,6,GPIO_DRIVER_AF5_SPI_1);
	GPIO_Driver_SetAlternateFunction(SPI_DRIVER_COMMUNICATION_PORT,7,GPIO_DRIVER_AF5_SPI_1);

	SysTick_Config(SystemCoreClock/1000);

	SS_Pin.Mode = GPIO_DRIVER_OUTPUT_MODE;
	SS_Pin.Pins = SPI_DRIVER_SLAVE_SELECT_PIN;
	SS_Pin.PuPd = GPIO_DRIVER_PUPD_UP;
	SS_Pin.Speed = GPIO_DRIVER_HIGH_SPEED_50MHZ;
	SS_Pin.Type = GPIO_DRIVER_OUTPUT_PP;

	GPIO_Driver_Init(SPI_DRIVER_SLAVE_SELECT_PORT,&SS_Pin);

	SPI_Driver_Init(SPI1);
	SPI_Driver_Start(SPI1);
	while (1)
	{
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)_H_);
		Delay(200);
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);

		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)_E_);
		Delay(200);
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);

		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)_L_);
		Delay(200);
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);

		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)_L_);
		Delay(200);
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);

		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)_O_);
		Delay(200);
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);

		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);
		TestVAr = SPI_Driver_Transcieve_Data(SPI1,(uint16_t)0x00);
		Delay(200);

	}
}
