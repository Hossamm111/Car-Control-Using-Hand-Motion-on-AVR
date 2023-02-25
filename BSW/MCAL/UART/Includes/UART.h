/*
 * USART.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef UART_H_
#define UART_H_

/*******************************************************************************
 *								File Includes                                  *
 *******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "../../../../Library/BIT_MATH.h"
#include "../../../../Library/STD_Types.h"
#include "../../../../Library/CLK.h"
#include "UART_HW.h"
#include "UART_Cfg.h"

/*******************************************************************************
 *								Function Prototypes                            *
 *******************************************************************************/

void  UART_Init		  (void);
uint8 UART_RxChar     (void);
void  UART_TxChar	  (uint8);
void  UART_SendString (uint16*);

#endif /* UART_H_ */