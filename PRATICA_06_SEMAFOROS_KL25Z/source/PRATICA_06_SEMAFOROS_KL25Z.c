#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_port.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

typedef struct {
	unsigned int num;
	unsigned int status;
} LedInfo;

#define LED_RED 	18 // B18
#define LED_GREEN 	19 // B19
#define LED_BLUE    1 // D1

#define ON 			1
#define OFF 		0

#define SW1			4		// D4
#define SW2 		12		// A12

/* Define the queue parameters. */
#define QUEUE_LENGTH 1
#define QUEUE_ITEM_SIZE sizeof(LedInfo)

SemaphoreHandle_t drvButtonSem;

void vButtonsInit() {
	PORTD->PCR[SW1] |= (1 << 8) | (1 << 1) | (1 << 0);
	PORTA->PCR[SW2] |= (1 << 8) | (1 << 1) | (1 << 0);
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
	PORTB->PCR[LED_GREEN] |= (1 << 8);
	GPIOB->PDDR |= (1 << LED_GREEN);
	GPIOB->PCOR |= (1 << LED_GREEN);
}

void lowLedGreen(){
	PORTB->PCR[LED_GREEN] |= (1 << 8);
	GPIOB->PDDR |= (1 << LED_GREEN);
	GPIOB->PSOR |= (1 << LED_GREEN);
}

void highLedRed(){
	PORTB->PCR[LED_RED] |= (1 << 8);
	GPIOB->PDDR |= (1 << LED_RED);
	GPIOB->PCOR |= (1 << LED_RED);
}

void lowLedRed(){
	PORTB->PCR[LED_RED] |= (1 << 8);
	GPIOB->PDDR |= (1 << LED_RED);
	GPIOB->PSOR |= (1 << LED_RED);
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
	if(GPIOD->PDIR & (1 << SW1)) {
		return 1;
	}
	return 0;
}

int drvButtonsSW2Pressed(void) {
	if(GPIOA->PDIR & (1 << SW2)) {
		return 1;
	}
	return 0;
}

void taskButton(void *params){
	QueueHandle_t ledQueue = (QueueHandle_t) params;

	LedInfo led;
	led.status = OFF;
	led.num = LED_RED;

	for (;;) {

		if (drvButtonsSW1Pressed() && led.status == OFF) {
			led.status = ON;
			xSemaphoreTake(drvButtonSem, portMAX_DELAY);
			xQueueSendToBack(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		}else if (drvButtonsSW2Pressed() && led.status == ON) {
			led.status = OFF;
			xSemaphoreTake(drvButtonSem, portMAX_DELAY);
			xQueueSendToBack(ledQueue, &led, (1000 / portTICK_PERIOD_MS));
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

void PORTD_IRQHandler(void) {

	if(GPIO_ReadPinInput(GPIOD, SW1)){
		printf("Botão 1 pressionado!");

		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

		PORT_ClearPinsInterruptFlags(PORTD, (1 << SW1));

		xSemaphoreGiveFromISR(drvButtonSem, &xHigherPriorityTaskWoken);

		portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
	}
}

void PORTA_IRQHandler(void){
	if(GPIO_ReadPinInput(GPIOA, SW2)){
		printf("Botão 2 pressionado!");

		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

		PORT_ClearPinsInterruptFlags(PORTA, (1 << SW2));

		xSemaphoreGiveFromISR(drvButtonSem, &xHigherPriorityTaskWoken);

		portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
	}
}

int main(void) {

	// Habilitando o clock das portas
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);

	// Inicializando semaforo
	vSemaphoreCreateBinary(drvButtonSem);
	xSemaphoreTake(drvButtonSem, 0);

	// Inicializando os botões
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