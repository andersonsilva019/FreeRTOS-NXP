/*
 * Pratica 05 - ;
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

static unsigned long int idle_tick_counter = 0;
void vApplicationIdleHook(void)
{
	unsigned long int tick = xTaskGetTickCount();
	while (xTaskGetTickCount() == tick);
	idle_tick_counter++;
}

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

void taskLedGreen(void *pvParameters){
	while (true) {
		highLedGreen();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		lowLedGreen();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

void taskLedRed(void *pvParameters){

	TickType_t xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	while (true) {
		highLedRed();
		vTaskDelayUntil(&xLastWakeTime, 2500 / portTICK_PERIOD_MS);
		lowLedRed();
		vTaskDelayUntil(&xLastWakeTime, 2500 / portTICK_PERIOD_MS);
	}
}


int main(void){

	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	/* create task 1 */
	xTaskCreate(taskLedGreen, "TaskLedGreen", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

	/* create task 2 */
	xTaskCreate(taskLedRed, "TaskLedRed", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	/* start the scheduler */
	vTaskStartScheduler();

	while(true){} /* should never reach here! */
}

