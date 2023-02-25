/*
 * OS.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/OS.h"

/*******************************************************************************
 *                              Functions                                      *
 *******************************************************************************/

#if Mode == MASTER

void Scheduler_Start (void)
{
	uint8 STATE;
	uint16 Front_Sensor, Back_Sensor, Left_Sensor, Right_Sensor;
	
	while(1)
	{
		STATE = 0;
		
		Front_Sensor = Potentiometer_Read (Sensor1);
		Back_Sensor  = Potentiometer_Read (Sensor2);
		Left_Sensor  = Potentiometer_Read (Sensor3);
		Right_Sensor = Potentiometer_Read (Sensor4);
		
		if (Front_Sensor > Back_Sensor)
		{
			STATE |= FRONT;
			
			if (Front_Sensor > HIGHER_THRESHOLD)
			{
				STATE |= FAST;
			}
			
			else if (Front_Sensor > LOWER_THRESHOLD )
			STATE &= SLOW;
			
			else
			STATE = STOP;
		}
		
		else
		{
			STATE &= BACK;
			
			if (Back_Sensor > HIGHER_THRESHOLD)
			STATE |= FAST;
			
			else if (Back_Sensor > LOWER_THRESHOLD )
			STATE &= SLOW;
			
			else
			STATE = STOP;
		}
		
		if (Left_Sensor > Right_Sensor)
		{
			if (Left_Sensor > MIDDLE_THRESHOLD)
			STATE |= LEFT;
			
			else
			{
				/* do nothing */
			}
		}
		
		else
		{
			if (Right_Sensor > MIDDLE_THRESHOLD)
			STATE |= RIGHT;
			
			else
			{
				/* do nothing */
			}
		}
		
		UARTSend_Message(STATE);
	}
}

#elif Mode == SLAVE

void Scheduler_Start (void)
{		
	DIO_Init();
	PWM_Init();
	
	DC_Motor Left_Motor, Right_Motor;
	
	DCMotor_Init(&Left_Motor, DIO_ChannelC3, DIO_ChannelC4, DIO_ChannelD5);
	DCMotor_Init(&Right_Motor, DIO_ChannelC5, DIO_ChannelC6, DIO_ChannelD4);
	
	uint8 Received_Msg;
	
	while(1)
	{
		Received_Msg = UARTReceive_Message();

		if(Received_Msg != STOP)
		{
			switch(Received_Msg)
			{
				case BACK_SLOW:

				DCMotor_SetDirection(Left_Motor,CCW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CCW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				
				break;
				
				case FRONT_SLOW:
				DCMotor_SetDirection(Left_Motor,CW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				
				break;
				
				case BACK_FAST:
				DCMotor_SetDirection(Left_Motor,CCW);
				DCMotor_SetSpeed(Left_Motor,FASTSPEED);
				
				DCMotor_SetDirection(Right_Motor,CCW);
				DCMotor_SetSpeed(Right_Motor,FASTSPEED);
				
				break;
				
				case FRONT_FAST:
				DCMotor_SetDirection(Left_Motor,CW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				break;
				
				case BACK_SLOW_LEFT:
				DCMotor_SetDirection(Left_Motor,CCW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED/2);
				
				DCMotor_SetDirection(Right_Motor,CCW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				break;
				
				case FRONT_SLOW_LEFT:
				DCMotor_SetDirection(Left_Motor,CW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED/2);
				
				DCMotor_SetDirection(Right_Motor,CW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				break;
				
				case BACK_FAST_LEFT:
				DCMotor_SetDirection(Left_Motor,CCW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CCW);
				DCMotor_SetSpeed(Right_Motor,FASTSPEED);
				break;
				
				case FRONT_FAST_LEFT:
				DCMotor_SetDirection(Left_Motor,CW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CW);
				DCMotor_SetSpeed(Right_Motor,FASTSPEED);
				break;
				
				case BACK_SLOW_RIGHT:
				DCMotor_SetDirection(Left_Motor,CCW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CCW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED/2);
				break;
				
				case FRONT_SLOW_RIGHT:
				DCMotor_SetDirection(Left_Motor,CW);
				DCMotor_SetSpeed(Left_Motor,SLOWSPEED);
				
				DCMotor_SetDirection(Right_Motor,CW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED/2);
				break;
				
				case BACK_FAST_RIGHT:
				DCMotor_SetDirection(Left_Motor,CCW);
				DCMotor_SetSpeed(Left_Motor,FASTSPEED);
				
				DCMotor_SetDirection(Right_Motor,CCW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				break;
				
				case FRONT_FAST_RIGHT:
				DCMotor_SetDirection(Left_Motor,CW);
				DCMotor_SetSpeed(Left_Motor,FASTSPEED);
				
				DCMotor_SetDirection(Right_Motor,CW);
				DCMotor_SetSpeed(Right_Motor,SLOWSPEED);
				break;
				
				default:
				DCMotor_Stop(Left_Motor);
				DCMotor_Stop(Right_Motor);
				break;
			}
		}
		
		else
		{
			DCMotor_Stop(Left_Motor);
			DCMotor_Stop(Right_Motor);
		}
	}
}

#endif