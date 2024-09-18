/*
 * Timer_Prog.c
 *
 *  Created on: Feb 25, 2024
 *      Author: mahmo
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "../EXTI/interrupt.h"

#include "Timer_Priv.h"
#include "Timer_Config.h"

static u32 Num_OVF=0;
static u32 Preload=0;

static void (*gptr)(void*)= NULL;
static void *gpara = NULL;

ES_t Timer_enuInit()
{
	ES_t Local_enuErrorSate = ES_NOK;
#if TIMER_PRESC == 1024
	TCCR0 &= 0xf8;
	TCCR0 |= 5;
#endif

#if TIMER_MODE == OVF
		TCCR0 &= ~(1<<3);
		TCCR0 &= ~(1<<6);

#elif TIMER_MODE == CTC
		TCCR0 |= (1<<3);
		TCCR0 &= ~(1<<6);

#elif TIMER_MODE == FAST
	TCCR0 |= (1<<3);
	TCCR0 |= (1<<6);

#elif TIMER_MODE == PHASE
	TCCR0 &= ~(1<<3);
	TCCR0 |= (1<<6);
#endif

#if OC_MODE == DISCONNECTED
	TCCR0 &=~(1<<4);
	TCCR0 &=~(1<<5);
#elif OC_MODE == TOOGLE
	TCCR0 |=(1<<4);
	TCCR0 &=~(1<<5);
#elif OC_MODE == CLEAR
	TCCR0 &=~(1<<4);
	TCCR0 |=(1<<5);
#elif OC_MODE == SET
	TCCR0 |=(1<<4);
	TCCR0 |=(1<<5);
#endif

	return Local_enuErrorSate;
}

ES_t Timer_enuSetPreload(u8 Copy_u8Preload)
{
	ES_t Local_enuErrorSate = ES_NOK;

	TCNT0 = Copy_u8Preload;

	return Local_enuErrorSate;
}

ES_t Timer_enuSetAsychDelay(u32 Copy_u8Time, void(*Copy_pfunApp)(void*), void* Parameter)
{
	ES_t Local_enuErrorSate = ES_NOK;

	f32 OVFTime= 256*((f32)TIMER_PRESC/TIMER_F_CPU); //Float*Integer= Float -- Float/Integer= Float.
	f32 NumOVF= (Copy_u8Time/OVFTime);

	if((NumOVF - (u32)NumOVF) != 0.0)
	{
		u8 preload = 256-((NumOVF - (u32)NumOVF)*256);
		Preload = preload;
		TCNT0 = preload;

		NumOVF = ((u32)NumOVF)+1;
		Num_OVF= NumOVF;
	}
	else
	{
		Num_OVF = ((u32)NumOVF)+1;
	}

	if(Copy_pfunApp != NULL)
	{
		gptr = Copy_pfunApp;
		gpara = Parameter;
	}

	TIMSK |= (1<<0);

	return Local_enuErrorSate;
}

ES_t Timer_enuSetSynchDelay(u32 Copy_u8Time)
{
	ES_t Local_enuErrorSate = ES_NOK;

	TIMSK &= ~(1<<0);
	f32 OVFTime= 256*((f32)TIMER_PRESC/TIMER_F_CPU); //Float*Integer= Float -- Float/Integer= Float.
	f32 NumOVF= (Copy_u8Time/OVFTime);

	if((NumOVF - (u32)NumOVF) != 0.0)
	{
		u8 preload = 256-((NumOVF - (u32)NumOVF)*256);
		NumOVF = ((u32)NumOVF)+1;
		TCNT0 = preload;
		while(NumOVF>0)
		{
			while (((TIFR<<0)&1) == 0);
			TIFR |= (1<<0);
			NumOVF--;
		}
	}
	else
	{
		NumOVF = ((u32)NumOVF);
		while(NumOVF>0)
		{
			while (((TIFR<<0)&1) ==0);
			TIFR |= (1<<0);
			NumOVF--;
		}

	}


	return Local_enuErrorSate;
}

ISR(VECT_TIMER0_OVF)
{
	if (gptr != NULL)
	{
		static u32 counts = 0;

		counts++;
		if (counts == Num_OVF)
		{
			TCNT0 = Preload;
			gptr(gpara);
			counts = 0;
		}
	}
}

ISR(VECT_TIMER0_CTC)
{

}
