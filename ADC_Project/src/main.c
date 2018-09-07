/* Includes */
#include "GPIO_Driver.h"
#include "ADC_Driver.h"

/*Input data from ADC1 channel x*/

uint32 ADC_Sample = 0x00;
uint32 ADC_Voltage = 0x00;
uint32 ADC_Voltage_TE = 0x00;
uint32 ADC_Voltage_H = 0x00;
uint32 ADC_Voltage_TH = 0x00;

GPIOD_Driver_Setup_type ADC_Channel;

int main(void)
{
	ADC_Channel.Mode = GPIO_DRIVER_ANALOG_MODE;
	ADC_Channel.Pins = GPIO_DRIVER_PIN_1;
	ADC_Channel.PuPd = GPIO_DRIVER_PUPD_NOPULL;
	ADC_Channel.Speed = GPIO_DRIVER_LOW_SPEED_2MHZ;
	ADC_Channel.Type = GPIO_DRIVER_OUTPUT_PP;

	GPIO_Driver_Init(GPIOA,&ADC_Channel);
	ADC_Driver_Init(ADC1);

  while (1)
  {
	  ADC_Driver_StartSampling(ADC1);
	  if(ADC_Driver_GetStatus(ADC1,ADC_DRIVER_REGULAR_CHANNEL_END_OF_CONVERSION_FLAG))
	  {
		  ADC_Sample = ADC_Driver_GetSample(ADC1);
		  /*ADC_Voltage = ((ADC_Sample/4095))*3;
		  ADC_Voltage_TE = ((ADC_Sample*10/4095))*3;
		  ADC_Voltage_H = ((ADC_Sample*100/4095))*3;
		  ADC_Voltage_TH = ((ADC_Sample*1000/4095))*3;*/
	  }
  }
}
