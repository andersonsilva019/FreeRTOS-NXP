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
		// Recebendo dados da fila
		xQueueReceive(ledQueue, &led, (1000 / portTICK_PERIOD_MS));

		// Realiza o processo de ligar ou desligar o LED
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

			// Enviando informa????o para fila
			xQueueSendToBack(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		}else if (drvButtonsSW2Pressed() && led.status == ON) {
			led.status = OFF;

			// Enviando informa????o para fila
			xQueueSendToBack(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

int main(void) {

	// Habilitando o clock do PortD e PortE
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	// Inicializando os bot??es
	vButtonsInit();

	// Criando um fila
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
