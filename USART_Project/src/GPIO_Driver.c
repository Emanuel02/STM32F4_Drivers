/*
 * GPIO_Driver.c
 *
 *  Created on: Jan 10, 2018
 *      Author: zsolt.balo
 */

#include "GPIO_Driver.h"
#include "GPIO_Driver_Cfg.h"

/*Initialize the selected GPIO modules, with the given configuration structure*/
void GPIO_Driver_Init(GPIO_TypeDef* GPIOx,GPIOD_Driver_Setup_type* Config)
{

	#if GPIO_DRIVER_GPIOA!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	#endif
	#if GPIO_DRIVER_GPIOB!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;
	#endif
	#if GPIO_DRIVER_GPIOC!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;
	#endif
	#if GPIO_DRIVER_GPIOD!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;
	#endif
	#if GPIO_DRIVER_GPIOE!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOEEN;
	#endif
	#if GPIO_DRIVER_GPIOF!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOFEN;
	#endif
	#if GPIO_DRIVER_GPIOG!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOGEN;
	#endif
	#if GPIO_DRIVER_GPIOH!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOHEN;
	#endif
	#if GPIO_DRIVER_GPIOI!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOIEN;
	#endif
	#if GPIO_DRIVER_GPIOJ!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOJEN;
	#endif
	#if GPIO_DRIVER_GPIOK!=NOK
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOKEN;
	#endif

	/*Variables used for various operations*/
	uint16 index = 0x00;
	uint16 position=0x00;
	uint16 setup_value=0x00;

	/*Check all pins and configure only the ones, which are given in the configuration structure*/
	for(index=0x00;index<16;index++)
	{
		position = ((uint32)0x01)<<index;
		setup_value = (Config->Pins)&position;
		/*Set the GPIO configuration, after the given structure*/
		if(setup_value!=0x00)
		{
			GPIOx->MODER  |=((uint32)((Config->Mode) <<(2*index)));
			GPIOx->OSPEEDR|=((uint32)((Config->Speed)<<(2*index)));
			GPIOx->PUPDR  |=((uint32)((Config->PuPd) <<(2*index)));
			GPIOx->OTYPER |=((uint32)((Config->Type) <<  (index)));
		}
	}
}

/*Set the selected pin to 1*/
void GPIO_Driver_SetPin(GPIO_TypeDef* GPIOx,uint16 Pin)
{
	GPIOx->BSRR|= Pin;
}

/*Clear the selected pin*/
void GPIO_Driver_ClearPin(GPIO_TypeDef* GPIOx,uint16 Pin)
{
	GPIOx->BSRR|= (Pin<<16);
}

/*Read the value of the input data (the value of all the bits)*/
uint16 GPIO_Driver_ReadInputData(GPIO_TypeDef* GPIOx)
{
	uint16 result = 0x00;
	result = ((uint16)(GPIOx->IDR));
	return result;
}

/*Read the value of the input data (the value of only one bit)*/
uint8 GPIO_Driver_ReadInputDataBit(GPIO_TypeDef* GPIOx,uint16 Bit_number)
{
	uint16 input = 0x00;
	uint8 result = 0x00;

	input  = ((uint16)(GPIOx->IDR));
	result = ((input&Bit_number)!=0x00) ? 1 : 0;
	return result;
}

/*Read the value of the output data register(the value of all the bits)*/
uint16 GPIO_Driver_ReadOutputData(GPIO_TypeDef* GPIOx)
{
	uint16 result = 0x00;
	result = ((uint16)(GPIOx->ODR));
	return result;
}

void GPIO_Driver_SetAlternateFunction(GPIO_TypeDef* GPIOx,uint16_t AF_Pin_number,uint8 Alternate_Function)
{
	if(AF_Pin_number<0x08)
	{
		GPIOx->AFR[0]|= (Alternate_Function<<(4*AF_Pin_number));
	}
	else
	{
		GPIOx->AFR[1]|= (Alternate_Function<<(4*(AF_Pin_number-8)));
	}
}
