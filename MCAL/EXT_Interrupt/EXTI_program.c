/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:EXTERNAL INTERRUPT        *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_voidInt0Init(void)
{

#if INT0_SENSE == LOW_LEVEL
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == ANY_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLEAR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == FALLING_EDGE
	CLEAR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "INT0 Wrong init"
#endif

#if INT0_STATE == INT0_ENABLE
	SET_BIT(GICR,GICR_INT0);
#elif  INT0_STATE == INT0_DISABLE
	CLEAR_BIT(GICR,GICR_INT0);
#else
#error "INT0 Wrong init"
#endif

}

void EXTI_voidInt1Init(void)
{
#if INT1_SENSE == LOW_LEVEL
	CLEAR_BIT(MCUCR,MCUCR_ISC10);
	CLEAR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == ANY_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLEAR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == FALLING_EDGE
	CLEAR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#warning "INT1 Wrong init"
#endif

#if INT1_STATE == INT1_ENABLE
	SET_BIT(GICR,GICR_INT1);
#elif  INT1_STATE == INT1_DISABLE
	CLEAR_BIT(GICR,GICR_INT1);
#else
#warning "INT1 Wrong init"
#endif
}
void EXTI_voidInt2Init(void)
{

#if INT2_SENSE == FALLING_EDGE
	CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
#elif INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#warning "INT2 Wrong init"
#endif


#if INT2_STATE == INT2_ENABLE
	SET_BIT(GICR,GICR_INT2);
#elif  INT0_STATE == INT2_DISABLE
	CLEAR_BIT(GICR,GICR_INT2);
#else
#warning "INT2 Wrong init"
#endif

}

u8 EXTI_u8IntSetSenseControl(u8 Copy_u8IntNumber,u8 Copy_u8Sense)
{
	u8 Local_ErrorState=0;
	if(INT0==Copy_u8IntNumber)
	{
		switch(Copy_u8Sense)
		{
		case EXTI_LOW_LEVEL :CLEAR_BIT(MCUCR,MCUCR_ISC00);CLEAR_BIT(MCUCR,MCUCR_ISC01);break;
		case EXTI_ANY_CHANGE :SET_BIT(MCUCR,MCUCR_ISC00);CLEAR_BIT(MCUCR,MCUCR_ISC01);break;
		case EXTI_FALLING:CLEAR_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
		case EXTI_RISING:SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01);break;
		default : Local_ErrorState=1;
		}
	}
	else if(INT1==Copy_u8IntNumber)
	{
		switch(Copy_u8Sense)
	  {
		case EXTI_LOW_LEVEL :CLEAR_BIT(MCUCR,MCUCR_ISC10);CLEAR_BIT(MCUCR,MCUCR_ISC11);break;
	   case EXTI_ANY_CHANGE :SET_BIT(MCUCR,MCUCR_ISC10);CLEAR_BIT(MCUCR,MCUCR_ISC11);break;
	   case EXTI_FALLING:CLEAR_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
	   case EXTI_RISING:SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11);break;
	   default : Local_ErrorState=1;
	  }
	}
	else if(INT2==Copy_u8IntNumber)
	{switch(Copy_u8Sense)
	  {
	   case EXTI_FALLING:CLEAR_BIT(MCUCSR,MCUCSR_ISC2);break;
	   case EXTI_RISING:SET_BIT(MCUCSR,MCUCSR_ISC2);break;
	   default : Local_ErrorState=1;
	  }
	}
	else
	{
		Local_ErrorState=1;
	}

return Local_ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber)
{
	u8 Local_ErrorState = 0;
	switch (Copy_u8IntNumber) {
	case INT0:SET_BIT(GICR,GICR_INT0);break;
	case INT1:SET_BIT(GICR,GICR_INT1);break;
	case INT2:SET_BIT(GICR,GICR_INT2);break;
    default  : Local_ErrorState=1;
	}
	return Local_ErrorState;
}


u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber)
{
	u8 Local_ErrorState = 0;
	switch (Copy_u8IntNumber) {
	case INT0:CLEAR_BIT(GICR,GICR_INT0);break;
	case INT1:CLEAR_BIT(GICR,GICR_INT1);break;
	case INT2:CLEAR_BIT(GICR,GICR_INT2);break;
    default  : Local_ErrorState=1;
	}
	return Local_ErrorState;
}

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorStatus=NULL;
	if(Copy_pvInt0Func!=NULL)
	{
		Global_EXTI_pvInt0Func=Copy_pvInt0Func;

	}
	else
	{
		 Local_u8ErrorStatus=2;

	}
	return Local_u8ErrorStatus;
}



u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorStatus=NULL;
	if(Copy_pvInt1Func!=NULL)
	{
		Global_EXTI_pvInt1Func=Copy_pvInt1Func;

	}
	else
	{
		 Local_u8ErrorStatus=2;

	}
	return Local_u8ErrorStatus;
}



u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorStatus=NULL;
	if(Copy_pvInt2Func!=NULL)
	{
		Global_EXTI_pvInt2Func=Copy_pvInt2Func;

	}
	else
	{
		 Local_u8ErrorStatus=2;

	}
	return Local_u8ErrorStatus;
}





/*ISR of INT0*/

void __vector_1(void)
{
	if(Global_EXTI_pvInt0Func!=NULL)
	{
		Global_EXTI_pvInt0Func();
	}
	else
	{
		//do nothing

	}
}

/*ISR of INT1*/

void __vector_2(void)
{
	if(Global_EXTI_pvInt1Func!=NULL)
		{
		Global_EXTI_pvInt1Func();
		}
		else
		{
			//do nothing

		}

	}



/*ISR of INT2*/

void __vector_3(void)
{

	if(Global_EXTI_pvInt2Func!=NULL)
		{
		Global_EXTI_pvInt2Func();
		}
		else
		{
			//do nothing

		}

}

