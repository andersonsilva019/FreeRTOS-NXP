#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

typedef struct {
	uint32_t TSI_GENCS;
	uint32_t TSI_DATA;
	uint32_t TSI_TSHD;
	uint32_t TSI_MODE;
	uint32_t TSI_MUL0;
	uint32_t TSI_MUL1;
	uint32_t TSI_SINC;
	uint32_t TSI_SSC0;
	uint32_t TSI_SSC1;
	uint32_t TSI_SSC2;
}TSIRegs_t;

#define TSI ((TSIRegs_t *) 0x400FF000)

typedef struct {
	unsigned int num;
	unsigned int status;
} LedInfo;

#define LED_RED 	31
#define LED_GREEN 	5
#define ON 			1
#define OFF 		0
#define SW1			2
#define SW2 		4

/* Define the queue parameters. */
#define QUEUE_LENGTH 1
#define QUEUE_ITEM_SIZE sizeof(LedInfo)

void vButtonsInit() {
	PORTD->PCR[SW1] |= (1 << 8) | (1 << 1) | (1 << 0);
	PORTD->PCR[SW2] |= (1 << 8) | (1 << 1) | (1 << 0);
}

void drvLedsSet(int num, int status) {
	if(num == LED_GREEN) {
		if(status == ON) {
			lowLedGreen();
		} else {
			highLedGreen();
		}
	} else {
		if(status == ON) {
			lowLedRed();
		} else {
			highLedRed();
		}
	}
}

void highLedGreen(){
	PORTD->PCR[LED_GREEN] |= (1 << 8);
	GPIOD->PDDR |= (1 << LED_GREEN);
	GPIOD->PCOR |= (1 << LED_GREEN);
}

void lowLedGreen(){
	PORTD->PCR[LED_GREEN] |= (1 << 8);
	GPIOD->PDDR |= (1 << LED_GREEN);
	GPIOD->PSOR |= (1 << LED_GREEN);
}

void highLedRed(){
	PORTE->PCR[LED_RED] |= (1 << 8);
	GPIOE->PDDR |= (1 << LED_RED);
	GPIOE->PCOR |= (1 << LED_RED);
}

void lowLedRed(){
	PORTE->PCR[LED_RED] |= (1 << 8);
	GPIOE->PDDR |= (1 << LED_RED);
	GPIOE->PSOR |= (1 << LED_RED);
}

void taskLed(void *pvParameters) {
	QueueHandle_t ledQueue = (QueueHandle_t) pvParameters;
	LedInfo led;

	for(;;) {
		xQueueReceive(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		drvLedsSet(led.num, led.status);
	}
}

int drvButtonsSW1Pressed(void) {
	if(GPIOD->PDIR & (1 << 4)) {
		return 1;
	}
	return 0;
}

int drvButtonsSW2Pressed(void) {
	if(GPIOD->PDIR & (1 << 2)) {
		return 1;
	}
	return 0;
}

void taskButton(void *pvParameters){
	QueueHandle_t ledQueue = (QueueHandle_t) pvParameters;

	LedInfo led;
	led.status = OFF;
	led.num = LED_RED;

	for (;;) {
		if (drvButtonsSW1Pressed() && led.status == OFF) {
			led.status = ON;
			xQueueSendToBack(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		}else if (drvButtonsSW2Pressed() && led.status == ON) {
			led.status = OFF;
			xQueueSendToBack(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

int main(void) {

	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	vButtonsInit();

	QueueHandle_t ledQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE);

	if(ledQueue == NULL){
		printf("The queue could not be created. \n");
	}

	/* create leds task */
	xTaskCreate(taskLed, "TaskLed", configMINIMAL_STACK_SIZE, (void *)ledQueue, 1, NULL);
	/* create buttons task */
	xTaskCreate(taskButton, "TaskButton", configMINIMAL_STACK_SIZE, (void *)ledQueue, 1, NULL);
	/* start the scheduler */
	vTaskStartScheduler();

	while(true){} /* should never reach here! */
    return 0 ;
}
