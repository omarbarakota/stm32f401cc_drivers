/*
 * BitMath.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Barakat
 */

#ifndef _LIB_BITMATH_H_
#define _LIB_BITMATH_H_

#define SET_BIT(VAR,BIT_NO)			((VAR)|=(1<<(BIT_NO)))
#define CLR_BIT(VAR,BIT_NO)			((VAR) &= (~(1<<(BIT_NO))))
#define TOGGLE_BIT(VAR,BIT_NO)		((VAR) ^= (1<<(BIT_NO)))
#define GET_BIT(VAR,BIT_NO)			(((VAR)>>(BIT_NO))&1)

//#define SET_BIT(BYTE,BIT_NUM)		(BYTE) |= (1<<(BIT_NUM))
#define CLEAR_BIT(BYTE,BIT_NUM)		(BYTE) &=(~(1<<BIT_NUM))
#define TOGGEL_BIT (BYTE,BIT_NUM)	(BYTE)^=((1<<BIT_NUM))
//#define GET_BIT(BYTE,BIT_NUM)		((BYTE>>BIT_NUM)&1)

#define READ_REG(REG)				((REG))
#define CLEAR_REG(REG)				((REG &=( 0x0)))
#define SET_REG(REG)				((REG)|=(0xFFFFFFFF))
#define WRITE_REG(REG,VALUE)		((REG)=(VALUE))
#define MODIFY_REG(REG,SET_MSK,CLEAR_MSK)	 (WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEAR_MSK))) | (SET_MSK))))

#define SET_BYTE(BYTE) (BYTE|=(0xFF))
#define CLEAR_BYTE(BYTE) (BYTE &=0x00
#define SET_NIBBLE_HIGH(Byte) (Byte |=(0xF0))
#define SET_NIBBLE_LOW(Byte) (Byte |=(0x0F))
#define CLEAR_NIBBLE_HIGH(Byte) (Byte &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte) (Byte &=(0xF0)))


#endif /* BITMATH_H_ */
