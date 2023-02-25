/*
 * UART_Interface.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../../../../MCAL/UART/Includes/UART.h"

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void  UARTCom_Init			(void);
void  UARTSend_Message		(uint8);
uint8 UARTReceive_Message	(void);
void  UARTSend_String		(uint16*);

#endif /* UART_INTERFACE_H_ */