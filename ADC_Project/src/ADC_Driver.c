/*
 * ADC_Driver.c
 *
 *  Created on: Jan 22, 2018
 *      Author: zsolt.balo
 */

#include "ADC_Driver.h"
#include "ADC_Driver_Cfg.h"

uint8 SamplingTimes[ADC_DRIVER_CHANNEL_NUMBER]=
{
		ADC_DRIVER_CHANNEL_SAMPLING_TIME_144_CYCLES
};

uint16 ADC_Driver_GetSample(ADC_TypeDef* ADCx)
{
	/*Get the result of the ADC conversion*/
	uint16 data=0x00;
	data = ((uint16)(ADCx->DR));
	//data = data>>4;
	return data;
}

uint8 ADC_Driver_GetStatus(ADC_TypeDef* ADCx,uint8 Event)
{
	/*Get the result of the ADC conversion*/
	if((ADCx->SR & Event)!=FALSE)
	{
		/*The selected option is set*/
		return SUCCES ;
	}
	else
	{
		/*The selected option is not set*/
		return FAILED;
	}
}

void ADC_Driver_Init(ADC_TypeDef* ADCx)
{
	/*Set the clock off the selected ADC instance*/
	#if ADC_DRIVER_ADC1 == OK
		RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;
	#endif
	#if ADC_DRIVER_ADC2 == OK
		RCC->APB2ENR|=RCC_APB2ENR_ADC2EN;
	#endif
	#if ADC_DRIVER_ADC3 == OK
		RCC->APB2ENR|=RCC_APB2ENR_ADC3EN;
	#endif

		/*The selected resolution (options 12bit,10bit,8bit,6bit) */
		ADCx->CR1|= ADC_DRIVER_RESOLUTION;

		/*Set the alignment*/
		ADCx->CR2|=ADC_DRIVER_ALIGNMENT;

		/*Set the sampling time of the */
		ADC_Driver_SamplingTimeSelect(ADCx,SamplingTimes);

		/*Set the regular channel sequence length*/
		ADCx->SQR1 |= ((ADC_DRIVER_SEQUENCE_LENGTH-1)<<20);

		/*Select the respective position(s) in the sampling sequence of the desired channel(s)*/
		ADC_Driver_Configure_Sequence(ADCx,ADC_DRIVER_CHANNEL_1,ADC_DRIVER_SEQUENCE_POSITION_1);

		/*Start the ADC*/
		ADCx->CR2|=ADC_DRIVER_ON;
}

void ADC_Driver_Off(ADC_TypeDef* ADCx)
{
	/*Turn off the ADC module*/
	ADCx->CR2|=ADC_DRIVER_OFF;
}

void ADC_Driver_On(ADC_TypeDef* ADCx)
{
	/*Turn on the ADC module*/
	ADCx->CR2|=ADC_DRIVER_ON;
}

void ADC_Driver_SamplingTimeSelect(ADC_TypeDef* ADCx,uint8* SamplingTimes)
{
	uint8 index = 0x00;
	uint8 SamplingTimeIndex = 0x00;

	/*Select the chosen channel's sampling time*/
	/*The sampling is used for the calculation of the conversion time
	 *
	 * Tconv = (12 + Sampling_time)*(1/ADCCLK)
	 * Sampling_Frequency = 1/Tconv
	 *
	 * */
	/*The default is 3 cycles*/

	#if((ADC_DRIVER_SELECTED_CHANNELS) < 0x400)
		for(index=0x00;index<0x12;index++)
		{
			if((ADC_DRIVER_SELECTED_CHANNELS & (1<<index))!=0x00)
			{
				ADCx->SMPR2|=((uint32_t)(SamplingTimes[SamplingTimeIndex]<<(3*index)));
				SamplingTimeIndex++;
			}
		}

	#else
	{
		for(index=0x00;index<0x12;index++)
		{
			if((ADC_DRIVER_SELECTED_CHANNELS & (1<<index))!=0x00)
			{
				if(index<0x0A)
				{
					ADCx->SMPR2|=((uint32_t)(SamplingTimes[SamplingTimeIndex]<<(3*index)));
					SamplingTimeIndex++;
				}
				else
				{
					ADCx->SMPR1|=((uint32_t)(SamplingTimes[SamplingTimeIndex]<<(3*(index-0x0A))));
					SamplingTimeIndex++;
				}
			}
		}

	}
	#endif
}


#if(SET_ADC_PCLK_PRESCALE_VALUE)
void ADC_Driver_Set_ADC_PCLK_Prescale_Value(ADC_TypeDef* ADCx)
{
	/*Select the desired division value*/
	/*By default the peripheral clock is divided by 2*/
	/*===UNDER CONSTRUCTION===*/
}
#endif

void ADC_Driver_Configure_Sequence(ADC_TypeDef* ADCx,uint8 ChannelNr,uint8 Position_in_Sequence)
{
	/*Configure the sampling sequence*/
	#if (ADC_DRIVER_SEQUENCE_LENGTH<=6)

		ADCx->SQR3|=((ChannelNr)<<(5*Position_in_Sequence));

	#elif ((ADC_DRIVER_SEQUENCE_LENGTH>6) && (ADC_DRIVER_SEQUENCE_LENGTH<=12))

		if(Position_in_Sequence<=6)
		{
			ADCx->SQR3|=((ChannelNr)<<(5*Position_in_Sequence));
		}
		else((Position_in_Sequence>6) && (Position_in_Sequence<=12))
		{
			ADCx->SQR2|=((ChannelNr)<<(5*Position_in_Sequence));
		}

	#else
		if(Position_in_Sequence<=6)
		{
			ADCx->SQR3|=((ChannelNr)<<(5*Position_in_Sequence));
		}
		else if((Position_in_Sequence>6) && (Position_in_Sequence<=12))
		{
			ADCx->SQR2|=((ChannelNr)<<(5*Position_in_Sequence));
		}
		else
		{
			ADCx->SQR1|=((ChannelNr)<<(5*Position_in_Sequence));
		}
	#endif
}

void ADC_Driver_StartSampling(ADC_TypeDef* ADCx)
{
	/*Start by Software of the regular conversion*/
	ADCx->CR2|=ADC_DRIVER_REGULAR_START;
}
