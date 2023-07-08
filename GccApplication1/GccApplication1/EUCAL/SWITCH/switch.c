/*
 * switch.c
 *
 * Created: 1/19/2023 8:53:52 PM
 *  Author: himah
 */ 
#include "switch.h"
/*initialize the pin as input*/
enum function_check switch_init(uint8 port_id,uint8 pin_id){
	enum function_check check=pin_init(port_id,pin_id,INPUT);
	return check;
}
/*change the value of the given adress according to the pin status */
enum function_check switch_read(uint8 port_id,uint8 pin_id,uint8 *pin_value){
	enum function_check check=pin_read(port_id,pin_id,pin_value);
	return check;
}