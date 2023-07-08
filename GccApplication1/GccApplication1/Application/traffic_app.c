/*
 * traffic_app.c
 *
 * Created: 1/28/2023 1:16:04 AM
 *  Author: himah
 */ 


#include "traffic_app.h"

/*initialize all the used drivers for the desired setup
3 leds -> Cars -->PORTA --> PIN0,PIN1,PIN2
3 leds -> People -->PORTB --> PIN0,PIN1,PIN2
interrupt switch --> PORTD --> PIN2
external_interrupt --> external_0 --> rising edge --> enable global interrupt --> set the ISR function
*/
void traffic_init(){
	led_init(cars_leds_port,cars_green_pin);
	led_init(cars_leds_port,cars_yellow_pin);
	led_init(cars_leds_port,cars_red_pin);
	
	led_init(people_leds_port,people_green_pin);
	led_init(people_leds_port,people_yellow_pin);
	led_init(people_leds_port,people_red_pin);

	switch_init(switch_port,switch_pin);
	external_interrupt_setup(external_0,rising_edge,ex_interrupt_mode);
	external_interrupt_Enable(external_0);
}

/*Turning off all leds instantaneously to start the normal mode*/
void leds_off(){
		led_off(cars_leds_port,cars_yellow_pin);
		led_off(cars_leds_port,cars_red_pin);
		led_off(cars_leds_port,cars_green_pin);
		
		
		led_off(people_leds_port,cars_yellow_pin);
		led_off(people_leds_port,cars_green_pin);
		led_off(people_leds_port,cars_red_pin);
}


/*the normal mode function 
blinking yellow for 5 seconds --> car`s green, people`s red --> yellow again --> car`s red, people`s green
*/
void normal_mode(void){
	while(1){
					
					leds_off();
					//car`s yellow
					led_on(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
	
					led_off(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
	
					led_on(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
						led_off(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
	
					led_on(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
	
					led_off(cars_leds_port,cars_yellow_pin);
	
					//Car`s green 
					led_on(cars_leds_port,cars_green_pin);
					timer_0_delay(1024,5.0);
					led_off(cars_leds_port,cars_green_pin);
					
					
					//car`s yellow
					led_on(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
					
					led_off(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
					
					led_on(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
					led_off(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
					
					led_on(cars_leds_port,cars_yellow_pin);
					timer_0_delay(1024,1.0);
					
					led_off(cars_leds_port,cars_yellow_pin);


	
					//car`s red
					led_on(cars_leds_port,cars_red_pin);
					timer_0_delay(1024,5.0);

	}
}

/*function called in the ISR routine
Case0 --> called when car`s red is on-->  car`s red and people`s green remain on for 5 seconds
Case1 --> called when car`s red or green are on --> yellow for 5 seconds then car`s red and people`s green remain on for 5 seconds
*/
void ex_interrupt_routine(){

	switch(mode){
		case 0:
				leds_off();
				led_on(cars_leds_port,cars_red_pin);
				led_on(people_leds_port,people_green_pin);
				timer_0_delay(1024,5.0);
				break;
		case 1:
				leds_off();
				led_on(cars_leds_port,cars_yellow_pin);
				led_on(people_leds_port,people_yellow_pin);
				timer_0_delay(1024,1.0);
				
				led_off(cars_leds_port,cars_yellow_pin);
				led_off(people_leds_port,cars_yellow_pin);
				timer_0_delay(1024,1.0);
				
				led_on(cars_leds_port,cars_yellow_pin);
				led_on(people_leds_port,people_yellow_pin);
				timer_0_delay(1024,1.0);
				
				led_off(cars_leds_port,cars_yellow_pin);
				led_off(people_leds_port,cars_yellow_pin);
				timer_0_delay(1024,1.0);
				
				led_on(cars_leds_port,cars_yellow_pin);
				led_on(people_leds_port,people_yellow_pin);
				timer_0_delay(1024,1.0);
				
				led_off(cars_leds_port,cars_yellow_pin);
				led_off(people_leds_port,cars_yellow_pin);
				
				
				led_on(cars_leds_port,cars_red_pin);
				led_on(people_leds_port,people_green_pin);
				timer_0_delay(1024,5.0);
				break;

	}
}

/*
ISR Routine
get the portA status then set the mode according to it
call the routine of leds 
program counter to start from the first
*/
void ex_interrupt_mode(){
	uint8 leds_state=PORTA_REG;
	leds_state = leds_state & 0b00000111;
	
	if(leds_state==4){
			mode=0;
	}
	else{
			mode=1;
	}

	ex_interrupt_routine();
	goto *0x00;
	//
}