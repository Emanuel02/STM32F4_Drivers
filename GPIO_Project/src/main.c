/* Includes */
#include "GPIO_Driver.h"

/*Input data from button*/
uint16_t InputData = 0x00;

int main(void)
{

	/*Configuration structures for button and for the leds*/
	GPIOD_Driver_Setup_type Config,Config_BTN;

	/* Configure port D pins 12,13,14,15 as pus-pull output,
	 * clock speed is 100MHz and without pull-up or down resistors
	 * */

	Config.Mode = GPIO_DRIVER_OUTPUT_MODE;
	Config.Pins = GPIO_DRIVER_PIN_13|GPIO_DRIVER_PIN_12|GPIO_DRIVER_PIN_14|GPIO_DRIVER_PIN_15;
	Config.PuPd = GPIO_DRIVER_PUPD_NOPULL;
	Config.Speed = GPIO_DRIVER_VERY_HIGH_SPEED_100MHZ;
	Config.Type = GPIO_DRIVER_OUTPUT_PP;

	/*Configure port A pin 0 as input*/
	Config_BTN.Mode = GPIO_DRIVER_INPUT_MODE;
	Config_BTN.Pins = GPIO_DRIVER_PIN_0;

	/*These are irrelevant*/
	Config_BTN.PuPd = GPIO_DRIVER_PUPD_NOPULL;
	Config_BTN.Speed = GPIO_DRIVER_VERY_HIGH_SPEED_100MHZ;
	Config_BTN.Type = GPIO_DRIVER_OUTPUT_PP;

	/*Initialize the GPIOs with the desired configuration structure*/
	GPIO_Driver_Init(GPIOA,&Config_BTN);
	GPIO_Driver_Init(GPIOD,&Config);

  while (1)
  {
	  /*get the button status*/
	  InputData = GPIO_Driver_ReadInputDataBit(GPIOA,GPIO_DRIVER_PIN_0);

	  /*If pressed*/
	  if(InputData!=0x00)
	  {
		  /*Set the selected pins to 1*/
		  GPIO_Driver_SetPin(GPIOD,GPIO_DRIVER_PIN_12);
		  GPIO_Driver_SetPin(GPIOD,GPIO_DRIVER_PIN_13);
		  GPIO_Driver_SetPin(GPIOD,GPIO_DRIVER_PIN_14);
		  GPIO_Driver_SetPin(GPIOD,GPIO_DRIVER_PIN_15);
	  }
	  /*If released*/
	  else
	  {
		  /*Clear the selected pins*/
		  GPIO_Driver_ClearPin(GPIOD,GPIO_DRIVER_PIN_12);
		  GPIO_Driver_ClearPin(GPIOD,GPIO_DRIVER_PIN_13);
		  GPIO_Driver_ClearPin(GPIOD,GPIO_DRIVER_PIN_14);
		  GPIO_Driver_ClearPin(GPIOD,GPIO_DRIVER_PIN_15);
	  }
  }
}
