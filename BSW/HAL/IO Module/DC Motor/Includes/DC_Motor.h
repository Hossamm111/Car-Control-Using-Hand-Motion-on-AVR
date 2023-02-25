/*
 * DC_Motor.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../../../../MCAL/Timer/Includes/Timer_Interface.h"
#include "DC_Motor_Cfg.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef struct DC_Motor{
	
	DIO_ChannelTypes	IN1;
	DIO_ChannelTypes	IN2;
	DIO_ChannelTypes	ENA;
	
	}DC_Motor;

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void DCMotor_Init		 (DC_Motor*, DIO_PortTypes, DIO_PortTypes, DIO_PortTypes);
void DCMotor_SetSpeed	 (DC_Motor, uint8);
void DCMotor_SetDirection(DC_Motor, uint8);
void DCMotor_Stop		 (DC_Motor);


#endif /* DC_MOTOR_H_ */