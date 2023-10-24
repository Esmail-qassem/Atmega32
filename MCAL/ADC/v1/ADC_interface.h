/*
 * ADC_interface.h
 *
 *  Created on: Oct 24, 2023
 *      Author: s_a_a
 */

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
	OK,
	POINTER_Err,
    ChannelErr,
	TIME_OUTErr
}Status_t;


void ADC_voidInit(void);

/*Starting ADC Conversion with Poling Technique*/
Status_t ADC_u8StartConversionSynchronus(Channel_t Copy_u8channel,u16* copy_u16PuReading);

/*Starting ADC Conversion with Interrupt technique*/
u8 ADC_u8StartConversionASynchronus(u8 Copy_u8channel,void (*copy_PvNotifacation)(void),u16* copy_u16PuReading);

#endif /* ADC_INTERFACE_H_ */
