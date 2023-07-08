/*
 * led.h
 *
 * Created: 1/19/2023 8:28:53 PM
 *  Author: himah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../Utilities/STD_Types.h"



/* PROTOTYPES OF LEDS FUNCTIONS */
enum function_check led_init(uint8 port_id,uint8 pin_id);
enum function_check led_on(uint8 port_id,uint8 pin_id);
enum function_check led_off(uint8 port_id,uint8 pin_id);
enum function_check led_toggle(uint8 port_id,uint8 pin_id);



#endif /* LED_H_ */