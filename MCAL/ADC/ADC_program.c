/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  ADC                     *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"

void ADC_voidInit(void) {
	/*PRE-SCALER SELECTION*/
	ADCSRA_Reg->ADPS = DESIRED_PRE_SCALER;

	/*Choosing the voltage reference*/
	ADMUX_Reg->REFS = DESIRED_VOLTAGE_REF;
	/*choose the Resolution*/
	ADMUX_Reg->ADLAR = RIGHT;

#ifdef AUTO_TREGERED

	ADCSRA_Reg->ADATE=ENABLE;

	SFIOR_Reg->ADTS=AUTO_TRIGER_SOURCE;

#endif
	/*ENABLE THE ADC*/
	ADCSRA_Reg->ADEN = ENABLE;

}
Status_t ADC_u8StartConversionSynchronus(Channel_t Copy_u8channel,u16* copy_u16PuReading) {
	Status_t Local_ErrorStatus = ADC_OK;
	u32 Local_u32Counter = 0;
	if (NULL == copy_u16PuReading) {
		Local_ErrorStatus = ADC_POINTER_Err;
	} else if ((Copy_u8channel > ADC_CHANNEL7)|| (Copy_u8channel < ADC_CHANNEL0)) {
		Local_ErrorStatus = ADC_ChannelErr;
	} else {
		/*Select the Channel*/
		ADMUX_Reg->MUX = Copy_u8channel;
#ifndef AUTO_TREGERED
		/*Start Conversion*/
		ADCSRA_Reg->ADSC = ENABLE;
#endif
		/*Polling until the conversion is complete OR TIME OUT*/
		while ((ADCSRA_Reg->ADIF) != 1 && Local_u32Counter < TIME_OUT) {
			Local_u32Counter++;
		}
		if (Local_u32Counter == TIME_OUT) {
			Local_ErrorStatus = ADC_TIME_OUTErr;
		} else {
			/*Clear the valg*/
			ADCSRA_Reg->ADIF = ENABLE;

#if     DATA_SIZE == BIT_10_MACRO
			*copy_u16PuReading=ADC;
#elif  DATA_SIZE == BIT_8_MACRO
			*copy_u16PuReading = ADC >> 2;
#endif

		}

	}

	return Local_ErrorStatus;
}

Status_t ADC_u8StartConversionASynchronus(Channel_t Copy_u8channel,void (*copy_PvNotifacation)(void), u16* copy_u16PuReading) {
	Status_t Local_ErrorStatus = ADC_OK;
	if (NULL == copy_u16PuReading) {
		Local_ErrorStatus = ADC_POINTER_Err;
	} else if ((Copy_u8channel > ADC_CHANNEL7)|| (Copy_u8channel < ADC_CHANNEL0)) {
		Local_ErrorStatus = ADC_ChannelErr;
	} else if (NULL == copy_PvNotifacation) {
		Local_ErrorStatus = ADC_POINTER_Err;
	} else {

		Global_PvNotifacation = copy_PvNotifacation;

		/*Assign Address of Receive Variable in Global Pointer to be used in ISR*/
		Global_u16PuReading = copy_u16PuReading;


		/* ADC Conversion Complete Interrupt Enable*/
		ADCSRA_Reg->ADIE = ENABLE;
#ifndef AUTO_TREGERED
		/*ADC Start Conversion*/
		ADCSRA_Reg->ADSC = ENABLE;
#endif
	}
	return Local_ErrorStatus;
}

void __vector_16(void) {
#if     DATA_SIZE == BIT_10_MACRO
	*Global_u16PuReading=ADC;
#elif  DATA_SIZE == BIT_8_MACRO
	*Global_u16PuReading = ADC >> 2;
#endif

	/*Execute Notification Function*/
	Global_PvNotifacation();
}

