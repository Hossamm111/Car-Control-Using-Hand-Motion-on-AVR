/*
 * Potentiometer.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/Potentiometer.h"

/*******************************************************************************
 *                              Functions									   *
 *******************************************************************************/

void Potentiometer_Init (void)
{
	ADC_Init();
}

uint16 Potentiometer_Read (ADC_Channel Channel)
{
	return ADC_READ(Channel);
}