/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:HAL                     *****************/
/*****************       Component: KPD                *****************/
/*****************       SWC:DIO                       *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


/**************************** CONFIGURATION ***********************************/
   /***************************** USER ***********************************/
#define KPD_PORT   DIO_PORTC

#define KPD_COLUMN0_PIN   DIO_Pin0
#define KPD_COLUMN1_PIN   DIO_Pin1
#define KPD_COLUMN2_PIN   DIO_Pin2
#define KPD_COLUMN3_PIN   DIO_Pin3

#define KPD_ROW0_PIN      DIO_Pin4
#define KPD_ROW1_PIN      DIO_Pin5
#define KPD_ROW2_PIN      DIO_Pin6
#define KPD_ROW3_PIN      DIO_Pin7
/******************************************************************************/
#define COLUMN_NUMBER 4
#define ROW_NUMBER    4
/******************************************************************************/

u8 KPD_u8GetPressedKey(void);


#endif /* KPD_INTERFACE_H_ */
