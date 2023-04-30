/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : DIO                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef DIO_interface_H_

 #define DIO_interface_H_

	 #define DIO_U8PIN_OUTPUT     1
	 #define DIO_U8PIN_INPUT      0

	 #define DIO_U8PIN_HIGH       1
	 #define DIO_U8PIN_LOW        0

	 #define DIO_U8PORT_OUTPUT     0xff
	 #define DIO_U8PORT_INPUT      0

	 #define DIO_U8PORT_HIGH       0xff
	 #define DIO_U8PORT_LOW        0

     #define DIO_U8PORTA           0
	 #define DIO_U8PORTB           1
     #define DIO_U8PORTC           2
     #define DIO_U8PORTD           3

     #define DIO_U8PIN0            0
     #define DIO_U8PIN1            1
     #define DIO_U8PIN2            2
     #define DIO_U8PIN3            3
     #define DIO_U8PIN4            4
     #define DIO_U8PIN5            5
     #define DIO_U8PIN6            6
     #define DIO_U8PIN7            7

 
	u8 DIO_u8SetPinDirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction);
	
	u8 DIO_u8SetPortDirection(u8 copy_u8port,u8 copy_u8direction);
	
	u8 DIO_u8SetPinValue(u8 copy_u8port,u8 copy_u8pin, u8 copy_u8value);
	
	u8 DIO_u8SetPortValue(u8 copy_u8port, u8 copy_u8value);
	
	u8 DIO_u8GetPinValue(u8 copy_u8port,u8 copy_u8pin,u8* copy_pu8value);
	

#endif
