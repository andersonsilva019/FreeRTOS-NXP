/**
 * Como as duas tarefas tem o mesmo objetivo (piscar um led), altere-as para
 * compartilharem o mesmo código da tarefa. Para isso, a aplicação deverá passar
 * como parâmetro para a função xTaskCreate() o led a ser piscado.
 *
 * Crie uma outra tarefa para piscar o led AMARELO apenas três vezes e finalizar sua
 * execução. Neste caso, a tarefa deverá chamar no fim a função vTaskDelete(). Não esqueça
 * também de verificar se a opção INCLUDE_vTaskDelete esta habilitada no arquivo de
 * configuração FreeRTOSConfig.h;
 */

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

	while(counter > 0){
		highLedGreen();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		--counter;

		lowLedGreen();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
	vTaskDelete(ledGreenHandler);
}

void controlHighLedRed(int qtd){
	int counter = qtd;

	while(counter > 0){
		highLedRed();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
		--counter;

		lowLedRed();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
	vTaskDelete(ledRedHandler);
}

void taskLedGreen(void *pvParameters){
	while (true) {
		controlHighLedGreen(3);
	}
}

void taskLedRed(void *pvParameters){
	while (true) {
		controlHighLedRed(5);
	}
}

void vTaskCreateLed(int led){
	if(led == CODE_LED_GREEN){
		xTaskCreate(taskLedGreen, "TaskLedGreen", configMINIMAL_STACK_SIZE, NULL, 1, &ledGreenHandler);
	}else if(led == CODE_LED_RED){
		xTaskCreate(taskLedRed, "TaskLedRed", configMINIMAL_STACK_SIZE, NULL, 1, &ledRedHandler);
	}else{
		return;
	}
}


int main(void){

	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);

	vTaskCreateLed(CODE_LED_GREEN);

	vTaskCreateLed(CODE_LED_RED);

	/* start the scheduler */
	vTaskStartScheduler();

	while(true){} /* should never reach here! */
}

