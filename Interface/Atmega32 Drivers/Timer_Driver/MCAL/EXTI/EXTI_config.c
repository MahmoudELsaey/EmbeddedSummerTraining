/*
 * EXTI_config.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"



EXTI_t EXTI_AstrEXTIConfig [3] =
{
		{ACTIVE, RISING_EDGE},
		{DEACTIVE},
		{DEACTIVE}
};
