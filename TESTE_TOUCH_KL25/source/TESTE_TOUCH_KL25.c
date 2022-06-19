#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

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

/*****************************************************
 * 					MACROS
 *****************************************************/
#define TOUCH_OFFSET 550  // offset value to be subtracted
#define TOUCH_DATA ((TSI0->DATA) & 0xFFFF)//macro for extracting the count from data register

/*****************************************************
 * 					GLOBAL VARIABLES
 *****************************************************/

extern volatile uint32_t touch_value;


void Touch_Init(){

	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock
	TSI0->GENCS = TSI_GENCS_MODE(0u) | //operating in non-noise mode
								TSI_GENCS_REFCHRG(0u) | //reference oscillator charge and discharge value 500nA
								TSI_GENCS_DVOLT(0u) | //oscillator voltage rails set to default
								TSI_GENCS_EXTCHRG(0u) | //electrode oscillator charge and discharge value 500nA
								TSI_GENCS_PS(0u) |  // frequency clcok divided by one
								TSI_GENCS_NSCN(31u) | //scanning the electrode 32 times
								TSI_GENCS_TSIEN_MASK | //enabling the TSI module
								TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag
}

uint32_t Touch_Scan_LH(void){
	uint32_t scan = 0;
	TSI0->DATA = 	TSI_DATA_TSICH(10u);
	TSI0->DATA |= TSI_DATA_SWTS_MASK; //software trigger to start the scan
	while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK )) // waiting for the scan to complete 32 times
	;
	scan = TOUCH_DATA;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; //writing one to clear the end of scan flag

	return scan- TOUCH_OFFSET;
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

int main(void) {

	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);


	while(true){
		if(Touch_Scan_LH() > 10){
			highLedGreen();
		}
	} /* should never reach here! */
    return 0 ;
}
