/*
 * RCC.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Barakat
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "Types.h"
#include "RCC_Types.h"

/*Interface Macros*/

//Busses
#define RCC_AHB1_BUS         0
#define RCC_AHB2_BUS         1
#define RCC_APB1_BUS         2
#define RCC_APB2_BUS         3

/*Peripherals IDS*/

//AHB1 Peripherals Clock enable
#define RCC_AHB1ENR_GPIOA	0
#define RCC_AHB1ENR_GPIOB	1
#define RCC_AHB1ENR_GPIOC	2
#define RCC_AHB1ENR_GPIOD	3
#define RCC_AHB1ENR_GPIOE	4
#define RCC_AHB1ENR_GPIOH	7
#define RCC_AHB1ENR_CRC		12
#define RCC_AHB1ENR_DMA1	21
#define RCC_AHB1ENR_DMA2	22


//AHB2 PREPHERALS CLOCK ENABLE
#define RCC_AHB2ENR_OTGFSEN	22

//APB2 Peripherals Clock enable
#define RCC_APB1ENR_TIM2EN		0
#define RCC_APB1ENR_TIM3EN		1
#define RCC_APB1ENR_TIM4EN		2
#define RCC_APB1ENR_TIM5EN		3
#define RCC_APB1ENR_WWDGEN		11
#define RCC_APB1ENR_SPI2EN		14
#define RCC_APB1ENR_SPI3EN		15
#define RCC_APB1ENR_USART2EN	17
#define RCC_APB1ENR_I2C1EN		21
#define RCC_APB1ENR_I2C2EN		22
#define RCC_APB1ENR_I2C3EN		23
#define RCC_APB1ENR_PWREN		28

//APB1 Peripherals Clock enable
#define RCC_APB2ENR_TIM1EN		0
#define RCC_APB2ENR_USART1EN	4
#define RCC_APB2ENR_USART6EN	5
#define RCC_APB2ENR_ADC1EN		8
#define RCC_APB2ENR_SDIOEN		11
#define RCC_APB2ENR_SPI1EN		12
#define RCC_APB2ENR_SPI4EN		13
#define RCC_APB2ENR_SYSCFGEN	14
#define RCC_APB2ENR_TIM9EN		16
#define RCC_APB2ENR_TIM10EN		17
#define RCC_APB2ENR_TIM11EN		18

/* API Function Prototypes */

Error_Types RCC_u8InitSysClk			(void);

Error_Types RCC_u8EnableHSE				(u32 HSE_mode);
Error_Types RCC_u8DisableHSE			(void);

Error_Types RCC_u8EnableHSI				(void);
Error_Types RCC_u8EnableHSI				(void);

Error_Types RCC_u8PLLConfig				(u8 PLLM,u8 PLLN,u8 PLLP,u8 PLLQ);

Error_Types RCC_u8EnablePeriphiralClk	(u8 BusID,u8 PeripheralID);
Error_Types RCC_u8DisablePeriphiralClk	(u8 BusID,u8 PeripheralID);








#endif /* MCAL_AUTOSARRCC_RCC_H_ */
