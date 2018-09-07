/*
 * ADC_Driver.h
 *
 *  Created on: Jan 22, 2018
 *      Author: zsolt.balo
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "stm32f4xx.h"
#include "StdTypes.h"

/*ADC Configuration*/
#define ADC_DRIVER_CHANNEL_0								         		0x00
#define ADC_DRIVER_CHANNEL_1								         		0x01
#define ADC_DRIVER_CHANNEL_2								         		0x02
#define ADC_DRIVER_CHANNEL_3								         		0x03
#define ADC_DRIVER_CHANNEL_4								         		0x04
#define ADC_DRIVER_CHANNEL_5								         		0x05
#define ADC_DRIVER_CHANNEL_6								         		0x06
#define ADC_DRIVER_CHANNEL_7								         		0x07
#define ADC_DRIVER_CHANNEL_8								         		0x08
#define ADC_DRIVER_CHANNEL_9								         		0x09
#define ADC_DRIVER_CHANNEL_10								         		0x0A
#define ADC_DRIVER_CHANNEL_11								         		0x0B
#define ADC_DRIVER_CHANNEL_12								         		0x0C
#define ADC_DRIVER_CHANNEL_13								         		0x0D
#define ADC_DRIVER_CHANNEL_14								         		0x0E
#define ADC_DRIVER_CHANNEL_15								         		0x0F
#define ADC_DRIVER_CHANNEL_16								         		0x10
#define ADC_DRIVER_CHANNEL_17								         		0x11
#define ADC_DRIVER_CHANNEL_18								         		0x12
#define ADC_DRIVER_SELECT_CHANNEL_0								            0x01
#define ADC_DRIVER_SELECT_CHANNEL_1								            0x02
#define ADC_DRIVER_SELECT_CHANNEL_2								            0x04
#define ADC_DRIVER_SELECT_CHANNEL_3								            0x08
#define ADC_DRIVER_SELECT_CHANNEL_4								            0x10
#define ADC_DRIVER_SELECT_CHANNEL_5								            0x20
#define ADC_DRIVER_SELECT_CHANNEL_6								            0x40
#define ADC_DRIVER_SELECT_CHANNEL_7								            0x80
#define ADC_DRIVER_SELECT_CHANNEL_8								           0x100
#define ADC_DRIVER_SELECT_CHANNEL_9								           0x200
#define ADC_DRIVER_SELECT_CHANNEL_10								       0x400
#define ADC_DRIVER_SELECT_CHANNEL_11								       0x800
#define ADC_DRIVER_SELECT_CHANNEL_12								      0x1000
#define ADC_DRIVER_SELECT_CHANNEL_13								      0x2000
#define ADC_DRIVER_SELECT_CHANNEL_14								      0x4000
#define ADC_DRIVER_SELECT_CHANNEL_15								      0x8000
#define ADC_DRIVER_SELECT_CHANNEL_16								      0x10000
#define ADC_DRIVER_SELECT_CHANNEL_17								      0x20000
#define ADC_DRIVER_SELECT_CHANNEL_18								      0x40000
#define ADC_DRIVER_ON										(((uint8)0x01))
#define ADC_DRIVER_OFF										(((uint8)0x00))
#define ADC_DRIVER_REGULAR_START							(((uint8)0x01)<<30)
#define ADC_DRIVER_ALIGNMENT_LEFT							(((uint8)0x01)<<11)
#define ADC_DRIVER_ALIGNMENT_RIGHT							(((uint8)0x00)<<11)
#define ADC_DRIVER_OVERRUN_FLAG 							((uint8)0x20)
#define ADC_DRIVER_REGULAR_CHANNEL_START_FLAG 				((uint8)0x10)
#define ADC_DRIVER_INJECTED_CHANNEL_START_FLAG 				((uint8)0x08)
#define ADC_DRIVER_INJECTED_CHANNEL_END_OF_CONVERSION_FLAG 	((uint8)0x04)
#define ADC_DRIVER_REGULAR_CHANNEL_END_OF_CONVERSION_FLAG 	((uint8)0x02)
#define ADC_DRIVER_ANALOG_WATCHDOG_FLAG 					((uint8)0x01)
#define ADC_DRIVER_RESOLUTION_12_Bits 						(((uint8)0x00)<<24)
#define ADC_DRIVER_RESOLUTION_10_Bits 						(((uint8)0x01)<<24)
#define ADC_DRIVER_RESOLUTION_8_Bits 						(((uint8)0x02)<<24)
#define ADC_DRIVER_RESOLUTION_6_Bits 						(((uint8)0x03)<<24)
#define ADC_DRIVER_PRESCALE_BY_2 							(((uint8)0x00)<<16);
#define ADC_DRIVER_PRESCALE_BY_4 							(((uint8)0x01)<<16);
#define ADC_DRIVER_PRESCALE_BY_6 							(((uint8)0x02)<<16);
#define ADC_DRIVER_PRESCALE_BY_8 							(((uint8)0x03)<<16);
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_3_CYCLES 			((uint8)0x00)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_15_CYCLES 			((uint8)0x01)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_28_CYCLES 			((uint8)0x02)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_56_CYCLES 			((uint8)0x03)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_84_CYCLES 			((uint8)0x04)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_112_CYCLES 		((uint8)0x05)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_144_CYCLES 		((uint8)0x06)
#define ADC_DRIVER_CHANNEL_SAMPLING_TIME_480_CYCLES 		((uint8)0x07)
#define ADC_DRIVER_SEQUENCE_1_CONVERSIONS							0x01
#define ADC_DRIVER_SEQUENCE_2_CONVERSIONS							0x02
#define ADC_DRIVER_SEQUENCE_3_CONVERSIONS							0x03
#define ADC_DRIVER_SEQUENCE_4_CONVERSIONS							0x04
#define ADC_DRIVER_SEQUENCE_5_CONVERSIONS							0x05
#define ADC_DRIVER_SEQUENCE_6_CONVERSIONS							0x06
#define ADC_DRIVER_SEQUENCE_7_CONVERSIONS							0x07
#define ADC_DRIVER_SEQUENCE_8_CONVERSIONS							0x08
#define ADC_DRIVER_SEQUENCE_9_CONVERSIONS							0x09
#define ADC_DRIVER_SEQUENCE_10_CONVERSIONS							0x0A
#define ADC_DRIVER_SEQUENCE_11_CONVERSIONS							0x0B
#define ADC_DRIVER_SEQUENCE_12_CONVERSIONS							0x0C
#define ADC_DRIVER_SEQUENCE_13_CONVERSIONS							0x0D
#define ADC_DRIVER_SEQUENCE_14_CONVERSIONS							0x0E
#define ADC_DRIVER_SEQUENCE_15_CONVERSIONS							0x0F
#define ADC_DRIVER_SEQUENCE_16_CONVERSIONS							0x10
#define ADC_DRIVER_SEQUENCE_POSITION_1								0x00
#define ADC_DRIVER_SEQUENCE_POSITION_2								0x01
#define ADC_DRIVER_SEQUENCE_POSITION_3								0x02
#define ADC_DRIVER_SEQUENCE_POSITION_4								0x03
#define ADC_DRIVER_SEQUENCE_POSITION_5								0x04
#define ADC_DRIVER_SEQUENCE_POSITION_6								0x05
#define ADC_DRIVER_SEQUENCE_POSITION_7								0x06
#define ADC_DRIVER_SEQUENCE_POSITION_8								0x07
#define ADC_DRIVER_SEQUENCE_POSITION_9								0x08
#define ADC_DRIVER_SEQUENCE_POSITION_10								0x09
#define ADC_DRIVER_SEQUENCE_POSITION_11								0x0A
#define ADC_DRIVER_SEQUENCE_POSITION_12								0x0B
#define ADC_DRIVER_SEQUENCE_POSITION_13								0x0C
#define ADC_DRIVER_SEQUENCE_POSITION_14								0x0D
#define ADC_DRIVER_SEQUENCE_POSITION_15								0x0E
#define ADC_DRIVER_SEQUENCE_POSITION_16								0x0F
#define SET_ADC_PCLK_PRESCALE_VALUE									0x00

void ADC_Driver_Configure_Sequence(ADC_TypeDef* ADCx,uint8 ChannelNr,uint8 Position_in_Sequnece);
uint16 ADC_Driver_GetSample(ADC_TypeDef* ADCx);
uint8 ADC_Driver_GetStatus(ADC_TypeDef* ADCx,uint8 Event);
void ADC_Driver_Init(ADC_TypeDef* ADCx);
void ADC_Driver_Off(ADC_TypeDef* ADCx);
void ADC_Driver_On(ADC_TypeDef* ADCx);
void ADC_Driver_SamplingTimeSelect(ADC_TypeDef* ADCx,uint8* SamplingTimes);
void ADC_Driver_Set_ADC_PCLK_Prescale_Value(ADC_TypeDef* ADCx);
void ADC_Driver_StartSampling(ADC_TypeDef* ADCx);

#endif /* ADC_DRIVER_H_ */
