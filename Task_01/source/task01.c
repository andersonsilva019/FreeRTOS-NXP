/*
 * Pratica 01 - Acender dois led(Verde e vermelho) com tempo de dalay diferente;
 *
 * Deve criar uma task para ligar e desligar o led verde;
 * Deve criar uma task para ligar e desligar o led vermelhor;
 * */

#include "FreeRTOS.h"
#include "task.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"

void highLedGreen(){
	PORTD->PCR[5] |= (1 << 8);
	GPIOD->PDDR |= (1 << 5);
	GPIOD->PTOR |= (1 << 5);
}

void highLedRed(){
	PORTE->PCR[31] |= (1 << 8);
	GPIOE->PDDR |= (1 << 31);
	GPIOE->PTOR |= (1 << 31);
}

void taskLedGreen(void *pvParameters){
	while (true) {
		highLedGreen();
		vTaskDelay(5000 / portTICK_PERIOD_MS);
	}
}

void taskLedRed(void *pvParameters){
	while (true) {
		highLedRed();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}


int main(void){
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	/* create task 1 */
	xTaskCreate(taskLedGreen, "TaskLedGreen", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	/* create task 2 */
	xTaskCreate(taskLedRed, "TaskLedRed", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	/* start the scheduler */
	vTaskStartScheduler();

	while(true){} /* should never reach here! */
}

