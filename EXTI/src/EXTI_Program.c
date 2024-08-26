/*
 * EXTI_Program.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Barakat
 */

#include "Types.h"
#include "BitMath.h"

#include "EXTI_Types.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"


typedef void(*fptr)(void);


static fptr Global_pfArray[23]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


Error_Types EXTI_eSetInterruptStatus	(EXTI_Line_t Copy_u8EXTINumber, EXTI_Mask_t Copy_u8EXTIStatus){
	Error_Types Local_Error_state = Types_OK;
	if(Copy_u8EXTINumber>22){
			Local_Error_state = Types_NOK;
	}
	else{
	if(Copy_u8EXTIStatus==EXTI_INTERRUPT_MASKED)
	{
		CLR_BIT(EXTI->IMR.REG,Copy_u8EXTINumber);
	}
	else if(Copy_u8EXTIStatus==EXTI_INTERRUPT_NOT_MASKED)
	{
		SET_BIT(EXTI->IMR.REG,Copy_u8EXTINumber);
	}
	else//Wrong input
	{
		Local_Error_state = Types_NOK;
	}
	}
	return Local_Error_state;
}

Error_Types EXTI_eSetInterruptEdge		(EXTI_Line_t Copy_u8EXTINumber, EXTI_Edge_t Copy_u8EXTIEdge){
	Error_Types Local_Error_state = Types_OK;
	if(Copy_u8EXTINumber>EXTI_LINE22){
		Local_Error_state = Types_NOK;
	}
	else{
	switch(Copy_u8EXTIEdge){
	case EXTI_RISING_EDGE:
		SET_BIT(EXTI->RTSR.REG,Copy_u8EXTINumber);
		CLR_BIT(EXTI->FTSR.REG,Copy_u8EXTINumber);
		break;
	case EXTI_FALLING_EDGE:
		CLR_BIT(EXTI->RTSR.REG,Copy_u8EXTINumber);
		SET_BIT(EXTI->FTSR.REG,Copy_u8EXTINumber);
		break;
	case EXTI_RISING_FALLING_EDGE:
		SET_BIT(EXTI->RTSR.REG,Copy_u8EXTINumber);
		SET_BIT(EXTI->FTSR.REG,Copy_u8EXTINumber);
		break;
	default:
		Local_Error_state = Types_NOK;
		break;
	}
	}
	return Local_Error_state;
}


Error_Types EXTI_eClearInterruptPending	(EXTI_Line_t Copy_u8EXTINumber){
	Error_Types Local_Error_state = Types_OK;
	if(Copy_u8EXTINumber>EXTI_LINE22){
			Local_Error_state = Types_NOK;
	}
	else{
		SET_BIT(EXTI->PR.REG,Copy_u8EXTINumber);
	}
	return Local_Error_state;

}
Error_Types EXTI_eIsInterruptActive(EXTI_Line_t Copy_u8EXTINumber, u8* Copy_pu8EXTIStatus)
{
	u8 Local_u8ErrorState = Types_OK;

	*Copy_pu8EXTIStatus = GET_BIT(EXTI->PR.REG, Copy_u8EXTINumber);

	return Local_u8ErrorState;
}


Error_Types EXTI_eSetInterruptCallback(EXTI_Line_t Copy_u8EXTINumber, void (*Copy_pfCallback)(void)){

	Error_Types Local_ErrorState = Types_OK;
	if(Copy_u8EXTINumber<23){
		Global_pfArray[Copy_u8EXTINumber]=Copy_pfCallback;

	}
	else{
		Local_ErrorState = Types_NOK;
	}
	return Local_ErrorState;
}



/*Note:This Function shouldn't be in this Driver*/
/*But I'll fix the by putting all registers in one file*/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/

Error_Types EXTI_eChangeEXTISource(EXTI_SYSCFG Copy_u8IntPort,EXTI_Line_t Copy_u8IntNum){
	Error_Types Local_ErrorState = Types_OK;
	switch(Copy_u8IntNum)
	{

	case EXTI_LINE0:
		SYSCFG->EXTICR1.BITS.EXTI0=Copy_u8IntPort;
		break;
	case EXTI_LINE1:
		SYSCFG->EXTICR1.BITS.EXTI1=Copy_u8IntPort;
		break;
	case EXTI_LINE2:
		SYSCFG->EXTICR1.BITS.EXTI2=Copy_u8IntPort;
		break;
	case EXTI_LINE3:
		SYSCFG->EXTICR1.BITS.EXTI3=Copy_u8IntPort;
		break;

	case EXTI_LINE4:
		SYSCFG->EXTICR2.BITS.EXTI4=Copy_u8IntPort;
		break;
	case EXTI_LINE5:
		SYSCFG->EXTICR2.BITS.EXTI5=Copy_u8IntPort;
		break;
	case EXTI_LINE6:
		SYSCFG->EXTICR2.BITS.EXTI6=Copy_u8IntPort;
		break;
	case EXTI_LINE7:
		SYSCFG->EXTICR2.BITS.EXTI7=Copy_u8IntPort;
		break;

	case EXTI_LINE8:
		SYSCFG->EXTICR3.BITS.EXTI8=Copy_u8IntPort;
		break;
	case EXTI_LINE9:
		SYSCFG->EXTICR3.BITS.EXTI9=Copy_u8IntPort;
		break;
	case EXTI_LINE10:
		SYSCFG->EXTICR3.BITS.EXTI10=Copy_u8IntPort;
		break;
	case EXTI_LINE11:
		SYSCFG->EXTICR3.BITS.EXTI11=Copy_u8IntPort;
		break;

	case EXTI_LINE12:
		SYSCFG->EXTICR4.BITS.EXTI12=Copy_u8IntPort;
		break;
	case EXTI_LINE13:
		SYSCFG->EXTICR4.BITS.EXTI13=Copy_u8IntPort;
		break;
	case EXTI_LINE14:
		SYSCFG->EXTICR4.BITS.EXTI14=Copy_u8IntPort;
		break;
	case EXTI_LINE15:
		SYSCFG->EXTICR4.BITS.EXTI15=Copy_u8IntPort;
		break;

	default:
		Local_ErrorState = Types_NOK;
		break;
	}
	return Local_ErrorState;
}




/**************************************** EXTI ISRs ****************************************/



void EXTI0_IRQHandler(void){

	SET_BIT(EXTI->PR.REG,EXTI_LINE0);//Clear Pending flag
	if(Global_pfArray[EXTI_LINE0]!=NULL){
		Global_pfArray[EXTI_LINE0]();
	}
	else{

	}

}

void EXTI1_IRQHandler(void){
	SET_BIT(EXTI->PR.REG,EXTI_LINE1);
	if(Global_pfArray[EXTI_LINE1]!=NULL){
		Global_pfArray[EXTI_LINE1]();
	}
	else{

	}
}


void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI -> PR.REG, EXTI_LINE2);

	if(Global_pfArray[EXTI_LINE2] != NULL)
	{
		Global_pfArray[EXTI_LINE2]();
	}
	else
	{
		/*Do nothing*/
	}
}

void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI -> PR.REG, EXTI_LINE3);

	if(Global_pfArray[EXTI_LINE3] != NULL)
	{
		Global_pfArray[3]();
	}
	else
	{
		/*Do nothing*/
	}
}

void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI -> PR.REG, EXTI_LINE4);

	if(Global_pfArray[EXTI_LINE4] != NULL)
	{
		Global_pfArray[EXTI_LINE4]();
	}
	else
	{
		/*Do nothing*/
	}
}

void EXTI9_5_IRQHandler(void)
{

	if(EXTI->PR.BITS.PR5==1){
		SET_BIT(EXTI -> PR.REG, EXTI_LINE5);
		Global_pfArray[EXTI_LINE5]();
	}
	 if(EXTI->PR.BITS.PR6==1){
		SET_BIT(EXTI -> PR.REG, EXTI_LINE6);
		Global_pfArray[EXTI_LINE6]();
	}
	 if(EXTI->PR.BITS.PR7==1){
		SET_BIT(EXTI -> PR.REG, EXTI_LINE7);

		Global_pfArray[EXTI_LINE7]();
	}
	 if(EXTI->PR.BITS.PR8==1){
		SET_BIT(EXTI -> PR.REG, EXTI_LINE8);
		Global_pfArray[EXTI_LINE8]();
	}

	 if(EXTI->PR.BITS.PR9==1){
		SET_BIT(EXTI -> PR.REG, EXTI_LINE9);
		Global_pfArray[EXTI_LINE9]();
	}

}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR.BITS.PR10==1){
		SET_BIT(EXTI -> PR.REG, 10);
		Global_pfArray[EXTI_LINE10]();
	}
	 if(EXTI->PR.BITS.PR11==1){
		SET_BIT(EXTI -> PR.REG,11);
		Global_pfArray[EXTI_LINE11]();
	}
	 if(EXTI->PR.BITS.PR12==1){
		SET_BIT(EXTI -> PR.REG, 12);
		Global_pfArray[EXTI_LINE12]();
	}
	 if(EXTI->PR.BITS.PR13==1){
		SET_BIT(EXTI -> PR.REG, 13);
		Global_pfArray[EXTI_LINE13]();
	}
	 if(EXTI->PR.BITS.PR14==1){
		SET_BIT(EXTI -> PR.REG, 14);
		Global_pfArray[EXTI_LINE14]();
	}
	 if(EXTI->PR.BITS.PR15==1){
		SET_BIT(EXTI -> PR.REG, 15);
		Global_pfArray[EXTI_LINE15]();
	}

}

