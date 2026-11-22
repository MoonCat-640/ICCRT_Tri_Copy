/******************************************************************************
 * Copyright (C) 2024 EternalChip, Inc.(Gmbh) or its affiliates.
 *
 * All Rights Reserved.
 *
 * @file bsp_led.c
 *
 * @par dependencies
 * - bsp_key.h
 * - stdio.h
 * - stdint.h
 *
 * @author JM Yang | GDUT_ICCRT. | EternalChip 立芯嵌入式
 *
 * @brief Provide the HAL APIs of AHT21 and corresponding opetions.
 *
 * Processing flow:
 *
 * call directly.
 *
 * @version V1.0 2026.11.21
 *
 * @note 1 tab == 4 spaces!
 *
 *****************************************************************************/

#include "bsp_led.h"
 //**********************Thread_Func********************************//
osThreadId_t led_TaskHandle;

const osThreadAttr_t led_Task_attributes = {
  .name = "led_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t)osPriorityHigh,
};
//**********************Thread_Func********************************//

QueueHandle_t led_queue;

 /******************************************************************
 * Steps:
 * 1. doing the specific operation
	  *@brief  Retargets the C library printf  function to the USART.
	  *@param  void
	  *@retval None
  ******************************************************************/
led_status_t led_on_off(led_operation_t led_operation) {
	led_status_t ret = LED_OK;

	if (LED_ON == led_operation) {
		//1.Make the LED ON
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	}
	if (LED_OFF == led_operation) {
		//1.Make the LED OFF
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
	}
	if (LED_TOGGLE == led_operation) {
		//1.Make the LED TOGGLE
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}

/* USER CODE BEGIN Header_StartDefaultTask */
 /**
   * @brief  Function implementing the defaultTask thread.
   * @param  argument: Not used
   * @retval None
   */
   /* USER CODE END Header_StartDefaultTask */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
  /* USER CODE END Header_StartDefaultTask */
void led_Task_func(void* argument) {

	led_status_t led_ret = LED_OK;
	led_operation_t led_value = LED_ON;
	led_queue = xQueueCreate(10, sizeof(led_operation_t));
	uint32_t counter_tick = 0;
	if (NULL == led_queue) {
		printf("led_queue created failed \r\n");
	}
	else {
		printf("led_queue created successfully \r\n");
	}
	for (;;) {

		printf("Hellow Led Thread\r\n");

		if (led_queue != 0)
		{
			// Receive a message on the created queue.  Block for 10 ticks if a
			// message is not immediately available.
			if (xQueueReceive(led_queue, &(led_value), (TickType_t)100))
			{
				// pcRxedMessage now points to the struct AMessage variable posted
				// by vATask.
				printf("received queue value = [%d]", led_value);
				led_on_off(led_value);
			}
		}
		osDelay(1000);
	}
}