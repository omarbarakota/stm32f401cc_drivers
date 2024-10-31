/*
 * EXTI_Types.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Barakat
 */

#ifndef EXTI_TYPES_H_
#define EXTI_TYPES_H_

#include "Types.h"

typedef struct{// IMR BITS
	u32	MR0:1;
	u32	MR1:1;
	u32	MR2:1;
	u32	MR3:1;
	u32	MR4:1;
	u32	MR5:1;
	u32	MR6:1;
	u32	MR7:1;
	u32	MR8:1;
	u32	MR9:1;
	u32	MR10:1;
	u32	MR11:1;
	u32	MR12:1;
	u32	MR13:1;
	u32	MR14:1;
	u32	MR15:1;
	u32	MR16:1;
	u32	MR17:1;
	u32	MR18:1;
	u32	RESERVED0:2;
	u32	MR21:1;
	u32	MR22:1;
	u32	RESERVED1:9;

}IMR_Bits_t;

typedef union{// IMR REG
	IMR_Bits_t			BITS;
	u32 				REG;
}IMR_t;

typedef struct{// EMR BITS
	u32	MR0:1;
	u32	MR1:1;
	u32	MR2:1;
	u32	MR3:1;
	u32	MR4:1;
	u32	MR5:1;
	u32	MR6:1;
	u32	MR7:1;
	u32	MR8:1;
	u32	MR9:1;
	u32	MR10:1;
	u32	MR11:1;
	u32	MR12:1;
	u32	MR13:1;
	u32	MR14:1;
	u32	MR15:1;
	u32	MR16:1;
	u32	MR17:1;
	u32	MR18:1;
	u32	RESERVED0:2;
	u32	MR21:1;
	u32	MR22:1;
	u32	RESERVED1:9;

}EMR_Bits_t;

typedef union{// EMR REG
	EMR_Bits_t			BITS;
	u32 				REG;
}EMR_t;

typedef struct{// RTSR BITS
	u32	TR0:1;
	u32	TR1:1;
	u32	TR2:1;
	u32	TR3:1;
	u32	TR4:1;
	u32	TR5:1;
	u32	TR6:1;
	u32	TR7:1;
	u32	TR8:1;
	u32	TR9:1;
	u32	TR10:1;
	u32	TR11:1;
	u32	TR12:1;
	u32	TR13:1;
	u32	TR14:1;
	u32	TR15:1;
	u32	TR16:1;
	u32	TR17:1;
	u32	TR18:1;
	u32	RESERVED0:2;
	u32	TR21:1;
	u32	TR22:1;
	u32	RESERVED1:9;

}RTSR_Bits_t;

typedef union{// RTSR REG
	RTSR_Bits_t			BITS;
	u32 				REG;
}RTSR_t;

typedef struct{// FTSR BITS
	u32	TR0:1;
	u32	TR1:1;
	u32	TR2:1;
	u32	TR3:1;
	u32	TR4:1;
	u32	TR5:1;
	u32	TR6:1;
	u32	TR7:1;
	u32	TR8:1;
	u32	TR9:1;
	u32	TR10:1;
	u32	TR11:1;
	u32	TR12:1;
	u32	TR13:1;
	u32	TR14:1;
	u32	TR15:1;
	u32	TR16:1;
	u32	TR17:1;
	u32	TR18:1;
	u32	RESERVED0:2;
	u32	TR21:1;
	u32	TR22:1;
	u32	RESERVED1:9;

}FTSR_Bits_t;

typedef union{// FTSR REG
	FTSR_Bits_t			BITS;
	u32 				REG;
}FTSR_t;

typedef struct{// SWIER BITS
	u32	SWIER0:1;
	u32	SWIER1:1;
	u32	SWIER2:1;
	u32	SWIER3:1;
	u32	SWIER4:1;
	u32	SWIER5:1;
	u32	SWIER6:1;
	u32	SWIER7:1;
	u32	SWIER8:1;
	u32	SWIER9:1;
	u32	SWIER10:1;
	u32	SWIER11:1;
	u32	SWIER12:1;
	u32	SWIER13:1;
	u32	SWIER14:1;
	u32	SWIER15:1;
	u32	SWIER16:1;
	u32	SWIER17:1;
	u32	SWIER18:1;
	u32	RESERVED0:2;
	u32	SWIER21:1;
	u32	SWIER22:1;
	u32	RESERVED1:9;

}SWIER_Bits_t;

typedef union{// SWIER REG
	SWIER_Bits_t		BITS;
	u32 				REG;
}SWIER_t;


typedef struct{// PR BITS
	u32	PR0:1;
	u32	PR1:1;
	u32	PR2:1;
	u32	PR3:1;
	u32	PR4:1;
	u32	PR5:1;
	u32	PR6:1;
	u32	PR7:1;
	u32	PR8:1;
	u32	PR9:1;
	u32	PR10:1;
	u32	PR11:1;
	u32	PR12:1;
	u32	PR13:1;
	u32	PR14:1;
	u32	PR15:1;
	u32	PR16:1;
	u32	PR17:1;
	u32	PR18:1;
	u32	RESERVED0:2;
	u32	PR21:1;
	u32	PR22:1;
	u32	RESERVED1:9;

}PR_Bits_t;

typedef union{// PR REG
	PR_Bits_t		BITS;
	u32 			REG;
}PR_t;

typedef struct{
	IMR_t 		IMR;
	EMR_t 		EMR;
	RTSR_t 		RTSR;
	FTSR_t 		FTSR;
	SWIER_t 	SWIER;
	PR_t 		PR;

}EXTI_t;

/**************** System Configuration Register****************/


typedef struct{// MEMRMP BITS
	u32	MEM_MODE:2;
	u32	RESERVED0:30;
}MEMRMP_Bits_t;

typedef union{// PMC REG
	MEMRMP_Bits_t	BITS;
	u32 			REG;
}MEMRMP_t;

typedef struct{// PMC BITS
	u32	RESERVED0:16;
	u32	ADC1DC2:1;
	u32	RESERVED1:15;
}PMC_Bits_t;

typedef union{// PMC REG
	PMC_Bits_t	BITS;
	u32 		REG;
}PMC_t;

typedef struct{// EXTICR1 BITS
	u32	EXTI0:4;
	u32	EXTI1:4;
	u32	EXTI2:4;
	u32	EXTI3:4;
	u32	RESERVED:16;
}EXTICR1_Bits_t;

typedef union{// EXTICR1 REG
	EXTICR1_Bits_t	BITS;
	u32 			REG;
}EXTICR1_t;

typedef struct{// EXTICR2 BITS
	u32	EXTI4:4;
	u32	EXTI5:4;
	u32	EXTI6:4;
	u32	EXTI7:4;
	u32	RESERVED:16;
}EXTICR2_Bits_t;

typedef union{// EXTICR2 REG
	EXTICR2_Bits_t	BITS;
	u32 			REG;
}EXTICR2_t;

typedef struct{// EXTICR3 BITS
	u32	EXTI8:4;
	u32	EXTI9:4;
	u32	EXTI10:4;
	u32	EXTI11:4;
	u32	RESERVED:16;
}EXTICR3_Bits_t;

typedef union{// EXTICR3 REG
	EXTICR3_Bits_t	BITS;
	u32 			REG;
}EXTICR3_t;

typedef struct{// EXTICR4 BITS
	u32	EXTI12:4;
	u32	EXTI13:4;
	u32	EXTI14:4;
	u32	EXTI15:4;
	u32	RESERVED:16;
}EXTICR4_Bits_t;

typedef union{// EXTICR4 REG
	EXTICR4_Bits_t	BITS;
	u32 			REG;
}EXTICR4_t;

typedef struct{// CMPCR BITS
	u32	CMP_PD:1;
	u32	RESERVED:6;
	u32	READY:1;
	u32	EXTI16:24;
}CMPCR_Bits_t;

typedef union{// CMPCR REG
	CMPCR_Bits_t	BITS;
	u32 			REG;
}CMPCR_t;


typedef struct{
	MEMRMP_t 		MEMRMP;
	PMC_t 			PMC;
	EXTICR1_t 		EXTICR1;
	EXTICR2_t 		EXTICR2;
	EXTICR3_t 		EXTICR3;
	EXTICR4_t 		EXTICR4;
	u32				RESERVED[2];
	CMPCR_t 		CMPCR;
}SYSCFG_t;




#endif /* EXTI_TYPES_H_ */
