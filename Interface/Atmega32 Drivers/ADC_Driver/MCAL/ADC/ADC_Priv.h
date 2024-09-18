/*
 * ADC_Priv.h
 *
 *  Created on: Feb 12, 2024
 *      Author: mahmo
 */


#define SFOIR ((*(volatile u8*)0x50))
#define ADMUX ((*(volatile u8*)0x27))
#define ADCSRA ((*(volatile u8*)0x26))
#define ADCL ((*(volatile u8*)0x24))
#define ADCH ((*(volatile u8*)0x25))
#define SREG (*((volatile u8*) 0x5f))


#define AREF 0
#define AVCC 1
#define Reserved 2
#define InternalVolt 3

#define Disable 0
#define Enable 1

#define Right 0
#define Left 1

#define FreeRunningMode 0
#define AnalogComparator 1
#define ExternalInterruptRequest0 2
#define Counter0CompareMatch 3
#define Counter0Overflow 4
#define CounterCompareMatchB 5
#define Counter1Overflow 6
#define Counter1CaptureEvent 7
