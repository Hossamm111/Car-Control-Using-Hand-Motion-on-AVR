/*
 * DC_Motor.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/DC_Motor.h"

/*******************************************************************************
 *                              Functions									   *
 *******************************************************************************/

void DCMotor_Init(DC_Motor* DC, DIO_PortTypes I1, DIO_PortTypes I2, DIO_PortTypes EN)
{
	DC->IN1 = I1;
	DC->IN2 = I2;
	DC->ENA = EN;
}

void DCMotor_SetSpeed(DC_Motor DC, uint8 Motor_Speed)
{
	if (DC.ENA == DIO_ChannelD5)
		OCR1AH = Motor_Speed;
		
	else if(DC.ENA == DIO_ChannelD4)
		OCR1BH = Motor_Speed;
		
	else
	{
		/* do nothing */
	}
}

void DCMotor_SetDirection(DC_Motor DC,uint8 Motor_Direction)
{
	switch(Motor_Direction)
	{
		case CW:
		DIO_WriteChannel(DC.IN1, STD_Low);
		DIO_WriteChannel(DC.IN2, STD_High);
		break;
		
		case CCW:
		DIO_WriteChannel(DC.IN1, STD_High);
		DIO_WriteChannel(DC.IN2, STD_Low);
		break;
	}
}

void DCMotor_Stop(DC_Motor DC)
{
	DIO_WriteChannel(DC.IN1, STD_Low);
	DIO_WriteChannel(DC.IN2, STD_Low);
}