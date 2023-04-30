/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : ADC                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef ADC_interface_H_

 #define ADC_interface_H_

typedef struct{
	u8* Size;
	u8* Channel;
	u16* Result;
	void (*NotificationFunc) (void);
}chain_t;
 
	void ADC_voidInit(void);
	
	u8 ADC_u8StartConversionSync(u8 copy_u8channel,u8 *copy_pu8reading);

	u8 ADC_u8StartConversionAsync(u8 copy_u8channel,u8 *copy_pu8reading,void (*ptrv_Notification_func)(void));

	u8 ADC_u8StartChainAsync(chain_t* copy_chain);
		
#endif
