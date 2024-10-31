/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Barakat
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "Types.h"

/**************************************** Interfacing macros ****************************************/


typedef enum{
	EXTI_INTERRUPT_MASKED,
	EXTI_INTERRUPT_NOT_MASKED
}EXTI_Mask_t;

typedef enum{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_FALLING_EDGE
}EXTI_Edge_t;

typedef enum{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
	EXTI_LINE16,
	EXTI_LINE17,
	EXTI_LINE18,
	EXTI_LINE21=21,
	EXTI_LINE22,
}EXTI_Line_t;

typedef enum{
	SYSCFG_PAx,
	SYSCFG_PBx,
	SYSCFG_PCx,
	//SYSCFG_PDx,
	//SYSCFG_PEx,
	//SYSCFG_PHx=7,
}EXTI_SYSCFG;

/**************************************** Functions' prototypes ****************************************/
/******************************************************///
Error_Types EXTI_eSetInterruptStatus	(EXTI_Line_t Copy_u8EXTINumber, EXTI_Mask_t Copy_u8EXTIStatus);

Error_Types EXTI_eSetInterruptEdge		(EXTI_Line_t Copy_u8EXTINumber, EXTI_Edge_t Copy_u8EXTIEdge);

Error_Types EXTI_eClearInterruptPending	(EXTI_Line_t Copy_u8EXTINumber);

Error_Types EXTI_eIsInterruptActive		(EXTI_Line_t Copy_u8EXTINumber, u8* Copy_pu8EXTIStatus);

Error_Types EXTI_eChangeEXTISource		(EXTI_SYSCFG Copy_u8IntPort,EXTI_Line_t Copy_u8IntNum);

Error_Types EXTI_eSetInterruptCallback(EXTI_Line_t Copy_u8EXTINumber, void (*Copy_pfCallback)(void));

#endif /* EXTI_INTERFACE_H_ */
