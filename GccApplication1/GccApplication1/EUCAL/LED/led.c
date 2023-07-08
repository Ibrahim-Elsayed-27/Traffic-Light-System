/*
 * led.c
 *
 * Created: 1/19/2023 8:29:06 PM
 *  Author: himah
 */ 
#include "led.h"

/*set the pin as output*/
enum function_check led_init(uint8 port_id,uint8 pin_id){

		enum function_check check=pin_init(port_id,pin_id,OUTPUT);
		return check;
}
/*write high*/
enum function_check led_on(uint8 port_id,uint8 pin_id){
	enum function_check check=pin_write(port_id,pin_id,HIGH);
	return check;
}
/*write low*/
enum function_check led_off(uint8 port_id,uint8 pin_id){
	enum function_check check=pin_write(port_id,pin_id,LOW);
	return check;
}
/*toggle led*/
enum function_check led_toggle(uint8 port_id,uint8 pin_id){
	enum function_check check=pin_toggle(port_id,pin_id);
	return check;
}