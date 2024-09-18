/*
 * main.c
 *
 *  Created on: Nov 5, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "LED_Config.h"
#include "LED_init.h"
#include <util/delay.h>

extern LED_t LED_AstrLedConfig[LED_NUM];

int main(void)
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);

	while(1)
	{
		LED_enuTurnOn(&LED_AstrLedConfig[0]);
		_delay_ms(1000);
		LED_enuTurnOff(&LED_AstrLedConfig[0]);
		_delay_ms(1000);
	}

}
