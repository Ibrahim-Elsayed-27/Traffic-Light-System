/*
 * external_interrupt_0.h
 *
 * Created: 1/27/2023 11:59:23 PM
 *  Author: himah
 */ 


#ifndef EXTERNAL_INTERRUPT_0_H_
#define EXTERNAL_INTERRUPT_0_H_

#include "../../Utilities/STD_Types.h"







/*MACROS OF ALL TIMER REGISTERS THAT WE WILL NEED */
#define MCUCR *((volatile uint8*)0x55)
#define MCUCSR *((volatile uint8*)0x54)
#define GICR *((volatile uint8*)0x5B)
#define GIFR *((volatile uint8*)0x5A)

/* MACROS FOR PIN ID */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

/*macros for global interrupt enable and disable in assembly language*/
#define enable_global_interrupt __asm__ __volatile__ ("sei" ::: "memory")
#define disable_global_interrupt __asm__ __volatile__ ("cli" ::: "memory")

/*enums for external interrupts number and modes*/
typedef enum interrupt_number{external_0,external_1,external_2};
typedef enum interrupt_mode{low_level,any_change,failling_edge,rising_edge};
	

/* PROTOTYPES OF EXTERNAL INTERRUPTS FUNCTIONS */
enum function_check external_interrupt_init(enum interrupt_number int_no,enum interrupt_mode int_mode);
enum function_check external_interrupt_callback(enum interrupt_number int_no, void (*callback) (void));
#endif /* EXTERNAL_INTERRUPT_0_H_ */