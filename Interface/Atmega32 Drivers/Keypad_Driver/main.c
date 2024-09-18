/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: mahmo
 */
#include "errorStates.h"
#include "stdTypes.h"

#include "DIO_int.h"
#include "KPD_int.h"
#include "LCD_int.h"

int main (void)
{
	u8 Local_u8Key;
	DIO_enuInit();
	LCD_enuInit();
	KPD_enuInit();

	while(1)
	{
		do
		{
			Local_u8Key = KPD_u8GetPressedKey();
		}while(Local_u8Key==0xff);

		LCD_enuDisplayChar(Local_u8Key+'0');
	}
}
