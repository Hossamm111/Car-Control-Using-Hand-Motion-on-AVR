/*
 * DIO_Types.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 
#ifndef DIO_Types_h_
#define DIO_Types_h_

/*******************************************************************************
 *								Module Data Types                              *
 *******************************************************************************/

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
	
typedef uint8 PIN_count_t;

typedef enum{
	Input,
	Output,
	}DIO_DirTypes;

typedef enum{
	STD_Low,
	STD_High,
	}STD_LevelTypes;
	
typedef enum{
	
	DIO_ChannelA0 = 0,
	DIO_ChannelA1,
	DIO_ChannelA2,
	DIO_ChannelA3,
	DIO_ChannelA4,
	DIO_ChannelA5,
	DIO_ChannelA6,
	DIO_ChannelA7,
	
	DIO_ChannelB0,
	DIO_ChannelB1,
	DIO_ChannelB2,
	DIO_ChannelB3,
	DIO_ChannelB4,
	DIO_ChannelB5,
	DIO_ChannelB6,
	DIO_ChannelB7,
	
	DIO_ChannelC0,
	DIO_ChannelC1,
	DIO_ChannelC2,
	DIO_ChannelC3,
	DIO_ChannelC4,
	DIO_ChannelC5,
	DIO_ChannelC6,
	DIO_ChannelC7,
	
	DIO_ChannelD0,
	DIO_ChannelD1,
	DIO_ChannelD2,
	DIO_ChannelD3,
	DIO_ChannelD4,
	DIO_ChannelD5,
	DIO_ChannelD6,
	DIO_ChannelD7,
	
	}DIO_ChannelTypes;
	
typedef enum{
	DIO_PortA = 0,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD,	
	}DIO_PortTypes;

#endif /* DIO_Types_h_ */