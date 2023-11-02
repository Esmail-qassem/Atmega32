/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER2                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

typedef enum
{
	TIMER_OK,
	TIMER_POINTER_Err,
}Status_t;

void TIMER2_voidInit(void);

/*Over flow value or preLoad value*/
/*2^n*(1-0.y)   in which n: the resolution */
void TIMER2_voiSetPreLoadValue(u8 Copy_u8Value);
void TIMER2_voiSetCompareMatchValue(u8 Copy_u8Value);

void TIMER2_Delay(u16 Copy_u16Delay);
void TIMER2_DutyCycle(u8 Copy_u8Duty);


Status_t Timer2_Timer2OVFCallBackFunc(void (*Copy_pvFunc)(void));
Status_t Timer2_Timer2CTCCallBackFunc(void (*Copy_pvFunc)(void));

#endif /* TIMER2_INTERFACE_H_ */
