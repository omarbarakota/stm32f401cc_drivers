/*
 * Systick_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Barakat
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/*Func name: STK_void_Init
 * Description: Initialize the Systick peripheral and select the systick clock source
 */
void STK_void_Init();
/*Func name: STK_voidSetBusyWait
 * Description: This function is the ideal substitute for the delay function for the handler
 * I/P arguments:
 * 				Copyu32NoCounts: The Value that the reload will count down from to zero aka. delay time
 */
void STK_voidSetBusyWait(u32 Copyu32NoCounts);

void STK_voidSetDelayMs(u32 Delay_u32Ms);

void STK_voidSetDelayUs(u32 Delay_u32Us);

/*Func name: STK_voidSetIntervalSingle
 * Description: This function Adjust the task that the Systick handler will (Only for one time)
 * I/P arguments:
 * 				Copyu32NoCounts: The Value that the reload will count down from to zero aka. periodicity
 * 				Lpf: The function that needs to be executed by the handler
 */
void STK_voidSetIntervalSingle(u32 Copyu32NoCounts,void (*Lpf)(void));
/*Func name: STK_voidSetIntervalPeriodic
 * Description: This function Adjust the task that the Systick handler will (For each period)
 * I/P arguments:
 * 				Copyu32NoCounts: The Value that the reload will count down from to zero aka. periodicity
 * 				Lpf: The function that needs to be executed by the handler
 */
void STK_voidSetIntervalPeriodic(u32 Copyu32NoCounts,void (*Lpf)(void));
/*Func name: STK_voidGetRemainingTime
 * Description: This returns the current time in counter
 * I/P arguments:
 * 				return: u32_Current
 */
u32 STK_voidGetRemainingTime(void);

/*Func name: STK_voidGetElapsedTime
 * Description: This returns the passed time by counter
 * I/P arguments:
 * 				return: u32_Elapsed
 */
u32 STK_voidGetElapsedTime(void);

/*Func name: STK_voidEnableInterrupt
 * Description: This Enables Interrupt systick interrupt generation
 */
void STK_voidEnableInterrupt(void);
/*Func name: STK_voidDisableInterrupt
 * Description: This Disables Interrupt systick interrupt generation
 */
void STK_voidDisableInterrupt(void);


#endif /* SYSTICK_INTERFACE_H_ */
