#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"

void ADC_voidInit(void)
{
	  /*PRE-SCALER SELECTION*/
	ADCSRA_Reg->ADPS=DESIRED_PRE_SCALER;

	/*Choosing the voltage reference*/

	ADMUX_Reg->REFS=DESIRED_VOLTAGE_REF;
	/*choose the Resolution*/
	ADMUX_Reg->ADLAR=RIGHT;
	/*ENABLE THE ADC*/
	ADCSRA_Reg->ADEN=1;
}
Status_t ADC_u8StartConversionSynchronus(Channel_t Copy_u8channel,u16* copy_u16PuReading)
{
	Status_t Local_ErrorStatus= OK;
	u32 Local_u32Counter=0;
	if(NULL==copy_u16PuReading)
	{
		Local_ErrorStatus=POINTER_Err;
	}
	else if((Copy_u8channel>ADC_CHANNEL7)||(Copy_u8channel<ADC_CHANNEL0))
	{
		Local_ErrorStatus=ChannelErr;
	}
	else
	{
		/*Select the Channel*/
		ADMUX_Reg->MUX=Copy_u8channel;
		/*Start Conversion*/
		ADCSRA_Reg->ADSC=1;
/*Polling until the conversion is complete OR TIME OUT*/
		while((ADCSRA_Reg->ADIF)!=1 && Local_u32Counter<TIME_OUT)
		{
			Local_u32Counter ++;
		}
		if(Local_u32Counter == TIME_OUT )
		{
			Local_ErrorStatus=TIME_OUTErr;
		}else
		{
           /*Clear the valg*/
			ADCSRA_Reg->ADIF=1;

#if     DATA_SIZE == BIT_10_MACRO
       *copy_u16PuReading=ADC;
#elif  DATA_SIZE == BIT_8_MACRO
       *copy_u16PuReading=ADC>>2;
#endif

		}

	}

	return Local_ErrorStatus;
}
