/*
 * DIO_interface.h
 *
 *  Author: himah
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../Utilities/STD_Types.h"

/*MACROS OF ALL DIO REGISTERS THAT WE WILL NEED */

// PORTA REGISTER SUMMARY
#define PORTA_REG *((volatile uint8*)0x3B)
#define DDRA_REG  *((volatile uint8*)0x3A)
#define PINA_REG  *((volatile uint8*)0x39)


// PORTB REGISTER SUMMARY
#define PORTB_REG *((volatile uint8*)0x38)
#define DDRB_REG  *((volatile uint8*)0x37)
#define PINB_REG  *((volatile uint8*)0x36)


// PORTC REGISTER SUMMARY
#define PORTC_REG *((volatile uint8*)0x35)
#define DDRC_REG  *((volatile uint8*)0x34)
#define PINC_REG  *((volatile uint8*)0x33)


// PORTD REGISTER SUMMARY
#define PORTD_REG *((volatile uint8*)0x32)
#define DDRD_REG  *((volatile uint8*)0x31)
#define PIND_REG  *((volatile uint8*)0x30)

/* MACROS FOR PORT ID */
#define PORTA 'A'
#define PORTB 'B'
#define PORTC 'C'
#define PORTD 'D'

/* MACROS FOR PIN ID */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7



/* MACROS FOR PIN DIRECTION */

#define OUTPUT   0
#define INPUT	 1


/* MACROS FOR OUTPUT  */
#define HIGH   1
#define LOW    0



/* PROTOTYPES OF DIO FUNCTIONS */


enum function_check pin_init(uint8 port_id,uint8 pin_id,uint8 direction);
enum function_check pin_write(uint8 port_id,uint8 pin_id,uint8 pin_value);
enum function_check pin_read(uint8 port_id,uint8 pin_id,uint8*pin_value);
enum function_check pin_toggle(uint8 port_id,uint8 pin_id);



#endif /* DIO_INTERFACE_H_ */