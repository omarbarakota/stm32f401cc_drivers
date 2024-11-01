/*
 * RCC_Types.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Barakat
 */

#ifndef RCC_TYPES_H_
#define RCC_TYPES_H_

#include "Types.h"

typedef struct/*CR*/
{
	u32 HSION		:1;
	u32 HSIRDY		:1;
	u32 RESERVED0	:1;
	u32 HSITRIM		:5;
	u32 HSICAL		:8;
	u32 HSEON		:1;
	u32 HSERDY		:1;
	u32 HSEBYP		:1;
	u32 CSSON		:1;
	u32 RESERVED1	:4;
	u32 PLLON		:1;
	u32 PLLRDY		:1;
	u32 PLLI2SON	:1;
	u32 PLLI2SRDY	:1;
	u32 RESERVED2	:4;
}CR_Type;

typedef struct/*PLLCFGR*/
{
	u32 PLLM		:6;
	u32 PLLN		:9;
	u32 RESERVED0	:1;
	u32 PLLP		:2;
	u32 RESERVED1	:4;
	u32 PLLSRC		:1;
	u32 RESERVED2	:1;
	u32 PLLQ		:4;
	u32 RESERVED3	:4;
}PLLCFGR_Type;

typedef struct/*CFGR*/
{
	u32 SW			:2;
	u32 SWS			:2;
	u32 HPRE		:4;
	u32 RESERVED1	:2;
	u32 PPRE1		:3;
	u32 PPRE2		:3;
	u32 RTCPRE		:5;
	u32 MCO1		:2;
	u32 I2SSCR		:1;
	u32 MCO1PRE		:3;
	u32 MCO2PRE		:3;
	u32 MCO2		:2;
}CFGR_Type;

typedef struct/*CIR*/
{
	u32 LSIRDYF		:1;
	u32 LSERDYF		:1;
	u32 HSIRDYF		:1;
	u32 HSERDYF		:1;
	u32 PLLRDYF		:1;
	u32 PLLI2SRDYF	:1;
	u32 RESERVED0	:1;
	u32 CSSF		:1;
	u32 LSIRDYIE	:1;
	u32 LSERDYIE	:1;
	u32 HSIRDYIE	:1;
	u32 HSERDYIE	:1;
	u32 PLLRDYIE	:1;
	u32 PLLI2SRDYIE	:1;
	u32 RESERVED1	:2;
	u32 LSIRDYC		:1;
	u32 LSERDYC		:1;
	u32 HSIRDYC		:1;
	u32 HSERDYC		:1;
	u32 PLLRDYC		:1;
	u32 PLLI2SRDYC	:1;
	u32 RESERVED2	:1;
	u32 CSSC		:1;
	u32 RESERVED	:8;
}CIR_Type;

typedef struct/*AHB1RSTR*/
{
	u32 GPIOARST	:1;
	u32 GPIOBRST	:1;
	u32 GPIOCRST	:1;
	u32 GPIODRST	:1;
	u32 GPIOERST	:1;
	u32 RESERVED0	:2;
	u32 GPIOHRST	:1;
	u32 RESERVED1	:4;
	u32 CRCRST		:1;
	u32 RESERVED2	:8;
	u32 DMA1RST		:1;
	u32 DMA2RST		:1;
	u32 RESERVED3	:9;
}AHB1RSTR_BITS_Type;

typedef union{
	u32 REG;
	AHB1RSTR_BITS_Type BITS;
}AHB1RSTR_Type;
typedef struct/*AHB2RSTR*/
{
	u32 RESERVED0	:7;
	u32 OTGFSRST	:1;
	u32 RESERVED1	:24;
}AHB2RSTR_Type;

typedef struct/*APB1RSTR*/
{
	u32 TIM2RST		:1;
	u32 TIM3RST		:1;
	u32 TIM4RST		:1;
	u32 TIM5RST		:1;
	u32 RESERVED0	:7;
	u32 WWDGRST		:1;
	u32 RESERVED1	:2;
	u32 SPI2RST		:1;
	u32 SPI3RST		:1;
	u32 RESERVED2	:1;
	u32 USART2RST	:1;
	u32 RESERVED3	:3;
	u32 I2C1RST		:1;
	u32 I2C2RST		:1;
	u32 I2C3RST		:1;
	u32 RESERVED4	:4;
	u32 PWRRST		:1;
	u32 RESERVED5	:3;
}APB1RSTR_BITS_Type;

typedef union{
	u32 REG;
	APB1RSTR_BITS_Type BITS;
}APB1RSTR_Type;

typedef struct/*APB2RSTR*/
{
	u32 TIM1RST		:1;
	u32 RESERVED0	:3;
	u32 USART1RST	:1;
	u32 USART6RST	:1;
	u32 RESERVED1	:2;
	u32 ADC1RST		:1;
	u32 RESERVED2	:2;
	u32 SDIORST		:1;
	u32 SPI1RST		:1;
	u32 SPI4RST		:1;
	u32 SYSCFGRST	:1;
	u32 RESERVED3	:1;
	u32 TIM9RST		:1;
	u32 TIM10RST	:1;
	u32 TIM11RST	:1;
	u32 RESERVED4:	13;
}APB2RSTR_BITS_Type;

typedef union{
	u32 REG;
	APB2RSTR_BITS_Type BITS;
}APB2RSTR_Type;

typedef struct/*AHB1ENR*/
{
	u32 GPIOAEN		:1;
	u32 GPIOBEN		:1;
	u32 GPIOCEN		:1;
	u32 GPIODEN		:1;
	u32 GPIOEEN		:1;
	u32 RESERVED0	:2;
	u32 GPIOHEN		:1;
	u32 RESERVED1	:4;
	u32 CRCEN		:1;
	u32 RESERVED3	:8;
	u32 DMA1EN		:1;
	u32 DMA2EN		:1;
	u32 RESERVED4	:9;
}AHB1ENR_BITS_Type;
typedef union{
	u32 REG;
	AHB1ENR_BITS_Type BITS;
}AHB1ENR_Type;

typedef struct/*AHB2ENR*/
{
	u32 RESERVED0	:7;
	u32 OTGFSEN		:1;
	u32 RESERVED1	:24;
}AHB2ENR_Type;

typedef struct/*APB1ENR*/
{
	u32 TIM2EN		:1;
	u32 TIM3EN		:1;
	u32 TIM4EN		:1;
	u32 TIM5EN		:1;
	u32 RESERVED0	:7;
	u32 WWDGEN		:1;
	u32 RESERVED1	:2;
	u32 SPI2EN		:1;
	u32 SPI3EN		:1;
	u32 RESERVED2	:1;
	u32 USART2EN	:1;
	u32 RESERVED3	:3;
	u32 I2C1EN		:1;
	u32 I2C2EN		:1;
	u32 I2C3EN		:1;
	u32 RESERVED4	:4;
	u32 PWREN		:1;
	u32 RESERVED5	:3;
}APB1ENR_BITS_Type;
typedef union{
	u32 REG;
	APB1ENR_BITS_Type BITS;
}APB1ENR_Type;

typedef struct/*APB2ENR*/
{
	u32 TIM1EN		:1;
	u32 RESERVED0	:3;
	u32 USART1EN	:1;
	u32 USART6EN	:1;
	u32 RESERVED1	:2;
	u32 ADC1EN		:1;
	u32 RESERVED2	:2;
	u32 SDIOEN		:1;
	u32 SPI1EN		:1;
	u32 SPI4EN		:1;
	u32 SYSCFGEN	:1;
	u32 RESERVED3	:1;
	u32 TIM9EN		:1;
	u32 TIM10EN		:1;
	u32 TIM11EN		:1;
	u32 RESERVED4	:13;
}APB2ENR_BITS_Type;
typedef union{
	u32 REG;
	APB2ENR_BITS_Type BITS;
}APB2ENR_Type;

typedef struct/*AHB1LPENR*/
{
	u32 GPIOALPEN	:1;
	u32 GPIOBLPEN	:1;
	u32 GPIOCLPEN	:1;
	u32 GPIODLPEN	:1;
	u32 GPIOELPEN	:1;
	u32 RESERVED0	:2;
	u32 GPIOHLPEN	:1;
	u32 RESERVED1	:4;
	u32 CRCLPEN		:1;
	u32 RESERVED2	:2;
	u32 FLITFLPEN	:1;
	u32 SRAM1LPEN	:1;
	u32 RESERVED3	:4;
	u32 DMA1LPEN	:1;
	u32 DMA2LPEN	:1;
	u32 RESERVED4	:9;
}AHB1LPENR_BITS_Type;
typedef union{
	u32 REG;
	AHB1LPENR_BITS_Type BITS;
}AHB1LPENR_Type;

typedef struct/*AHB2LPENR*/
{
	u32 RESERVED0	:7;
	u32 OTGFSLPEN	:1;
	u32 RESERVED1	:24;
}AHB2LPENR_Type;

typedef struct/*APB1LPENR*/
{
	u32 TIM2LPEN	:1;
	u32 TIM3LPEN	:1;
	u32 TIM4LPEN	:1;
	u32 TIM5LPEN	:1;
	u32 RESERVED3	:7;
	u32 WWDGLPEN	:1;
	u32 RESERVED4	:2;
	u32 SPI2LPEN	:1;
	u32 SPI3LPEN	:1;
	u32 RESERVED5	:1;
	u32 USART2LPEN	:1;
	u32 RESERVED6	:3;
	u32 I2C1LPEN	:1;
	u32 I2C2LPEN	:1;
	u32 I2C3LPEN	:1;
	u32 RESERVED7	:4;
	u32 PWRLPEN		:1;
	u32 RESERVED8	:3;
}APB1LPENR_BITS_Type;
typedef union{
	u32 REG;
	APB1LPENR_BITS_Type BITS;
}APB1LPENR_Type;

typedef struct/*APB2LPENR*/
{
	u32 TIM1LPEN	:1;
	u32 RESERVED0	:3;
	u32 USART1LPEN	:1;
	u32 USART6LPEN	:1;
	u32 RESERVED1	:2;
	u32 ADC1LPEN	:1;
	u32 RESERVED2	:2;
	u32 SDIOLPEN	:1;
	u32 SPI1LPEN	:1;
	u32 SPI4LPEN	:1;
	u32 SYSCFGLPEN	:1;
	u32 RESERVED3	:1;
	u32 TIM9LPEN	:1;
	u32 TIM10LPEN	:1;
	u32 TIM11LPEN	:1;
	u32 RESERVED4	:13;
}APB2LPENR_BITS_Type;
typedef union{
	u32 REG;
	APB2LPENR_BITS_Type BITS;
}APB2LPENR_Type;

typedef struct/*BDCR*/
{
	u32 LSEON		:1;
	u32 LSERDY		:1;
	u32 LSEBYP		:1;
	u32 RESERVED0	:5;
	u32 RTCSEL0		:1;
	u32 RTCSEL1		:1;
	u32 RESERVED1	:5;
	u32 RTCEN		:1;
	u32 BDRST		:1;
	u32 RESERVED2	:15;
}BDCR_Type;

typedef struct/*CSR*/
{
	u32 LSION		:1;
	u32 LSIRDY		:1;
	u32 RESERVED0	:22;
	u32 RMVF		:1;
	u32 BORRSTF		:1;
	u32 PINRSTF		:1;
	u32 PORRSTF		:1;
	u32 SFTRSTF		:1;
	u32 IWDGRSTF	:1;
	u32 WWDGRSTF	:1;
	u32 LPWRRSTF	:1;
}CSR_Type;

typedef struct/*INCSTEP_BITS_Type*/
{
	u32 INCSTEP0:1;
	u32 INCSTEP1:1;
	u32 INCSTEP2:1;
	u32 INCSTEP3:1;
	u32 INCSTEP4:1;
	u32 INCSTEP5:1;
	u32 INCSTEP6:1;
	u32 INCSTEP7:1;
	u32 INCSTEP8:1;
	u32 INCSTEP9:1;
	u32 INCSTEP10:1;
	u32 INCSTEP11:1;
	u32 INCSTEP12:1;
	u32 INCSTEP13:1;
	u32 INCSTEP14:1;
}INCSTEP_BITS_Types;
typedef union/*INCSTEP_Type*/
{
	INCSTEP_BITS_Types	BITS;
	u32					ALLREG:15;
}INCSTEP_Type;

typedef struct/*MODPER_BITS_Type*/
{
	u32 b0:1;
	u32 b1:1;
	u32 b2:1;
	u32 b3:1;
	u32 b4:1;
	u32 b5:1;
	u32 b6:1;
	u32 b7:1;
	u32 b8:1;
	u32 b9:1;
	u32 b10:1;
	u32 b11:1;
	u32 b12:1;
}MODPER_BITS_Type;
typedef union/*MODPER_Type*/
{
	MODPER_BITS_Type	BITS;
	u32					ALLREG:13;
}MODPER_Type;

typedef struct/*SSCGR*/
{
	MODPER_Type 	MODPER		;/*13Bit*/
	INCSTEP_Type	INCSTEP		;/*15Bit*/
	u32				RESERVED	:2;
	u32 			SPREADSEL	:1;
	u32 			SSCGEN		:1;
}SSCGR_Type;


typedef struct/*PLLI2SN BITS*/
{
	u32 b0:1;
	u32 b1:1;
	u32 b2:1;
	u32 b3:1;
	u32 b4:1;
	u32 b5:1;
	u32 b6:1;
	u32 b7:1;
	u32 b8:1;
}PLLI2SN_BITS_Type;
typedef union{/*PLLI2SN Type*/
	PLLI2SN_BITS_Type BITS;
	u32 			  ALLREG:9;
}PLLI2SN_Type;

typedef struct/*PLLI2SR BITS*/
{
	u32 PLLI2SR0:1;
	u32 PLLI2SR1:1;
	u32 PLLI2SR3:1;
}PLLI2SR_BITS_Type;
typedef union{/*PLLI2SR Type*/
	PLLI2SR_BITS_Type BITS;
	u32 			  ALLREG:3;
}PLLI2SR_Type;


typedef struct/*PLLI2SCFGR_Type*/
{
	u32 			RESERVED0	:6;
	PLLI2SN_Type	PLLI2SN		;/*9Bit*/
	u32 			RESERVED1	:13;
	PLLI2SR_Type 	PLLI2SR		;/*3Bit*/
	u32 			RESERVED2	:1;

}PLLI2SCFGR_Type;


typedef struct/*DCKCFGR*/
{
    u32  RESERVED0	:23;
    u32  TIMPRE		:1;
    u32  RESERVED1	:8;
}DCKCFGR_Type;


typedef struct/*RCC*/
{
    CR_Type          CR;
    PLLCFGR_Type     PLLCFGR;
    CFGR_Type        CFGR;
    CIR_Type         CIR;

    AHB1RSTR_Type    AHB1RSTR;
    AHB2RSTR_Type    AHB2RSTR;

    u32              RESERVED0;
    u32              RESERVED1;

    APB1RSTR_Type    APB1RSTR;
    APB2RSTR_Type    APB2RSTR;

    u32              RESERVED2;
    u32              RESERVED3;

    AHB1ENR_Type     AHB1ENR;
    AHB2ENR_Type     AHB2ENR;

    u32              RESERVED4;
    u32              RESERVED5;
    
    APB1ENR_Type     APB1ENR;
    APB2ENR_Type     APB2ENR;

    u32              RESERVED6;
    u32              RESERVED7;
    
    AHB1LPENR_Type   AHB1LPENR;
    AHB2LPENR_Type   AHB2LPENR;

    u32              RESERVED8;
    u32              RESERVED9;
    
    APB1LPENR_Type   APB1LPENR;
    APB2LPENR_Type   APB2LPENR;

    u32              RESERVED10;
    u32              RESERVED11;
    
    BDCR_Type        BDCR;
    CSR_Type         CSR;

    u32              RESERVED12;
    u32              RESERVED13;
    
    SSCGR_Type       SSCGR;
    PLLI2SCFGR_Type  PLLI2SCFGR;

    u32              RESERVED14;
    
    DCKCFGR_Type     DCKCFGR;

}RCC_Reg;

#endif /* MCAL_AUTOSARRCC_RCC_TYPES_H_ */
