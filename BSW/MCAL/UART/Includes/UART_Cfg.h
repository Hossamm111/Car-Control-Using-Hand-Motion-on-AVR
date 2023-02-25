/*
 * UART_Cfg.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

/*******************************************************************************
 *								Module Configurations                          *
 *******************************************************************************/

#define UART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 16UL))) - 1)

#endif /* UART_CFG_H_ */