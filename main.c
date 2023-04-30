/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: User
 */


#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "PORT_interface.h"


void ADC_notification (void);

u8 APP_u8ADCReading;

void main(void){

//	u8 Local_u8ADCReading;
//	u8 *Local_u8ptr = &Local_u8ADCReading;

    PORT_voidInit();

    ADC_voidInit();

    while(1){

//    	ADC_u8StartConversionSync(0,Local_u8ptr);

    	ADC_u8StartConversionAsync(0,&APP_u8ADCReading,&ADC_notification);

//    	DIO_u8SetPortValue(DIO_U8PORTC,*Local_u8ptr);

    }


}

void ADC_notification (void){

	DIO_u8SetPortValue(DIO_U8PORTC,APP_u8ADCReading);

}
