/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:HAL                     *****************/
/*****************       Component: KPD                *****************/
/*****************       SWC:DIO                       *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "KPD_interface.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 KPD_NO_PRESS=0xff;

	u8 Local_u8CoulmnIndex,Local_u8RowIndex;
	u8 Local_u8PinState;

static u8 Local_u8KPDArr[ROW_NUMBER][COLUMN_NUMBER]={{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{10,0,'=','+'}};
static u8 Local_u8KPDcoulmnArr[COLUMN_NUMBER]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
static u8 Local_u8KPDRowArr[ROW_NUMBER]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};


	for(Local_u8CoulmnIndex=0;Local_u8CoulmnIndex<COLUMN_NUMBER;Local_u8CoulmnIndex++)
	{
		DIO_SetPinVal(KPD_PORT,Local_u8KPDcoulmnArr[Local_u8CoulmnIndex],DIO_LOW);
		for(Local_u8RowIndex=0;Local_u8RowIndex<ROW_NUMBER;Local_u8RowIndex++)
		{
           DIO_GetPinVal(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
		    if(Local_u8PinState==DIO_LOW)
		   {
			KPD_NO_PRESS=Local_u8KPDArr[Local_u8RowIndex][Local_u8CoulmnIndex];
		/*polling wuntil the key is released*/
			while(Local_u8PinState==DIO_LOW)
			{
			DIO_GetPinVal(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
			}

		return KPD_NO_PRESS;

		   }
		}
		DIO_SetPinVal(KPD_PORT,Local_u8KPDcoulmnArr[Local_u8CoulmnIndex],DIO_HIGH);
	}
	return KPD_NO_PRESS;
}
