/*
 * ADC_HW.h
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

#define ADMUX_REG	(*(volatile uint8 *)0x27)
#define REFS0_BIT	6
#define REFS1_BIT	7
#define ADLAR_BIT	5

#define ADCSRA_REG	(*(volatile uint8 *)0x26)
#define ADC_EN_BIT		7
#define ADC_SC_BIT		6
#define ADC_ADATE_BIT	5
#define ADC_ADIF_BIT	4
#define ADC_ADIE_BIT	3

#define ADCH_REG	(*(volatile uint8 *)0x25)
#define ADCL_REG	(*(volatile uint8 *)0x24)

typedef enum{
	ChannelA0,
	ChannelA1,
	ChannelA2,
	ChannelA3,
	ChannelA4,
	ChannelA5,
	ChannelA6,
	ChannelA7
	}ADC_Channel;

#endif /* ADC_HW_H_ */