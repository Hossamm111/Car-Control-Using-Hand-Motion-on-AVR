/*
 * Potentiometer.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../../../../MCAL/ADC/Includes/ADC.h"
#include "Potentiometer_Cfg.h"

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void   Potentiometer_Init (void);
uint16 Potentiometer_Read (ADC_Channel Channel);

#endif /* POTENTIOMETER_H_ */