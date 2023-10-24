
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_




#define ADMUX_Reg         ((volatile ADMUX*)0x27)

#define ADCSRA_Reg        ((volatile ADCSRA *)0x26)

#define ADC              *((volatile u16*)0x24)
#define ADCL              *((volatile u8*)0x24)
#define ADCH              *((volatile u8*)0x25)
#define SFIOR_Reg         ((volatile SFIOR *)0x50)

//#define  ADIF_MACRO 4

#endif /* ADC_REGISTER_H_ */
