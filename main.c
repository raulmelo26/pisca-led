/*
 * pisca_lec.c
 *
 * Created: 14/12/2017 16:36:51
 * Author : raulmelo-trix
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include "74hc595.h"
#include "io.h"
#include "usart.h"
#include "ibutton.h"
#include "calamp_tracker.h"
#include "adc.h"
#include "timer0.h"

int main(void) {

	io_init();
	
	HC595_init();
	HC595_write(HC595_Cleared);
	HC595_setPin(0);
	HC595_setPin(1);
	HC595_setPin(HC595_S0);
	HC595_setPin(HC595_S2);

	USART1_Init(BAUD_115200);
	
	adc_setPrescaler(ADC_CLOCK_DIV16);
	adc_setReference(VCC);
	adc_enable();
	
	timer0_init();
	
	sei();
	timerCount = 0;
	while(1) {
		HC595_setPin(HC595_S3);
		_delay_ms(1000);
		HC595_clrPin(HC595_S3);
		_delay_ms(1000);
	}
}

