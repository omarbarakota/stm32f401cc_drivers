/*
 * NVIC_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Barakat
 */

#include "Types.h"
#include "BitMath.h"

#include "NVIC_Types.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"



static u8 StaticGlobal_u8PriorityConfig;

// Reg num=IRQn/32 Binnum=IRQn%32

Error_Types NVIC_eEnableIRQ(IRQn_t IRQn)
{
	Error_Types ErrorState=Types_OK;
	if(IRQn<32){//IRQ0 0->31
		SET_BIT(NVIC->NVIC_ISER[0].REG,(IRQn-(0*32)));
	}
	else if(IRQn>=32 && IRQn<64)//IRQ1 32->63
	{
		SET_BIT(NVIC->NVIC_ISER[1].REG,(IRQn-(1*32)));
	}
	else if(IRQn>=64 && IRQn<96)//IRQ2 64->95
	{
		SET_BIT(NVIC->NVIC_ISER[2].REG,(IRQn-(2*32)));
	}
//	else if(IRQn>=96 && IRQn<128)// 96->127
//	{
//		SET_BIT(NVIC->NVIC_ISER[3].REG,(IRQn-(3*32)));
//	}
//	else if(IRQn>=128 && IRQn<160)//IRQ4 128->159
//	{
//		SET_BIT(NVIC->NVIC_ISER[4].REG,(IRQn-(4*32)));
//	}
//	else if(IRQn>=160 && IRQn<192)//IRQ5 160->191
//	{
//		SET_BIT(NVIC->NVIC_ISER[5].REG,(IRQn-(5*32)));
//	}
//	else if(IRQn>=192 && IRQn<224)//IRQ6 192->223
//	{
//		SET_BIT(NVIC->NVIC_ISER[6].REG,(IRQn-(6*32)));
//	}
//	else if(IRQn>=224 && IRQn<240)//IRQ7 224 ->239
//	{
//		SET_BIT(NVIC->NVIC_ISER[7].REG,(IRQn-(7*32)));
//	}
	else //Error
	{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}


Error_Types NVIC_eDisableIRQ(IRQn_t IRQn)
{
	Error_Types ErrorState=Types_OK;
	if(IRQn<32){//IRQ0
		SET_BIT(NVIC->NVIC_ICER[0].REG,(IRQn-(0*32)));
	}
	else if(IRQn>=32 && IRQn<64)//IRQ1
	{
		SET_BIT(NVIC->NVIC_ICER[1].REG,(IRQn-(1*32)));
	}
	else if(IRQn>=64 && IRQn<96)//IRQ2
	{
		SET_BIT(NVIC->NVIC_ICER[2].REG,(IRQn-(2*32)));
	}
//	else if(IRQn>=96 && IRQn<128)//IRQ3
//	{
//		SET_BIT(NVIC->NVIC_ICER[3].REG,(IRQn-(3*32)));
//	}
//	else if(IRQn>=128 && IRQn<160)//IRQ4
//	{
//		SET_BIT(NVIC->NVIC_ICER[4].REG,(IRQn-(4*32)));
//	}
//	else if(IRQn>=160 && IRQn<192)//IRQ5
//	{
//		SET_BIT(NVIC->NVIC_ICER[5].REG,(IRQn-(5*32)));
//	}
//	else if(IRQn>=192 && IRQn<224)//IRQ6
//	{
//		SET_BIT(NVIC->NVIC_ICER[6].REG,(IRQn-(6*32)));
//	}
//	else if(IRQn>=224 && IRQn<240)//IRQ7
//	{
//		SET_BIT(NVIC->NVIC_ICER[7].REG,(IRQn-(7*32)));
//	}
	else
	{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}


u8 NVIC_u8GetStateIRQ(IRQn_t IRQn)
{
	Error_Types ErrorState=Types_OK;
	if(IRQn<32){//IRQ0 0->31
		return GET_BIT(NVIC->NVIC_IABR[0].REG,(IRQn-(0*32)));
	}
	else if(IRQn>=32 && IRQn<64)//IRQ1 32->63
	{
		return GET_BIT(NVIC->NVIC_IABR[1].REG,(IRQn-(1*32)));
	}
	else if(IRQn>=64 && IRQn<96)//IRQ2 64->95
	{
		return GET_BIT(NVIC->NVIC_IABR[2].REG,(IRQn-(2*32)));
	}
//	else if(IRQn>=96 && IRQn<128)// 96->127
//	{
//		return GET_BIT(NVIC->NVIC_IABR[3].REG,(IRQn-(3*32)));
//	}
//	else if(IRQn>=128 && IRQn<160)//IRQ4 128->159
//	{
//		return GET_BIT(NVIC->NVIC_IABR[4].REG,(IRQn-(4*32)));
//	}
//	else if(IRQn>=160 && IRQn<192)//IRQ5 160->191
//	{
//		return GET_BIT(NVIC->NVIC_IABR[5].REG,(IRQn-(5*32)));
//	}
//	else if(IRQn>=192 && IRQn<224)//IRQ6 192->223
//	{
//		return GET_BIT(NVIC->NVIC_IABR[6].REG,(IRQn-(6*32)));
//	}
//	else if(IRQn>=224 && IRQn<240)//IRQ7 224 ->239
//	{
//		return GET_BIT(NVIC->NVIC_IABR[7].REG,(IRQn-(7*32)));
//	}
	else //Error
	{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}

Error_Types NVIC_eSetPendingIRQ(IRQn_t IRQn)
{
	Error_Types ErrorState=Types_OK;
	if(IRQn<32){//IRQ0 0->31
		SET_BIT(NVIC->NVIC_ISPR[0].REG,(IRQn-(0*32)));
	}
	else if(IRQn>=32 && IRQn<64)//IRQ1 32->63
	{
		SET_BIT(NVIC->NVIC_ISPR[1].REG,(IRQn-(1*32)));
	}
	else if(IRQn>=64 && IRQn<96)//IRQ2 64->95
	{
		SET_BIT(NVIC->NVIC_ISPR[2].REG,(IRQn-(2*32)));
	}
//	else if(IRQn>=96 && IRQn<128)// 96->127
//	{
//		SET_BIT(NVIC->NVIC_ISPR[3].REG,(IRQn-(3*32)));
//	}
//	else if(IRQn>=128 && IRQn<160)//IRQ4 128->159
//	{
//		SET_BIT(NVIC->NVIC_ISPR[4].REG,(IRQn-(4*32)));
//	}
//	else if(IRQn>=160 && IRQn<192)//IRQ5 160->191
//	{
//		SET_BIT(NVIC->NVIC_ISPR[5].REG,(IRQn-(5*32)));
//	}
//	else if(IRQn>=192 && IRQn<224)//IRQ6 192->223
//	{
//		SET_BIT(NVIC->NVIC_ISPR[6].REG,(IRQn-(6*32)));
//	}
//	else if(IRQn>=224 && IRQn<240)//IRQ7 224 ->239
//	{
//		SET_BIT(NVIC->NVIC_ISPR[7].REG,(IRQn-(7*32)));
//	}
	else //Error
	{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}

Error_Types NVIC_eClearPendingIRQ(IRQn_t IRQn)
{
	Error_Types ErrorState=Types_OK;
	if(IRQn<32){//IRQ0 0->31
		SET_BIT(NVIC->NVIC_ICPR[0].REG,(IRQn-(0*32)));
	}
	else if(IRQn>=32 && IRQn<64)//IRQ1 32->63
	{
		SET_BIT(NVIC->NVIC_ICPR[1].REG,(IRQn-(1*32)));
	}
	else if(IRQn>=64 && IRQn<96)//IRQ2 64->95
	{
		SET_BIT(NVIC->NVIC_ICPR[2].REG,(IRQn-(2*32)));
	}
//	else if(IRQn>=96 && IRQn<128)// 96->127
//	{
//		SET_BIT(NVIC->NVIC_ICPR[3].REG,(IRQn-(3*32)));
//	}
//	else if(IRQn>=128 && IRQn<160)//IRQ4 128->159
//	{
//		SET_BIT(NVIC->NVIC_ICPR[4].REG,(IRQn-(4*32)));
//	}
//	else if(IRQn>=160 && IRQn<192)//IRQ5 160->191
//	{
//		SET_BIT(NVIC->NVIC_ICPR[5].REG,(IRQn-(5*32)));
//	}
//	else if(IRQn>=192 && IRQn<224)//IRQ6 192->223
//	{
//		SET_BIT(NVIC->NVIC_ICPR[6].REG,(IRQn-(6*32)));
//	}
//	else if(IRQn>=224 && IRQn<240)//IRQ7 224 ->239
//	{
//		SET_BIT(NVIC->NVIC_ICPR[7].REG,(IRQn-(7*32)));
//	}
	else //Error
	{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}

u8 NVIC_u8GetPendingIRQ(IRQn_t IRQn)
{
	Error_Types ErrorState=Types_OK;
	if(IRQn<32){//IRQ0 0->31
		return GET_BIT(NVIC->NVIC_ISPR[0].REG,(IRQn-(0*32)));
	}
	else if(IRQn>=32 && IRQn<64)//IRQ1 32->63
	{
		return GET_BIT(NVIC->NVIC_ISPR[1].REG,(IRQn-(1*32)));
	}
	else if(IRQn>=64 && IRQn<96)//IRQ2 64->95
	{
		return GET_BIT(NVIC->NVIC_ISPR[2].REG,(IRQn-(2*32)));
	}
//	else if(IRQn>=96 && IRQn<128)// 96->127
//	{
//		return GET_BIT(NVIC->NVIC_ISPR[3].REG,(IRQn-(3*32)));
//	}
//	else if(IRQn>=128 && IRQn<160)//IRQ4 128->159
//	{
//		return GET_BIT(NVIC->NVIC_ISPR[4].REG,(IRQn-(4*32)));
//	}
//	else if(IRQn>=160 && IRQn<192)//IRQ5 160->191
//	{
//		return GET_BIT(NVIC->NVIC_ISPR[5].REG,(IRQn-(5*32)));
//	}
//	else if(IRQn>=190 && IRQn<224)//IRQ6 192->223
//	{
//		return GET_BIT(NVIC->NVIC_ISPR[6].REG,(IRQn-(6*32)));
//	}
//	else if(IRQn>=224 && IRQn<240)//IRQ7 224 ->239
//	{
//		return GET_BIT(NVIC->NVIC_ISPR[7].REG,(IRQn-(7*32)));
//	}
	else //Error
	{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}


Error_Types NVIC_eSetPriorityConfig(Priority_Group_Config_t Priority_Config){
	Error_Types ErrorState=Types_OK;

	if(Priority_Config<= NVIC_Group0_16Sub){
		SCB->AIRCR.BITS.PRIGROUP=Priority_Config;
		StaticGlobal_u8PriorityConfig=Priority_Config;
	}
	else{
		ErrorState=Types_NOK;
	}
	return ErrorState;
}

Error_Types NVIC_eSetPriority(IRQn_t IRQn, Priority_Group_t GroupNum,Priority_SubGroup_t SubGroupNum)
{
	Error_Types ErrorState=Types_OK;
    switch (StaticGlobal_u8PriorityConfig) {
        case NVIC_Group16_0Sub:
            if(GroupNum>NVIC_Group15 || SubGroupNum>NVIC_SubGroupNoSub)
            {
                ErrorState=Types_NOK;
                break;
            }
            NVIC->NVIC_IPR[IRQn].REG=(GroupNum<<4);//Because only from 4-7 are the only bits used for priority
        break;
        case NVIC_Group8_2Sub:
            if(GroupNum>NVIC_Group7 || SubGroupNum>NVIC_SubGroup1)
            {
                ErrorState=Types_NOK;
                break;
            }
            NVIC->NVIC_IPR[IRQn].REG=((GroupNum&0b111)<<5)|((SubGroupNum & 0b1)<<4);
        break;
        case NVIC_Group4_4Sub:
            if(GroupNum>NVIC_Group3 || SubGroupNum>NVIC_SubGroup3)
            {
                ErrorState=Types_NOK;
                break;
            }
            NVIC->NVIC_IPR[IRQn].REG=((GroupNum&0b11)<<6)|((SubGroupNum & 0b11)<<4);

        break;
        case NVIC_Group2_8Sub:
            if(GroupNum>NVIC_Group1 || SubGroupNum>NVIC_SubGroup7)
            {
                ErrorState=Types_NOK;
                break;
            }
            NVIC->NVIC_IPR[IRQn].REG=((GroupNum&0b1)<<7)|((SubGroupNum & 0b111)<<4);
        break;
        case NVIC_Group0_16Sub:
            if(GroupNum>NVIC_GroupNoGroup || SubGroupNum>NVIC_SubGroup15)
            {
                ErrorState=Types_NOK;
                break;
            }
            NVIC->NVIC_IPR[IRQn].REG=((SubGroupNum & 0b1111)<<4);
        break;
        default:
            ErrorState=Types_NOK;
            break;
    }
	return ErrorState;
}
Error_Types NVIC_eGetPriority(IRQn_t IRQn, Priority_Group_t *GroupNum,Priority_SubGroup_t *SubGroupNum)
{
	Error_Types ErrorState=Types_OK;
    switch (StaticGlobal_u8PriorityConfig) {
        case NVIC_Group16_0Sub:
            *GroupNum=(NVIC->NVIC_IPR[IRQn].REG>>4);//Because only from 4-7 are the only bits used for priority
        break;
        case NVIC_Group8_2Sub:
            *GroupNum=(NVIC->NVIC_IPR[IRQn].REG>>5 & 0b111);
            *SubGroupNum=(NVIC->NVIC_IPR[IRQn].REG>>4 & 0b1);
        break;
        case NVIC_Group4_4Sub:
            *GroupNum=(NVIC->NVIC_IPR[IRQn].REG>>6 & 0b11);
            *SubGroupNum=(NVIC->NVIC_IPR[IRQn].REG>>4 & 0b11);
        break;
        case NVIC_Group2_8Sub:
            *GroupNum=(NVIC->NVIC_IPR[IRQn].REG>>7 & 0b1);
            *SubGroupNum=(NVIC->NVIC_IPR[IRQn].REG>>4 & 0b111);
        break;
        case NVIC_Group0_16Sub:
            *SubGroupNum= (NVIC->NVIC_IPR[IRQn].REG>>4);//Because only from 4-7 are the only bits used for priority
        break;
        default:
            ErrorState=Types_NOK;
            break;
    }
	return ErrorState;
}


u8 NVIC_u8GetInterruptState(u8 Copy_u8InterruptNum){
	u8 Local_u8IntState=GET_BIT( NVIC->NVIC_IABR[Copy_u8InterruptNum/32].REG,(Copy_u8InterruptNum%32));

	return Local_u8IntState;
}




