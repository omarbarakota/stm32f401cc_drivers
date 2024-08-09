/*
 * RCC_Config.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_AUTOSARRCC_RCC_CONFIG_H_
#define MCAL_AUTOSARRCC_RCC_CONFIG_H_

#include "RCC_Private.h"

/*The system's clock source options
 * 1-RCC_HSI
 * 2-RCC_HSE
 * 3-RCC_PLL
 */
#define RCC_CLK_SRC RCC_HSI

#if RCC_CLK_SRC==RCC_HSE

/* HSE Mode Configurations
 * 1-RCC_HSE_BYPASS
 * 2-RCC_HSE_CRYSTAL
 */
#define RCC_HSE_MODE	RCC_HSE_CRYSTAL

#elif RCC_CLK_SRC==RCC_PLL
/*PLL Configurations*/
/* Equation-> CLK_SRC_OUT=CLK_SRC_IN/M*N/P
 * Equation-> CLK_SRC_OUT=CLK_SRC_IN/M*N/P
 * */
/*PLLSRC options
 * 1-RCC_PLL_HSI
 * 2-RCC_PLL_HSE
 */
#define RCC_PLL_SRC		RCC_PLL_HSE
/*PLLP options
 * Out clock freq=VCO freq/PLLP
 * 1-RCC_PLL2
 * 2-RCC_PLL4
 * 3-RCC_PLL6
 * 4-RCC_PLL8
 */
#define RCC_PLLP	RCC_PLL4

/*PLLM options
 * 2:63
 */
#define RCC_PLLM		4

/*PLLN options
 * 2:432
 */
#define RCC_PLLN		16

/*PLLQ options
 * 2:15
 */
#define RCC_PLLQ		2

#endif	//RCC_CLK_SRC Modes
#endif /* MCAL_AUTOSARRCC_RCC_CONFIG_H_ */
