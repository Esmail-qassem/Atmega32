/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:DIO_PROGRAM               *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include  "DIO_register.h"
#include "DIO_private.h"

u8 DIO_u8SetPortVal(Port_t Copy_Port, u8 Copy_u8Value) {
	u8 Local_u8ErrorState = 0;
	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_u8ErrorState = 1;
	} else {
		switch (Copy_Port) {
		case DIO_PORTA:
			PORTA = Copy_u8Value;
			break;
		case DIO_PORTB:
			PORTB = Copy_u8Value;
			break;
		case DIO_PORTC:
			PORTC = Copy_u8Value;
			break;
		case DIO_PORTD:
			PORTD = Copy_u8Value;
			break;
		}
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, u8 Copy_u8Value) {
	u8 Local_u8ErrorState = 0;

	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_u8ErrorState = 1;
	} else if ((Copy_Pin > DIO_Pin7) || (Copy_Pin < DIO_Pin0)) {
		Local_u8ErrorState = 1;
	} else {
		if (DIO_HIGH == Copy_u8Value) {
			switch (Copy_Port) {
			case DIO_PORTA:
				SET_BIT(PORTA, Copy_Pin);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB, Copy_Pin);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC, Copy_Pin);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD, Copy_Pin);
				break;
			}
		} else if (DIO_LOW == Copy_u8Value) {
			switch (Copy_Port) {
			case DIO_PORTA:
				CLEAR_BIT(PORTA, Copy_Pin);
				break;
			case DIO_PORTB:
				CLEAR_BIT(PORTB, Copy_Pin);
				break;
			case DIO_PORTC:
				CLEAR_BIT(PORTC, Copy_Pin);
				break;
			case DIO_PORTD:
				CLEAR_BIT(PORTD, Copy_Pin);
				break;
			}
		}
	}

	return Local_u8ErrorState;
}

u8 DIO_u8SetPortDir(Port_t Copy_Port, u8 Copy_u8Direction) {
	u8 Local_u8ErrorState = 0;
	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_u8ErrorState = 1;
	} else {
		switch (Copy_Port) {
		case DIO_PORTA:
			DDRA = Copy_u8Direction;
			break;
		case DIO_PORTB:
			DDRB = Copy_u8Direction;
			break;
		case DIO_PORTC:
			DDRC = Copy_u8Direction;
			break;
		case DIO_PORTD:
			DDRD = Copy_u8Direction;
			break;
		}
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValDir(Port_t Copy_Port, Pin_t Copy_Pin, Dir_t Copy_Direction) {
	u8 Local_u8ErrorState = 0;

	if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
		Local_u8ErrorState = 1;
	} else if ((Copy_Pin > DIO_Pin7) || (Copy_Pin < DIO_Pin0)) {
		Local_u8ErrorState = 1;
	} else {
		if (DIO_INPUT == Copy_Direction) {
			switch (Copy_Port) {
			case DIO_PORTA:
				CLEAR_BIT(DDRA, Copy_Pin);
				break;
			case DIO_PORTB:
				CLEAR_BIT(DDRB, Copy_Pin);
				break;
			case DIO_PORTC:
				CLEAR_BIT(DDRC, Copy_Pin);
				break;
			case DIO_PORTD:
				CLEAR_BIT(DDRD, Copy_Pin);
				break;
			}
		} else if (DIO_HIGH == Copy_Direction) {
			switch (Copy_Port) {
			case DIO_PORTA:
				SET_BIT(DDRA, Copy_Pin);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB, Copy_Pin);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC, Copy_Pin);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD, Copy_Pin);
				break;
			}
		}
	}
	return Local_u8ErrorState;
}


u8 DIO_u8GetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, u8* Copy_pvValue)
{
	u8 Local_u8ErrorState = 0;

		if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
			Local_u8ErrorState = 1;
		} else if ((Copy_Pin > DIO_Pin7) || (Copy_Pin < DIO_Pin0)) {
			Local_u8ErrorState = 1;
		} else {
			switch (Copy_Port)
			{case DIO_PORTA : *Copy_pvValue=GET_BIT(PORTA,Copy_Pin);break;
			case DIO_PORTB : *Copy_pvValue=GET_BIT(PORTB,Copy_Pin);break;
			case DIO_PORTC : *Copy_pvValue=GET_BIT(PORTC,Copy_Pin);break;
			case DIO_PORTD : *Copy_pvValue=GET_BIT(PORTD,Copy_Pin);break;

			}
		}
return Local_u8ErrorState;
}


u8 DIO_u8GetPortVal(Port_t Copy_Port,u8* Copy_pvValue)
{
	u8 Local_u8ErrorState = 0;
		if ((Copy_Port > DIO_PORTD) || (Copy_Port < DIO_PORTA)) {
			Local_u8ErrorState = 1;
		} else {
			switch(Copy_Port)
			{case DIO_PORTA:*Copy_pvValue=PINA;break;
			case DIO_PORTB:*Copy_pvValue=PINB;break;
			case DIO_PORTC:*Copy_pvValue=PINC;break;
			case DIO_PORTD:*Copy_pvValue=PIND;break;
			}
		}

return Local_u8ErrorState;
}
