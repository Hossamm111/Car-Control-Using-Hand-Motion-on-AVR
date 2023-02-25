/*
 * BIT_MATH.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*******************************************************************************
 *                              BIT MATH MACROS                                *
 *******************************************************************************/

#define SET_BIT(REG,BIT)		(REG |= (1<<BIT) )
#define CLEAR_BIT(REG,BIT)		(REG &= ~(1<<BIT))
#define READ_BIT(REG,BIT)		(  (REG>>BIT)&1	 )
#define TOGGLE_BIT(REG,BIT)		(REG ^= (1<<BIT) )  
#define Write_Bit(REG,BIT,High_OR_Low)	(REG = High_OR_Low == 1 ?	( REG | (1<<BIT)) : ( REG & ~(1<<BIT)))

#endif /* BIT_MATH_H_ */