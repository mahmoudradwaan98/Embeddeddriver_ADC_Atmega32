/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : ADC                 *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_register.h"

static u8* ADC_ptru8Reading = NULL;

u8 ADC_u8state = IDLE;

static void(*ADC_ptrvoidCallbackNotificationFunc)(void) = NULL;

/* global variable to carry chain array */
static u8* ADC_pu8chainchannelArr = NULL;

/* global variable to carry no. of channels */

static u8 ADC_u8chainsize;

/* global variable to carry current conversion index */

static u8 ADC_u8ChainConversionIndex = 0;

/* global variable to carry chain result */

static u16* ADC_pu16chainchannelResultArr = NULL;

/*global variable to carry ISR source*/

static u8 ADC_u8ISRsource;


void ADC_voidInit(void){
		
		
		/* AVCC as reference voltage */
		
		SET_BIT(ADMUX,ADMUX_REFS0);
		CLR_BIT(ADMUX,ADMUX_REFS1);

		/* Activate left adjust result (8 bit) */
		SET_BIT(ADMUX,ADMUX_ADLAR);

		/* Set prescaler to divide by 128 */

		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);



		/* Enable peripheral */
		SET_BIT(ADCSRA,ADCSRA_ADEN);



	}
	
u8 ADC_u8StartConversionSync(u8 copy_u8channel,u8 *copy_pu8reading){
		
		/* */
		u32 Local_u32counter = 0;
		u8 Local_errorstate = OK;

		if(ADC_u8state!=BUSY){

					ADC_u8state = BUSY;

			        /* Clear the mux bits in ADMUX register */

					ADMUX &= 0b11100000;

					/* set required channels into mux bits */

					ADMUX |= copy_u8channel;

					/* ADC start conversion */

					SET_BIT(ADCSRA,ADCSRA_ADSC);

					/* polling (busy waiting) */
					while( ( GET_BIT(ADCSRA,ADCSRA_ADIF) == 0 ) && (Local_u32counter != ADC_u32TIMEOUT) ){

						Local_u32counter++;
					}

					if(Local_u32counter == ADC_u32TIMEOUT){

						/* loop is broken because Time out is reached*/
						Local_errorstate = NOK;

					}
					else
					{

						/* loop is broken because flag is fired*/

						/* Clear conversion complete flag by setting bin ADIF */

						SET_BIT(ADCSRA,ADCSRA_ADIF);

						/*return reading*/

						 *copy_pu8reading = ADCH;

						 /* ADC is finished return state to idle */

						 ADC_u8state = IDLE;

					}
		}
		else {

			Local_errorstate = BUSY_FUNC;
		}



		return Local_errorstate;
	}
	
u8 ADC_u8StartConversionAsync(u8 copy_u8channel,u8 *copy_pu8reading,void (*ptrv_Notification_func)(void)){

		u8 Local_errorstate = OK;

		if(ADC_u8state != BUSY){
			if((*copy_pu8reading==NULL)||(*ptrv_Notification_func==NULL)){

				Local_errorstate = NULLPOINTER;

			}

			else {

				/* make ADC busy in order not to work until being idle */

				ADC_u8state = BUSY;

				/* make ADC ISR source SINGLE CHANNEL ASYNC */

				ADC_u8ISRsource = SINGLE_CHANNEL_ASYNC;

				/* INIT reading variable globally */

				ADC_ptru8Reading = copy_u8channel;

				/* INIT callback notification function globally */

				ADC_ptrvoidCallbackNotificationFunc = ptrv_Notification_func;
				/* Clear conversion complete flag by setting bin ADIF */

				SET_BIT(ADCSRA,ADCSRA_ADIF);

				/* return reading */

				 *copy_pu8reading = ADCH;

				/* ADC interrupt Enable  */
				 SET_BIT(ADCSRA,ADCSRA_ADIE);
			}
		}
		else {

			Local_errorstate = BUSY_FUNC;
		}



        return Local_errorstate;
	}

u8 ADC_u8StartChainAsync(chain_t* copy_chain){

	u8 Local_u8errorstate = OK;
	/* Check null pointer */
	if(copy_chain==NULL){

		Local_u8errorstate = NULLPOINTER;
	}
	else{
		if(ADC_u8state==BUSY){

				Local_u8errorstate = BUSY_FUNC;
			}
			else{

				/* make ADC state busy */

				ADC_u8state = BUSY;

				/*make ADC ISR source CHAIN ASYNC */

				ADC_u8ISRsource = CHAIN_ASYNC;

				/* Initialize Chain channel array */

				ADC_pu8chainchannelArr = copy_chain -> Channel;

				/* Initialize Chain channel size */

				ADC_u8chainsize = copy_chain -> Size;

				/* Initialize Chain channel result */

				ADC_pu16chainchannelResultArr = copy_chain -> Result;

				/* Initialize Notification function */

				ADC_ptrvoidCallbackNotificationFunc = copy_chain -> NotificationFunc;

				/* Initialize current conversion index */

				ADC_u8ChainConversionIndex = 0;

				/* set required channel (first channel)*/

				ADMUX &= 0b11100000;

				ADMUX |= ADC_pu8chainchannelArr[ADC_u8ChainConversionIndex];

				/* Start conversion*/

				SET_BIT(ADCSRA,ADCSRA_ADSC);

				/* Enable  conversion complete interrupt */

				SET_BIT(ADCSRA,ADCSRA_ADIE);

			}

	}

	return Local_u8errorstate;
}

void __vector_16(void) __attribute__((signal));

void __vector_16(void) {


	if(ADC_u8ISRsource==SINGLE_CHANNEL_ASYNC){
		/* Read ADC result */

		*ADC_ptru8Reading = ADCH;

		/* make ADC state IDLE because it finished*/

		ADC_u8state = IDLE;

		/*Invoke callback function notification*/

		ADC_ptrvoidCallbackNotificationFunc();

		/* Disable ADC conversion complete interrupt */

		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRsource == CHAIN_ASYNC){

		/* Read current conversion */

		ADC_pu16chainchannelResultArr[ADC_u8ChainConversionIndex] = ADCH;

		/* increment chain index */

		ADC_u8ChainConversionIndex++;

		/* check  chain is finished or not */

		if(ADC_u8ChainConversionIndex==ADC_u8chainsize){

			/*chain is finished*/

			/* Make ADC state idle*/

			ADC_u8state = IDLE;

			/* Invoke Callback Notification function*/

			ADC_ptrvoidCallbackNotificationFunc();

			/*Disable ADC conversion complete Interrupt*/

			CLR_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else {

			/*chain is not finished*/

			/* Set new required channel */

			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8chainchannelArr[ADC_u8ChainConversionIndex];

			/* Start new conversion*/

			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/* */
		}

	}



}










