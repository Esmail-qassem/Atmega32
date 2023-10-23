/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:EXTERNAL INTERRUPT        *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*Global pointer to function to hold INT ISR address*/

static void(*Global_EXTI_pvInt0Func)(void)=NULL;
static void(*Global_EXTI_pvInt1Func)(void)=NULL;
static void(*Global_EXTI_pvInt2Func)(void)=NULL;
/********************************************************/
/*Compiler Directive That Deal with Linker Optimizer To keep ISR And Not Remove It*/
void __vector_1 (void)  __attribute__((signal));
void __vector_2 (void)  __attribute__((signal));
void __vector_3 (void)  __attribute__((signal));

#define LOW_LEVEL    1
#define ANY_CHANGE   2
#define FALLING_EDGE 3
#define RISING_EDGE  4


#define  INT0_ENABLE   1
#define  INT0_DISABLE  2

#define  INT1_ENABLE   1
#define  INT1_DISABLE  2

#define  INT2_ENABLE   1
#define  INT2_DISABLE  2


#endif /* EXTI_PRIVATE_H_ */
