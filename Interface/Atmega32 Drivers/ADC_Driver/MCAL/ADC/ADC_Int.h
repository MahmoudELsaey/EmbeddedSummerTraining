/*
 * ADC_Int.h
 *
 *  Created on: Feb 12, 2024
 *      Author: mahmo
 */
#include "../../LIBRARIES/errorStates.h"
#include "../../LIBRARIES/stdtypes.h"

ES_t enu_ADC_Int(u8 ValueVref, u8 AdjustValue, u8 ADC_ChValue, u8 PrescValue);
ES_t enu_ADC_Vref(u8 ValueVref);
ES_t enu_ADC_Adjust(u8 AdjustValue);
ES_t enu_ADC_Channel_Selc(u8 ADC_ChValue);
ES_t enu_ADC_Enable(u8 EnableValue);
ES_t enu_ADC_StartConver();
ES_t enu_ADC_AutoTrigger(u8 EnAutoTrigger);
ES_t enu_GIE (u8 Value);
ES_t enu_ADC_InterruptEnable(u8 IntEnValue);
ES_t enu_ADC_FlagClear();
ES_t enu_ADC_Prescaler(u8 PrescValue);
ES_t enu_ADC_AutoTriggerSource(u8 SourceType);
ES_t enu_ADC_Read(u8 AdjustValue, u16* ADC_Result);
