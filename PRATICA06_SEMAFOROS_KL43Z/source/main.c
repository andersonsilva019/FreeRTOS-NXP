#include <stdio.h>
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "led_control.h"
#include "button_control.h"

/* Define the queue parameters. */
#define QUEUE_LENGTH 1
#define QUEUE_ITEM_SIZE sizeof(LedInfo)

SemaphoreHandle_t drvButtonSem = NULL;

void PORTC_PORTD_IRQHandler(void){

	// Verificando se o SW1 gerou interrupção
	if(SW_01_PORT->ISFR & (1 << SW1_PIN)){
		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

		// Limpando flag de interrupção do SW1
		SW_01_PORT->ISFR |= (1 << SW1_PIN);

		// Liberando o semaforo
		if(xSemaphoreGiveFromISR(drvButtonSem, &xHigherPriorityTaskWoken) == pdTRUE){
			printf("Semaforo liberado pelo Sw1! \n");
		}

		portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);

	// Verificando se o SW2 gerou interrupção
	}else if(SW_02_PORT->ISFR & (1 << SW2_PIN)){
		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

		// Limpando flag de interrupção
		SW_02_PORT->ISFR |= (1 << SW2_PIN);

		// Liberando semaforo
		if(xSemaphoreGiveFromISR(drvButtonSem, &xHigherPriorityTaskWoken) == pdTRUE){
			printf("Semaforo liberado pelo Sw2! \n");
		}

		portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);

	}
}

void taskLed(void *pvParameters) {
	QueueHandle_t ledQueue = (QueueHandle_t) pvParameters;

	LedInfo led;

	for(;;) {
		// Recebendo dados da fila
		if(xQueueReceive(ledQueue, &led, portMAX_DELAY) != pdPASS){

			printf("Nenhum dado foi recebido da fila! \n");

		}else{
			/* Realiza o processo de ligar ou desligar o LED de acordo
			 * com o comando recebido via fila.
			 */
			drvLedsSet(led.num, led.status);
		}

	}
}


void taskButton(void *pvParameters){

	QueueHandle_t ledQueue = (QueueHandle_t) pvParameters;

	LedInfo led;
	led.status = OFF;
	led.num = LED_RED;

	for (;;) {
		if (drvButtonsSW1Pressed() && led.status == OFF) {

			led.status = ON;

			/* Enviando informação para fila apenas se o semaforo estiver liberado
			 * Se o semaforo não estiver disponível espere 250ms para ver se fica livre.
			 */

			if(xSemaphoreTake(drvButtonSem, (250 / portTICK_PERIOD_MS)) == pdTRUE){

				xQueueSendToBack(ledQueue, &led, portMAX_DELAY);

				xSemaphoreGive(drvButtonSem);

			}else{
				printf("Opss... O LED não pode ser ligado devido ao semaforo não ter sido liberado! \n");
			}
		}else if (drvButtonsSW2Pressed() && led.status == ON) {

			led.status = OFF;

			/* Enviando informação para fila apenas se o semaforo estiver liberado
			 * Se o semaforo não estiver disponível espere 250ms para ver se fica livre.
			 */
			if(xSemaphoreTake(drvButtonSem, (250 / portTICK_PERIOD_MS)) == pdTRUE){

				xQueueSendToBack(ledQueue, &led, portMAX_DELAY);

				xSemaphoreGive(drvButtonSem);

			}else{
				printf("Opss... O LED não pode ser desligado devido ao semaforo não ter sido liberado! \n");
			}
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

int main(void) {

	// Habilitando o clock do PortD e PortE
	SIM->SCGC5 |= (1 << 12) | (1 << 13);

	//Criando semaforo
	drvButtonSem = xSemaphoreCreateBinary();

	if(drvButtonSem == NULL){
		printf("Não há heap do FreeRTOS suficiente para alocação do semaforo! \n");
		return 0;
	}

	// Inicializando os botões
	initButtons();

	// Criando um fila
	QueueHandle_t ledQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE);

	if(ledQueue == NULL){
		printf("The queue could not be created. \n");
		return 0;
	}

	NVIC_EnableIRQ(PORTC_PORTD_IRQn);

	/* create leds task */
	xTaskCreate(taskLed, "TaskLed", configMINIMAL_STACK_SIZE, (void *)ledQueue, 1, NULL);

	/* create buttons task */
	xTaskCreate(taskButton, "TaskButton", configMINIMAL_STACK_SIZE, (void *)ledQueue, 1, NULL);

	/* start the scheduler */
	vTaskStartScheduler();

	while(true){} /* should never reach here! */
    return 0 ;
}
