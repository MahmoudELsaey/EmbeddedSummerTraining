/*
 * SW_MAIN.C
 *
 *  Created on: Oct 31, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "SW_Config.h"
#include "SW_Int.h"

extern SW_t Switch_AstrSwitchStates[SW_NUM];
int main(void)
{
	DIO_enuInit();
	Switch_enuInit(Switch_AstrSwitchStates);

	u8 pinstate;

	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchStates[1], &pinstate);
		if(pinstate==0)
			DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8HIGH);
		else
			DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8LOW);
	}
}
