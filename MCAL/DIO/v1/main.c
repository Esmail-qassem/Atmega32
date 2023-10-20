/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: s_a_a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include  "DIO_register.h"
#include "DIO_private.h"
#include <util/delay.h>


void main()
{
	DIO_u8SetPortDir(DIO_PORTA,0xff);



	while(1)
	{
	DIO_u8SetPinVal(DIO_PORTA,DIO_Pin6,DIO_HIGH);
DIO_u8SetPinVal(DIO_PORTA,DIO_Pin5,DIO_HIGH);
DIO_u8SetPinVal(DIO_PORTA,DIO_Pin4,DIO_HIGH);
	_delay_ms(1000);
DIO_u8SetPinVal(DIO_PORTA,DIO_Pin6,DIO_LOW);
DIO_u8SetPinVal(DIO_PORTA,DIO_Pin5,DIO_LOW);
DIO_u8SetPinVal(DIO_PORTA,DIO_Pin4,DIO_LOW);

_delay_ms(1000);

	}





}

