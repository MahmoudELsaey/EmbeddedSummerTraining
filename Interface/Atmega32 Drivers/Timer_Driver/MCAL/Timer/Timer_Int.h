/*
 * Timer_int.h
 *
 *  Created on: Feb 25, 2024
 *      Author: mahmo
 */


ES_t Timer_enuInit();

ES_t Timer_enuSetPreload(u8 Copy_u8Preload);

ES_t Timer_enuSetAsychDelay(u32 Copy_u8Time, void(*Copy_pfunApp)(void*), void* Parameter);

ES_t Timer_enuSetSynchDelay(u32 Copy_u8Time);
