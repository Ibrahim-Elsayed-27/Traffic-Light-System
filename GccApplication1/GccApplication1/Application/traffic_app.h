/*
 * traffic_app.h
 *
 * Created: 1/28/2023 1:15:51 AM
 *  Author: himah
 */ 


#ifndef TRAFFIC_APP_H_
#define TRAFFIC_APP_H_

#include "../Utilities/STD_Types.h"
#include "../EUCAL/INTERRUPT/INTERUUPT.h"
#include "../EUCAL/LED/led.h"
#include "../EUCAL/SWITCH/switch.h"
#include "../EUCAL/TIMER/DELAY.h"

//variable to handle modes when interrupt happens
uint8 mode;

/*Macros for ports and pins of cars and people leds*/
#define cars_leds_port  PORTA
#define people_leds_port PORTB

#define cars_green_pin PIN0 
#define cars_yellow_pin PIN1
#define cars_red_pin PIN2

#define people_green_pin PIN0
#define people_yellow_pin PIN1
#define people_red_pin PIN2

/*macros for external interrupt switch*/
#define switch_port PORTD
#define switch_pin PIN2


/* PROTOTYPES OF Application FUNCTIONS */
void traffic_init();
void normal_mode(void);
void ex_interrupt_mode();
void ex_interrupt_routine();
void leds_off();


#endif /* TRAFFIC_APP_H_ */