/*
 * AMIT - Car Control using Hand Motion.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */

/*******************************************************************************
 *							Mode Select (MASTER / SLAVE)                       *
 *******************************************************************************/

#define	Mode	SLAVE

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#if Mode == MASTER
#include "APP/Master/Includes/Master.h"
#elif Mode == SLAVE	
#include "APP/Slave/Includes/Slave.h"
#endif

/*******************************************************************************
 *								Functions								       *
 *******************************************************************************/

int main()
{
#if Mode == MASTER
	Master_APP_Start();		/* MASTER APP Mode */

#elif Mode == SLAVE	
	Slave_APP_Start();		/* SLAVE APP Mode */
	
#endif
}