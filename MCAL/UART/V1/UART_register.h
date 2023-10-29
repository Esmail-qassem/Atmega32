

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UCSRA     *((volatile u8*)0x2B)


#define UCSRB     *((volatile u8*)0x2A)

#define UDR           *((volatile u8*)0X2C)

#define UBRRL           *((volatile u8*)0X29)

#define UCSRC        *((volatile u8*)0X29)  /*UBRRH*/


#endif /* UART_REGISTER_H_ */
