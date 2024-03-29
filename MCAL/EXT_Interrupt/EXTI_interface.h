/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:EXTERNAL INTERRUPT        *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define INT0  1
#define INT1  2
#define INT2  3


#define EXTI_LOW_LEVEL   0
#define EXTI_ANY_CHANGE  1
#define EXTI_FALLING     2
#define EXTI_RISING      3




void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);


u8 EXTI_u8IntSetSenseControl(u8 Copy_u8IntNumber,u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber);

u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif /* EXTI_INTERFACE_H_ */
