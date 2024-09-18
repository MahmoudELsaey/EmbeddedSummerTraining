/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: mahmo
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "int.h"

void main (void)
{
	u8 Local_u8KeyValue = 0xff;
	DIO_enuInit();
	LCD_enuInit();
	KPD_enuInit();

	while(1)
	{
		//Polling in case no key pressed
		while(Local_u8KeyValue == 0xff)
		{
			Local_u8KeyValue = KPD_u8GetPressedKey();
		}
		//Printing pressed key
		LCD_enuDisplayChar(Local_u8KeyValue);
	}

}
