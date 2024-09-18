/*
 * SW_PROG.C
 *
 *  Created on: Oct 31, 2023
 *      Author: mahmo
 */

#ifndef SW_PROG_C_
#define SW_PROG_C_
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "SW_Config.h"
#include "SW_Priv.h"

ES_t Switch_enuInit(SW_t * Copy_AstrSwitches)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_AstrSwitches != NULL)
	{
		u8 Local_u8Iterator =0;
		for(Local_u8Iterator =0; Local_u8Iterator < SW_NUM; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_AstrSwitches[Local_u8Iterator].SW_PortID, Copy_AstrSwitches[Local_u8Iterator].SW_PinID, DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrSwitches[Local_u8Iterator].SW_PortID, Copy_AstrSwitches[Local_u8Iterator].SW_PinID, Copy_AstrSwitches[Local_u8Iterator].SW_Status);
		}
	}
	else
		Local_enuErrorState = ES_NULL_POINTER;

	return Local_enuErrorState;
}

// Pressed OR Not Pressed
ES_t Switch_enuGetState(SW_t * Copy_AstrSwitches ,u8 * Copy_pu8SwState)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_AstrSwitches && Copy_pu8SwState != NULL)
	{
		Local_enuErrorState = DIO_enuGetPinValue(Copy_AstrSwitches->SW_PortID, Copy_AstrSwitches->SW_PinID, Copy_pu8SwState);
	}
	else
		Local_enuErrorState = ES_NULL_POINTER;

	return Local_enuErrorState;
}

#endif /* SW_PROG_C_ */
