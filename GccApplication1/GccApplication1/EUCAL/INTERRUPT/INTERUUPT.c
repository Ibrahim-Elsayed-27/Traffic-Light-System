/*
 * INTERUUPT.c
 *
 * Created: 1/31/2023 11:49:16 PM
 *  Author: himah
 */ 

/*Enabling the corresponding interrupt from GICR Reg
external_0 --> GICR --> BIT6 --> High
external_1 --> GICR --> BIT7 --> High
external_2 --> GICR --> BIT5 --> High
*/
#include "INTERUUPT.h"
enum function_check external_interrupt_Enable(enum interrupt_number int_no){
	switch(int_no){
		case external_0:
		SET_BIT(GICR,BIT6);
		break;
		case external_1:
		SET_BIT(GICR,BIT7);
		break;
		case external_2:
		SET_BIT(GICR,BIT5);
		break;
		default:
		return ERROR;
	}
	return FINE;
}
/*Disabling the corresponding interrupt from GICR Reg
external_0 --> GICR --> BIT6 --> LOW
external_1 --> GICR --> BIT7 --> LOW
external_2 --> GICR --> BIT5 --> LOW
*/
enum function_check external_interrupt_disable(enum interrupt_number int_no){
	switch(int_no){
		case external_0:
		CLR_BIT(GICR,BIT6);
		break;
		case external_1:
		CLR_BIT(GICR,BIT7);
		break;
		case external_2:
		CLR_BIT(GICR,BIT5);
		break;
		default:
		return ERROR;
	}
	return FINE;
}

enum function_check external_interrupt_setup(enum interrupt_number int_no,enum interrupt_mode int_mode,void (*callback) (void)){
		enum function_check check1=external_interrupt_init(int_no,int_mode);
		enable_global_interrupt;
		enum function_check check2=external_interrupt_callback(int_no,callback);
		
		if (check1 == check2 && check1==FINE){
			return FINE;
		}else{
			return ERROR;
		}
	}