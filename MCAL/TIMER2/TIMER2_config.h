/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER2                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_


/**NORMAL_MODE
 * CTC_MODE
 * FAST_PWM_MODE
 * PWM_PHASE_CORRECT_MODE
 * */
#define TIMER_MODE  CTC_MODE

/*if you use: CTC             |  FAST_PWM                 | PHASE_CORRECT                |
 *----------------------------|---------------------------|----------------------------  |
 * NON_OC2_DISCONNECT_NORMAL  | FAST_OC2_DISCONNECT_NORMAL|   PHASE_OC2_DISCONNECT_NORMAL|
 * NON_TOGGLE_OC2             | FAST_DIRECT_OC2           |   PHASE_DIRECT_OC2           |
 * NON_CLEAR_OC2              | FAST_INVERTED_OC2         |   PHASE_INVERTED_OC2         |
 * NON_SET_OC2                |                           |                              |
 *--------------------------------------------------------------------------------------------
 */

#define CTC_OUTPUT_MODE            NON_TOGGLE_OC2

#define FAST_PWM_OUTPUT_MODE       FAST_DIRECT_OC2

#define CORRECT_PWM_OUTPUT_MODE    PHASE_OC2_DISCONNECT_NORMAL


/*
 * NO_CLCK
 * NO_PRESCALLING
 * DIVIDE_BY_8
 * DIVIDE_BY_32
 * DIVIDE_BY_64
 * DIVIDE_BY_128
 * DIVIDE_BY_256
 * DIVIDE_BY_1024
 * **/
#define CLCK_SELECTION  DIVIDE_BY_64


/** INTERRUPT OPTIONS :
1-COMPARE_MATCH_ISR_ENABLE
2-OVERFLOW_ISR_ENABLE
3-ISR_DISABLE
**/

#define COMPARE_MATCH_ISR_ENABLE

#endif /* TIMER2_CONFIG_H_ */
