/*
 * DIO.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

#ifndef DIO_H_
#define DIO_H_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../../../../Library/BIT_MATH.h"
#include "../../../../Library/STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void DIO_WriteChannel(DIO_ChannelTypes WhichPin,STD_LevelTypes Write);

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes WhichPin);

void DIO_WritePort(DIO_PortTypes WhichPort,uint8 PortValue);

uint8 DIO_ReadPort(DIO_PortTypes WhichPort);

void DIO_ToggleChannel(DIO_ChannelTypes WhichPin);

#endif /* DIO_H_ */
