/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER2                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

/***************************************************************************************************************************/
void __vector_4 (void)__attribute((signal));
static void (*Global_PvCompareMatch)(void)=NULL;


static void (*Global_PvOverFlow)(void)=NULL;
void __vector_5 (void)__attribute((signal));

/***************************************************************************************************************************/


typedef struct
{
	u8 CS2x  :3;  /*Clock Select*/
	u8 WGM21 :1;  /*Waveform generation*/
	u8 COM2x  :2;  /*Compare Match Output Mode*/
	u8 WGM20 :1;  /*Waveform generation*/
	u8 FOC2  :1;
}TCCR2;



typedef struct
{
	u8 TCR2UB :3;  /*Clock Select*/
	u8 OCR2UB :1;  /*Waveform generation*/
	u8 TCN2UB :2;  /*Compare Match Output Mode*/
	u8 AS2    :1;  /*Waveform generation*/
	u8 :4;
}ASSR;


typedef struct
{
	u8 :6   ;          /*Reserved*/
	u8 TOIE2:1;   /*OVERFLOW INTERRUPT ENABLE*/
	u8 OCIE2:1;   /*COMPARE MATCH INTERRUPT ENABLE*/

}Timer2_TIMSK;

typedef struct
{
	u8 :6;         /*Reserved*/
	u8 TOV2:1;   /*OVERFLOW FLAG 0*/
	u8 OCF2:1;   /*COMPARE MATCH FLAG 0*/

}Timer2_TIFR;


typedef struct
{
	u8 :1;         /*Reserved*/
	u8 PSR2:1;
	u8 :6;         /*Reserved*/
}Timer2_SFIOR;


enum CLCK_SELECT
{
	NO_CLCK=0b000,
	NO_PRESCALLING=0b001,
	DIVIDE_BY_8 =0b010,
	DIVIDE_BY_32 =0b011,
	DIVIDE_BY_64 =0b100,
	DIVIDE_BY_128 =0b101,
	DIVIDE_BY_256 =0b110,
	DIVIDE_BY_1024 =0b111,
};
enum CTC_NON_PWM
{
	NON_OC2_DISCONNECT_NORMAL =0b00,
	NON_TOGGLE_OC2=0b01,
	NON_CLEAR_OC2=0b10,
	NON_SET_OC2=0b11
};
enum CTC_FAST_PWM
{
	FAST_OC2_DISCONNECT_NORMAL =0b00,
	FAST_DIRECT_OC2=0b10,   /*Clear OC0 on compare match, set OC0 at TOP*/
	FAST_INVERTED_OC2=0b11  /*Set OC0 on compare match, clear OC0 at TOP*/
};

enum CTC_PHASE_CORRECT_PWM
{
	PHASE_OC2_DISCONNECT_NORMAL =0b00,
	PHASE_DIRECT_OC2=0b10,   /*Clear OC0 on compare match, set OC0 at TOP*/
	PHASE_INVERTED_OC2=0b11  /*Set OC0 on compare match, clear OC0 at TOP*/
};

enum ABILITY
{
	DISABLE,
	ENABLE

};

#define NORMAL_MODE             0
#define PWM_PHASE_CORRECT_MODE  1
#define CTC_MODE                2
#define FAST_PWM_MODE           3

#endif /* TIMER2_PRIVATE_H_ */
