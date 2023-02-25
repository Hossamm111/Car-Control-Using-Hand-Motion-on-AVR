/*
 * UART_Interface.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/UART_Interface.h"

/*******************************************************************************
 *								Functions                                      *
 *******************************************************************************/

void UARTCom_Init (void)
{
	UART_Init();
}

void UARTSend_Message (uint8 Msg)
{
	UART_TxChar(Msg);
}

uint8 UARTReceive_Message (void)
{
	return UART_RxChar();
}

void UARTSend_String (uint16* Str)
{
	UART_SendString(Str);
}