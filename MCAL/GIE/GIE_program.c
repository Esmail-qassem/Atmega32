/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:GIE                       *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_Enable(void)
{
SET_BIT(SREG,SREG_I);

}
void GIE_Disable(void)
{
	CLEAR_BIT(SREG,SREG_I);
}

