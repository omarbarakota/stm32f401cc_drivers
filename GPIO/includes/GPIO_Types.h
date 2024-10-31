/*
 * GPIO_Types.h
 *
 *  Created on: Aug 9, 2023
 *     Author: Barakat
 */
#ifndef _MCAL_GPIO_TYPES_H_
#define _MCAL_GPIO_TYPES_H_
#include "Types.h"


typedef struct{/*MODER_BITS*/
	u32 MODER0:2;
	u32 MODER1:2;
	u32 MODER2:2;
	u32 MODER3:2;
	u32 MODER4:2;
	u32 MODER5:2;
	u32 MODER6:2;
	u32 MODER7:2;
	u32 MODER8:2;
	u32 MODER9:2;
	u32 MODER10:2;
	u32 MODER11:2;
	u32 MODER12:2;
	u32 MODER13:2;
	u32 MODER14:2;
	u32 MODER15:2;
}MODER_BITS_Type;
typedef union{/*PUPDR_Type*/
	MODER_BITS_Type  BITS;
	u32			     REG;
}MODER_Type;



typedef struct{/*OTYPER_BITS*/
	u32 OT0	 	 :1;
	u32 OT1	 	 :1;
	u32 OT2	  	 :1;
	u32 OT3	 	 :1;
	u32 OT4	 	 :1;
	u32 OT5		 :1;
	u32 OT6		 :1;
	u32 OT7 	 :1;
	u32 OT8		 :1;
	u32 OT9		 :1;
	u32 OT10	 :1;
	u32 OT11 	 :1;
	u32 OT12 	 :1;
	u32 OT13	 :1;
	u32 OT14 	 :1;
	u32 OT15	 :1;
	u32 RESERVED :16;
}OTYPER_BITS_Type;
typedef union{/*OTYPER_Type*/
	OTYPER_BITS_Type  BITS;
	u32			      REG;
}OTYPER_Type;



typedef struct{/*OSPEEDR_BITS*/
	u32 OSPEEDR0 :2;
	u32 OSPEEDR1 :2;
	u32 OSPEEDR2 :2;
	u32 OSPEEDR3 :2;
	u32 OSPEEDR4 :2;
	u32 OSPEEDR5 :2;
	u32 OSPEEDR6 :2;
	u32 OSPEEDR7 :2;
	u32 OSPEEDR8 :2;
	u32 OSPEEDR9 :2;
	u32 OSPEEDR10:2;
	u32 OSPEEDR11:2;
	u32 OSPEEDR12:2;
	u32 OSPEEDR13:2;
	u32 OSPEEDR14:2;
	u32 OSPEEDR15:2;
}OSPEEDR_BITS_Type;
typedef union{/*OSPEEDR_Type*/
	OSPEEDR_BITS_Type  BITS;
	u32			       REG;
}OSPEEDR_Type;


typedef struct{/*PUPDR_BIS*/
	u32 PUPDR0:2;
	u32 PUPDR1:2;
	u32 PUPDR2:2;
	u32 PUPDR3:2;
	u32 PUPDR4:2;
	u32 PUPDR5:2;
	u32 PUPDR6:2;
	u32 PUPDR7:2;
	u32 PUPDR8:2;
	u32 PUPDR9:2;
	u32 PUPDR10:2;
	u32 PUPDR11:2;
	u32 PUPDR12:2;
	u32 PUPDR13:2;
	u32 PUPDR14:2;
	u32 PUPDR15:2;
}PUPDR_BITS_Type;
typedef union{/*PUPDR_Type*/
	PUPDR_BITS_Type  BITS;
	u32			     REG;
}PUPDR_Type;

typedef struct{/*IDR_BITS*/
	u32 IDR0	 :1;
	u32 IDR1	 :1;
	u32 IDR2	 :1;
	u32 IDR3	 :1;
	u32 IDR4	 :1;
	u32 IDR5	 :1;
	u32 IDR6	 :1;
	u32 IDR7 	 :1;
	u32 IDR8	 :1;
	u32 IDR9	 :1;
	u32 IDR10	 :1;
	u32 IDR11 	 :1;
	u32 IDR12 	 :1;
	u32 IDR13	 :1;
	u32 IDR14 	 :1;
	u32 IDR15	 :1;
	u32 RESERVED:16;
}IDR_BITS_Type;
typedef union{/*IDR_Type*/
	IDR_BITS_Type  BITS;
	u32			   REG;
}IDR_Type;


typedef struct{/*ODR_BITS*/
	u32 ODR0	 :1;
	u32 ODR1	 :1;
	u32 ODR2	 :1;
	u32 ODR3	 :1;
	u32 ODR4	 :1;
	u32 ODR5	 :1;
	u32 ODR6	 :1;
	u32 ODR7 	 :1;
	u32 ODR8	 :1;
	u32 ODR9	 :1;
	u32 ODR10	 :1;
	u32 ODR11 	 :1;
	u32 ODR12 	 :1;
	u32 ODR13	 :1;
	u32 ODR14 	 :1;
	u32 ODR15	 :1;
	u32 RESERVED:16;
}ODR_BITS_Type;
typedef union{/*ODR_Type*/
	ODR_BITS_Type  BITS;
	u32			   REG;
}ODR_Type;


typedef struct{/*BSRR_BITS*/
	u32 BS0		:1;
	u32 BS1		:1;
	u32 BS2		:1;
	u32 BS3		:1;
	u32 BS4		:1;
	u32 BS5		:1;
	u32 BS6		:1;
	u32 BS7		:1;
	u32 BS8		:1;
	u32 BS9		:1;
	u32 BS10	:1;
	u32 BS11	:1;
	u32 BS12	:1;
	u32 BS13	:1;
	u32 BS14	:1;
	u32 BS15	:1;
}BSRR_BS_BITS_Type;
typedef struct{
	u32 BR0		:1;
	u32 BS1		:1;
	u32 BR2		:1;
	u32 BR3		:1;
	u32 BR4		:1;
	u32 BR5		:1;
	u32 BR6		:1;
	u32 BR7		:1;
	u32 BR8		:1;
	u32 BR9		:1;
	u32 BR10	:1;
	u32 BR11	:1;
	u32 BR12	:1;
	u32 BR13	:1;
	u32 BR14	:1;
	u32 BR15	:1;
}BSRR_BR_BITS_Type;
typedef union{
	BSRR_BS_BITS_Type BITS;
	u16			   	  REG;
}BSRR_BS_Type;
typedef union{
	BSRR_BR_BITS_Type BITS;
	u16			   	  REG;
}BSRR_BR_Type;
typedef struct{
	BSRR_BS_Type	BS;
	BSRR_BR_Type	BR;
}BSRR_BITS_Type;
typedef union{/*BSRR_Type*/
	BSRR_BITS_Type BITS;
	u32			   REG;
}BSRR_Type;


typedef struct{/*LCKR_BITS*/
	u32 LCK0:1;
	u32 LCK1:1;
	u32 LCK2:1;
	u32 LCK3:1;
	u32 LCK4:1;
	u32 LCK5:1;
	u32 LCK6:1;
	u32 LCK7:1;
	u32 LCK8:1;
	u32 LCK9:1;
	u32 LCK10:1;
	u32 LCK11:1;
	u32 LCK12:1;
	u32 LCK13:1;
	u32 LCK14:1;
	u32 LCK15:1;
	u32 LCKK:1;
	u32 RESERVED:15;
}LCKR_BITS_Type;
typedef union{/*LCKR_Type*/
	LCKR_BITS_Type BITS;
	u32			   REG;
}LCKR_Type;


typedef struct{/*AFRL_BITS*/
	u32 AFRL0 :4;
	u32 AFRL1 :4;
	u32 AFRL2 :4;
	u32 AFRL3 :4;
	u32 AFRL4 :4;
	u32 AFRL5 :4;
	u32 AFRL6 :4;
	u32 AFRL7:4;
}AFRL_BITS_Type;
typedef union{/*AFRL_Type*/
	AFRL_BITS_Type BITS;
	u32			   REG;
}AFRL_Type;


typedef struct{/*AFRH_BITS*/
	u32 AFRH8 :4;
	u32 AFRH9 :4;
	u32 AFRH10:4;
	u32 AFRH11:4;
	u32 AFRH12:4;
	u32 AFRH13:4;
	u32 AFRH14:4;
	u32 AFRH15:4;
}AFRH_BITS_Type;
typedef union{/*AFRH_Type*/
	AFRH_BITS_Type BITS;
	u32			   REG;
}AFRH_Type;


typedef struct{/*GPIO_Type*/
	MODER_Type		 MODER;
	OTYPER_Type 	 OTYPER;
	OSPEEDR_Type 	 OSPEEDR;
	PUPDR_Type		 PUPDR;
	IDR_Type		 IDR;
	ODR_Type		 ODR;
	BSRR_Type		 BSRR;
	LCKR_Type 		 LCKR;
	AFRL_Type 		 AFRL;
	AFRH_Type 		 AFRH;
}GPIO_MemMap_t;

#endif /*_MCAL_GPIO_TYPES_H_*/
