/*
 * Systick_Private.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Barakat
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#include "Systick_Types.h"

#define STK 		((volatile STK_CorePreph_t*)0xE000E010)

/* You can use only one way whether by accessing all registers in peripheral
 * using a single pointer To structure like what i did
 * Or
 * define each register with it's address like down below
 *		 #define STK_CTRL		*((volatile u32*)0xE000E010)
 *		 #define STK_LOAD		*((volatile u32*)0xE000E014)
 *		 #define STK_VAL		*((volatile u32*)0xE000E018)
 *		 #define STK_CALIB 		*((volatile u32*)0xE000E01C)
 */

/* Clock Source Options */
#define STK_AHB_CLK					0
#define STK_AHB_CLK_DIV_BY_8		1

/*Interval Flag Types */
#define STK_IntervalFlag_Single		0
#define STK_IntervalFlag_Period		1


#endif /* SYSTICK_PRIVATE_H_ */
