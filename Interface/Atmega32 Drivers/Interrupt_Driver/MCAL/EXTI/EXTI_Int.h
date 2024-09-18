/*
 * EXTI_Int.h
 *
 *  Created on: Feb 2, 2024
 *      Author: mahmo
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_



#endif /* EXTI_INT_H_ */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"


ES_t enu_Int (EXTI_t *PointerToStruct);

ES_t enu_ChangeSence (u8 PerieID, u8 SenceLevel);

ES_t enu_GIE (u8 Value);

ES_t enu_PIE (u8 PerieID, u8 Value);

ES_t enu_PIF (u8 PerieID, u8 Value);

ES_t EXTI_CallBack(void(*ptr)(void*), u8 PerieID, void *p);
