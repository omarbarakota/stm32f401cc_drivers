/*
 * EXTI_Private.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Barakat
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#include "EXTI_Types.h"

#define EXTI_BASE_ADDRESS  0x40013C00

#define EXTI ((volatile EXTI_t*)EXTI_BASE_ADDRESS)

#define SYSCFG_BASE_ADDRESS  0x40013800

#define SYSCFG ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)



#endif /* EXTI_PRIVATE_H_ */
