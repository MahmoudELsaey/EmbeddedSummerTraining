/*
 * EXTI_Config.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mahmo
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "EXTI_Config.h"
#include "EXTI_Priv.h"
EXTI_t Arr_Str[3] =
			   {
					   {Active, RisingEdge},
					   {Deactive},
					   {Deactive}
			   };
