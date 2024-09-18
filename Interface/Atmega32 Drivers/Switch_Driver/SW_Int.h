/*
 * SW_INT.h
 *
 *  Created on: Oct 31, 2023
 *      Author: mahmo
 */

#ifndef SW_INT_H_
#define SW_INT_H_

ES_t Switch_enuInit(SW_t * Copy_AstrSwitches);

ES_t Switch_enuGetState(SW_t * Copy_AstrSwitches ,u8 * Copy_pu8SwState);

#endif /* SW_INT_H_ */
