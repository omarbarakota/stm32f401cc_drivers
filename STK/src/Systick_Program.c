/*
 * Systick_Program.c
 *  Created on: Aug 12, 2023
 *      Author: Barakat
 */

#include "Types.h"
#include "BitMath.h"

#include "Systick_Types.h"
#include "Systick_Config.h"
#include "Systick_Interface.h"
#include "Systick_Private.h"

/*Flag indicates which mode you want the handler to run (single time or each period) */
u8 STK_u8SingleIntFlag=STK_IntervalFlag_Single;
/* The Pointer that will hold the Task's function and call it */
void(*STK_pToFunction)(void);

/*Func name: STK_void_Init
 * Description: Initialize the Systick peripheral and select the systick clock source
 */
void STK_void_Init(void){
	/*Set Initial Values to the registers*/
	STK->CTRL.BITS.ENABLE=Types_LOW;
	STK->CTRL.BITS.TICKINT=Types_LOW;
	STK->LOAD.BITS.RELOAD=0;
	STK->VAL.BITS.CURRENT=0;


#if(STK_CLK==STK_AHB_CLK)
	/*Select Clock source mode AHB clock (System Clock)*/
	STK->CTRL.BITS.CLKSOURCE=STK_AHB_CLK;
#elif(STK_CLK==STK_AHB_CLK_DIV_BY_8)
	/*Select Clock source mode AHB/8 clock (System Clock/8)*/
	STK->CTRL.BITS.CLKSOURCE=STK_AHB_CLK_DIV_BY_8;
#else
#error("ERROR SYSTICK CLK")
#endif
}

/*Func name: STK_voidSetBusyWait
 * Description: This function is the ideal substitute for the delay function for the handler
 * I/P arguments:
 * 				Copyu32NoCounts: The Value that the reload will count down from to zero aka. delay time
 */
void STK_voidSetBusyWait(u32 Copyu32NoCounts){
	STK->CTRL.BITS.ENABLE=Types_LOW;
	STK->CTRL.BITS.TICKINT=Types_LOW;
	STK->LOAD.BITS.RELOAD=0;
	STK->VAL.BITS.CURRENT=0;

	STK->LOAD.BITS.RELOAD=Copyu32NoCounts;
	STK->CTRL.BITS.ENABLE=Types_HIGH;
	while(STK->CTRL.BITS.COUNTFLAG==Types_LOW);
	STK->CTRL.BITS.TICKINT=Types_LOW;

}

void STK_voidSetDelayMs(u32 Delay_u32Ms){
    // Assuming a system clock of 16 MHz and SysTick configured for 1 ms tick
    // 1 ms delay corresponds to 16000 ticks (16 MHz / 1000)
	u32 ticks = Delay_u32Ms * (STK_CLK_Value/1000);
    STK_voidSetBusyWait(ticks);
}

void STK_voidSetDelayUs(u32 Delay_u32Us){
    // Assuming a system clock of 16 MHz and SysTick configured for 1 us tick
    // 1 us delay corresponds to 16 ticks (16 MHz / 1000000)
    u32 ticks = Delay_u32Us * (STK_CLK_Value/1000000);
    STK_voidSetBusyWait(ticks);
}


/*Func name: STK_voidSetIntervalSingle
 * Description: This function Adjust the task that the Systick handler will (Only for one time)
 * I/P arguments:
 * 				Copyu32NoCounts: The Value that the reload will count down from to zero aka. periodicity
 * 				Lpf: The function that needs to be executed by the handler
 */
void STK_voidSetIntervalSingle(u32 Copyu32NoCounts,void (*Lpf)(void)){
	STK_pToFunction=Lpf;
	STK->LOAD.BITS.RELOAD=Copyu32NoCounts;
	STK->CTRL.BITS.ENABLE=Types_HIGH;
	STK->CTRL.BITS.TICKINT=Types_HIGH;
	/*Interval flag when up only does the interrupt handler once*/
	STK_u8SingleIntFlag=STK_IntervalFlag_Period;
}
/*Func name: STK_voidSetIntervalPeriodic
 * Description: This function Adjust the task that the Systick handler will (For each period)
 * I/P arguments:
 * 				Copyu32NoCounts: The Value that the reload will count down from to zero aka. periodicity
 * 				Lpf: The function that needs to be executed by the handler
 */
void STK_voidSetIntervalPeriodic(u32 Copyu32NoCounts,void (*Lpf)(void)){
	STK_pToFunction=Lpf;
	STK->LOAD.BITS.RELOAD=Copyu32NoCounts;
	STK->CTRL.BITS.ENABLE=Types_HIGH;
	STK->CTRL.BITS.TICKINT=Types_HIGH;
	STK_u8SingleIntFlag=STK_IntervalFlag_Single;

}

/*Func name: STK_voidGetRemainingTime
 * Description: This returns the current value in counter
 * I/P arguments:
 * 				return: u32_Current
 */
u32 STK_voidGetRemainingTime(void)
{
	return (u32) STK->VAL.BITS.CURRENT;
}

/*Func name: STK_voidGetElapsedTime
 * Description: This returns the passed time by counter
 * I/P arguments:
 * 				return: u32_Elapsed
 */
u32 STK_voidGetElapsedTime(void){

	/*Remaining time = Reload time (Initial start)- Current time */
	return (u32) ((STK->LOAD.BITS.RELOAD)-(STK->VAL.BITS.CURRENT));
}


/*Func name: Private_voidDisableSTK
 * Description: Disable Systick Peripheral
 */
void Private_voidDisableSTK(void){
	STK->CTRL.BITS.ENABLE=Types_LOW;
	STK->CTRL.BITS.TICKINT=Types_LOW;
	STK->LOAD.BITS.RELOAD=0;
	STK->VAL.BITS.CURRENT=0;

}


/*Func name: STK_voidEnableInterrupt
 * Description: This Enables Interrupt systick interrupt generation
 */
void STK_voidEnableInterrupt(void){
	STK->CTRL.BITS.TICKINT=Types_HIGH;
}

/*Func name: STK_voidDisableInterrupt
 * Description: This Disables Interrupt systick interrupt generation
 */
void STK_voidDisableInterrupt(void){
	STK->CTRL.BITS.TICKINT=Types_LOW;
}



/*Func name: SysTick_Handler
 * Description: This Is the handler that runs when the systick interrupt flag is set
 */
void SysTick_Handler(void){
	if(STK_u8SingleIntFlag==STK_IntervalFlag_Period){
		/*Interval flag is up only when calling set interval single so we do the handler here only once*/
		Private_voidDisableSTK();
	}
	if(STK_pToFunction!=NULL){
		/*Interval flag is down set interval single is not called and the only function that
		 * can edit STK_ptrtofunc is the periodic function so it always execute the handler*/
		STK_pToFunction();
	}

}





