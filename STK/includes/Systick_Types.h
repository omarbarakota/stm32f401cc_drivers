/*
 * STK_Types.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Barakat
 */

#ifndef SYSTICK_TYPES_H_
#define SYSTICK_TYPES_H_

#include "Types.h"

typedef struct{/*STK_CTRL_Bits_t*/
	u32 ENABLE 		:1;
	u32 TICKINT 	:1;
	u32 CLKSOURCE	:1;
	u32 RESERVED0	:13;
	u32 COUNTFLAG	:1;
	u32 RESERVED1	:15;
}STK_CTRL_Bits_t;
typedef union{/*STK_CTRL_Reg_t*/
	STK_CTRL_Bits_t BITS;
	u32			   	REG;
}STK_CTRL_Reg_t;

typedef struct{/*STK_LOAD_Bits_t*/
	u32 RELOAD 		:24;
	u32 RESERVED 	:8;
}STK_LOAD_Bits_t;
typedef union{/*STK_LOAD_Reg_t*/
	STK_LOAD_Bits_t BITS;
	u32			   	REG;
}STK_LOAD_Reg_t;

typedef struct{/*STK_VAL_Bits_t*/
	u32 CURRENT 	:24;
	u32 RESERVED 	:8;
}STK_VAL_Bits_t;
typedef union{/*STK_VAL_Reg_t*/
	STK_VAL_Bits_t 	BITS;
	u32			   	REG;
}STK_VAL_Reg_t;

typedef struct{/*STK_CALIB_Bits_t*/
	u32 TENMS 		:24;
	u32 RESERVED 	:6;
	u32 SKEW		:1;
	u32 NOREF		:1;
}STK_CALIB_Bits_t;
typedef union{/*STK_CALIB_Reg_t*/
	STK_CTRL_Bits_t BITS;
	u32			   		REG;
}STK_CALIB_Reg_t;


typedef struct{/*STK_Type*/
	STK_CTRL_Reg_t		CTRL;
	STK_LOAD_Reg_t 	 	LOAD;
	STK_VAL_Reg_t 	 	VAL;
	STK_CALIB_Reg_t		CALIB;
}STK_CorePreph_t;


#endif /* SYSTICK_TYPES_H_ */
