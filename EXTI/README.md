
# EXTI Driver

These drivers are made for all students for learning porposes **ONLY**

## Table Of Content

[1- Overview](#1--Overview)

[2- API Overview](#2--api-overview)


- [2.1- API Function description](#functions)

- [2.2- Usage Example](#usage-example)


[3- Installation](#3--installation)

- [3.1- Install Drivers](#install-drivers)

- [3.2- Run Application](#run-application)

[Folder Structure](#folder-structure)

## 1- Overview

This repository contains an EXTI (External Interrupt) library designed for STM32F401CC microcontrollers. The library provides a set of macros, enums, and functions to configure and manage external interrupts in an efficient and user-friendly manner.

### EXTI Diagram

I made this diagram so you can visualize the circuit and processes 

![EXTI Diagram](https://i.imgur.com/FzEpkVQ.png)

## Features

- **Interrupt Masking**: Enable or disable external interrupt lines.
- **Edge Selection**: Configure the interrupt to trigger on rising edge, falling edge, or both.
- **Line Selection**: Choose from a wide range of EXTI lines (0-18, 21-22).
- **SYSCFG Configuration**: Configure the system configuration for different GPIO ports.
- **Callback Support**: Assign and manage callback functions for handling interrupts.

## 2- API Overview

### Interfacing Macros

The library uses the following enums for easier configuration:

- **EXTI_Mask_t**: Defines the masking status of the interrupt.
  - `EXTI_INTERRUPT_MASKED`
  - `EXTI_INTERRUPT_NOT_MASKED`

- **EXTI_Edge_t**: Defines the edge on which the interrupt should trigger.
  - `EXTI_RISING_EDGE`
  - `EXTI_FALLING_EDGE`
  - `EXTI_RISING_FALLING_EDGE`

- **EXTI_Line_t**: Defines the available EXTI lines.
  - `EXTI_LINE0` to `EXTI_LINE18`
  - `EXTI_LINE21` to `EXTI_LINE22`

- **EXTI_SYSCFG**: Defines the available system configuration ports.
  - `SYSCFG_PAx`
  - `SYSCFG_PBx`
  - `SYSCFG_PCx`

### Functions

The library provides the following functions:

- **`EXTI_eSetInterruptStatus`**: Configure the interrupt status (masked or not masked) for a specific EXTI line.
  ```c
  Error_Types EXTI_eSetInterruptStatus(EXTI_Line_t Copy_u8EXTINumber, EXTI_Mask_t Copy_u8EXTIStatus);
  ```

- **`EXTI_eSetInterruptEdge`**: Configure the edge on which the interrupt should trigger for a specific EXTI line.
  ```c
  Error_Types EXTI_eSetInterruptEdge(EXTI_Line_t Copy_u8EXTINumber, EXTI_Edge_t Copy_u8EXTIEdge);
  ```

- **`EXTI_eClearInterruptPending`**: Clear the pending interrupt flag for a specific EXTI line.
  ```c
  Error_Types EXTI_eClearInterruptPending(EXTI_Line_t Copy_u8EXTINumber);
  ```

- **`EXTI_eIsInterruptActive`**: Check if an interrupt is active for a specific EXTI line.
  ```c
  Error_Types EXTI_eIsInterruptActive(EXTI_Line_t Copy_u8EXTINumber, u8* Copy_pu8EXTIStatus);
  ```

- **`EXTI_eChangeEXTISource`**: Change the source input for a specific EXTI line.
  ```c
  Error_Types EXTI_eChangeEXTISource(EXTI_SYSCFG Copy_u8IntPort, EXTI_Line_t Copy_u8IntNum);
  ```

- **`EXTI_eSetInterruptCallback`**: Set a callback function that will be called when an interrupt occurs on a specific EXTI line.
  ```c
  Error_Types EXTI_eSetInterruptCallback(EXTI_Line_t Copy_u8EXTINumber, void (*Copy_pfCallback)(void));
  ```

## Usage Example

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
### Summary of the steps

1- Enable the GPIO clock for the relevant port.
2- Configure the GPIO pin as an input.
3- (Optional) Configure pull-up/pull-down resistors for the GPIO pin.
4- Map the GPIO pin to an EXTI line using the SYSCFG_EXTICR register.
5- Set the EXTI trigger to rising edge (or falling edge, or both).
6- Unmask the EXTI line in the IMR to enable interrupt generation.
7- Enable the EXTI interrupt in the NVIC and set its priority.
8- Implement the ISR to handle the interrupt and clear the pending bit.
9- Run your main loop, relying on interrupts to handle external events.

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
stm32f401cc EXTI Driver
      └── includes/         # This file Include all needed header files for EXTI
      |   |  └── EXTI_Private.h    # This file include the physical addresses
      |   |  └── EXTI_Config.h     # This file include any needed configuration
      |   |  └── EXTI_Interface.h  # This file has all the interfaces that the user may need
      |   |  └── EXTI_Types.h      # This File has all specific needed types for EXTI Driver 
      |   |
      └──  src/      
             └── EXTI_Program.c     # This file has all the implementation for the EXTI Driver
   
````

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss any changes.

## Authors

- [Omar Barakat](https://github.com/omarbarakota)

## Acknowledgements

- Inspired by the STM32 HAL library and CMSIS.

