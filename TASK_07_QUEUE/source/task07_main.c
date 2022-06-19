///*
// * Copyright 2016-2022 NXP
// * All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without modification,
// * are permitted provided that the following conditions are met:
// *
// * o Redistributions of source code must retain the above copyright notice, this list
// *   of conditions and the following disclaimer.
// *
// * o Redistributions in binary form must reproduce the above copyright notice, this
// *   list of conditions and the following disclaimer in the documentation and/or
// *   other materials provided with the distribution.
// *
// * o Neither the name of NXP Semiconductor, Inc. nor the names of its
// *   contributors may be used to endorse or promote products derived from this
// *   software without specific prior written permission.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
// * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
///**
// * @file    PRATICA5_FRDM-KL46Z.c
// * @brief   Application entry point.
// */
//#include <stdio.h>
//#include "board.h"
//#include "pin_mux.h"
//#include "clock_config.h"
//#include "MKL43Z4.h"
//#include "fsl_debug_console.h"
//
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//
//#define LED_RED 	31
//#define LED_GREEN 	5
//#define ON 			1
//#define OFF 		0
//
//
//typedef struct {
//	unsigned int num;
//	unsigned int status;
//} LedInfo;
//
//void vLedsInit() {
//	CLOCK_EnableClock(kCLOCK_PortD);
//	CLOCK_EnableClock(kCLOCK_PortE);
//
//	PORTD->PCR[LED_GREEN] |= (1 << 8);
//	GPIOD->PDDR |= (1 << LED_GREEN);
//	GPIOD->PSOR |= (1 << LED_GREEN);
//	PORTE->PCR[LED_RED] |= (1 << 8);
//	GPIOE->PDDR |= (1 << LED_RED);
//	GPIOE->PSOR |= (1 << LED_RED);
//}
//
//void drvLedsSet(int num, int status) {
//	if(num == LED_GREEN) {
//		if(status == ON) {
//			GPIOD->PCOR = (1 << 5);
//		} else {
//			GPIOD->PSOR = (1 << 5);
//		}
//	} else {
//		if(status == ON) {
//			GPIOE->PCOR = (1 << 29);
//		} else {
//			GPIOE->PSOR = (1 << 29);
//		}
//	}
//}
//
//void taskLed(void *pvParameters) {
//	QueueHandle_t ledQueue = (QueueHandle_t) pvParameters;
//	LedInfo led;
//
//	for(;;) {
//		xQueueReceive(ledQueue, &led, portMAX_DELAY);
//		drvLedsSet(led.num, led.status);
//	}
//}
//
//int drvButtonsSW1Pressed(void) {
//	if(GPIOD->PDIR & (1 << 4)) {
//		return 1;
//	}
//	return 0;
//}
//
//int drvButtonsSW2Pressed(void) {
//	if(GPIOD->PDIR & (1 << 2)) {
//		return 1;
//	}
//	return 0;
//}
//
//void taskButton(void *pvParameters){
//	QueueHandle_t ledQueue = (QueueHandle_t) pvParameters;
//	LedInfo led;
//	led.status = OFF;
//	led.num = LED_RED;
//	for (;;) {
//		if (drvButtonsSW1Pressed() && led.status == OFF) {
//			led.status = ON;
//			xQueueSendToBack(ledQueue, &led, portMAX_DELAY);
//		}else if (drvButtonsSW2Pressed() && led.status == ON) {
//			led.status = OFF;
//			xQueueSendToBack(ledQueue, &led, portMAX_DELAY);
//		}
//		vTaskDelay(100 / portTICK_PERIOD_MS);
//	}
//}
///*
// * @brief   Application entry point.
// */
//int main(void) {
//
//	QueueHandle_t ledQueue;
//	vLedsInit();
//
//	ledQueue = xQueueCreate(1, sizeof(LedInfo));
//
//	/* create leds task */
//	xTaskCreate(taskLed, "TaskLed", configMINIMAL_STACK_SIZE, (void *)ledQueue, 1, NULL);
//	/* create buttons task */
//	xTaskCreate(taskButton, "TaskButton", configMINIMAL_STACK_SIZE, (void *)ledQueue, 1, NULL);
//	/* start the scheduler */
//	vTaskStartScheduler();
//
//	while(true){} /* should never reach here! */
//    return 0 ;
//}
