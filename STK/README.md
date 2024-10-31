# SysTick Driver
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

The SysTick driver provides an easy-to-use interface for configuring and managing the System Timer (SysTick) on the STM32F401CC microcontroller. SysTick is a crucial component for generating time delays, periodic interrupts, and timekeeping functions in embedded systems. This driver simplifies the process of setting up the SysTick timer and leveraging its features for various timing-related tasks.

## Features

- **Configurable Tick Frequency:**
  - Set the SysTick timer to generate interrupts at a desired frequency, enabling accurate time delays and periodic tasks.

- **Delay Generation:**
  - Create precise time delays in milliseconds or microseconds using the SysTick timer.

- **Elapsed Time Measurement:**
  - Measure the elapsed time since the SysTick timer started, useful for benchmarking and time-critical applications.

- **Remaining Time Query:**
  - Check the remaining time before the SysTick timer expires, helping in tasks where the time left is critical.

## Configuration Macros

- **`STK_CLK_Value`**: This Macro should be modified in `SysTick_config.h` to have the system frequency for example if system clock is `16Mhz` 

```C
#define STK_CLK_Value 16000000
```

- **`STK_CLK`**: This macro should be modified depending on the options that you want `STK_AHB_CLK` or `STK_AHB_CLK_DIV_BY_8`
```C
#define STK_CLK		STK_AHB_CLK_DIV_BY_8
```


## API Functions

### Initialization and Configuration

- **`void STK_voidInit(void);`**
  - Initializes the SysTick timer with default settings (typically disables it initially).

### Time Delay Functions

- **`void STK_voidSetBusyWait(u32 Delay_u32Ticks);`**
  - Creates a blocking delay for the specified number of SysTick ticks.

- **`void STK_voidSetDelayMs(u32 Delay_u32Ms);`**
  - Creates a blocking delay in milliseconds.

- **`void STK_voidSetDelayUs(u32 Delay_u32Us);`**
  - Creates a blocking delay in microseconds.

### Time Measurement Functions

- **`u32 STK_voidGetRemainingTime(void);`**
  - Returns the remaining time (in ticks) before the SysTick timer reaches zero.

- **`u32 STK_voidGetElapsedTime(void);`**
  - Calculates and returns the time (in ticks) that has elapsed since the SysTick timer started.

### Interrupt Management

- **`void STK_voidEnsableInterrupt(void);`**
  - Enables the SysTick interrupt, allowing the timer to generate an interrupt when it reaches zero.

- **`void STK_voidDisableInterrupt(void);`**
  - Disables the SysTick interrupt.
  void STK_voidSetIntervalPeriodic(u32 Copyu32NoCounts,void (*Lpf)(void));

- **`void STK_voidSetIntervalSingle(u32 Copyu32NoCounts,void (*Lpf)(void));`**
  - Sets a user-defined callback function to be executed when the SysTick interrupt occurs **ONE TIME ONLY**.

- **`void STK_voidSetIntervalPeriodic(u32 Copyu32NoCounts,void (*Lpf)(void));`**
  - Sets a user-defined callback function to be executed when the SysTick interrupt occurs **For each period**.

## Usage Example

```c
#include "systick_driver.h"

int main(void) {
    // Initialize and start SysTick
    STK_voidInit();
    STK_voidSetDelayMs(1000);  // 1 second delay

    while (1) {
        // Main loop
        // Toggle an LED or perform a task every second
        STK_voidSetBusyWait(16000000);  // Assuming SysTick is configured for 16 MHz
    }
}
```

## Supported Platforms

- STM32F401CC

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
stm32f401cc Systick Driver
      └── includes/         # This file Include all needed header files for Systick
      |   |  └── Systick_Private.h    # This file include the physical addresses
      |   |  └── Systick_Config.h     # This file include any needed configuration
      |   |  └── Systick_Interface.h  # This file has all the interfaces that the user may need
      |   |  └── Systick_Types.h      # This File has all specific needed types for Systick Driver 
      |   |
      └──  src/      
      |      └── Systick_Program.c     # This file has all the implementation for the Systick Driver
   
````

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss any changes.

## Authors

- [Omar Barakat](https://github.com/omarbarakota)

## Acknowledgements

- Inspired by the STM32 HAL library and CMSIS.







