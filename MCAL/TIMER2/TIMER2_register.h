/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER2                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_


#define TCNT2_Reg  *((volatile u8*)0x44)


#define OCR2_Reg   *((volatile u8*)0x43)


#define ASSR_Reg           ((volatile ASSR *)0x42)


#define TCCR2_Reg   ((volatile TCCR2 *)0x45)

#define TIMSK_Reg   ((volatile Timer2_TIMSK *)0x59)

#define TIFR_Reg   ((volatile Timer2_TIFR *)0x58)

#define TIMER2_SFIOR_Reg   ((volatile Timer2_SFIOR *)0x50)

#endif /* TIMER2_REGISTER_H_ */
