/*
 * EXTI_Priv.h
 *
 *  Created on: Feb 2, 2024
 *      Author: mahmo
 */

//Interrupt Registers
#define SREG (*((volatile u8*) 0x5f))
#define MCUCR (*((volatile u8*) 0x55))
#define MCUCSR (*((volatile u8*) 0x54))
#define GICR (*((volatile u8*) 0x5B))
#define GIFR (*((volatile u8*) 0x5A))

//Tnterrupt Global Enable (SREG)
//#define EXTI_INT_Disable 0
//#define EXTI_GIE_Enable 1

//Interrubt Sense *INT0 INT1 (MCUCR)* -> Delete.
#define LowLevel 0
#define AnyLogicalChange 1
#define FallingEdge 2
#define RisingEdge 3

////Interrupt Sense INT2 (MCUCSR) -> Delete.
//#define INT2_FallingEdge 0
//#define INT2_RisingEdge 1

//Interrupt Prefeiral Enable (GICR)
#define Deactive 0
#define Active 1
