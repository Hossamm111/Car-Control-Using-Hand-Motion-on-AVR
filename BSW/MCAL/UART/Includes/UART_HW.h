/*
 * USART_HW.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

#ifndef UART_HW_H_
#define UART_HW_H_

/*******************************************************************************
 *							Module Hardware Definitions                        *
 *******************************************************************************/

#define UCSRA_REG (*(volatile uint8 *) 0x2B)
#define UCSRB_REG (*(volatile uint8 *) 0x2A)
#define UCSRC_REG (*(volatile uint8 *) 0x40)
#define UBRRH_REG (*(volatile uint8 *) 0x40)
#define UBRRL_REG (*(volatile uint8 *) 0x29)
#define UDR_REG   (*(volatile uint8 *) 0x2C)

/*******************************************************************************
 *								Module Definitions                             *
 *******************************************************************************/

#define UDRE_BIT	5
#define TXC_BIT		6
#define RXC_BIT		7

#define RXEN_BIT	4
#define TXEN_BIT	3

#define UCSZ0_BIT	1
#define USCZ1_BIT	2
#define URSEL_BIT	7

#define USBS_BIT	3

#endif /* UART_HW_H_ */