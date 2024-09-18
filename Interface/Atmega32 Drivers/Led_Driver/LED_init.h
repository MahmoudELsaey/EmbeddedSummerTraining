/*
 * LED_init.h
 *
 *  Created on: Nov 5, 2023
 *      Author: mahmo
 */

#ifndef LED_INIT_H_
#define LED_INIT_H_

ES_t LED_enuInit(LED_t *Copy_pstrLedConfig);

ES_t LED_enuTurnOn(LED_t *Copy_pstrLedID);

ES_t LED_enuTurnOff(LED_t *Copy_pstrLedID);

#endif /* LED_INIT_H_ */
