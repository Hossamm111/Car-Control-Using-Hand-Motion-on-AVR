/*
 * UART.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */

/*******************************************************************************
 *								File Includes                                  *
 *******************************************************************************/

#include "../Includes/UART.h"

/*******************************************************************************
 *								Functions                                      *
 *******************************************************************************/

void UART_Init (void)
{
	UCSRB_REG |= (1 << RXEN_BIT) | (1 << TXEN_BIT);							/* Turn on transmission and reception */
	UCSRC_REG |= (1 << URSEL_BIT) | (1 << UCSZ0_BIT) | (1 << USCZ1_BIT);	/* Use 8-bit character sizes */
	UBRRL_REG = BAUD_PRESCALE;												/* Load lower 8-bits of the baud rate value */
	UBRRH_REG = (BAUD_PRESCALE >> 8);										/* Load upper 8-bits*/
}

uint8 UART_RxChar (void)
{
	while (!(UCSRA_REG & (1<<RXC_BIT)));									/* Wait till data is received */
	return UDR_REG;															/* Return the byte*/
}

void UART_TxChar (uint8 message)
{
	while (! (UCSRA_REG & (1<<UDRE_BIT)));									/* Wait for empty transmit buffer*/
	UDR_REG = message;
}

void UART_SendString(uint16 *Str)
{
	uint8 counter = 0;
	
	while (Str[counter] != 0)												/* Send string till null */
	{
		UART_TxChar (Str[counter]);
		counter++;
	}
}