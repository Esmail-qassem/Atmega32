/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  TIMER0                  *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_register.h"
#include "TIMER0_config.h"

void TIMER0_DutyCycle(u8 Copy_u8Duty)
{
	u16 Local_VCalue=0;
	Local_VCalue=Copy_u8Duty*256;
	Local_VCalue/=100;
	OCR0_Reg=Local_VCalue;
}


void TIMER0_Delay(u16 Copy_u16Delay)
{
	u16 Counter=0;


	while(Counter<Copy_u16Delay)
	{
	while(TIFR_Reg->OCF0 == 0);
	TIFR_Reg->OCF0 =1;
	Counter++;


	}

}
void TIMER0_voidInit(void)
{
	TCCR0_Reg->CS0x= CLCK_SELECTION;

#if TIMER_MODE==NORMAL_MODE
TCCR0_Reg->WGM00=0b0;
TCCR0_Reg->WGM01=0b0;
#elif TIMER_MODE==PWM_PHASE_CORRECT_MODE
TCCR0_Reg->WGM00=ENABLE;
TCCR0_Reg->WGM01=DISABLE;
TCCR0_Reg->COM0=CORRECT_PWM_OUTPUT_MODE;


#elif TIMER_MODE==CTC_MODE
TCCR0_Reg->WGM00=DISABLE;
TCCR0_Reg->WGM01=ENABLE;
TCCR0_Reg->COM0=CTC_OUTPUT_MODE;

#elif TIMER_MODE==FAST_PWM_MODE
TCCR0_Reg->WGM00=ENABLE;
TCCR0_Reg->WGM01=ENABLE;
TCCR0_Reg->COM0=FAST_PWM_OUTPUT_MODE;
#endif



#ifdef OVERFLOW_ISR_ENABLE
TIMSK_Reg->TOIE0=ENABLE;
#endif

#ifdef COMPARE_MATCH_ISR_ENABLE
TIMSK_Reg->OCIE0=ENABLE;
#endif


}


void TIMER0_voiSetPreLoadValue(u8 Copy_u8Value)
{
	TCNT0_Reg=Copy_u8Value;
}


void TIMER0_voiSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR0_Reg=Copy_u8Value;
}

Status_t Timer0_Timer0OVFCallBackFunc(void (*Copy_pvFunc)(void))
{
	Status_t Local_ErrorState= TIMER_OK;
	if(NULL == Copy_pvFunc )
	{
		Local_ErrorState =TIMER_POINTER_Err;
	}
	else
	{
		Global_PvOverFlow = Copy_pvFunc;
	}

	return Local_ErrorState;
}

Status_t Timer0_Timer0CTCCallBackFunc(void (*Copy_pvFunc)(void))
{
	Status_t Local_ErrorState= TIMER_OK;
	if(NULL == Copy_pvFunc )
		{
			Local_ErrorState =TIMER_POINTER_Err;
		}
		else
		{
			Global_PvCompareMatch=Copy_pvFunc;
		}

	return Local_ErrorState;
}




/*TIMER0 COMPARE MATCH*/
void __vector_10(void){

	Global_PvCompareMatch();
}

/*TIMER0 OVERFLOW*/
void __vector_11(void){

	Global_PvOverFlow();
}

