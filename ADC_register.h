/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : ADC                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/





#ifndef ADC_register_H_

 #define ADC_register_H_ 
	
	#define ADMUX                   *((volatile u8*)0x27)  /* ADC MULTIPLEXER SELECTION REGISTER */
	
	#define ADMUX_REFS1             7                        /* Reference selection bit 1 */ 
	#define ADMUX_REFS0             6                       /* Reference selection bit 0 */ 
	#define ADMUX_ADLAR             5                      /*  ADC left adjust result */ 
	
	#define ADCSRA                  *((volatile u8*)0x26)        /* ADC control & status REGISTER */
	
	#define ADCSRA_ADEN             7                            /* ADC ENABLE */
	#define ADCSRA_ADSC             6                            /* ADC start conversion*/
	#define ADCSRA_ADATE            5                            /* Auto trigger ENABLE*/
	#define ADCSRA_ADIF             4                            /* Interrupt flag*/
	#define ADCSRA_ADIE             3                            /* Interrupt ENABLE*/
	#define ADCSRA_ADPS2            2                            /* prescaler bit 2*/
	#define ADCSRA_ADPS1            1                            /* prescaler bit 1*/
	#define ADCSRA_ADPS0            0                            /* prescaler bit 0*/

	
	#define ADCH                 *((volatile u8*)0x25)          /* ADC HIGH REGISTER */
	#define ADCL                 *((volatile u8*)0x24)          /* ADC LOW REGISTER */
	
	
#endif
