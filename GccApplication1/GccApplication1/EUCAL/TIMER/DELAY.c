/*
 * DELAY.c
 *
 * Created: 1/31/2023 11:35:31 PM
 *  Author: himah
 */ 

#include "DELAY.h"
/*Main function to call and take the delay value in seconds also the prescalar value to start the timer
1-start the timer0
2-call the initial_value function
3-start the time then wait till the overflow flag raised
4-stop the timer
*/
enum function_check timer_0_delay(unsigned int prescalar,long double delay_value){
	unsigned int overflows_counter=0;
	timer_0_normal_init();
	unsigned int overflows=timer_0_normal_initial_value_sec(prescalar,delay_value);
	enum function_check check= timer_0_normal_start(prescalar);
	switch(check){
		case ERROR:
		timer_0_normal_stop();
		return ERROR;
		case FINE:

		while(overflows_counter <= overflows){
			
			while((TIFR & (1<<0)) == 0);
			
			CLR_BIT(TIFR,BIT1);
			
			overflows_counter++;
		}
		break;
		
	}
	timer_0_normal_stop();
	return FINE;
	
}