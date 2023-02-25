/*
 * Timer_Prog.c
 *
 * Created: 2/22/2023 0:00:00 AM
 * Author : Hossam
 */

/*******************************************************************************
 *                              File Includes                                  *
 *******************************************************************************/

#include "../Includes/Timer_Interface.h"

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/

uint32 Timer_uint32_NumOfOverFlows    = 0;
uint8  Timer_uint8_RemTicks           = 0;
uint32 Timer_uint32_NumOfCompareMatch = 0;

/*******************************************************************************
 *                              Functions                                      *
 *******************************************************************************/

void Timer_Init (uint8 Copy_uint8_TimerChannel)
{
	switch(Copy_uint8_TimerChannel)
	{
	case TIMER0_CHANNEL:
#if   TIMER0_MODE   ==   NORMAL_MODE
		CLEAR_BIT(TCCR0_REG,WGM00_BIT);
		CLEAR_BIT(TCCR0_REG,WGM01_BIT);
		/* TO ENABLE TIMER0 OVERFLOW INT */
		SET_BIT(TIMSK_REG,TOIE0_BIT);
#elif TIMER0_MODE   ==   CTC_MODE
		CLEAR_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);
		/* TO ENABLE TIMER0 COMPARE MATCH INT */
		SET_BIT(TIMSK_REG,OCIE0_BIT);
#endif
		break;
	case TIMER1_CHANNEL:

		break;
	case TIMER2_CHANNEL:

		break;
	default:
		break;
	}
}

void Timer_SetTime (uint8 Copy_uint8_TimerChannel,uint32 Copy_uint32_DesiredTime)
{
	uint32 Local_uint32_TickTime   = TIMER_PRESCALER_DV / F_OSC;       /* result will be in micro second */
	uint32 Local_uint32_TotalTicks = (Copy_uint32_DesiredTime * 1000) / Local_uint32_TickTime;
	//uint8 Local_uint8_DF  = 255;
	switch(Copy_uint8_TimerChannel)
	{
	case TIMER0_CHANNEL:
#if TIMER0_MODE   ==   NORMAL_MODE
		Timer_uint32_NumOfOverFlows = Local_uint32_TotalTicks / 256;
		uint8 Timer_uint8_RemTicks     = Local_uint32_TotalTicks % 256 ;
		if(Timer_uint8_RemTicks != 0)
		{
			TCNT0_REG = 256 - Timer_uint8_RemTicks;
			Timer_uint32_NumOfOverFlows++;
		}
#elif TIMER0_MODE   ==   CTC_MODE     // 500 tick
		while(Local_uint32_TotalTicks % Local_uint8_DF)
		{
			--Local_uint8_DF;
		}
		Timer_uint32_NumOfCompareMatch = Local_uint32_TotalTicks / Local_uint8_DF;
		OCR0_REG = Local_uint8_DF - 1;

#endif
		break;
	case TIMER1_CHANNEL:

		break;
	case TIMER2_CHANNEL:

		break;
	default: break;
	}

}

void Timer_Start (uint8 Copy_uint8_TimerChannel)
{
	switch(Copy_uint8_TimerChannel)
	{
	case TIMER0_CHANNEL:
#if   TIMER_PRESCALER_DV   ==   1024
		SET_BIT(TCCR0_REG,CS00_BIT);
		CLEAR_BIT(TCCR0_REG,CS01_BIT);
		SET_BIT(TCCR0_REG,CS02_BIT);
#elif TIMER_PRESCALER_DV   ==   256
		CLEAR_BIT(TCCR0_REG,CS00_BIT);
		CLEAR_BIT(TCCR0_REG,CS01_BIT);
		SET_BIT(TCCR0_REG,CS02_BIT);
#endif
		break;
	case TIMER1_CHANNEL:
		/* TO SELECT TIMER1 PRESCALER DV -> 256 */
		CLEAR_BIT(TCCR1B_REG,CS10_BIT);
		CLEAR_BIT(TCCR1B_REG,CS11_BIT);
		SET_BIT(TCCR1B_REG,CS12_BIT);
		break;
	case TIMER2_CHANNEL:

		break;
	default : break;
	}
}

void Timer_Stop (uint8 Copy_uint8_TimerChannel)
{
	switch(Copy_uint8_TimerChannel)
	{
	case TIMER0_CHANNEL:
		CLEAR_BIT(TCCR0_REG,CS00_BIT);
		CLEAR_BIT(TCCR0_REG,CS01_BIT);
		CLEAR_BIT(TCCR0_REG,CS02_BIT);
		break;
	case TIMER1_CHANNEL:
		CLEAR_BIT(TCCR1B_REG,CS10_BIT);
		CLEAR_BIT(TCCR1B_REG,CS11_BIT);
		CLEAR_BIT(TCCR1B_REG,CS12_BIT);
		break;
	case TIMER2_CHANNEL:

		break;
	default : break;
	}
}

void PWM_Init(void)
{
	uint16 sreg = SREG;
	cli();
	
	TCCR1B = 0;
	
	TCCR1A =
	0
	| (1 << COM1A1) | (0 << COM1A0)
	| (1 << COM1B1) | (0 << COM1B0)
	| (1 << WGM11) | (0 << WGM10);
	
	TCCR1B =
	0
	| (1 << WGM13) | (0 << WGM12);
	
	ICR1  = 0xFFFF;
	OCR1A = 0x00FF;
	OCR1B = 0x00FF;
	
	TCCR1B |= (0 << CS12) |(0 << CS11) | (1 << CS10);
	
	SREG = sreg;
	sei();
}

void PWM_SetDutyCycle (uint8 Copy_uint8_TimerChannel,fint32 Copy_fint32_DutyCycle)
{
	switch(Copy_uint8_TimerChannel)
	{
	case TIMER0_CHANNEL:
#if   PWM0_MODE   ==   FAST_PWM
#if   PWM0_MODE2   ==   NON_INVERTED
		if(Copy_fint32_DutyCycle == 0)
		{
			OCR0_REG = 0;
		}
		else
		{
			OCR0_REG = ((Copy_fint32_DutyCycle * 256) / 100) - 1;
		}
#elif   PWM0_MODE2   ==   INVERTED

#endif
#elif PWM0_MODE   ==   PHASE_CORRECT_PWM
#if   PWM0_MODE2   ==   NON_INVERTED

		OCR0_REG = (Copy_fint32_DutyCycle * 255) / 100;

#elif   PWM0_MODE2   ==   INVERTED

#endif
#endif
		break;
	case TIMER1_CHANNEL:
		OCR1A_REG = ((Copy_fint32_DutyCycle * ICR1_REG) / 100) - 1;
		break;
	case TIMER2_CHANNEL:
		break;
	default:  break;
	}
}

void SetCallBack (uint8 Copy_uint8_TimerChannel,void(*Copy_Ptr)(void))
{
	switch(Copy_uint8_TimerChannel)
	{
	case TIMER0_CHANNEL:
		Timer0_CallBack = Copy_Ptr;
		break;
	case TIMER1_CHANNEL:
		Timer1_CallBack = Copy_Ptr;
		break;
	case TIMER2_CHANNEL:
		Timer2_CallBack = Copy_Ptr;
		break;
	}
}
#if TIMER0_MODE   ==   NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static uint32 Local_uint32_Counter = 0;
	Local_uint32_Counter++;
	if(Local_uint32_Counter == Timer_uint32_NumOfOverFlows)
	{
		Timer0_CallBack();
		TCNT0_REG = 256 - Timer_uint8_RemTicks;
		Local_uint32_Counter = 0;
	}
}
#elif TIMER0_MODE   ==   CTC_MODE

ISR(TIMER0_COMP_vect)
{
	static uint32 Local_uint32_Counter = 0;
	Local_uint32_Counter++;
	if(Local_uint32_Counter == Timer_uint32_NumOfCompareMatch)
	{
		Timer0_CallBack();
		Local_uint32_Counter = 0;
	}
}

#endif
