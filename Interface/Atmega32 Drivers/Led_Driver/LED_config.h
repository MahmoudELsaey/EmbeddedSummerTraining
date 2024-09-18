/*
 * LED_config.h
 *
 *  Created on: Nov 5, 2023
 *      Author: mahmo
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM 3

typedef struct
{
	u8 Led_u8PortID;
	u8 Led_u8PinID;
	u8 Led_u8Connection;
	u8 Led_u8InitState;
}LED_t;

#endif /* LED_CONFIG_H_ */
