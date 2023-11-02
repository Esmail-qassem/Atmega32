/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  TIMER0                  *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/***************************************************************************************************************************/
void __vector_10 (void)__attribute((signal));
static void (*Global_PvCompareMatch)(void)=NULL;


static void (*Global_PvOverFlow)(void)=NULL;
void __vector_11 (void)__attribute((signal));

/***************************************************************************************************************************/


typedef struct
{
	u8 CS0x  :3;  /*Clock Select*/
	u8 WGM01 :1;  /*Waveform generation*/
	u8 COM0  :2;  /*Compare Match Output Mode*/
	u8 WGM00 :1;  /*Waveform generation*/
	u8 FOC0  :1;
}TCCR0;

typedef struct
{
	u8 TOIE0:1;   /*OVERFLOW INTERRUPT ENABLE*/
	u8 OCIE0:1;   /*COMPARE MATCH INTERRUPT ENABLE*/
	u8 :6;         /*Reserved*/
}Timer0_TIMSK;

typedef struct
{
	u8 TOV0:1;   /*OVERFLOW FLAG 0*/
	u8 OCF0:1;   /*COMPARE MATCH FLAG 0*/
	u8 :6;         /*Reserved*/
}Timer0_TIFR;


/*When this bit is written to one, the Timer/Counter1 and Timer/Counter0 prescaler will be
reset. The bit will be cleared by hardware after the operation is performed. Writing a
zero to this bit will have no effect. Note that Timer/Counter1 and Timer/Counter0 share
the same prescaler and a reset of this prescaler will affect both timers. This bit will
always be read as zero*/
typedef struct
{
	u8 TIMER_PSR10:1;
	u8 :7;         /*Reserved*/
}Timer0_SFIOR;


enum CLCK_SELECT
{
	NO_CLCK=0b000,
	NO_PRESCALLING=0b001,
	DIVIDE_BY_8 =0b010,
	DIVIDE_BY_64 =0b011,
	DIVIDE_BY_256 =0b100,
	DIVIDE_BY_1024 =0b101,
	EXTERNAL_CLCK_FALLING_EDGE =0b110,
	EXTERNAL_CLCK_RISING_EDGE =0b111,
};
enum CTC_NON_PWM
{
	NON_OC0_DISCONNECT_NORMAL =0b00,
	NON_TOGGLE_OC0=0b01,
	NON_CLEAR_OC0=0b10,
	NON_SET_OC0=0b11
};
enum CTC_FAST_PWM
{
	FAST_OC0_DISCONNECT_NORMAL =0b00,
	FAST_DIRECT_OC0=0b10,   /*Clear OC0 on compare match, set OC0 at TOP*/
	FAST_INVERTED_OC0=0b11  /*Set OC0 on compare match, clear OC0 at TOP*/
};

enum CTC_PHASE_CORRECT_PWM
{
	PHASE_OC0_DISCONNECT_NORMAL =0b00,
	PHASE_DIRECT_OC0=0b10,   /*Clear OC0 on compare match, set OC0 at TOP*/
	PHASE_INVERTED_OC0=0b11  /*Set OC0 on compare match, clear OC0 at TOP*/
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

#endif /* TIMER0_PRIVATE_H_ */
