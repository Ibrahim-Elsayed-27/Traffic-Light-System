/*
 * INTERUUPT.h
 *
 * Created: 1/31/2023 11:48:55 PM
 *  Author: himah
 */ 


#ifndef INTERUUPT_H_
#define INTERUUPT_H_
#include "../../MCAL/EXTERNAL_INTERR/external_interrupt.h"


enum function_check external_interrupt_setup(enum interrupt_number int_no,enum interrupt_mode int_mode,void (*callback) (void));
enum function_check external_interrupt_Enable(enum interrupt_number int_no);
enum function_check external_interrupt_disable(enum interrupt_number int_no);

#endif /* INTERUUPT_H_ */