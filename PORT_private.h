/*******************************************************************************/
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : PORT                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/





#ifndef PORT_private_H_

 #define PORT_private_H_
 
 
	  
	
	#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                CONCHELPER(b7,b6,b5,b4,b3,b2,b1,b0)
	
	#define CONCHELPER(b7,b6,b5,b4,b3,b2,b1,b0)          0b##b7##b6##b5##b4##b3##b2##b1##b0
	
	#define PORTA_DIR   CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)

	#define PORTB_DIR   CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
	
	#define PORTC_DIR   CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
	
	#define PORTD_DIR   CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)
	
	
	#define PORTA_Inital_Value   CONC(PORTA_PIN7_Inital_Value,PORTA_PIN6_Inital_Value,PORTA_PIN5_Inital_Value,PORTA_PIN4_Inital_Value,PORTA_PIN3_Inital_Value,PORTA_PIN2_Inital_Value,PORTA_PIN1_Inital_Value,PORTA_PIN0_Inital_Value)

	#define PORTB_Inital_Value   CONC(PORTB_PIN7_Inital_Value,PORTB_PIN6_Inital_Value,PORTB_PIN5_Inital_Value,PORTB_PIN4_Inital_Value,PORTB_PIN3_Inital_Value,PORTB_PIN2_Inital_Value,PORTB_PIN1_Inital_Value,PORTB_PIN0_Inital_Value)
	
	#define PORTC_Inital_Value   CONC(PORTC_PIN7_Inital_Value,PORTC_PIN6_Inital_Value,PORTC_PIN5_Inital_Value,PORTC_PIN4_Inital_Value,PORTC_PIN3_Inital_Value,PORTC_PIN2_Inital_Value,PORTC_PIN1_Inital_Value,PORTC_PIN0_Inital_Value)
	
	#define PORTD_Inital_Value   CONC(PORTD_PIN7_Inital_Value,PORTD_PIN6_Inital_Value,PORTD_PIN5_Inital_Value,PORTD_PIN4_Inital_Value,PORTD_PIN3_Inital_Value,PORTD_PIN2_Inital_Value,PORTD_PIN1_Inital_Value,PORTD_PIN0_Inital_Value)
	
#endif