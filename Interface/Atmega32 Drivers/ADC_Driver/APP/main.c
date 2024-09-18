/*
 * main.c
 *
 *  Created on: Feb 18, 2024
 *      Author: mahmo
 */
#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorStates.h"

#include "../MCAL/DIO/DIO_int.h"


//#include "../MCAL/ADC/ADC_Priv.h"
#include "../MCAL/ADC/ADC_Config.h"
#include "../MCAL/ADC/ADC_Int.h"

void main (void)
{
	u16 result;

	u8 ValueVref = 1;
	u8 AdjustValue = 0;
	u8 ADC_ChValue = 0;
	u8 PrescValue = 3;


	enu_ADC_Int(ValueVref, AdjustValue, ADC_ChValue, PrescValue);

	enu_ADC_Read(0, &result);
}
