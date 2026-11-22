//******************************************************************************
// * Copyright (C) 2024 EternalChip, Inc.(Gmbh) or its affiliates.
// *
// * All Rights Reserved.
// *
// * @file bsp_key.h
// *
// * @par dependencies
// * - bsp_key.h
// * - stdio.h
// * - stdint.h
// *
// * @author JM Yang | GDUT_ICCRT. | EternalChip 立芯嵌入式
// *
// * @brief Provide the HAL APIs of AHT21 and corresponding opetions.
// *
// * Processing flow:
// *
// * call directly.
// *
// * @version V1.0 2026.11.21
// *
// * @note 1 tab == 4 spaces!
// *
// *****************************************************************************/

#ifndef __BSP_KEY_H__
#define __BSP_KEY_H__
/***********************************includes************************************/
#include<stdint.h>
#include<stdio.h>
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
/***********************************includes************************************/

/***********************************defines*************************************/

//函数返回状态枚举
typedef enum {
	KEY_OK					= 0,			/* Operation completed successfully		*/
	KEY_ERROR				= 1,			/* Run-Time error without case matched	*/
	KEY_ERRORTIMEOUT		= 2,			/* Operation failed with timeout		*/	
	KEY_ERRORRESOURCE		= 3,			/* Resource not available				*/	
	KEY_ERRORARAMETER		= 4,			/* Parameter error						*/
	KEY_ERRORMEMORY			= 5,			/* Out of memory						*/
	KEY_ERRORISR			= 6,			/* Not allowed in ISR context			*/
	KEY_RESERVED			= 0x7FFFFFF		/* Reserved								*/
}key_status_t;

typedef enum {
	KEY_PRESSED				= 0,		/* Key is pressed						*/
	KEY_NOT_PRESSED			= 1,		/* Key is not pressed now				*/		
}key_press_status_t;

/***********************************defines*************************************/
/***********************************declaring***********************************/
key_status_t key_scan(key_press_status_t* key_value);

/***********************************declaring***********************************/


#endif // !__BSP_KEY_H__
