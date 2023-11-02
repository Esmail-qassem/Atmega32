
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_interface.h"
#include "SERVO_interface.h"
u8 SERVO_u8SetAngle(u8 Copy_u8Channel ,s8 Copy_u8Angle)
{
	u8 Local_u8ErrorStatus=0;

if(Copy_u8Channel<TIMER1_CHANNELA || Copy_u8Channel>TIMER1_CHANNELB  )
{
	Local_u8ErrorStatus=1;
}
else if((Copy_u8Angle>=-90)&&(Copy_u8Angle<=90))
	{
	switch(Copy_u8Channel)
	{
	case TIMER1_CHANNELA :TIMER1_voidSetChannelACompMatch(5.556*Copy_u8Angle+1500);break;

    case TIMER1_CHANNELB :TIMER1_voidSetChannelBCompMatch(5.556*Copy_u8Angle+1500);break;
	}


	}
	else
	{
		Local_u8ErrorStatus=1;
	}

return Local_u8ErrorStatus;
}





