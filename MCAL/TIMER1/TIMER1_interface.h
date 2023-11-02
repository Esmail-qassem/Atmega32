/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER1                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

typedef enum
{
	TIMER1_OK,
	TIMER1_PONTER_ERR
}Timer1_status;



void TIMER1_voidInit(void);

void TIMER1_voidSetChannelACompMatch(u16 Copy_u16Data);
void TIMER1_voidSetChannelBCompMatch(u16 Copy_u16Data);
void TIMER1_voidSetICR(u16 Copy_u16ICR);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16 TIMER1_u16GetTimerValue(void);




Timer1_status TIMER1_CTCASetCallBck(void(*Copy_pvCallBackFunc)(void));
Timer1_status TIMER1_CTCBSetCallBck(void(*Copy_pvCallBackFunc)(void));

Timer1_status TIMER1_OVSetCallBck(void(*Copy_pvCallBackFunc)(void));

Timer1_status TIMER1_CAPTURESetCallBck(void(*Copy_pvCallBackFunc)(void));



#endif /* TIMER1_INTERFACE_H_ */
