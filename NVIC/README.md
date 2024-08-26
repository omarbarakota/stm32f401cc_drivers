

# NVIC Driver

These drivers are made for all students for learning porposes **ONLY**

## Table Of Content

[1- Overview](#1--Overview)

[2- API Functions](#2--api-functions)


- [2.1- API Function description](#2--api-functions)

- [2.2- Usage Example](#usage-example)


[3- Installation](#3--installation)

- [3.1- Install Drivers](#install-drivers)

- [3.2- Run Application](#run-application)

[Folder Structure](#folder-structure)


## 1- Overview

This repository contains an NVIC (Nested Vectored Interrupt Controller) library designed for STM32F401CC microcontrollers. The library provides a set of enums and functions to configure and manage interrupt priorities, enable or disable interrupts, and handle pending interrupts efficiently.

## Features

- **IRQ Management**: Enable or disable specific IRQs (Interrupt Requests).
- **Pending IRQ Handling**: Set or clear pending IRQs.
- **Priority Configuration**: Configure group and sub-group priorities for interrupts.
- **IRQ Status Check**: Retrieve the state and priority of specific IRQs.


## 2- API Overview

### Enums

The library uses the following enums for easier configuration:

- **IRQn_t**: Defines the available interrupt request (IRQ) numbers, including Cortex-M4 processor exceptions and STM32F401CC-specific interrupts.
  - Cortex-M4 Exceptions: `NVIC_IRQ_NMI`, `NVIC_IRQ_HardFault`, `NVIC_IRQ_MemManage`, etc.
  - STM32F401CC Interrupts: `NVIC_IRQ_WWDG`, `NVIC_IRQ_EXTI0`, `NVIC_IRQ_TIM1_CC`, etc.

- **Priority_Group_Config_t**: Defines the priority group and sub-group configurations.
  - `NVIC_Group16_0Sub`: 16 priority groups, 0 sub-groups.
  - `NVIC_Group8_2Sub`: 8 priority groups, 2 sub-groups.
  - `NVIC_Group4_4Sub`: 4 priority groups, 4 sub-groups.
  - `NVIC_Group2_8Sub`: 2 priority groups, 8 sub-groups.
  - `NVIC_Group0_16Sub`: 0 priority groups, 16 sub-groups.

- **Priority_Group_t**: Defines the priority groups.
  - `NVIC_Group0` to `NVIC_Group15`

- **Priority_SubGroup_t**: Defines the priority sub-groups.
  - `NVIC_SubGroup0` to `NVIC_SubGroup15`

### Functions

The library provides the following functions:

- **`NVIC_eEnableIRQ`**: Enable a specific IRQ.
  ```c
  Error_Types NVIC_eEnableIRQ(IRQn_t IRQn);
  ```

- **`NVIC_eDisableIRQ`**: Disable a specific IRQ.
  ```c
  Error_Types NVIC_eDisableIRQ(IRQn_t IRQn);
  ```

- **`NVIC_u8GetStateIRQ`**: Get the state of a specific IRQ.
  ```c
  u8 NVIC_u8GetStateIRQ(IRQn_t IRQn);
  ```

- **`NVIC_eSetPendingIRQ`**: Set a pending state for a specific IRQ.
  ```c
  Error_Types NVIC_eSetPendingIRQ(IRQn_t IRQn);
  ```

- **`NVIC_eClearPendingIRQ`**: Clear the pending state for a specific IRQ.
  ```c
  Error_Types NVIC_eClearPendingIRQ(IRQn_t IRQn);
  ```

- **`NVIC_u8GetPendingIRQ`**: Get the pending state of a specific IRQ.
  ```c
  u8 NVIC_u8GetPendingIRQ(IRQn_t IRQn);
  ```

- **`NVIC_eSetPriorityConfig`**: Set the priority configuration for group and sub-group priorities.
  ```c
  Error_Types NVIC_eSetPriorityConfig(Priority_Group_Config_t Priority_Config);
  ```

- **`NVIC_eSetPriority`**: Set the priority for a specific IRQ.
  ```c
  Error_Types NVIC_eSetPriority(IRQn_t IRQn, Priority_Group_t GroupNum, Priority_SubGroup_t SubGroupNum);
  ```

- **`NVIC_eGetPriority`**: Get the priority of a specific IRQ.
  ```c
  Error_Types NVIC_eGetPriority(IRQn_t IRQn, Priority_Group_t *GroupNum, Priority_SubGroup_t *SubGroupNum);
  ```

## Usage Example (With EXTI)

```c
#include "Types.h"
#include "RCC_Interface.h"
#include "GPIO.Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"

int main()
{

    RCC_u8InitSysClk();
	RCC_u8EnablePeriphiralClk(RCC_AHB1_BUS,RCC_AHB1ENR_GPIOA);
	
    // This is the prephiral used to select EXTI port
	RCC_u8EnablePeriphiralClk(RCC_APB2_BUS,RCC_APB2ENR_SYSCFGEN);
    
    //Set Pin A2 as output for led
	GPIO_u8SetPinMode		(GPIO_PORTA,GPIO_PIN2,GPIO_PINMODE_OUTPUT);
	GPIO_u8SetPinOutputMode	(GPIO_PORTA,GPIO_PIN2,GPIO_PINOUT_MODE_PushPull);
	GPIO_u8SetPinOutputSpeed(GPIO_PORTA,GPIO_PIN2,GPIO_PINOUT_SPD_MedSpeed);

    //Set EXTI Pin B12 as input
	GPIO_u8SetPinMode		(GPIO_PORTB,GPIO_PIN12,GPIO_PINMODE_INPUT);
	//Set Pin Pull Mode (Optional)
    GPIO_u8SetPinPullMode	(GPIO_PORTB,GPIO_PIN12,GPIO_PININ_PullDown);
    //Set NVIC Priority config
	NVIC_eSetPriorityConfig		(NVIC_Group2_8Sub);
    //Set EXTI Priority
	NVIC_eSetPriority			(NVIC_IRQ_EXTI15_10,NVIC_Group0,NVIC_SubGroup0);
    //Set Call Back function
	EXTI_eSetInterruptCallback	(EXTI_LINE12,Toggle_led_A2);
    //Set Trigger edge select
	EXTI_eSetInterruptEdge		(EXTI_LINE12,EXTI_RISING_EDGE);
    // Enable EXTI
	EXTI_eSetInterruptStatus	(EXTI_LINE12,EXTI_INTERRUPT_NOT_MASKED);
    // Select EXTI1 from portB
	EXTI_eChangeEXTISource		(SYSCFG_PBx, EXTI_LINE12);
    // Enable Interrupt for NVIC
	NVIC_eEnableIRQ				(NVIC_IRQ_EXTI15_10);

  // Empty Infinite loop
  while (1)
    {

    }
  return 0;
}

```
I would highly recommend checking [EXTI Driver](https://github.com/omarbarakota/stm32f401cc_drivers/tree/main/EXTI) for deep understanding

## 3- Installation

### Install Drivers

Clone the repo and navigate to the project directory

```bash
git clone https://github.com/omarbarakota/stm32f401cc_drivers.git
```

1- Copy the Header files with `.h` extention to the `includes` into your project

2- Copy the source files with `.c` extention to the `src` into your project

### Run Application

1- Include the Interface file into `main.c` by
`#include "file_Interface.h"`

2- Using the functions inside you can run your needed application

## Folder Structure

````bash
stm32f401cc NVIC Driver
      └── includes/         # This file Include all needed header files for NVIC
      |   |  └── NVIC_Private.h    # This file include the physical addresses
      |   |  └── NVIC_Config.h     # This file include any needed configuration
      |   |  └── NVIC_Interface.h  # This file has all the interfaces that the user may need
      |   |  └── NVIC_Types.h      # This File has all specific needed types for NVIC Driver 
      |   |
      └──  src/      
             └── NVIC_Program.c     # This file has all the implementation for the NVIC Driver
   
````

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss any changes.

## Authors

- [Omar Barakat](https://github.com/omarbarakota)

## Acknowledgements

- Inspired by the STM32 HAL library and CMSIS.



