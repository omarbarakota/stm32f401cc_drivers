/*
 * RCC_HW.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Barakat
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#include "RCC_Types.h"

#define RCC_BASE_ADDRESS	0x40023800

#define RCC 		((volatile RCC_Reg*)RCC_BASE_ADDRESS)

#define RCC_Peripheral_Size 32
/*Clock Source Configurations*/
#define RCC_HSI	0
#define RCC_HSE	1
#define RCC_PLL	2

/*HSE Modes*/
#define RCC_HSE_BYPASS		1
#define RCC_HSE_CRYSTAL		0

#define RCC_PLL_HSI			0
#define RCC_PLL_HSE			1
/*Clock Frequencies */
#define RCC_PLL2			0
#define RCC_PLL4			1
#define RCC_PLL6			2
#define RCC_PLL8			3

/*PLL Configuration maximum values*/
#define PLLM_Max 			63
#define PLLN_Max 			433
#define PLLP_Max 			3
#define PLLQ_Max	    	15

#define RCC_CFGR_SW			0x00000003UL
#define RCC_CFGR_SWS		0x0000000CUL

#define RCC_CFGR_SWS_HSI			0x00000000CUL
#define RCC_CFGR_SWS_HSE			0x00000004CUL
#define RCC_CFGR_SWS_PLL			0x00000008CUL

//Main PLL division factor
#define RCC_PLL_DIV_FACTOR_NONE			0x00000000
#define RCC_PLL_DIV_FACTOR_2			0x00020000	//VALUE of RCC_CFGR_PLLXTPRE





#endif /* MCAL_AUTOSARRCC_RCC_HW_H_ */

