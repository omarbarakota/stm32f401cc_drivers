# RCC Driver

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

The RCC (Reset and Clock Control) driver provides an interface to configure and manage the clock system of a microcontroller. This driver allows you to enable or disable peripheral clocks, configure the system clock, and manage clock sources like PLL, HSE, and HSI.

## Features

- **Clock Configuration:** 
  - System clock configuration using HSI, HSE, and PLL.
  - Configurable AHB, APB1, and APB2 prescalers.
  - Peripheral clock gating control for power optimization.
  
- **Reset Control:**
  - Manage peripheral resets.
  - Control system reset sources.

- **Clock Source Management:**
  - Configure and select different clock sources (HSI, HSE, PLL).
  - Ability to fine-tune PLL settings for different system frequencies.

## 2- API Functions

### RCC Initialization
- `void RCC_u8InitSysClk(void);`
  - Initializes the RCC system with default or user-defined configurations.

### Peripheral Clock Management
- `void RCC_u8EnablePeripheralClk(RCC_Peripheral_t peripheral);`
  - Enables the clock for a specific peripheral.

- `void RCC_u8DisablePeripheralClk(RCC_Peripheral_t peripheral);`
  - Disables the clock for a specific peripheral.

### Reset Management
- `void RCC_u8ResetPeripheral(RCC_Peripheral_t peripheral);`
  - Resets a specific peripheral.

### Reset Management
- `void RCC_u8EnableHSE(void);`
  - Enable High Speed External Clock Source `Note: 4-26 Mhz`

### Reset Management
- `void RCC_u8DisableHSE(void);`
  - Disable High Speed External Clock Source

### Reset Management
- `void RCC_u8EnableHSI(void);`
  - Enable High Speed Internal Clock Source

### Reset Management
- `void RCC_u8DisableHSI(void);`
  - Disable High Speed Internal Clock Source


## Usage Example

```c
#include "RCC_Interface.h"

int main(void) {
    
    // Configure the system clock from RCC_Config.h file
    // Initialize RCC system
    RCC_u8InitSysClk();
    // Enable clock for GPIOA
	  RCC_u8EnablePeriphiralClk(RCC_AHB1_BUS,RCC_AHB1ENR_GPIOA);
    // Your application code here
    
    while(1) {
        // Main loop
    }
}
```

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
stm32f401cc RCC Driver
      │
      └── RCC/                  # This folder has the GPIO Driverfile
      │   └── includes/         # This file Include all needed header files for RCC
      |   |    └── RCC_Private.h    # This file include the physical addresses
      |   |    └── RCC_Config.h     # This file include any needed configuration
      |   |    └── RCC_Interface.h  # This file has all the interfaces that the user may need
      |   |
      └── └── src/      
               └── RCC_Program.c    # This file has all the implementation for the RCC Driver
     
````

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss any changes.

## Authors

- [Omar Barakat](https://github.com/omarbarakota)

## Acknowledgements

- Inspired by the STM32 HAL library and CMSIS.

