/*
 * GPIO_Driver.h
 *
 *  Created on: Jan 10, 2018
 *      Author: zsolt.balo
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f4xx.h"
#include "StdTypes.h"

#define GPIO_DRIVER_INPUT_MODE 								((uint32)0x0000)
#define GPIO_DRIVER_OUTPUT_MODE  							((uint32)0x0001)
#define GPIO_DRIVER_ALTERNATE_FUNCTION_MODE 				((uint32)0x0002)
#define GPIO_DRIVER_ANALOG_MODE  							((uint32)0x0003)
#define GPIO_DRIVER_OUTPUT_PP 								((uint32)0x0000)
#define GPIO_DRIVER_OUTPUT_OD 								((uint32)0x0001)
#define GPIO_DRIVER_LOW_SPEED_2MHZ 							((uint32)0x0000)
#define GPIO_DRIVER_MEDIUM_SPEED_25MHZ 						((uint32)0x0001)
#define GPIO_DRIVER_HIGH_SPEED_50MHZ 						((uint32)0x0002)
#define GPIO_DRIVER_VERY_HIGH_SPEED_100MHZ					((uint32)0x0003)
#define GPIO_DRIVER_PUPD_NOPULL 							((uint32)0x0000)
#define GPIO_DRIVER_PUPD_UP 								((uint32)0x0001)
#define GPIO_DRIVER_PUPD_DOWN 								((uint32)0x0002)
#define GPIO_DRIVER_PIN_NR_0                 				((uint16)0x00)
#define GPIO_DRIVER_PIN_AFNR_1                 				((uint16)0x01)
#define GPIO_DRIVER_PIN_AFNR_2                 				((uint16)0x02)
#define GPIO_DRIVER_PIN_AFNR_3                 				((uint16)0x03)
#define GPIO_DRIVER_PIN_AFNR_4                 				((uint16)0x04)
#define GPIO_DRIVER_PIN_AFNR_5                 				((uint16)0x05)
#define GPIO_DRIVER_PIN_AFNR_6                 				((uint16)0x06)
#define GPIO_DRIVER_PIN_AFNR_7                 				((uint16)0x07)
#define GPIO_DRIVER_PIN_AFNR_8                 				((uint16)0x08)
#define GPIO_DRIVER_PIN_AFNR_9                 				((uint16)0x09)
#define GPIO_DRIVER_PIN_AFNR_10                				((uint16)0x0A)
#define GPIO_DRIVER_PIN_AFNR_11                				((uint16)0x0B)
#define GPIO_DRIVER_PIN_AFNR_12                				((uint16)0x0C)
#define GPIO_DRIVER_PIN_AFNR_13                				((uint16)0x0D)
#define GPIO_DRIVER_PIN_AFNR_14                				((uint16)0x0E)
#define GPIO_DRIVER_PIN_AFNR_15                				((uint16)0x0F)
#define GPIO_DRIVER_PIN_0                 					((uint16)0x0001)
#define GPIO_DRIVER_PIN_1                 					((uint16)0x0002)
#define GPIO_DRIVER_PIN_2                 					((uint16)0x0004)
#define GPIO_DRIVER_PIN_3                 					((uint16)0x0008)
#define GPIO_DRIVER_PIN_4                 					((uint16)0x0010)
#define GPIO_DRIVER_PIN_5                 					((uint16)0x0020)
#define GPIO_DRIVER_PIN_6                 					((uint16)0x0040)
#define GPIO_DRIVER_PIN_7                 					((uint16)0x0080)
#define GPIO_DRIVER_PIN_8                 					((uint16)0x0100)
#define GPIO_DRIVER_PIN_9                 					((uint16)0x0200)
#define GPIO_DRIVER_PIN_10                					((uint16)0x0400)
#define GPIO_DRIVER_PIN_11                					((uint16)0x0800)
#define GPIO_DRIVER_PIN_12                					((uint16)0x1000)
#define GPIO_DRIVER_PIN_13                					((uint16)0x2000)
#define GPIO_DRIVER_PIN_14                					((uint16)0x4000)
#define GPIO_DRIVER_PIN_15                					((uint16)0x8000)
#define GPIO_DRIVER_PIN_ALL               					((uint16)0xFFFF)
#define GPIO_DRIVER_AF0_SYSTEM								((uint8)0x00)
#define GPIO_DRIVER_AF1_TIM_1								((uint8)0x01)
#define GPIO_DRIVER_AF1_TIM_2                               ((uint8)0x01)
#define GPIO_DRIVER_AF2_TIM_3                               ((uint8)0x02)
#define GPIO_DRIVER_AF2_TIM_4                               ((uint8)0x02)
#define GPIO_DRIVER_AF2_TIM_5                               ((uint8)0x02)
#define GPIO_DRIVER_AF3_TIM_8                               ((uint8)0x03)
#define GPIO_DRIVER_AF3_TIM_9                               ((uint8)0x03)
#define GPIO_DRIVER_AF3_TIM_10                              ((uint8)0x03)
#define GPIO_DRIVER_AF3_TIM_11                              ((uint8)0x03)
#define GPIO_DRIVER_AF4_I2C_1                               ((uint8)0x04)
#define GPIO_DRIVER_AF4_I2C_2                               ((uint8)0x04)
#define GPIO_DRIVER_AF4_I2C_3                               ((uint8)0x04)
#define GPIO_DRIVER_AF5_SPI_1                               ((uint8)0x05)
#define GPIO_DRIVER_AF5_SPI_2                               ((uint8)0x05)
#define GPIO_DRIVER_AF6_SPI_3                               ((uint8)0x06)
#define GPIO_DRIVER_AF7_USART_1                             ((uint8)0x07)
#define GPIO_DRIVER_AF7_USART_2                             ((uint8)0x07)
#define GPIO_DRIVER_AF7_USART_3                             ((uint8)0x07)
#define GPIO_DRIVER_AF8_USART_4                             ((uint8)0x08)
#define GPIO_DRIVER_AF8_USART_5                             ((uint8)0x08)
#define GPIO_DRIVER_AF8_USART_6                             ((uint8)0x08)
#define GPIO_DRIVER_AF9_CAN_1                               ((uint8)0x09)
#define GPIO_DRIVER_AF9_CAN_2                               ((uint8)0x09)
#define GPIO_DRIVER_AF9_TIM_12                              ((uint8)0x09)
#define GPIO_DRIVER_AF9_TIM_13                              ((uint8)0x09)
#define GPIO_DRIVER_AF9_TIM_14                              ((uint8)0x09)
#define GPIO_DRIVER_AF10_OTG_FS                             ((uint8)0x0A)
#define GPIO_DRIVER_AF10_OTG_HS                             ((uint8)0x0A)
#define GPIO_DRIVER_AF11_ETH                                ((uint8)0x0B)
#define GPIO_DRIVER_AF12_FSMC                               ((uint8)0x0C)
#define GPIO_DRIVER_AF12_SDIO                               ((uint8)0x0C)
#define GPIO_DRIVER_AF12_OTG_HS                             ((uint8)0x0C)
#define GPIO_DRIVER_AF13_DCMI                               ((uint8)0x0D)
#define GPIO_DRIVER_AF14                                    ((uint8)0x0E)
#define GPIO_DRIVER_AF15_EVENTOUT                           ((uint8)0x0F)

void GPIO_Driver_Init(GPIO_TypeDef* GPIOx,GPIOD_Driver_Setup_type* Config);
void GPIO_Driver_SetPin(GPIO_TypeDef* GPIOx,uint16 Pin);
void GPIO_Driver_ClearPin(GPIO_TypeDef* GPIOx,uint16 Pin);
uint16 GPIO_Driver_ReadInputData(GPIO_TypeDef* GPIOx);
uint16 GPIO_Driver_ReadOutputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_Driver_ReadInputDataBit(GPIO_TypeDef* GPIOx,uint16 Bit_number);
void GPIO_Driver_SetAlternateFunction(GPIO_TypeDef* GPIOx,uint16_t Pin_number,uint8 Alternate_Function);

#endif /* GPIO_DRIVER_H_ */

