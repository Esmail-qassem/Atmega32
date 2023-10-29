/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:ADC_INTERFACE             *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum{
	ADC_CHANNEL0 = 0b00000,
	ADC_CHANNEL1 = 0b00001,
	ADC_CHANNEL2 = 0b00010,
	ADC_CHANNEL3 = 0b00011,
	ADC_CHANNEL4 = 0b00100,
	ADC_CHANNEL5 = 0b00101,
	ADC_CHANNEL6 = 0b00110,
	ADC_CHANNEL7 = 0b00111,

}Channel_t;

typedef enum
{
	ADC_OK,
	ADC_POINTER_Err,
	ADC_ChannelErr,
	ADC_TIME_OUTErr
}ADC_Status_t;


void ADC_voidInit(void);

/*Starting ADC Conversion with Poling Technique*/
ADC_Status_t ADC_u8StartConversionSynchronus(Channel_t Copy_u8channel,u16* copy_u16PuReading);

/*Starting ADC Conversion with Interrupt technique*/
ADC_Status_t ADC_u8StartConversionASynchronus(Channel_t Copy_u8channel,void (*copy_PvNotifacation)(void),u16* copy_u16PuReading);


u16 ADC_mapping(u16 adc_value, u16 adc_lower_range, u16 adc_upper_range, u16 new_lower_range, u16 new_upper_range) ;

#endif /* ADC_INTERFACE_H_ */
