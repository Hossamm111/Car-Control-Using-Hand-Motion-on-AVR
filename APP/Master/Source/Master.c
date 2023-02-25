/*
 * Master.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/Master.h"

/*******************************************************************************
 *									Functions                                  *
 *******************************************************************************/

void Master_APP_Init (void)
{
	Potentiometer_Init();
	UARTCom_Init();
}

void Master_APP_Start (void)
{
	Master_APP_Init();
	
	while(1)
	{
		Scheduler_Start();
	}
}