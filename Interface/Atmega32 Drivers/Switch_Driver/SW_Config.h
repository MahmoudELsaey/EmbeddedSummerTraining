/*
 * SW_CONFIG.h
 *
 *  Created on: Oct 31, 2023
 *      Author: mahmo
 */

#ifndef SW_CONFIG_H_
#define SW_CONFIG_H_

#include "stdTypes.h"

#define SW_NUM 		3

typedef struct
{
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_Status;
}SW_t;

#endif /* SW_CONFIG_H_ */
