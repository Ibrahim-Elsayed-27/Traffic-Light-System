/*
 * timer_interface.h
 *
 * Created: 1/26/2023 3:13:09 AM
 *  Author: himah
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#include "../../Utilities/STD_Types.h"

/*macro for tick time*/
#define TCPU 1/1000000





/*MACROS OF ALL TIMER REGISTERS THAT WE WILL NEED */
#define TCCR0 *((volatile uint8*)0x53)
#define TCNT0 *((volatile uint8*)0x52)
#define TIFR *((volatile uint8*)0x58)

/* MACROS FOR PIN ID */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

/* PROTOTYPES OF DIO FUNCTIONS */
enum function_check  timer_0_normal_start(unsigned int prescalar);
void timer_0_normal_init();
void timer_0_normal_stop();
unsigned int timer_0_normal_initial_value_sec(long double prescalar,long double delay_value);



#endif /* TIMER_INTERFACE_H_ */