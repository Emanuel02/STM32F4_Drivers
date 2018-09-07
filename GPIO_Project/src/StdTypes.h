/*
 * Typedef.h
 *
 *  Created on: Jan 23, 2018
 *      Author: zsolt.balo
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

/*Generic*/
#define TRUE 				0x01
#define FALSE 				0x00
#define DEFAULT				0x00
#define OK 					0x01
#define NOK 				0x00
#define ON 					0x01
#define OFF 				0x00
#define SUCCES		((uint8)0x00)
#define FAILED		((uint8)0x01)
#define uint8			uint8_t
#define uint16			uint16_t
#define uint32			uint32_t



/*GPIO*/

typedef struct
{
	uint32_t Speed;
	uint32_t Mode;
	uint32_t Type;
	uint32_t PuPd;
	uint32_t Pins;
}GPIOD_Driver_Setup_type;

#endif /* STDTYPES_H_ */
