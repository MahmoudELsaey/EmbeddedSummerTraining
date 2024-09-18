/*
 * EXTI_Prog.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mahmo
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"
#include "EXTI_Priv.h"
#include "EXTI_Config.h"
#include "../EXTI.h"

static volatile void (*gptr[3])(void*) = {NULL, NULL, NULL};
static volatile void *pToArg[3]= {NULL, NULL, NULL};

ES_t enu_Int (EXTI_t *PointerToStruct)
{
	u8 Local_u8_errorState = ES_NOK;
			if (PointerToStruct != NULL)
			{

				for(u8 local_Iter=0; local_Iter<3; local_Iter++)
				{
					if (PointerToStruct[local_Iter].EXTI_u8State == Active)
					{
						switch(local_Iter)
						{
						case 0:
							MCUCR &= ~(3<<0);
							GICR |= (1<<6);
							switch(PointerToStruct[local_Iter].EXTI_u8SenceLevel)
							{
								case LowLevel:
									MCUCR &= ~(3<<0);
									break;
								case AnyLogicalChange:
									MCUCR |= (1<<0);
									break;
								case FallingEdge:
									MCUCR |= (1<<1);
									break;
								case RisingEdge:
									MCUCR |= (3<<0);
									break;
							}
							break;
						case 1:
							MCUCR &= ~(3<<2);
							GICR |= (1<<7);
							switch(PointerToStruct[local_Iter].EXTI_u8SenceLevel)
							{
								case LowLevel:
									MCUCR &= ~(3<<2);
									break;
								case AnyLogicalChange:
									MCUCR |= (1<<2);
									break;
								case FallingEdge:
									MCUCR |= (1<<3);
									break;
								case RisingEdge:
									MCUCR |= (3<<2);
									break;
							}
							break;
						case 2:
							MCUCSR &= ~(1<<6);
							GICR |= (1<<5);
							switch(PointerToStruct[local_Iter].EXTI_u8SenceLevel)
							{
								case FallingEdge:
									MCUCSR &= ~(1<<6);
									break;
								case RisingEdge:
									MCUCSR |= (1<<6);
									break;
							}
							break;
						}
					}
				}
				Local_u8_errorState= ES_OK;
			}


	return Local_u8_errorState;
}
ES_t enu_ChangeSence (u8 PerieID, u8 SenceLevel)
{
	u8 Local_u8_errorState = ES_NOK;
	if (SenceLevel >=0 && SenceLevel<=3)
	{
		if(PerieID >= 0 && PerieID <= 2)
		{
			switch(PerieID)
			{
			case 0:
				MCUCR &= ~(3<<0);
				switch(SenceLevel)
				{
					case LowLevel:
						MCUCR &= ~(3<<0);
						break;
					case AnyLogicalChange:
						MCUCR |= (1<<0);
						break;
					case FallingEdge:
						MCUCR |= (1<<1);
						break;
					case RisingEdge:
						MCUCR |= (3<<0);
						break;
				}
				break;
			case 1:
				MCUCR &= ~(3<<2);
				switch(SenceLevel)
				{
					case LowLevel:
						MCUCR &= ~(3<<2);
						break;
					case AnyLogicalChange:
						MCUCR |= (1<<2);
						break;
					case FallingEdge:
						MCUCR |= (1<<3);
						break;
					case RisingEdge:
						MCUCR |= (3<<2);
						break;
				}
				break;
			case 2:
				MCUCSR &= ~(1<<6);
				switch(SenceLevel)
				{
					case FallingEdge:
						MCUCSR &= ~(1<<6);
						break;
					case RisingEdge:
						MCUCSR |= (1<<6);
						break;
				}
				break;
			}
		}
		Local_u8_errorState = ES_OK;
	}


	return Local_u8_errorState;
}
ES_t enu_GIE (u8 Value)
{
	u8 Local_u8_errorState = ES_NOK;
	switch (Value)
	{
	case 0:
		SREG &= ~(1<<7);
		break;
	case 1:
		SREG |= (1<<7);
		break;
	default:
		Local_u8_errorState = ES_OUT_OF_RANGE;
	}

	return Local_u8_errorState;
}
ES_t enu_PIE (u8 PerieID, u8 Value)
{
	u8 Local_u8_errorState = ES_NOK;

	if(PerieID >= 0 && PerieID <= 2)
	{
		switch(PerieID)
		{
		case 0:
			switch(Value)
			{
				case 0:
					GICR &= ~(1<<6);
					break;
				case 1:
					GICR |= (1<<6);
					break;
			}
			break;
		case 1:
			switch(Value)
			{
				case 0:
					GICR &= ~(1<<7);
					break;
				case 1:
					GICR |= (1<<7);
					break;
			}
			break;
		case 2:
			switch(Value)
			{
				case 0:
					GICR &= ~(1<<5);
					break;
				case 1:
					GICR |= (1<<5);
					break;
			}
			break;
		}
	}

	return Local_u8_errorState;
}
ES_t enu_PIF (u8 PerieID, u8 Value)
{
	u8 Local_u8_errorState = ES_NOK;

	if(PerieID >= 0 && PerieID <= 2)
	{
		switch(PerieID)
		{
		case 0:
			switch(Value)
			{
				case 0:
					GIFR &= ~(1<<6);
					break;
				case 1:
					GIFR |= (1<<6);
					break;
			}
			break;
		case 1:
			switch(Value)
			{
				case 0:
					GIFR &= ~(1<<7);
					break;
				case 1:
					GIFR |= (1<<7);
					break;
			}
			break;
		case 2:
			switch(Value)
			{
				case 0:
					GIFR &= ~(1<<5);
					break;
				case 1:
					GIFR |= (1<<5);
					break;
			}
			break;
		}
	}
	return Local_u8_errorState;
}

ES_t EXTI_CallBack(volatile void(*ptr)(void *), u8 PerieID, volatile void *p)
{
	u8 Local_u8_errorState = ES_NOK;

	if(ptr!=NULL && PerieID<3)
	{
		gptr[PerieID]=ptr;
		pToArg[PerieID]=p;
	}
	else
	{
		Local_u8_errorState = ES_NULL_POINTER;
	}
	return Local_u8_errorState;
}


ISR(VECT_INT0)
{
	if (gptr[0]!=NULL && pToArg!=NULL)
	{
		gptr[0](pToArg[0]);
	}
}

ISR(VECT_INT1)
{
	if (gptr[1]!=NULL && pToArg!=NULL)
	{
		gptr[1](pToArg[1]);
	}

}

ISR(VECT_INT2)
{
	if (gptr[2]!=NULL && pToArg!=NULL)
	{
		gptr[2](pToArg[2]);
	}

}
