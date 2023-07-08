/*
 * External_interrupt_0.c
 *
 * Created: 1/27/2023 11:59:47 PM
 *  Author: himah
 */ 

#include "external_interrupt.h"
#include <avr/interrupt.h>


/*initialize the isr functions for each interrupt to null */ 
static void (*external_interrupt_0_callback) (void) = NULL;
static void (*external_interrupt_1_callback) (void) = NULL;
static void (*external_interrupt_2_callback) (void) = NULL;

/*initializing the external interrupt given the external interrupt number and mode
external_0 --> mode --> MCUCR --> BIT0,BIT1
external_1 --> mode --> MCUCR --> BIT2,BIT3
external_1 --> mode --> MCUCSR --> BIT6
*/
enum function_check external_interrupt_init(enum interrupt_number int_no,enum interrupt_mode int_mode){
	
	switch(int_no){
		case external_0:
			switch(int_mode){
				case low_level:
					CLR_BIT(MCUCR,BIT0);
					CLR_BIT(MCUCR,BIT1);
					break;
				case any_change:
					SET_BIT(MCUCR,BIT0);
					CLR_BIT(MCUCR,BIT1);
					break;
				case failling_edge:
					CLR_BIT(MCUCR,BIT0);
					SET_BIT(MCUCR,BIT1);
					break;
				case rising_edge:
					SET_BIT(MCUCR,BIT0);
					SET_BIT(MCUCR,BIT1);
					break;
				default:
					return ERROR;
			}
			break;
		case external_1:
			switch(int_mode){
				case low_level:
					CLR_BIT(MCUCR,BIT2);
					CLR_BIT(MCUCR,BIT3);
					break;
				case any_change:
					SET_BIT(MCUCR,BIT2);
					CLR_BIT(MCUCR,BIT3);
					break;
				case failling_edge:
					CLR_BIT(MCUCR,BIT2);
					SET_BIT(MCUCR,BIT3);
					break;
				case rising_edge:
					SET_BIT(MCUCR,BIT2);
					SET_BIT(MCUCR,BIT3);
					break;
				default:
					return ERROR;
		}
			break;
		case external_2:
			switch(int_mode){
				case failling_edge:
					CLR_BIT(MCUCSR,BIT6);
					break;
				case rising_edge:
					SET_BIT(MCUCSR,BIT6);
					break;
				default:
					return ERROR;
			}
			break;
		default:
			return ERROR;
	
	}
	return FINE;
}


/*
Setting the callback function for a given interrupt and the corresponding function to be executed upon calling
*/
enum function_check external_interrupt_callback(enum interrupt_number int_no, void (*callback) (void) ){
	switch(int_no){
		case external_0:
			external_interrupt_0_callback=callback;
			break;
		case external_1:
			external_interrupt_1_callback=callback;
			break;
		case external_2:
			external_interrupt_2_callback=callback;
			break;
		default:
			return ERROR;
	}
	return FINE;
}

ISR(INT0_vect)
{
	external_interrupt_0_callback();
}
ISR(INT1_vect)
{
	external_interrupt_1_callback();
}
ISR(INT2_vect)
{
	external_interrupt_2_callback();
}