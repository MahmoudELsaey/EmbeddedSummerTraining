/*
 * Timer_Priv.h
 *
 *  Created on: Feb 25, 2024
 *      Author: mahmo
 */

#define TCCR0 	(*(volatile u8*)0x53)
#define	TCNT0 	(*(volatile u8*)0x52)
#define	TIFR 	(*(volatile u8*)0x58)
#define	TIMSK	(*(volatile u8*)0x59)
#define	OCR0	(*(volatile u8*)0x5C)

#define	SREG	(*(volatile u8*)0x5f)

#define	DDRA	(*(volatile u8*)0x3A)
#define	DDRB	(*(volatile u8*)0x37)

#define	PORTA	(*(volatile u8*)0x3B)

#define OVF		0
#define DISCONNECTED 	0
