/*
 * DIO_CFG.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 

#ifndef DIO_CFG_h_
#define DIO_CFG_h_

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "DIO.h"

/*******************************************************************************
 *							Mode Select (MASTER / SLAVE)                       *
 *******************************************************************************/

#define	Mode	SLAVE

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef struct
{
	DIO_DirTypes pinDir;
	STD_LevelTypes Level;
#if Mode == SLAVE
	DIO_PortTypes PORT;
	PIN_count_t PINnum;
#endif
	}DIO_pincfg;

#if Mode == MASTER

#define PINCOUNT	0

#elif Mode == SLAVE

#define PINCOUNT	6

#endif
/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

void DIO_Init(void);

#endif /* DIO_CFG_h_ */
