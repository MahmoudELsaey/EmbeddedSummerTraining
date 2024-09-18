/*
 * EXTI_priv.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define ACTIVE 		5
#define DEACTIVE 		9


#define RISING_EDGE			5
#define FALLING_EDGE		9
#define ANY_LOGIC			19
#define LOW_LEVEL			93


#define MCUCR				*((u8*)0x55)
#define MCUCSR				*((u8*)0x54)
#define GICR				*((u8*)0x5B)
#define GIFR				*((u8*)0x5A)


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
