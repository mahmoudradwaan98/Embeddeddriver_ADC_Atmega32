#ifndef BIT_MATH_H_

	#define BIT_MATH_H_
	
		#define SET_BIT(BYTE,BIT_NO)    (BYTE) |= (1 << BIT_NO)
		#define CLR_BIT(BYTE,BIT_NO)    (BYTE) &= (~(1 << BIT_NO))
		#define GET_BIT(BYTE,BIT_NO)    (BYTE >> BIT_NO) & 0x01
		#define TOGGLE_BIT(BYTE,BIT_NO) (BYTE) ^= (1<<BIT_NO)
		
		
		#define SET_BYTE(Byte) (Byte |=(0xFF))
		#define CLEAR_BYTE(Byte) (Byte &=(0x00))
		#define SET_NIBBLE_HIGH(Byte) (Byte |=(0xF0))
		#define SET_NIBBLE_LOW(Byte) (Byte |=(0x0F))
		#define CLEAR_NIBBLE_HIGH(Byte) (Byte &=(0x0F))
		#define CLEAR_NIBBLE_LOW(Byte) (Byte &=(0xF0))
				
		
		#define BIT_CONC(A7,A6,A5,A4,A3,A2,A1,A0)  CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)
		#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)  0b##A7##A6##A5##A4##A3##A2##A1##A0		
		

#endif
