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

#ifndef __BSP_LED_H__
#define __BSP_LED_H__
/***********************************includes************************************/
#include<stdint.h>//the compiling lib
#include<stdio.h>

#include "main.h"//Core/OS layer
#include "cmsis_os.h"

#include "queue.h"//Core/OS layer
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
/***********************************defines*************************************/

//*************************Thread Func**********************//
extern osThreadId_t led_TaskHandle;
extern const osThreadAttr_t led_Task_attributes;
//*************************Thread Func**********************//

//Queue Handler*********************************************//
extern QueueHandle_t led_queue;
//Queue Handler*********************************************//
// 
//function resturn status
typedef enum {
	LED_OK = 0,						/* Operation completed successfully		*/
	LED_ERROR = 1,					/* Run-Time error without case matched	*/
	LED_ERRORTIMEOUT = 2,			/* Operation failed with timeout		*/
	LED_ERRORRESOURCE = 3,			/* Resource not available				*/
	LED_ERRORARAMETER = 4,			/* Parameter error						*/
	LED_ERRORMEMORY = 5,			/* Out of memory						*/
	LED_ERRORISR = 6,				/* Not allowed in ISR context			*/
	LED_RESERVED = 0x7FFFFFF		/* Reserved								*/
}led_status_t;

typedef enum {
	LED_ON = 0,						/* Operation completed successfully		*/
	LED_OFF = 1,					/* Run-Time error without case matched	*/
	LED_TOGGLE = 2
}led_operation_t;
/***********************************declaring***********************************/

/******************************************************************
* Steps:
* 1. doing the specific operation
	 *@brief  Retargets the C library printf  function to the USART.
	 *@param  void
	 *@retval None
 ******************************************************************/
led_status_t led_on_off(led_operation_t led_operation);

/***********************************declaring***********************************/

/**
  * @brief  key thread function for thread to run
  * @param  void * argument
  * @retval void
*/
void led_Task_func(void* argument);
/***********************************declaring***********************************/


#endif // !__BSP_LED_H__
