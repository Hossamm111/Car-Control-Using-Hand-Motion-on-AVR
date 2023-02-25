/*
 * ADC.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

#ifndef ADC_H_
#define ADC_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../../../../Library/BIT_MATH.h"
#include "../../../../Library/STD_Types.h"
#include "ADC_HW.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void   ADC_Init (void);
uint16 ADC_READ (ADC_Channel Channel);

#endif /* ADC_H_ */