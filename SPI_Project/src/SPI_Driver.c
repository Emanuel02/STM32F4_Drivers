/*
 * SPI_Driver.c
 *
 *  Created on: Feb 1, 2018
 *      Author: zsolt.balo
 */

#include "SPI_Driver.h"
#include "SPI_Driver_Cfg.h"

void SPI_Driver_Init(SPI_TypeDef* SPIx)
{
	#if(SPI_DRIVER_SPI1 == OK)
		RCC->APB2ENR|=RCC_APB2ENR_SPI1EN;
	#endif

	#if(SPI_DRIVER_SPI2 == OK)
		RCC->APB1ENR|=RCC_APB1ENR_SPI2EN;
	#endif

	#if(SPI_DRIVER_SPI3 == OK)
		RCC->APB1ENR|=RCC_APB1ENR_SPI3EN;
	#endif

	SPIx->CR1|=(SPI_DRIVER_BIDIRECTIONAL_DATA_MODE_ENABLE)
			 |(SPI_DRIVER_OUTPUT_ENABLE_IN_BIDIRECTIONAL_MODE)

	#if (SPI_DRIVER_CRC_CALCULATION_ENABLE == OK)
			 |(SPI_DRIVER_CRC_CALCULATION_ENABLE)
	#endif
			 |(SPI_DRIVER_DATA_FRAME_FORMAT)
			 |(SPI_DRIVER_RECEIVE_ONLY_OR_FULL_DUPLEX)
	#if (SPI_DRIVER_SOFTWARE_SLAVE_MANAGEMENT == OK)
			 |(0x01<<9)
	#endif
	#if (SPI_DRIVER_INETRNAL_SLAVE_SELECT == OK)
			 |(0X01<<8)
	#endif
			 |(SPI_DRIVER_FRAME_FORMAT)
			 |(SPI_DRIVER_BAUD_RATE_CONTROL)
			 |(SPI_DRIVER_MASTER_SLAVE_SELECTION)
			 |(SPI_DRIVER_CLOCK_POLARITY)
			 |(SPI_DRIVER_CLOCK_PHASE);


	#if (SPI_DRIVER_SS_OUTPUT_ENABLE == OK)
		SPIx->CR2|=((0x01)<<0x02);
	#endif

}

void SPI_Driver_Start(SPI_TypeDef* SPIx)
{
	SPIx->CR1|=(SPI_DRIVER_PERIPHERAL_ENABLE);
}

void SPI_Driver_Stop(SPI_TypeDef* SPIx)
{
	SPIx->CR1 &=(SPI_DRIVER_PERIPHERAL_DISABLE);
}

uint8 SPI_Driver_Get_Status(SPI_TypeDef* SPIx,uint16 StatusCode)
{
	if((SPIx->SR & StatusCode)!=FALSE)
	{
		return SUCCES;
	}
	else
	{
		return FAILED;
	}
}

uint32 SPI_Driver_Transcieve_Data(SPI_TypeDef* SPIx,uint16 data)
{
	uint32 Payload = 0x00;

	SPI_Driver_Set_Slave_Select_Low(SPI_DRIVER_SLAVE_SELECT_PORT,SPI_DRIVER_SLAVE_SELECT_PIN);

	while(SPI_Driver_Get_Status(SPIx,SPI_DRIVER_TRANSMIT_BUFFER_EMPTY)!=SUCCES);
	SPI1->DR = data;
	while(SPI_Driver_Get_Status(SPIx,SPI_DRIVER_RECEIVE_BUFFER_NOT_EMPTY)!=SUCCES);
	Payload = SPI1->DR;

	SPI_Driver_Set_Slave_Select_High(SPI_DRIVER_SLAVE_SELECT_PORT,SPI_DRIVER_SLAVE_SELECT_PIN);

	return Payload;
}

void SPI_Driver_Set_Slave_Select_Low(GPIO_TypeDef* GPIOx,uint16 slavePin)
{
	GPIO_Driver_ClearPin(GPIOx,slavePin);
}


void SPI_Driver_Set_Slave_Select_High(GPIO_TypeDef* GPIOx,uint16 slavePin)
{
	GPIO_Driver_SetPin(GPIOx,slavePin);
}

