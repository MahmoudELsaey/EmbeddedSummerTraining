/*
 * main.c
 *
 *  Created on: Feb 25, 2024
 *      Author: mahmo
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"


#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/Timer/Timer_Int.h"
#include "../MCAL/Timer/Timer_Priv.h"

#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/EXTI/EXTI_priv.h"

#include "../HAL/LCD/LCD_int.h"

void main (void)
{
	//OCO PIN
	DIO_enuSetPinDirection(DIO_u8PORTB, DIO_u8PIN3, DIO_u8OUTPUT);
	//CTC INTERRUPT
	TIMSK |= (1<<1);
	//GLOBAL INTERRUPT
	SREG |= (1<<7);

	while (1)
		{

		}
}
