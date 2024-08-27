/*
 * Systick_Config.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Barakat
 */

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

/* Systick Clock Options
 * 1- STK_AHB_CLK
 * 2- STK_AHB_CLK_DIV_BY_8
 */
#define STK_CLK		STK_AHB_CLK_DIV_BY_8

/*
 * HSI=16000000
 * HSE=(4:26)000000Mhz
 * PLL=
 */
/*This depends on the RCC System Clock Configurations*/
#define STK_CLK_Value 16000000

#endif /* SYSTICK_CONFIG_H_ */
