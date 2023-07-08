/*
 * switch.h
 *
 * Created: 1/19/2023 8:53:41 PM
 *  Author: himah
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "../../Utilities/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"


/* PROTOTYPES OF Switch FUNCTIONS */
enum function_check switch_init(uint8 port_id,uint8 pin_id);
enum function_check  switch_read(uint8 port_id,uint8 pin_id,uint8 *pin_value);



#endif /* SWITCH_H_ */