/*
 * NVIC_Types.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Barakat
 */

#ifndef _NVIC_TYPES_H_
#define _NVIC_TYPES_H_

#include "Types.h"


/**************** Nested Vector Interrupt Control NVIC****************/

typedef struct{/*NVIC_ISER_BITS_t*/
	u32 SETENA0		:1;
	u32 SETENA1		:1;
	u32 SETENA2		:1;
	u32 SETENA3		:1;
	u32 SETENA4		:1;
	u32 SETENA5		:1;
	u32 SETENA6		:1;
	u32 SETENA7		:1;
	u32 SETENA8		:1;
	u32 SETENA9		:1;
	u32 SETENA10	:1;
	u32 SETENA11	:1;
	u32 SETENA12	:1;
	u32 SETENA13	:1;
	u32 SETENA14	:1;
	u32 SETENA15	:1;
	u32 SETENA16	:1;
	u32 SETENA17	:1;
	u32 SETENA18	:1;
	u32 SETENA19	:1;
	u32 SETENA20	:1;
	u32 SETENA21	:1;
	u32 SETENA22	:1;
	u32 SETENA23	:1;
	u32 SETENA24	:1;
	u32 SETENA25	:1;
	u32 SETENA26	:1;
	u32 SETENA27	:1;
	u32 SETENA28	:1;
	u32 SETENA29	:1;
	u32 SETENA30	:1;
	u32 SETENA31	:1;
}NVIC_ISER_BITS_t;
typedef union{/*NVIC_ISER_t*/
	NVIC_ISER_BITS_t BITS;
	u32 			 REG;
}NVIC_ISER_t;


typedef struct{/*NVIC_ICER_BITS_t*/
	u32 CLRENA0		:1;
	u32 CLRENA1		:1;
	u32 CLRENA2		:1;
	u32 CLRENA3		:1;
	u32 CLRENA4		:1;
	u32 CLRENA5		:1;
	u32 CLRENA6		:1;
	u32 CLRENA7		:1;
	u32 CLRENA8		:1;
	u32 CLRENA9		:1;
	u32 CLRENA10	:1;
	u32 CLRENA11	:1;
	u32 CLRENA12	:1;
	u32 CLRENA13	:1;
	u32 CLRENA14	:1;
	u32 CLRENA15	:1;
	u32 CLRENA16	:1;
	u32 CLRENA17	:1;
	u32 CLRENA18	:1;
	u32 CLRENA19	:1;
	u32 CLRENA20	:1;
	u32 CLRENA21	:1;
	u32 CLRENA22	:1;
	u32 CLRENA23	:1;
	u32 CLRENA24	:1;
	u32 CLRENA25	:1;
	u32 CLRENA26	:1;
	u32 CLRENA27	:1;
	u32 CLRENA28	:1;
	u32 CLRENA29	:1;
	u32 CLRENA30	:1;
	u32 CLRENA31	:1;
}NVIC_ICER_BITS_t;
typedef union{/*NVIC_ICER_t*/
	NVIC_ICER_BITS_t BITS;
	u32 			 REG;
}NVIC_ICER_t;


typedef struct{/*NVIC_ISPR_BITS_t*/
	u32 SETPEND0	:1;
	u32 SETPEND1	:1;
	u32 SETPEND2	:1;
	u32 SETPEND3	:1;
	u32 SETPEND4	:1;
	u32 SETPEND5	:1;
	u32 SETPEND6	:1;
	u32 SETPEND7	:1;
	u32 SETPEND8	:1;
	u32 SETPEND9	:1;
	u32 SETPEND10	:1;
	u32 SETPEND11	:1;
	u32 SETPEND12	:1;
	u32 SETPEND13	:1;
	u32 SETPEND14	:1;
	u32 SETPEND15	:1;
	u32 SETPEND16	:1;
	u32 SETPEND17	:1;
	u32 SETPEND18	:1;
	u32 SETPEND19	:1;
	u32 SETPEND20	:1;
	u32 SETPEND21	:1;
	u32 SETPEND22	:1;
	u32 SETPEND23	:1;
	u32 SETPEND24	:1;
	u32 SETPEND25	:1;
	u32 SETPEND26	:1;
	u32 SETPEND27	:1;
	u32 SETPEND28	:1;
	u32 SETPEND29	:1;
	u32 SETPEND30	:1;
	u32 SETPEND31	:1;
}NVIC_ISPR_BITS_t;
typedef union{/*NVIC_ISPR_t*/
	NVIC_ISPR_BITS_t BITS;
	u32 			 REG;
}NVIC_ISPR_t;


typedef struct{/*NVIC_ICPR_BITS_t*/
	u32 CLRPEND0	:1;
	u32 CLRPEND1	:1;
	u32 CLRPEND2	:1;
	u32 CLRPEND3	:1;
	u32 CLRPEND4	:1;
	u32 CLRPEND5	:1;
	u32 CLRPEND6	:1;
	u32 CLRPEND7	:1;
	u32 CLRPEND8	:1;
	u32 CLRPEND9	:1;
	u32 CLRPEND10	:1;
	u32 CLRPEND11	:1;
	u32 CLRPEND12	:1;
	u32 CLRPEND13	:1;
	u32 CLRPEND14	:1;
	u32 CLRPEND15	:1;
	u32 CLRPEND16	:1;
	u32 CLRPEND17	:1;
	u32 CLRPEND18	:1;
	u32 CLRPEND19	:1;
	u32 CLRPEND20	:1;
	u32 CLRPEND21	:1;
	u32 CLRPEND22	:1;
	u32 CLRPEND23	:1;
	u32 CLRPEND24	:1;
	u32 CLRPEND25	:1;
	u32 CLRPEND26	:1;
	u32 CLRPEND27	:1;
	u32 CLRPEND28	:1;
	u32 CLRPEND29	:1;
	u32 CLRPEND30	:1;
	u32 CLRPEND31	:1;
}NVIC_ICPR_BITS_t;
typedef union{/*NVIC_ICPR_t*/
	NVIC_ICPR_BITS_t BITS;
	u32 			 REG;
}NVIC_ICPR_t;


typedef struct{/*NVIC_IABR_BITS_t*/
	u32 ACTIVE0		:1;
	u32 ACTIVE1		:1;
	u32 ACTIVE2		:1;
	u32 ACTIVE3		:1;
	u32 ACTIVE4		:1;
	u32 ACTIVE5		:1;
	u32 ACTIVE6		:1;
	u32 ACTIVE7		:1;
	u32 ACTIVE8		:1;
	u32 ACTIVE9		:1;
	u32 ACTIVE10	:1;
	u32 ACTIVE11	:1;
	u32 ACTIVE12	:1;
	u32 ACTIVE13	:1;
	u32 ACTIVE14	:1;
	u32 ACTIVE15	:1;
	u32 ACTIVE16	:1;
	u32 ACTIVE17	:1;
	u32 ACTIVE18	:1;
	u32 ACTIVE19	:1;
	u32 ACTIVE20	:1;
	u32 ACTIVE21	:1;
	u32 ACTIVE22	:1;
	u32 ACTIVE23	:1;
	u32 ACTIVE24	:1;
	u32 ACTIVE25	:1;
	u32 ACTIVE26	:1;
	u32 ACTIVE27	:1;
	u32 ACTIVE28	:1;
	u32 ACTIVE29	:1;
	u32 ACTIVE30	:1;
	u32 ACTIVE31	:1;
}NVIC_IABR_BITS_t;
typedef union{/*NVIC_IAB_t*/
	NVIC_IABR_BITS_t BITS;
	u32 			REG;
}NVIC_IABR_t;


typedef struct{/*NVIC_IPR_BITS_t*/
	u32 BIT0:1;
	u32 BIT1:1;
	u32 BIT2:1;
	u32 BIT3:1;
	u32 BIT4:1;
	u32 BIT5:1;
	u32 BIT6:1;
	u32 BIT7:1;
}NVIC_IPR_BITS_t;
typedef union{/*NVIC_IPR_t*/
	NVIC_IPR_BITS_t BITS;
	u8 				REG;//Each IP has 8 bits only
}NVIC_IPR_t;

typedef struct{

	NVIC_ISER_t NVIC_ISER[8+24];//There are 24 Empty address between ISER and ICER
	NVIC_ICER_t NVIC_ICER[8+24];//There are 24 Empty address between ICER and ISPR
	NVIC_ISPR_t NVIC_ISPR[8+24];//There are 24 Empty address between ISPR and ICPR
	NVIC_ICPR_t NVIC_ICPR[8+24];//There are 24 Empty address between ICPR and IPR
	NVIC_IABR_t NVIC_IABR[8+56];//There are 56 Empty address between ICER and ISPR
	NVIC_IPR_t  NVIC_IPR [60*4];//60 IPR, 4 IP for Each IPR
}NVIC_t;


/**************** System Control Block SCB****************/


typedef struct{// CPUID BITS
	u32	REVISION		:4;
	u32	PARTNO			:12;
	u32	CONSTANT		:4;
	u32	VARIANT			:4;
	u32	IMPLEMENTER		:8;
}CPUID_Bits_t;

typedef union{// CPUID REG
	CPUID_Bits_t	BITS;
	u32 			REG;
}CPUID_t;

typedef struct{// ICSR BITS
	u32	VECTACTIVE		:9;
	u32	RESERVED0		:2;
	u32	RETOBASE		:1;
	u32	VECTPENDING		:10;
	u32	ISRPENDING		:1;
	u32	RESERVED1		:2;
	u32	PENDSTCLR		:1;
	u32	PENDSTSET		:1;
	u32	PENDSVCLR		:1;
	u32	PENDSVSET		:1;
	u32	RESERVED2		:2;
	u32	NMIPENDSET		:1;

}ICSR_Bits_t;

typedef union{// ICSR REG
	ICSR_Bits_t		BITS;
	u32 			REG;
}ICSR_t;

typedef struct{// VTOR BITS
	u32 RESERVED0		:8;
	u32 TABLEOFF		:23;
	u32 RESERVED1		:1;

}VTOR_Bits_t;

typedef union{// VTOR REG
	VTOR_Bits_t		BITS;
	u32 			REG;
}VTOR_t;

typedef struct{// AIRCR BITS
	u32	VECTRESET		:1;
	u32	VECTCLRACTIVE	:1;
	u32	SYSRESETREQ		:1;
	u32	RESERVED0		:5;
	u32	PRIGROUP		:3;
	u32	RESERVED1		:4;
	u32	ENDIANESS		:1;
	u32	VECTKEY			:16;

}AIRCR_Bits_t;

typedef union{// AIRCR REG
	AIRCR_Bits_t	BITS;
	u32 			REG;
}AIRCR_t;

typedef struct{// SCR BITS
	u32 RESERVED0		:1;
	u32 SEVONPEND		:1;
	u32 RESERVED1		:1;
	u32 SLEEPDEEP		:1;
	u32 SLEEPONEXIT		:1;
	u32 RESERVED2		:27;
}SCR_Bits_t;

typedef union{// SCR REG
	SCR_Bits_t		BITS;
	u32 			REG;
}SCR_t;

typedef struct{// CCR BITS
	u32	MONBASETHRDENA	:1;
	u32	USERSETMPEND	:1;
	u32	RESERVED0		:1;
	u32	UNALIGN_TRP		:1;
	u32	DIV_0_TRP		:1;
	u32	RESERVED1		:3;
	u32	BFHFNIGN		:1;
	u32	STKALIGN		:1;
	u32	RESERVED2		:22;
}CCR_Bits_t;

typedef union{// CCR REG
	CCR_Bits_t		BITS;
	u32 			REG;
}CCR_t;

typedef struct{// SHPR1 BITS
	u32	PRI4			:8;
	u32 PRI5			:8;
	u32 PRI6			:8;
	u32 RESERVED		:8;
}SHPR1_Bits_t;

typedef union{// SHPR1 REG
	SHPR1_Bits_t	BITS;
	u32 			REG;
}SHPR1_t;

typedef struct{// SHPR2 BITS
	u32 RESERVED		:24;
	u32	PRI11			:8;
}SHPR2_Bits_t;

typedef union{// SHPR2 REG
	SHPR2_Bits_t	BITS;
	u32 			REG;
}SHPR2_t;

typedef struct{// SHPR3 BITS
	u32 RESERVED		:16;
	u32	PRI14			:8;
	u32 PRI15			:8;
}SHPR3_Bits_t;

typedef union{// SHPR3 REG
	SHPR3_Bits_t	BITS;
	u32 			REG;
}SHPR3_t;

typedef struct{// SHCSR BITS
	u32	MEM_FAULT_ACT	:1;
	u32	BUS_FAULT_ACT	:1;
	u32	RESERVED0		:1;
	u32	USG_FAULT_ACT	:1;
	u32	RESERVED1		:3;
	u32	SV_CALL_ACT		:1;
	u32	MONITOR_ACT		:1;
	u32	RESERVED2		:1;
	u32	PENDSV_ACT		:1;
	u32	SYSTICK_ACT		:1;
	u32	USG_FAULT_BENDED:1;
	u32	MEM_FAULT_BENDED:1;
	u32	BUS_FAULT_BENDED:1;
	u32	SV_CALL_BENDED	:1;
	u32	MEM_FAULT_ENA	:1;
	u32	BUS_FAULT_ENA	:1;
	u32	USG_FAULT_ENA	:1;
	u32	RESERVED3		:13;

}SHCSR_Bits_t;

typedef union{// SHCSR REG
	SHCSR_Bits_t		BITS;
	u32 				REG;
}SHCSR_t;

typedef struct{// MMAR BITS
	u32	MMFSR:8;
	u32	BFSR:8;
	u32	UFSR:16;
}CFSR_Bits_t;

typedef union{// CFSR REG
	CFSR_Bits_t			BITS;
	u32 				REG;
}CFSR_t;

typedef struct{// HFSR BITS
	u32	RESERVED0	:1;
	u32	VECTTBL		:1;
	u32	RESERVED1	:28;
	u32	FORCED		:1;
	u32 DEBUG_VT	:1;

}HFSR_Bits_t;

typedef union{// HFSR REG
	HFSR_Bits_t			BITS;
	u32 				REG;
}HFSR_t;

typedef struct{// MMAR BITS
	u32	BIT0:1;
	u32	BIT1:1;
	u32	BIT2:1;
	u32	BIT3:1;
	u32	BIT4:1;
	u32	BIT5:1;
	u32	BIT6:1;
	u32	BIT7:1;
	u32	BIT8:1;
	u32	BIT9:1;
	u32	BIT10:1;
	u32	BIT11:1;
	u32	BIT12:1;
	u32	BIT13:1;
	u32	BIT14:1;
	u32	BIT15:1;
	u32	BIT16:1;
	u32	BIT17:1;
	u32	BIT18:1;
	u32	BIT19:1;
	u32	BIT20:1;
	u32	BIT21:1;
	u32	BIT22:1;
	u32	BIT23:1;
	u32	BIT24:1;
	u32	BIT25:1;
	u32	BIT26:1;
	u32	BIT27:1;
	u32	BIT28:1;
	u32	BIT29:1;
	u32	BIT30:1;
	u32 BIT31:1;

}MMAR_Bits_t;

typedef union{// MMAR REG
	MMAR_Bits_t			BITS;
	u32 				REG;
}MMAR_t;

typedef struct{// BFAR BITS
	u32	BIT0:1;
	u32	BIT1:1;
	u32	BIT2:1;
	u32	BIT3:1;
	u32	BIT4:1;
	u32	BIT5:1;
	u32	BIT6:1;
	u32	BIT7:1;
	u32	BIT8:1;
	u32	BIT9:1;
	u32	BIT10:1;
	u32	BIT11:1;
	u32	BIT12:1;
	u32	BIT13:1;
	u32	BIT14:1;
	u32	BIT15:1;
	u32	BIT16:1;
	u32	BIT17:1;
	u32	BIT18:1;
	u32	BIT19:1;
	u32	BIT20:1;
	u32	BIT21:1;
	u32	BIT22:1;
	u32	BIT23:1;
	u32	BIT24:1;
	u32	BIT25:1;
	u32	BIT26:1;
	u32	BIT27:1;
	u32	BIT28:1;
	u32	BIT29:1;
	u32	BIT30:1;
	u32 BIT31:1;

}BFAR_Bits_t;

typedef union{// BFAR REG
	BFAR_Bits_t			BITS;
	u32 				REG;
}BFAR_t;

typedef struct{// AFSR BITS
	u32	BIT0:1;
	u32	BIT1:1;
	u32	BIT2:1;
	u32	BIT3:1;
	u32	BIT4:1;
	u32	BIT5:1;
	u32	BIT6:1;
	u32	BIT7:1;
	u32	BIT8:1;
	u32	BIT9:1;
	u32	BIT10:1;
	u32	BIT11:1;
	u32	BIT12:1;
	u32	BIT13:1;
	u32	BIT14:1;
	u32	BIT15:1;
	u32	BIT16:1;
	u32	BIT17:1;
	u32	BIT18:1;
	u32	BIT19:1;
	u32	BIT20:1;
	u32	BIT21:1;
	u32	BIT22:1;
	u32	BIT23:1;
	u32	BIT24:1;
	u32	BIT25:1;
	u32	BIT26:1;
	u32	BIT27:1;
	u32	BIT28:1;
	u32	BIT29:1;
	u32	BIT30:1;
	u32 BIT31:1;

}AFSR_Bits_t;

typedef union{// AFSR REG
	AFSR_Bits_t			BITS;
	u32 				REG;
}AFSR_t;

typedef struct{
	CPUID_t CPUID;
	ICSR_t 	ICSR;
	VTOR_t 	VTOR;
	AIRCR_t AIRCR;
	SCR_t 	SCR;
	CCR_t 	CCR;
	SHPR1_t SHPR1;
	SHPR2_t SHPR2;
	SHPR3_t SHPR3;
	SHCSR_t SHCSR;
	CFSR_t 	CFSR;
	HFSR_t 	HFSR;
	u32 	RESERVED;
	MMAR_t 	MMAR;
	BFAR_t 	BFAR;
	AFSR_t 	AFSR;
}SCB_t;



#endif /* MCAL_NVIC_NVIC_TYPES_H_ */
