# STM32F401CC Drivers Repository
![View Counter](https://komarev.com/ghpvc/?username=omarbarakota&label=REPO+VIEWS&color=104de6&style=for-the-badge&base=30&abbreviated=true)

## Table Of Content

[1- Overview](#fverview)

[2- Features](#2--features)

[3- Getting Started](#getting-started)

[4- Example](#example)

[5- Repo Structure](#repo-structure)

- [Contributing](#contributing)

- [Authors](#authors)


## Overview

This repository contains a comprehensive collection of low-level drivers for the STM32F401CC microcontroller. These drivers are designed to provide easy access and control over the various peripherals and features of the STM32F401CC, enabling developers to build robust embedded systems with minimal overhead.

## Features

- **Modular Design:**
  - Each driver is modular, making it easy to include only the components you need for your project.

- **Peripheral Support:**
  - **GPIO:** General-purpose input/output configuration and control.
  - **USART:** Asynchronous serial communication.
  - **SPI:** Serial Peripheral Interface master and slave modes.
  - **I2C:** Inter-Integrated Circuit communication.
  - **ADC:** Analog-to-Digital Conversion.
  - **Timers:** Basic, general-purpose, and advanced timer configurations.
  - **RCC:** Reset and Clock Control for clock source management and peripheral clock gating.
  - **NVIC:** Nested Vectored Interrupt Controller for managing interrupts.

- **Easy Integration:**
  - Simple API designed for ease of use and integration into various applications.

- **Optimized for Performance:**
  - Efficient and lightweight code, optimized for the STM32F401CC microcontroller’s architecture.

## Documentation

- Detailed documentation for each driver is available in the respective `README.md` files within the driver directories.
- Example projects and usage scenarios are provided to demonstrate how to utilize these drivers effectively.

## Getting Started

1. **Clone the Repository:**
   - Clone this repository to your local machine using:
   ```bash
   git clone https://github.com/omarbarakota/stm32f401cc_drivers.git
   ```

2. **Include the Drivers in Your Project:**
   - Add the required driver files to your project and include the corresponding headers.

3. **Initialization:**
   - Initialize the peripherals in your `main.c` or equivalent, using the provided API.

4. **Build and Deploy:**
   - Compile your project using your preferred IDE or toolchain (e.g., STM32CubeIDE, Keil, or GCC) and flash it onto your STM32F401CC.

## Example

```c
#include "GPIO_Interface.h"
#include "USART_Interface.h"

int main(void) {
    // Initialize the GPIO and USART drivers
    GPIO_Init();
    USART_Init();

    // Application code
    while (1) {
        // Main loop
    }
}
```


## Repo Structure

This is the sturcture of the whole repo and the drivers inside for example `X_Driver`:

- `X_Private.h`: This file include the physical addresses and fixed data
- `X_Config.h`:  This file include any needed configuration to be set `Pre-compile configurations`
- `X_Interface.h`: This file has all the interfaces that the user may need
- `X_Types.h`: This File has all specialized types needed for `X Driver` 

- `X_Program.c`: This file has all the implementation for the Whole Driver

### Repo Example

````bash
stm32f401cc Drivers
      │
      └── RCC/                  # This folder has the GPIO Driverfile
      │   └── includes/         # This file Include all needed header files for RCC
      |   |    └── RCC_Private.h    # This file include the physical addresses
      |   |    └── RCC_Config.h     # This file include any needed configuration
      |   |    └── RCC_Interface.h  # This file has all the interfaces that the user may need
      |   |    └── RCC_Types.h      # This File has all specific needed types for RCC Driver 
      |   |
      └── └── src/      
      |       └── RCC_Program.c     # This file has all the implementation for the RCC Driver
      |
      ├── GPIO/             # This folder has the GPIO Driver
      │   └── includes/         # This file Include all needed header files for GPIO
      |   |    └── GPIO_Private.h    # This file include the physical addresses
      |   |    └── GPIO_Config.h     # This file include any needed configuration
      |   |    └── GPIO_Interface.h  # This file has all the interfaces that the user may need
      |   |    └── GPIO_Types.h      # This File has all specific needed types for RCC Driver       
      |   |
      └── └── src/       
      |       └── GPIO_Program.c     # This file has all the implementation for the RCC Driver
      └── etc...
````
## Supported Platforms

- STM32F401Cx


## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, feel free to open an issue or submit a pull request.

## Authors

- [Omar Barakat](https://github.com/omarbarakota)

## Acknowledgements

- Inspired by the STM32 HAL library and CMSIS.





