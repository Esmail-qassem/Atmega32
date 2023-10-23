/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:EXTERNAL INTERRUPT        *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/**choose between
 * LOW_LEVEL
 * ANY_CHANGE
 * FALLING_EDGE
 * RISING_EDGE
 * */


/**choose between
 * INT2_ENABLE
 * INT2_DISABLE
 * */
#define INT0_SENSE  ANY_CHANGE

#define INT0_STATE INT0_ENABLE

#define INT1_SENSE  ANY_CHANGE

#define INT1_STATE  INT_DISABLE

#define INT2_SENSE  FALLING_EDGE
#define INT2_STATE  INT2_DISABLE
#endif /* EXTI_CONFIG_H_ */
