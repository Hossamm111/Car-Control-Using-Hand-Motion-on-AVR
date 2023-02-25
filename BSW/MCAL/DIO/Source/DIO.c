/*
 * DIO.c
 *
  * Created: 2/22/2023 0:00:00 AM
  * Author : Hossam
 */ 

/*******************************************************************************
 *								File Includes                                  *
 *******************************************************************************/

#include "../Includes/DIO.h"

/*******************************************************************************
 *									Functions                                  *
 *******************************************************************************/

void DIO_WriteChannel(DIO_ChannelTypes WhichPin, STD_LevelTypes Write)
{
	DIO_PortTypes Port_X = WhichPin / 8;
	DIO_ChannelTypes Pin_Number = WhichPin % 8;
	
	switch(Port_X)
	{
		case DIO_PortA :
		Write_Bit(PORTA_REG,Pin_Number,Write);
		break;
		
		case DIO_PortB :
		Write_Bit(PORTB_REG,Pin_Number,Write);
		break;
		
		case DIO_PortC :
		Write_Bit(PORTC_REG,Pin_Number,Write);
		break;
		
		case DIO_PortD :
		Write_Bit(PORTD_REG,Pin_Number,Write);
		break;
	}
}

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes WhichPin)
{
	STD_LevelTypes Pin_State = STD_Low;
	DIO_PortTypes Port_X = WhichPin  / 8;
	DIO_ChannelTypes Pin_Number = WhichPin % 8;
	
	switch(Port_X)
	{
		case DIO_PortA :
		Pin_State = READ_BIT(PINA_REG,Pin_Number);
		break;
		
		case DIO_PortB :
		Pin_State = READ_BIT(PINB_REG,Pin_Number);
		break;
		
		case DIO_PortC :
		Pin_State = READ_BIT(PINC_REG,Pin_Number);
		break;
		
		case DIO_PortD :
		Pin_State = READ_BIT(PIND_REG,Pin_Number);
		break;
	}
	return Pin_State;
}

void DIO_WritePort(DIO_PortTypes WhichPort,uint8 PortValue)
{
	switch(WhichPort)
	{
		case DIO_PortA :	PORTA_REG = PortValue;	break;
		case DIO_PortB :	PORTB_REG = PortValue;	break;
		case DIO_PortC :	PORTC_REG = PortValue;	break;
		case DIO_PortD :	PORTD_REG = PortValue;	break;
	}
}

uint8 DIO_ReadPort(DIO_PortTypes WhichPort)
{
	uint8 Port_Value = 0x00;
	
	switch(WhichPort)
	{
		case DIO_PortA :	Port_Value = PINA_REG;	break;
		case DIO_PortB :	Port_Value = PINB_REG;	break;
		case DIO_PortC :	Port_Value = PINC_REG;	break;
		case DIO_PortD :	Port_Value = PIND_REG;	break;	
	}
	return	Port_Value;
}


void DIO_ToggleChannel(DIO_ChannelTypes WhichPin)
{
	DIO_PortTypes Port_X = WhichPin / 8;
	DIO_ChannelTypes Pin_Number = WhichPin % 8;
	
	switch(Port_X)
	{
		case DIO_PortA :
		TOGGLE_BIT(PORTA_REG,Pin_Number);
		break;
		
		case DIO_PortB :
		TOGGLE_BIT(PORTB_REG,Pin_Number);
		break;
		
		case DIO_PortC :
		TOGGLE_BIT(PORTC_REG,Pin_Number);
		break;
		
		case DIO_PortD :
		TOGGLE_BIT(PORTD_REG,Pin_Number);
		break;
	}
}