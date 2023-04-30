/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : DIO                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"



u8 DIO_u8SetPinDirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction){

	u8 Local_ErrorState = 0;
	if(copy_u8pin <= DIO_U8PIN7){

		if(copy_u8direction==DIO_U8PIN_OUTPUT){

			switch(copy_u8port){

			case  DIO_U8PORTA: SET_BIT(DDRA,copy_u8pin); break;
			case  DIO_U8PORTB: SET_BIT(DDRB,copy_u8pin); break;
			case  DIO_U8PORTC: SET_BIT(DDRC,copy_u8pin); break;
			case  DIO_U8PORTD: SET_BIT(DDRD,copy_u8pin); break;
			default :Local_ErrorState=1;break;

			}

		}
		else if(copy_u8direction==DIO_U8PIN_INPUT){

			switch(copy_u8port){

			case  DIO_U8PORTA: CLR_BIT(DDRA,copy_u8pin); break;
			case  DIO_U8PORTB: CLR_BIT(DDRB,copy_u8pin); break;
			case  DIO_U8PORTC: CLR_BIT(DDRC,copy_u8pin); break;
			case  DIO_U8PORTD: CLR_BIT(DDRD,copy_u8pin); break;
			default :Local_ErrorState=1;break;

			}


		}
		else{
			Local_ErrorState=1;
			}
	}
	else{
		Local_ErrorState = 1;
	}

	return Local_ErrorState;

}

u8 DIO_u8SetPortDirection(u8 copy_u8port,u8 copy_u8direction){

	u8 Local_ErrorState = 0;

	switch(copy_u8port){

	case  DIO_U8PORTA: DDRA = copy_u8direction; break;
	case  DIO_U8PORTB: DDRB = copy_u8direction; break;
	case  DIO_U8PORTC: DDRC = copy_u8direction; break;
	case  DIO_U8PORTD: DDRD = copy_u8direction; break;
	default :Local_ErrorState=1; break;

	}

	return Local_ErrorState;
}

u8 DIO_u8SetPinValue(u8 copy_u8port,u8 copy_u8pin, u8 copy_u8value){

	u8 Local_ErrorState = 0;
		if(copy_u8pin <= DIO_U8PIN7){

			if(copy_u8value==DIO_U8PIN_HIGH){

				switch(copy_u8port){

				case  DIO_U8PORTA: SET_BIT(PORTA,copy_u8pin); break;
				case  DIO_U8PORTB: SET_BIT(PORTB,copy_u8pin); break;
				case  DIO_U8PORTC: SET_BIT(PORTC,copy_u8pin); break;
				case  DIO_U8PORTD: SET_BIT(PORTD,copy_u8pin); break;
				default :Local_ErrorState=1;break;

				}

			}
			else if(copy_u8value==DIO_U8PIN_LOW){

				switch(copy_u8port){

				case  DIO_U8PORTA: CLR_BIT(PORTA,copy_u8pin); break;
				case  DIO_U8PORTB: CLR_BIT(PORTB,copy_u8pin); break;
				case  DIO_U8PORTC: CLR_BIT(PORTC,copy_u8pin); break;
				case  DIO_U8PORTD: CLR_BIT(PORTD,copy_u8pin); break;
				default :Local_ErrorState=1;break;

				}


			}
			else{
				Local_ErrorState=1;
				}
		}
		else{
			Local_ErrorState = 1;
		}

		return Local_ErrorState;
}

u8 DIO_u8SetPortValue(u8 copy_u8port, u8 copy_u8value){

	u8 Local_ErrorState = 0;
	switch(copy_u8port){

		case  DIO_U8PORTA: PORTA = copy_u8value; break;
		case  DIO_U8PORTB: PORTB = copy_u8value; break;
		case  DIO_U8PORTC: PORTC = copy_u8value; break;
		case  DIO_U8PORTD: PORTD = copy_u8value; break;
		default :Local_ErrorState=1; break;

		}
	return Local_ErrorState;
}

u8 DIO_u8GetPinValue(u8 copy_u8port,u8 copy_u8pin,u8* copy_pu8value){

	u8 Local_ErrorState = 0;

	if((copy_pu8value != NULL)&&(copy_u8pin<=DIO_U8PIN7)){

		switch(copy_u8port){

			case  DIO_U8PORTA: *copy_pu8value = GET_BIT(PINA,copy_u8pin); break;
			case  DIO_U8PORTB: *copy_pu8value = GET_BIT(PINB,copy_u8pin); break;
			case  DIO_U8PORTC: *copy_pu8value = GET_BIT(PINC,copy_u8pin); break;
			case  DIO_U8PORTD: *copy_pu8value = GET_BIT(PIND,copy_u8pin); break;
			default :Local_ErrorState=1; break;

			}


	}
	else{
		Local_ErrorState = 1;
	}


	return Local_ErrorState;

}

