/*
 * timer_program.c
 *
 * Created: 1/26/2023 11:39:53 PM
 *  Author: himah
 */ 
#include "timer_interface.h"
#include <math.h>

/*initialize the timer0 by clearing the 3 lowest significant bits in TCCR0 Reg,
Also clear the timer_overflow flag
*/
void timer_0_normal_init(){
	CLR_BIT(TCCR0,BIT0);
	CLR_BIT(TCCR0,BIT1);
	CLR_BIT(TCCR0,BIT2);
	CLR_BIT(TIFR,BIT1);
}

/*start the timer0 according to the given prescalar the 3 lowest significant bits in TCRR0 are set*/
enum function_check  timer_0_normal_start(unsigned int prescalar){
	switch(prescalar){
		case 1:
			SET_BIT(TCCR0,BIT0);
			CLR_BIT(TCCR0,BIT1);
			CLR_BIT(TCCR0,BIT2);
			break;
		case 8:
			CLR_BIT(TCCR0,BIT0);
			SET_BIT(TCCR0,BIT1);
			CLR_BIT(TCCR0,BIT2);
			break;
		case 64:
			SET_BIT(TCCR0,BIT0);
			SET_BIT(TCCR0,BIT1);
			CLR_BIT(TCCR0,BIT2);
			break;
		case 256:
			CLR_BIT(TCCR0,BIT0);
			CLR_BIT(TCCR0,BIT1);
			SET_BIT(TCCR0,BIT2);
			break;
		case 1024:
			SET_BIT(TCCR0,BIT0);
			CLR_BIT(TCCR0,BIT1);
			SET_BIT(TCCR0,BIT2);
			break;
		default:
			return ERROR;
		
	}
	return FINE;
}
/*Stop the timer0 by clearing the 3 lowest significant bits in TCCR0 Reg,
Also clear the timer_overflow flag
*/
void timer_0_normal_stop(){
		CLR_BIT(TCCR0,BIT0);
		CLR_BIT(TCCR0,BIT1);
		CLR_BIT(TCCR0,BIT2);
		CLR_BIT(TIFR,BIT1);
}

/*Calculations for the initial value of TCNTO and the number of overflows needed to get the given delay in seconds */ 

unsigned int timer_0_normal_initial_value_sec(long double prescalar,long double delay_value){
	
	long double tick_time=prescalar*TCPU;
	long double max_delay=tick_time*256;
	long double overflows=trunc(delay_value/max_delay);
	TCNT0=(uint8)(256-(delay_value/tick_time)/overflows);
	return (unsigned int)overflows;
}
