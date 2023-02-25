/*
 * OS.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef OS_H_
#define OS_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include <avr/io.h>
#include "../../../../Library/CLK.h"
#include <util/delay.h>
#include "../../../HAL/Communication Module/UART Interface/Includes/UART_Interface.h"
#include "OS_Cfg.h"

#if Mode == MASTER

#include "../../../HAL/IO Module/Potentiometer/Includes/Potentiometer.h"

#elif Mode == SLAVE

#include "../../../MCAL/DIO/Includes/DIO.h"
#include "../../../HAL/IO Module/DC Motor/Includes/DC_Motor.h"

#endif
/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/
#if Mode == MASTER

#define LOWER_THRESHOLD		(256)
#define MIDDLE_THRESHOLD	(512)
#define HIGHER_THRESHOLD	(768)

#define BACK	(0<<0)
#define FRONT	(1<<0)
#define SLOW	(0<<1)
#define FAST	(1<<1)
#define LEFT	(1<<2)
#define RIGHT	(1<<3)
#define STOP	(0xF)

#elif Mode == SLAVE

#define BACK_SLOW			(0x0)
#define FRONT_SLOW			(0X1)

#define BACK_FAST			(0X2)
#define FRONT_FAST			(0X3)

#define BACK_SLOW_LEFT		(0X4)
#define FRONT_SLOW_LEFT		(0X5)

#define BACK_FAST_LEFT		(0X6)
#define FRONT_FAST_LEFT		(0x7)

#define BACK_SLOW_RIGHT		(0X8)
#define FRONT_SLOW_RIGHT	(0X9)

#define BACK_FAST_RIGHT		(0XA)
#define FRONT_FAST_RIGHT	(0XB)

#define STOP				(0XF)
#define SLOWSPEED			(128)
#define FASTSPEED			(255)

#endif
/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void Scheduler_Start (void);

#endif /* OS_H_ */