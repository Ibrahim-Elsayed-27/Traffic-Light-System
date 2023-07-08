/*
 * DIO_program.c
 *
 *  Author: himah
 */ 


#include "DIO_interface.h"
#include "../../Utilities/STD_Types.h"

/* pin init DDRx-->BITx-->low if input and high if output*/
enum function_check pin_init(uint8 port_id,uint8 pin_id,uint8 direction){
	switch (direction){
		case OUTPUT:
			switch (port_id){
				
				case PORTA:
					SET_BIT(DDRA_REG,pin_id);
					break;
					
				case PORTB:
					SET_BIT(DDRB_REG,pin_id);
					break;
				
				case PORTC:
					SET_BIT(DDRC_REG,pin_id);
					break;
				
				case PORTD:
					SET_BIT(DDRD_REG,pin_id);
					break;
				default:
					return ERROR;
			}
			break;
			
			
		case INPUT:
			switch (port_id){
				
				case PORTA:
					CLR_BIT(DDRA_REG,pin_id);
					break;
				
				case PORTB:
					CLR_BIT(DDRB_REG,pin_id);
					break;
				
				case PORTC:
					CLR_BIT(DDRC_REG,pin_id);
					break;
				
				case PORTD:
					CLR_BIT(DDRD_REG,pin_id);
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
/* pin write PORTx-->BITX-->High if on and LOW if off*/
enum function_check pin_write(uint8 port_id,uint8 pin_id,uint8 pin_value){
	switch (pin_value){
		case HIGH:
		switch (port_id){
			
			case PORTA:
			SET_BIT(PORTA_REG,pin_id);
			break;
			
			case PORTB:
			SET_BIT(PORTB_REG,pin_id);
			break;
			
			case PORTC:
			SET_BIT(PORTC_REG,pin_id);
			break;
			
			case PORTD:
			SET_BIT(PORTD_REG,pin_id);
			break;
			
			default:
				return ERROR;
		}
		break;
		
		
		case LOW:
		switch (port_id){
			
			case PORTA:
			CLR_BIT(PORTA_REG,pin_id);
			break;
			
			case PORTB:
			CLR_BIT(PORTB_REG,pin_id);
			break;
			
			case PORTC:
			CLR_BIT(PORTC_REG,pin_id);
			break;
			
			case PORTD:
			CLR_BIT(PORTD_REG,pin_id);
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

/* pin read  PINx-->BITx-->change the value of given adress according to BITX state*/
enum function_check pin_read(uint8 port_id,uint8 pin_id,uint8*pin_value){
		switch (port_id){
			case PORTA:
			*pin_value = GET_BIT(PINA_REG,pin_id);
			break;
			
			case PORTB:
			*pin_value = GET_BIT(PINB_REG,pin_id);
			break;
			
			case PORTC:
			*pin_value = GET_BIT(PINC_REG,pin_id);
			break;
			
			case PORTD:
			*pin_value = GET_BIT(PIND_REG,pin_id);
			break;
			default:
				return ERROR;
		}
		return FINE;
}
/* pin toggle  PORTx-->BITx-->toggle BITX state*/
enum function_check pin_toggle(uint8 port_id,uint8 pin_id){

		switch (port_id){
			
			case PORTA:
			TOG_BIT(PORTA_REG,pin_id);
			break;
			
			case PORTB:
			TOG_BIT(PORTB_REG,pin_id);
			break;
			
			case PORTC:
			TOG_BIT(PORTC_REG,pin_id);
			break;
			
			case PORTD:
			TOG_BIT(PORTD_REG,pin_id);
			break;
			default:
				return ERROR;
		}
		return FINE;
		
		

}