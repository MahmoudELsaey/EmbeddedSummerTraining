/*
 * SW_CONFIG.c
 *
 *  Created on: Oct 31, 2023
 *      Author: mahmo
 */

#ifndef SW_CONFIG_C_
#define SW_CONFIG_C_
#include "SW_Config.h"

#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "SW_Priv.h"

SW_t Switch_AstrSwitchStates [SW_NUM]= {
		{DIO_u8PORTA, DIO_u8PIN4, DIO_u8FLOAT},
		{DIO_u8PORTD, DIO_u8PIN3, DIO_u8PULL_UP},
		{DIO_u8PORTC, DIO_u8PIN5, DIO_u8PULL_UP}
};

#endif /* SW_CONFIG_C_ */
