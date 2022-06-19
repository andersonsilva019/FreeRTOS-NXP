/*
 * Pratica 04 - Passando parâmetro para a função da task;
 *
 * */

#include "FreeRTOS.h"
#include "task.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"

#define CODE_LED_GREEN 1
#define CODE_LED_RED 2


TaskHandle_t ledGreenHandler;
TaskHandle_t ledRedHandler;

void highLedGreen(){
	PORTD->PCR[5] |= (1 << 8);
	GPIOD->PDDR |= (1 << 5);
	GPIOD->PCOR |= (1 << 5);
}

void lowLedGreen(){
	PORTD->PCR[5] |= (1 << 8);
	GPIOD->PDDR |= (1 << 5);
	GPIOD->PSOR |= (1 << 5);
}

void highLedRed(){
	PORTE->PCR[31] |= (1 << 8);
	GPIOE->PDDR |= (1 << 31);
	GPIOE->PCOR |= (1 << 31);
}

void lowLedRed(){
	PORTE->PCR[31] |= (1 << 8);
	GPIOE->PDDR |= (1 << 31);
	GPIOE->PSOR |= (1 << 31);
}

void controlHighLedGreen(int qtd){
	int counter = qtd;

	while(true){
		if(counter > 0){
			highLedGreen();
			vTaskDelay(1000 / portTICK_PERIOD_MS);
			--counter;

			lowLedGreen();
			vTaskDelay(1000 / portTICK_PERIOD_MS);
		}else{
			highLedGreen();
			vTaskDelay(250 / portTICK_PERIOD_MS);

			lowLedGreen();
			vTaskDelay(250 / portTICK_PERIOD_MS);
		}
	}
}

void controlHighLedRed(int qtd){
	int counter = qtd;

	while(true){

		if(counter > 0){
			highLedRed();
			vTaskDelay(1000 / portTICK_PERIOD_MS);
			--counter;

			lowLedRed();
			vTaskDelay(1000 / portTICK_PERIOD_MS);
		}else{
			highLedRed();
			vTaskDelay(250 / portTICK_PERIOD_MS);

			lowLedRed();
			vTaskDelay(250 / portTICK_PERIOD_MS);
		}


	}
}

void taskLedGreen(void *pvParameters){
	while (true) {
		controlHighLedGreen(*((int*) pvParameters));
	}
}

void taskLedRed(void *pvParameters){
	while (true) {
		controlHighLedRed(*((int*) pvParameters));
	}
}

void vTaskCreateLed(int led, int* counter){
	if(led == CODE_LED_GREEN){
		xTaskCreate(taskLedGreen, "TaskLedGreen", configMINIMAL_STACK_SIZE, counter, 1, &ledGreenHandler);
	}else if(led == CODE_LED_RED){
		xTaskCreate(taskLedRed, "TaskLedRed", configMINIMAL_STACK_SIZE, counter, 1, &ledRedHandler);
	}else{
		return;
	}
}


int main(void){

	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	int counter_led_green = 3;
	int counter_led_red = 5;

	vTaskCreateLed(CODE_LED_GREEN, &counter_led_green);

	vTaskCreateLed(CODE_LED_RED, &counter_led_red);

	/* start the scheduler */
	vTaskStartScheduler();

	while(true){} /* should never reach here! */
}

