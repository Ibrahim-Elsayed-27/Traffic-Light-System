/*
 * STD_Types.h
 *
 *  Author: himah
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char uint8;

typedef enum function_check{ERROR,FINE};

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7



#define SET_BIT(VAR,BITNO)     (VAR)|=(1<<(BITNO))
#define CLR_BIT(VAR,BITNO)     (VAR)&=~(1<<(BITNO))
#define TOG_BIT(VAR,BITNO)     (VAR)^=(1<<(BITNO))
#define GET_BIT(VAR,BITNO)     (((VAR)>>(BITNO)) & (0x01))





#define NULL ((volatile void*)0)


#endif /* STD_TYPES_H_ */