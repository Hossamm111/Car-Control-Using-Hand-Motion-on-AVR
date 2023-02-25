/*
 * Timer_Interface.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "Timer_Private.h"
#include "Timer_Config.h"
#include "../../DIO/Includes/DIO.h"
#include "../../../../Library/BIT_MATH.h"
#include "../../../../Library/STD_Types.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *								Module Definitions                             *
 *******************************************************************************/

#define TIMER0_CHANNEL          0
#define TIMER1_CHANNEL          1
#define TIMER2_CHANNEL          2

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void Timer_Init(uint8);
void Timer_SetTime(uint8, uint32);
void Timer_Start(uint8);
void Timer_Stop(uint8);
void PWM_Init(void);
void PWM_SetDutyCycle(uint8, fint32);
void SetCallBack(uint8, void(*)(void));
void (*Timer0_CallBack) (void);
void (*Timer1_CallBack) (void);
void (*Timer2_CallBack) (void);

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
