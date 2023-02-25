/*
 * DIO_CFG.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */
 
 /*******************************************************************************
 *								File Includes                                  *
 *******************************************************************************/
 
#include "../Includes/DIO.h"

/*******************************************************************************
 *							Module Configurations                              *
 *******************************************************************************/

#if Mode == MASTER

DIO_pincfg pinCfg[] ={
	
	/* port A */
	{Input, STD_Low},	//0
	{Input, STD_Low},	//1
	{Input, STD_Low},	//2
    {Input, STD_Low},	//3
	{Input, STD_Low},	//4
	{Input, STD_Low},	//5
	{Input, STD_Low},	//6
	{Input, STD_Low},	//7
		
	/* port B */
	{Input, STD_Low},	//0
	{Input, STD_Low},	//1
	{Input, STD_Low},	//2
	{Input, STD_Low},	//3
	{Input, STD_Low},	//4
	{Input, STD_Low},	//5
	{Input, STD_Low},	//6
	{Input, STD_Low},	//7
	
	/* port C */
	{Input, STD_Low},	//0
	{Input, STD_Low},	//1
	{Input, STD_Low},	//2
	{Input, STD_Low},	//3
	{Input, STD_Low},	//4
	{Input, STD_Low},	//5
	{Input, STD_Low},	//6
	{Input, STD_Low},	//7
	
	/* port D */
	{Input, STD_Low},	//0
	{Input, STD_Low},	//1
	{Input, STD_Low},	//2
	{Input, STD_Low},	//3
	{Input, STD_Low},	//4
	{Input, STD_Low},	//5
	{Input, STD_Low},	//6
	{Input, STD_Low},	//7
};

#elif Mode == SLAVE

DIO_pincfg pinCfg[] ={
	
	/* port A */
	//{Input, STD_Low, DIO_PortA, PIN0},	//0
	//{Input, STD_Low, DIO_PortA, PIN1},	//1
	//{Input, STD_Low, DIO_PortA, PIN2},	//2
	//{Input, STD_Low, DIO_PortA, PIN3},	//3
	//{Input, STD_Low, DIO_PortA, PIN4},	//4
	//{Input, STD_Low, DIO_PortA, PIN5},	//5
	//{Input, STD_Low, DIO_PortA, PIN6},	//6
	//{Input, STD_Low, DIO_PortA, PIN7},	//7
	
	/* port B */
	//{Input, STD_Low, DIO_PortB, PIN0},	//0
	//{Input, STD_Low, DIO_PortB, PIN1},	//1
	//{Input, STD_Low, DIO_PortB, PIN2},	//2
	//{Input, STD_Low, DIO_PortB, PIN3},	//3
	//{Input, STD_Low, DIO_PortB, PIN4},	//4
	//{Input, STD_Low, DIO_PortB, PIN5},	//5
	//{Input, STD_Low, DIO_PortB, PIN6},	//6
	//{Input, STD_Low, DIO_PortB, PIN7},	//7
	
	/* port C */
	//{Input, STD_Low, DIO_PortC, PIN0},	//0
	//{Input, STD_Low, DIO_PortC, PIN1},	//1
	//{Input, STD_Low, DIO_PortC, PIN2},	//2
	{Input, STD_Low, DIO_PortC, PIN3},	//3
	{Input, STD_Low, DIO_PortC, PIN4},	//4
	{Input, STD_Low, DIO_PortC, PIN5},	//5
	{Input, STD_Low, DIO_PortC, PIN6},	//6
	//{Input, STD_Low, DIO_PortC, PIN7},	//7
	
	/* port D */
	//{Input, STD_Low, DIO_PortD, PIN0},	//0
	//{Input, STD_Low, DIO_PortD, PIN1},	//1
	//{Input, STD_Low, DIO_PortD, PIN2},	//2
	//{Input, STD_Low, DIO_PortD, PIN3},	//3
	{Input, STD_Low, DIO_PortD, PIN4},	//4
	{Input, STD_Low, DIO_PortD, PIN5},	//5
	//{Input, STD_Low, DIO_PortD, PIN6},	//6
	//{Input, STD_Low, DIO_PortD, PIN7},	//7
};

#endif
/*******************************************************************************
 *									Functions                                  *
 *******************************************************************************/

#if Mode == MASTER

void DIO_Init(void)
{
	DIO_ChannelTypes count = DIO_ChannelA0;
	DIO_ChannelTypes BitNO;
	DIO_PortTypes Portx;
	
	for(count = DIO_ChannelA0; count < PINCOUNT;count++)
	{
		Portx = count/8;
		BitNO = count%8;
		
		switch(Portx)
		{
			case DIO_PortA:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRA_REG,BitNO);
			else
			CLEAR_BIT(DDRA_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTA_REG,BitNO);
			else
			CLEAR_BIT(PORTA_REG,BitNO);
			break;
			
			case DIO_PortB:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRB_REG,BitNO);
			else
			CLEAR_BIT(DDRB_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTB_REG,BitNO);
			else
			CLEAR_BIT(PORTB_REG,BitNO);
			break;
			
			case DIO_PortC:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRC_REG,BitNO);
			else
			CLEAR_BIT(DDRC_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTC_REG,BitNO);
			else
			CLEAR_BIT(PORTC_REG,BitNO);
			break;
			
			case DIO_PortD:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRD_REG,BitNO);
			else
			CLEAR_BIT(DDRD_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTD_REG,BitNO);
			else
			CLEAR_BIT(PORTD_REG,BitNO);
			break;
		}
	}
}

#elif Mode == SLAVE

void DIO_Init(void)
{
	uint8 count = 0;
	PIN_count_t BitNO;
	DIO_PortTypes Portx;
	
	for(count = 0; count < PINCOUNT; count++)
	{
		Portx = pinCfg[count].PORT;
		BitNO = pinCfg[count].PINnum;
		
		switch(Portx)
		{
			case DIO_PortA:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRA_REG,BitNO);
			else
			CLEAR_BIT(DDRA_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTA_REG,BitNO);
			else
			CLEAR_BIT(PORTA_REG,BitNO);
			break;
			
			case DIO_PortB:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRB_REG,BitNO);
			else
			CLEAR_BIT(DDRB_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTB_REG,BitNO);
			else
			CLEAR_BIT(PORTB_REG,BitNO);
			break;
			
			case DIO_PortC:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRC_REG,BitNO);
			else
			CLEAR_BIT(DDRC_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTC_REG,BitNO);
			else
			CLEAR_BIT(PORTC_REG,BitNO);
			break;
			
			case DIO_PortD:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRD_REG,BitNO);
			else
			CLEAR_BIT(DDRD_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTD_REG,BitNO);
			else
			CLEAR_BIT(PORTD_REG,BitNO);
			break;
		}
	}
}
#endif