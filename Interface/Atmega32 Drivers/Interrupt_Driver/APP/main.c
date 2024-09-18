/*
 * main.c
 *
 *  Created on: Feb 6, 2024
 *      Author: mahmo
 */

#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorStates.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/EXTI/EXTI_Config.h"
#include "../MCAL/EXTI/EXTI_Int.h"
//#include "../MCAL/EXTI/EXTI_Priv.h"

extern EXTI_t Arr_Str[3];

#define SREG *((u8*)0x5F)

void tog(void*);

int main (void)
{
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN2, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PULL_UP);

	u8 pin = DIO_u8PIN2;

	EXTI_CallBack(tog, 0, &pin);
	enu_Int(Arr_Str);
	enu_GIE (1);

	while (1);
}

void tog(void *pPin)
{
	DIO_enuTogPinValue(DIO_u8PORTA, *((u8*)pPin));
}
