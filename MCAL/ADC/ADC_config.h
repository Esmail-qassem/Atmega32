/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:ADC_CONGIG                *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*DIVISION_BY_2
DIVISION_BY_4
DIVISION_BY_8
DIVISION_BY_16
DIVISION_BY_32
DIVISION_BY_64
DIVISION_BY_128
 * */

#define DESIRED_PRE_SCALER  DIVISION_BY_8

/* AREF
   AVCC
   INTERNAL_2_56V
 * */
#define DESIRED_VOLTAGE_REF  AVCC

/*
* BIT_8_MACRO
* BIT_10_MACRO */

#define DATA_SIZE  BIT_10_MACRO

/*AUTO_TREGERED
 *  or SINGLE_CONVERTION
 * **/
#define SINGLE_CONVERTION

/**  FREE_RUNNUNG_MODE
  *  ANALOG_COMPARATOR_MODE
  *  EXTERNAL_INTERRUPT0_REQUEST
  *  TIMER0_CTC
  *  TIMER0_OVERFLOW
  *  TIMER1_CTC_B
  *  TIMER1_OVERFLOW
  *  TIMER1_CAPTURE_EVENT
 * */

#define AUTO_TRIGER_SOURCE    TIMER0_OVERFLOW

#endif /* ADC_CONFIG_H_ */
