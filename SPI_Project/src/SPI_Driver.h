/*
 * SPI_Driver.h
 *
 *  Created on: Feb 1, 2018
 *      Author: zsolt.balo
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include "stm32f4xx.h"
#include "StdTypes.h"
#include "GPIO_Driver.h"

#define SPI_DRIVER_SLAVE_SELECT_PORT								GPIOE
#define SPI_DRIVER_SLAVE_SELECT_PIN									GPIO_DRIVER_PIN_3
#define SPI_DRIVER_COMMUNICATION_PORT								GPIOA
#define SPI_DRIVER_MISO_PIN											GPIO_DRIVER_PIN_6
#define SPI_DRIVER_MOSI_PIN											GPIO_DRIVER_PIN_7
#define SPI_DRIVER_SCK_PIN											GPIO_DRIVER_PIN_5
#define SPI_DRIVER_2_LINE_UNIDIRECTIONAL_DATA_FLOW					(((uint8)0x00)<<0x0F)
#define SPI_DRIVER_1_LINE_BIDIRECTIONAL_DATA_FLOW                   (((uint8)0x01)<<0x0F)
#define SPI_DRIVER_RECEIVE_ONLY_MODE                                (((uint8)0x00)<<0x0E)
#define SPI_DRIVER_TRANSMIT_ONLY_MODE                               (((uint8)0x01)<<0x0E)
#define SPI_DRIVER_8_BIT_DATA_FORMAT                                (((uint8)0x00)<<0x0B)
#define SPI_DRIVER_16_BIT_DATA_FORMAT                               (((uint8)0x01)<<0x0B)
/*Receive and Transmit*/
#define SPI_DRIVER_FULL_DUPLEX                                      (((uint8)0x00)<<0x0A)
/*Receive only mode*/
#define SPI_DRIVER_OUTPUT_DISABLED                                  (((uint8)0x01)<<0x0A)
#define SPI_DRIVER_MSB_FIRST                                        (((uint8)0x00)<<0x07)
#define SPI_DRIVER_LSB_FIRST                                        (((uint8)0x01)<<0x07)
#define SPI_DRIVER_BAUD_RATE_DIV2                                   (((uint8)0x00)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV4                                   (((uint8)0x01)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV8                                   (((uint8)0x02)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV16                                  (((uint8)0x03)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV32                                  (((uint8)0x04)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV64                                  (((uint8)0x05)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV128                                 (((uint8)0x06)<<0x03)
#define SPI_DRIVER_BAUD_RATE_DIV256                                 (((uint8)0x07)<<0x03)
#define SPI_DRIVER_MASTER_CONFIGURATION                             (((uint8)0x01)<<0x02)
#define SPI_DRIVER_SALVE_CONFIGURATION                              (((uint8)0x00)<<0x02)
#define SPI_DRIVER_CPOL_IDLE_0                                      (((uint8)0x00)<<0x01)
#define SPI_DRIVER_CPOL_IDLE_1                                      (((uint8)0x01)<<0x01)
#define SPI_DRIVER_PERIPHERAL_ENABLE                                (((uint8)0x01)<<0x06)
#define SPI_DRIVER_PERIPHERAL_DISABLE                               (((uint8)0x00)<<0x06)
#define SPI_DRIVER_CPHA_FIRST_CLOCK_TRANSITION                      ((uint8)0x00)
#define SPI_DRIVER_CPHA_SECOND_CLOCK_TRANSITION                     ((uint8)0x01)
#define SPI_DRIVER_TI_FRAME_MODE                                    (((uint8)0x01)<<0x04)
#define SPI_DRIVER_MOTOROLA_FRAME_MODE                              (((uint8)0x00)<<0x04)
#define SPI_DRIVER_FRAME_FORMAT_ERROR								 ((uint16)0x0100)
#define SPI_DRIVER_CRC_POLYNOME										 ((uint16)0x0888)
#define SPI_DRIVER_BUSY_FLAG                                         ((uint16)0x0080)
#define SPI_DRIVER_OVERRUN_FLAG                                      ((uint16)0x0040)
#define SPI_DRIVER_MODE_FAULT                                        ((uint16)0x0020)
#define SPI_DRIVER_CRC_ERROR_FLAG                                    ((uint16)0x0010)
#define SPI_DRIVER_UNDERRUN_FLAG                                     ((uint16)0x0008)
#define SPI_DRIVER_CHANNEL_SIDE                                      ((uint16)0x0004)
#define SPI_DRIVER_TRANSMIT_BUFFER_EMPTY                             ((uint16)0x0002)
#define SPI_DRIVER_RECEIVE_BUFFER_NOT_EMPTY                          ((uint16)0x0001)

void SPI_Driver_Init(SPI_TypeDef* SPIx);
uint8 SPI_Driver_Get_Status(SPI_TypeDef* SPIx,uint16 StatusCode);
uint32 SPI_Driver_Transcieve_Data(SPI_TypeDef* SPIx,uint16 data);
void SPI_Driver_Set_Slave_Select_Low(GPIO_TypeDef* GPIOx,uint16 slavePin);
void SPI_Driver_Set_Slave_Select_High(GPIO_TypeDef* GPIOx,uint16 slavePin);
void SPI_Driver_Start(SPI_TypeDef* SPIx);
void SPI_Driver_Stop(SPI_TypeDef* SPIx);
void SPI_Driver_Flush(SPI_TypeDef* SPIx);

#endif /* SPI_DRIVER_H_ */
