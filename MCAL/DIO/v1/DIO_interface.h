/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:DIO_INTERFACE             *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum {
	DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD
} Port_t;

typedef enum {
	DIO_Pin0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7
} Pin_t;

typedef enum {
	DIO_INPUT, DIO_OUTPUT,
} Dir_t;

#define DIO_HIGH 1
#define DIO_LOW  0





/**
*@brief  setting the port value
*@param  Mc desired port
*@retval Error Status
*/
u8 DIO_u8SetPortVal(Port_t Copy_Port, u8 Copy_u8Value);

/**
*@brief  setting the port value
*@param  Mc desired port,desired pin
*@retval Error Status
*/
u8 DIO_u8SetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, u8 Copy_u8Value);


/**
*@brief  setting the port Direction
*@param  Mc desired port
*@retval Error Status
*/
u8 DIO_u8SetPortDir(Port_t Copy_Port, u8 Copy_u8Direction);


/**
*@brief  setting the pin Direction
*@param  Mc desired port,desired pin
*@retval Error Status
*/
u8 DIO_u8SetPinValDir(Port_t Copy_Port, Pin_t Copy_Pin, Dir_t Copy_Direction);


/**
*@brief  Getting the pin value
*@param  Mc desired port,desired pin, pointer to receive the value
*@retval Error Status
*/
u8 DIO_u8GetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, u8* Copy_pvValue);

/**
*@brief  Getting the Port value
*@param  Mc desired port, pointer to receive the value
*@retval Error Status
*/
u8 DIO_u8GetPortVal(Port_t Copy_Port,u8* Copy_pvValue);



#endif /* DIO_INTERFACE_H_ */
