/*
 * DC_Prog.c
 *
 *  Created on: Feb 12, 2024
 *      Author: mahmo
 */

#include "../../LIBRARIES/errorStates.h"
#include "../../LIBRARIES/stdtypes.h"
#include "ADC_Priv.h"
#include "ADC_Int.h"

ES_t enu_ADC_Int(u8 ValueVref, u8 AdjustValue, u8 ADC_ChValue, u8 PrescValue)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	enu_ADC_Vref(ValueVref);
	enu_ADC_Adjust(AdjustValue);
	enu_ADC_Channel_Selc(ADC_ChValue);
	enu_ADC_Prescaler(PrescValue);
	enu_ADC_Enable(1);

	return u8_Localenu_ErrorState;
}
ES_t enu_ADC_Vref(u8 ValueVref)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	ADMUX &= ~(1<<6);
	ADMUX &= ~(1<<7);
	switch(ValueVref)
	{
	case AREF:
		ADMUX &= ~(1<<6);
		ADMUX &= ~(1<<7);
		break;
	case AVCC:
		ADMUX |= (1<<6);
		ADMUX &= ~(1<<7);
		break;
	case InternalVolt:
		ADMUX |= (1<<6);
		ADMUX |= (1<<7);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}

	return u8_Localenu_ErrorState;

}
ES_t enu_ADC_Adjust(u8 AdjustValue)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	switch (AdjustValue)
	{
	case Right:
		ADMUX &= ~(1<<5);
		break;
	case Left:
		ADMUX |= (1<<5);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}
	return u8_Localenu_ErrorState;
}
ES_t enu_ADC_Channel_Selc(u8 ADC_ChValue)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	switch (ADC_ChValue)
	{
	case 0:
		ADMUX &= ~(7<<0);
		break;
	case 1:
		ADMUX |= (1<<0);
		break;
	case 2:
		ADMUX |= (1<<1);
		break;
	case 3:
		ADMUX |= (3<<0);
		break;
	case 4:
		ADMUX |= (1<<2);
		break;
	case 5:
		ADMUX |= (5<<0);
		break;
	case 6:
		ADMUX |= (3<<1);
		break;
	case 7:
		ADMUX |= (7<<0);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}

	return u8_Localenu_ErrorState;

}
ES_t enu_ADC_Enable(u8 EnableValue)
{
	u8 u8_Localenu_ErrorState = ES_NOK;
	switch (EnableValue)
	{
	case Disable:
		ADCSRA &= ~(1<<7);
		break;
	case Enable:
		ADCSRA |= (1<<7);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}
	return u8_Localenu_ErrorState;
}
ES_t enu_ADC_StartConver()
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	ADCSRA |= (1<<6);

	return u8_Localenu_ErrorState;

}
ES_t enu_ADC_AutoTrigger(u8 EnAutoTrigger)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	switch (EnAutoTrigger)
	{
	case Disable:
		ADCSRA &= ~(1<<5);
		break;
	case Enable:
		ADCSRA |= (1<<5);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}

	return u8_Localenu_ErrorState;

}
ES_t enu_GIE (u8 Value)
{
	u8 Local_u8_errorState = ES_NOK;
	switch (Value)
	{
	case Disable:
		SREG &= ~(1<<7);
		break;
	case Enable:
		SREG |= (1<<7);
		break;
	default:
		Local_u8_errorState = ES_OUT_OF_RANGE;
	}

	return Local_u8_errorState;
}
ES_t enu_ADC_InterruptEnable(u8 IntEnValue)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	switch (IntEnValue)
	{
	case Disable:
		ADCSRA &= ~(1<<3);
		break;
	case Enable:
		ADCSRA |= (1<<3);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}
	return u8_Localenu_ErrorState;
}
ES_t enu_ADC_FlagClear()
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	ADCSRA &= ~(1<<4);

	return u8_Localenu_ErrorState;

}
ES_t enu_ADC_Prescaler(u8 PrescValue)
{
	u8 u8_Localenu_ErrorState = ES_NOK;
	ADCSRA &= ~(7<<0);
	switch (PrescValue)
	{
	case 0:
		ADCSRA &= ~(7<<0);
		break;
	case 1:
		ADCSRA |= (1<<0);
		break;
	case 2:
		ADCSRA |= (1<<1);
		break;
	case 3:
		ADCSRA |= (3<<0);
		break;
	case 4:
		ADCSRA |= (1<<2);
		break;
	case 5:
		ADCSRA |= (5<<0);
		break;
	case 6:
		ADCSRA |= (3<<1);
		break;
	case 7:
		ADCSRA |= (7<<0);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}
	return u8_Localenu_ErrorState;
}
ES_t enu_ADC_AutoTriggerSource(u8 SourceType)
{
	u8 u8_Localenu_ErrorState = ES_NOK;
	SFOIR &= ~(7<<5);
	switch (SourceType)
	{
	case 0:
		SFOIR &= ~(7<<0);
		break;
	case 1:
		SFOIR |= (1<<0);
		break;
	case 2:
		SFOIR |= (1<<1);
		break;
	case 3:
		SFOIR |= (3<<0);
		break;
	case 4:
		SFOIR |= (1<<2);
		break;
	case 5:
		SFOIR |= (5<<0);
		break;
	case 6:
		SFOIR |= (3<<1);
		break;
	case 7:
		SFOIR |= (7<<0);
		break;
	default:
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;
	}

	return u8_Localenu_ErrorState;

}

ES_t enu_ADC_Read(u8 AdjustValue, u16* ADC_Result)
{
	u8 u8_Localenu_ErrorState = ES_NOK;

	enu_ADC_StartConver();
	while(ADCSRA & (1<<6));
	enu_ADC_FlagClear();

	if (AdjustValue == 0)
	{
		*ADC_Result = ADCL | (ADCH<<8);
	}
	else if (AdjustValue == 1)
	{
		*ADC_Result = (ADCL>>6) | (ADCH<<2);
	}
	else
		u8_Localenu_ErrorState = ES_OUT_OF_RANGE;

	return u8_Localenu_ErrorState;
}
