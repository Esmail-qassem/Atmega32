/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  TIMER0                  *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/**NORMAL_MODE
 * CTC_MODE
 * FAST_PWM_MODE
 * PWM_PHASE_CORRECT_MODE
 * */
#define TIMER_MODE  FAST_PWM_MODE

/*if you use: CTC             |  FAST_PWM                 | PHASE_CORRECT                |
 *----------------------------|---------------------------|----------------------------  |
 * NON_OC0_DISCONNECT_NORMAL  | FAST_OC0_DISCONNECT_NORMAL|   PHASE_OC0_DISCONNECT_NORMAL|
 * NON_TOGGLE_OC0             | FAST_DIRECT_OC0           |   PHASE_DIRECT_OC0           |
 * NON_CLEAR_OC0              | FAST_INVERTED_OC0         |   PHASE_INVERTED_OC0         |
 * NON_SET_OC0                |                           |                              |
 *--------------------------------------------------------------------------------------------
 */

#define CTC_OUTPUT_MODE            NON_TOGGLE_OC0

#define FAST_PWM_OUTPUT_MODE       FAST_DIRECT_OC0

#define CORRECT_PWM_OUTPUT_MODE    PHASE_OC0_DISCONNECT_NORMAL


/*
 * NO_CLCK
 * NO_PRESCALLING
 * DIVIDE_BY_8
 * DIVIDE_BY_64
 * DIVIDE_BY_256
 * DIVIDE_BY_1024
 * EXTERNAL_CLCK_FALLING_EDGE
 * EXTERNAL_CLCK_RISING_EDGE
 * **/
#define CLCK_SELECTION  DIVIDE_BY_8


/** INTERRUPT OPTIONS :
1-COMPARE_MATCH_ISR_ENABLE
2-OVERFLOW_ISR_ENABLE
3-ISR_DISABLE
**/

#define COMPARE_MATCH_ISR_ENABLE

#endif /* TIMER0_CONFIG_H_ */
