/*
 * GccApplication1.c
 *
 * Created: 20/11/2017 17:14:45
 * Author : admin
 */ 

#ifndef IO_H_
#define IO_H_

#include <avr/io.h>
#include "tx006_IO.h"

void io_init();
uint16_t io_getOutputs();
uint16_t io_getInputs();

#endif /* IO_H_ */
