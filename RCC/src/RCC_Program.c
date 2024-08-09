/*
 * RCC_Program.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Barakat
 */
/*
 * Driver:  RCC_Driver
 * Author:  Omar Barakat
 * Version: V 1.0
 * Date:    Aug, 2023
 * Description:
 * */

#include "Types.h"
#include "Bitmath.h"

#include "RCC_Types.h"
#include "RCC_Config.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"

/* API Name:
 * Parameter In: void
 * Parameter Out: u8 Error_State
 * Description:
 */
Error_Types RCC_u8InitSysClk(void) {

	Error_Types Local_error_state = Types_OK;

#if(RCC_CLK_SRC==RCC_HSI)
	RCC->CR.HSION= Types_HIGH;
	while (RCC->CR.HSIRDY == Types_LOW);
	//RCC->CFGR.SW=RCC_HSI;
#elif(RCC_CLK_SRC== RCC_HSE)

	#if(RCC_u32_HSE_MODE== RCC_HSE_BYBASS)
		RCC->CR.HSEBYP=Types_HIGH;
	#elif(RCC_u32_HSE_MODE== RCC_HSE_CRYSTAL)
		CLEAR_BIT((RCC->RCC_CR),18);
		RCC->CR.HSEBYP=Types_LOW;
	#else
		#error "wrong HSE Mode"
		Local_error_state=Types_NOK;
	#endif
	RCC->CR.HSEON=Types_HIGH;
	while(RCC->CR.HSERDY==Types_LOW);
	//switch to HSE as main clock source
	//RCC->CFGR.SW=RCC_HSE;


//in case of choosing PLL as clock source ,the PLL Clock input and multiplication factor must be configured
#elif(RCC_CLK_SRC==RCC_PLL)

	#if(RCC_PLL_SRC==RCC_PLL_HSI)
		RCC->CR.HSION=Types_HIGH;
		while (RCC->CR.HSIRDY == Types_LOW);

	#elif(RCC_PLL_SRC==RCC_PLL_HSE)

			#if(RCC_HSE_MODE== RCC_HSE_BYBASS)
					RCC->CR.HSEBYP=Types_HIGH;
			#elif(RCC_HSE_MODE== RCC_HSE_CRYSTAL)
					RCC->CR.HSEBYP=Types_LOW;
			#else
				#error "Wrong PLL HSE Mode"
				Local_error_state=Types_NOK;

				#endif
			//Enable HSE clock and wait until stabilize
			RCC->CR.HSEON=Types_HIGH;
			while(RCC->CR.HSERDY==Types_LOW);

		#endif
		//prepare PLL configs ans wait pll stabilize
		RCC->PLLCFGR.PLLM=RCC_PLLM;
		RCC->PLLCFGR.PLLN=RCC_PLLN;
		RCC->PLLCFGR.PLLQ=RCC_PLLQ;
		RCC->PLLCFGR.PLLP=RCC_PLLP;
		RCC->PLLCFGR.PLLSRC=RCC_PLL_SRC;
		RCC->CR.PLLON=Types_HIGH;
		while(RCC->CR.PLLRDY==Types_LOW);
		//switch to PLL as main clock source
		//RCC->CFGR.SW=RCC_PLL;

#else
	#error "wrong Clock source Mode"
	Local_error_state=Types_NOK;
#endif
	//switch to selected clock as main clock source
	RCC->CFGR.SW=RCC_CLK_SRC;
	//SET_BIT(RCC->RCC_CR,7);
	//RCC->CR.HSITRIM=0x10;
	return Local_error_state;
}

/* API Name:       RCC_u8EnableHSE
 * Parameter In:   u32 HSE_Mode(RCC_u32_HSE_CRYSTAL,RCC_u32_HSE_BYBASS)
 * Parameter Out:  u8 Error_State
 * Description:    Enable High Speed External Clock
 */
Error_Types RCC_u8EnableHSE(u32 HSE_mode) {
	Error_Types Local_error_state = Types_OK;
	if (HSE_mode == RCC_HSE_CRYSTAL)
	{
		RCC->CR.HSEBYP=Types_LOW;
	}
	else if (HSE_mode == RCC_HSE_BYPASS)
	{
		RCC->CR.HSEBYP=Types_HIGH;
	}
	RCC->CR.HSEON=Types_HIGH;
	while (RCC->CR.HSERDY == Types_LOW);
	return Local_error_state;
}

/* API Name:       RCC_u8DisableHSE
 * Parameter In:   void
 * Parameter Out:  u8 Error_State
 * Description:    Disable High Speed External Clock
 */
Error_Types RCC_u8DisableHSE(void){
	Error_Types Local_error_state = Types_OK;
	RCC->CR.HSEON=Types_LOW;
	return Local_error_state;
}

/* API Name:       RCC_u8EnableHSI
 * Parameter In:   void
 * Parameter Out:  u8 Error_State
 * Description:    Enable High Speed Internal Clock
 */
Error_Types RCC_u8EnableHSI(void){
	Error_Types Local_error_state = Types_OK;
	RCC->CR.HSION=Types_HIGH;
	while (RCC->CR.HSIRDY == Types_LOW);
	return Local_error_state;

}

/* API Name:       RCC_u8DisableHSI
 * Parameter In:   void
 * Parameter Out:  u8 Error_State
 * Description:    Disable High Speed Internal Clock
 */
Error_Types RCC_u8DisableHSI(void){
	Error_Types Local_error_state = Types_OK;
	RCC->CR.HSION=Types_LOW;
	return Local_error_state;
}

/* API Name:       RCC_u8EnablePeripheralClk
 * Parameter In:   u8 copy_u8BusId,u8 copy_u8Peripheral
 * Parameter Out:  u8 Error_State
 * Description:    Disable Peripheral's  Clock
 */
Error_Types RCC_u8EnablePeriphiralClk(u8 copy_u8BusId,u8 copy_u8Peripheral){
	Error_Types Local_error_state = Types_OK;
		if (copy_u8Peripheral <= 31) {
			switch (copy_u8BusId) {
			case RCC_AHB1_BUS:
				SET_BIT(RCC->AHB1ENR.REG, copy_u8Peripheral);
				break;
			case RCC_AHB2_BUS:
				//Because it's the only periphiral on AHB2 bus
				RCC->AHB2ENR.OTGFSEN=Types_HIGH;
				break;
			case RCC_APB1_BUS:
				SET_BIT((RCC->APB1ENR.REG), copy_u8Peripheral);
				break;
			case RCC_APB2_BUS:
				SET_BIT((RCC->APB2ENR.REG), copy_u8Peripheral);
				break;
			default:
				Local_error_state = Types_NOK;
				break;
			}

		}
		else{
			Local_error_state = Types_NOK;
		}

		return Local_error_state;
	}

/* API Name:       RCC_u8DisablePeripheralClk
 * Parameter In:   void
 * Parameter Out:  u8 Error_State
 * Description:    Enable Peripheral's  Clock
 */
Error_Types RCC_u8DisablePeriphiralClk(u8 copy_u8BusId, u8 copy_u8Peripheral) {
	Error_Types Local_error_state = Types_OK;
	if (copy_u8Peripheral <= 31) {
		switch (copy_u8BusId) {
		case RCC_AHB1_BUS:
			CLR_BIT((RCC->AHB1ENR.REG), copy_u8Peripheral);
			break;
		case RCC_AHB2_BUS:
			//Because it's the only periphiral on AHB2 bus
			RCC->AHB2ENR.OTGFSEN=Types_LOW;
			break;
		case RCC_APB1_BUS:
			CLR_BIT((RCC->APB1ENR.REG), copy_u8Peripheral);

			break;
		case RCC_APB2_BUS:
			CLR_BIT((RCC->APB2ENR.REG), copy_u8Peripheral);

			break;
		default:
			Local_error_state = Types_NOK;
			break;
		}

	}
	else{
				Local_error_state = Types_NOK;
			}

	return Local_error_state;
}


