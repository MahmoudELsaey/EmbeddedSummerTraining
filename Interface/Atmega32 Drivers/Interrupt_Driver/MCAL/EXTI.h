/*
 * EXTI.h
 *
 *  Created on: Feb 6, 2024
 *      Author: mahmo
 */

#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0 			__vector_1
#define VECT_INT1 			__vector_2
#define VECT_INT2 			__vector_3
