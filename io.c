/*
 * GccApplication1.c
 *
 * Created: 20/11/2017 17:14:45
 * Author : admin
 */ 
#include "io.h"

void io_init() {

	IO_ED0_PullUp_Enable();
	IO_ED1_PullUp_Enable();
	IO_ED2_PullUp_Enable();
	
	IO_setup_ED0_Input();
	IO_setup_ED2_Input();
	
	PUEC |= (1<<2);
}

uint16_t io_getOutputs() {
	
	uint16_t outputs = 0; // No output is being used
	return outputs;
}

uint16_t io_getInputs() {
	
	uint8_t port1State = (PINA & (1<<PORTA2))? 1 : 0;
	uint8_t port2State = (PINA & (1<<PORTA0))? 1 : 0;
	
	return (((uint16_t) port2State << 1) | port1State);
}

