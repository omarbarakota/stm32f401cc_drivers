/*
 * NVIC_Private.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Barakat
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "NVIC_Types.h"

#define NVIC_BASE_ADDRESS  0xE000E100

#define NVIC ((volatile NVIC_t*)NVIC_BASE_ADDRESS)

/*This Register in a seperate block*/
//#define NVIC_STIR ((volatile NVIC_t*)NVIC_BASE_ADDRESS+0xE00)

#define SCB_BASE_ADDRESS  0xE000E008

#define SCB ((volatile SCB_t*)SCB_BASE_ADDRESS)

/*This Register in a seperate block*/
#define SCB_ACTLR	0xE000E008

/*
ACTLR 	0xE000E008
CPUID 	0xE000ED00
ICSR  	0xE000ED04
VTOR	0xE000ED08
AIRCR   0xE000ED0C
SCR     0xE000ED10
CCR     0xE000ED14
SHPR1   0xE000ED18
SHPR2   0xE000ED1C
SHPR3   0xE000ED20
SHCSR   0xE000ED24
CFSR    0xE000ED28
MMSR    0xE000ED28
BFSR    0xE000ED29
UFSR    0xE000ED2A
HFSR    0xE000ED2C
MMAR    0xE000ED34
BFAR    0xE000ED38
ASFAR   0xE000ED3C
*/


#endif /* NVIC_PRIVATE_H_ */
