/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:ADC_PRIVATE               *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

static void (*Global_PvNotifacation)(void)=NULL;
static u16 *Global_u16PuReading=NULL;
void __vector_16 (void)__attribute((signal));


typedef struct {
	u8 MUX :5;   /*ADC CHANNEL*/
	u8 ADLAR :1; /*LEFT Or RIGHT ADJUSTMENT*/
	u8 REFS :2; /*Voltage Reference Selections BIT */

} ADMUX;

typedef struct {
	u8 ADPS :3; /* ADC PRESCALER Select bit*/
	u8 ADIE :1; /* ADC Interrupt Enable bit */
	u8 ADIF :1; /* ADC Interrupt flag bit */
	u8 ADATE :1; /* ADC Auto Trigger enable bit */
	u8 ADSC :1; /* ADC Start conversion bit */
	u8 ADEN :1; /* ADC Enable bit */

} ADCSRA;

typedef struct {
	u8 :5;
	u8 ADTS :3;
} ADC_SFIOR;


enum TRIGGER_S {
	FREE_RUNNUNG_MODE            = 0b000,
	ANALOG_COMPARATOR_MODE       = 0b001,
	EXTERNAL_INTERRUPT0_REQUEST  = 0b010,
	TIMER0_CTC                   = 0b011,
	TIMER0_OVERFLOW              = 0b100,
	TIMER1_CTC_B                 = 0b101,
	TIMER1_OVERFLOW              = 0b110,
	TIMER1_CAPTURE_EVENT         = 0b111,

};
enum ADC_PRESCALER {
	DIVISION_BY_2 = 0b001,
	DIVISION_BY_4 = 0b010,
	DIVISION_BY_8 = 0b011,
	DIVISION_BY_16 = 0b100,
	DIVISION_BY_32 = 0b101,
	DIVISION_BY_64 = 0b110,
	DIVISION_BY_128 = 0b111,
};
enum VOLTAGE_REFERENCE {
	AREF = 0b00, AVCC = 0b01, INTERNAL_2_56V = 0b11
};

enum RESOLUTION {
	RIGHT = 0b0, LEFT= 0b1,
};
enum ABILITY
{ DISABLE,
ENABLE
};

#define TIME_OUT 500
#define BIT_8_MACRO  0
#define BIT_10_MACRO  1

#endif /* ADC_PRIVATE_H_ */
