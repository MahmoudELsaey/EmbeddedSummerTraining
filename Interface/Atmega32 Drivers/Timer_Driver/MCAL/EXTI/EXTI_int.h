/*
 * EXTI_int.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES_t EXTI_enuInit (EXTI_t * Copy_pstrEXTIConfig);

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void*), void * Copy_pvidParameter , u8 Copy_u8EXTI_ID);



#endif /* MCAL_EXTI_EXTI_INT_H_ */
