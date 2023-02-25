/*
 * ADC.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */ 
/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/ADC.h"

/*******************************************************************************
 *                              Functions                                      *
 *******************************************************************************/

void ADC_Init(void)
{
	/* Enable ADC */
	SET_BIT(ADCSRA_REG, ADC_EN_BIT);
	
	/* Setting the PSC	between 50k to 200k HZ */
	ADCSRA_REG &= 0xF8;
	ADCSRA_REG |= 0x07;
	
	/* Setting AVCC AS Voltage Reference */
	SET_BIT(ADMUX_REG, REFS0_BIT);
	CLEAR_BIT(ADMUX_REG, REFS1_BIT);
}

uint16 ADC_READ(ADC_Channel Channel)
{
	uint16 Read;
	ADMUX_REG &= 0xE0;
	ADMUX_REG |= Channel;
	
	SET_BIT(ADCSRA_REG, ADC_SC_BIT);
	
	while(READ_BIT(ADCSRA_REG, ADC_ADIF_BIT) == 0);
	
	SET_BIT(ADCSRA_REG, ADC_ADIF_BIT);
	
	Read = ADCL_REG;
	Read |= ADCH_REG << 8;
	
	return Read;
}
