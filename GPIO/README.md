# GPIO Driver

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

The GPIO (General-Purpose Input/Output) driver provides a simple and efficient interface to configure and control the GPIO pins of the STM32F401CC microcontroller. This driver enables you to easily manage pin configurations, control output states, and read input states, making it essential for interfacing with various peripherals and components.

## Features

- **Pin Configuration:**
  - Configure pins as input, output, alternate function, or analog.
  - Set the output type (push-pull or open-drain) and speed (low, medium, high, or very high).
  - Configure internal pull-up and pull-down resistors.

- **Pin Control:**
  - Set or clear output pins.
  - Read the state of input pins.
  - Toggle output pins.

## 2- API Functions

### GPIO Pin Configuration Functions

- **`u8 GPIO_u8SetPinMode(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_Mode_Type PinMode);`**
  - Configures the mode of a specific GPIO pin (input, output, analog, or alternate function).

- **`u8 GPIO_u8SetPinOutputMode(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_OutputMode_Types PinOutMode);`**
  - Sets the output mode (push-pull or open-drain) for a specific GPIO pin.

- **`u8 GPIO_u8SetPinOutputSpeed(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_OutputSpeed_Types PinOutSpeed);`**
  - Configures the output speed (low, medium, high, very high) for a specific GPIO pin.

- **`u8 GPIO_u8SetPinPullMode(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_PullMode_Types PinPullMode);`**
  - Sets the internal pull-up or pull-down resistor configuration for a specific GPIO pin.

### GPIO Pin Control Functions

- **`u8 GPIO_u8GetPinValue(PORTx_Value_Type PortNum, PINx_Num_Type PinNum);`**
  - Reads the current input value (high or low) of a specific GPIO pin.

- **`u8 GPIO_u8PinOutputValue(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_BS_BR_Types PinValue);`**
  - Sets the output value (high or low) of a specific GPIO pin.

- **`u8 GPIO_u8TogglePinOutputMo(PORTx_Value_Type PortNum, PINx_Num_Type PinNum);`**
  - Toggles the output state of a specific GPIO pin.

- **`u8 GPIO_u8DirectSetPinOutputM(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_BS_BR_Types PinValue);`**
  - Directly sets or clears the output value of a specific GPIO pin without any additional processing.

- **`u8 GPIO_u8SetPinConfigLock(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, PINx_LockConfig_Type PinLockMode);`**
  - Locks the configuration of a specific GPIO pin to prevent any further changes.

- **`u8 GPIO_u8SetPinAlternativeFunc(PORTx_Value_Type PortNum, PINx_Num_Type PinNum, GPIO_AF_Values_Type PinValue);`**
  - Configures the alternate function for a specific GPIO pin to enable peripheral functionality.

### GPIO Port Configuration Functions

- **`u8 GPIO_u8SetPortMode(PORTx_Value_Type PortNum, PINx_Mode_Type PortMode);`**
  - Configures the mode of all pins in a specified GPIO port.

- **`u8 GPIO_u8SetPortOutputMode(PORTx_Value_Type PortNum, PINx_OutputMode_Types PortOutMode);`**
  - Sets the output mode (push-pull or open-drain) for all pins in a specified GPIO port.

- **`u8 GPIO_u8SetPortOutputSpeed(PORTx_Value_Type PortNum, PINx_OutputSpeed_Types PortOutSpeed);`**
  - Configures the output speed (low, medium, high, very high) for all pins in a specified GPIO port.

- **`u8 GPIO_u8SetPortPullMode(PORTx_Value_Type PortNum, PINx_PullMode_Types PortPullMode);`**
  - Sets the internal pull-up or pull-down resistors for all pins in a specified GPIO port.

### GPIO Port Control Functions

- **`u8 GPIO_u8PortOutputVal(PORTx_Value_Type PortNum, u16 copy_u16PortOutVal);`**
  - Sets the output value of all pins in a specified GPIO port.

- **`u16 GPIO_u8GetPortValue(u8 PortNum);`**
  - Reads the current input value of all pins in a specified GPIO port.

## Usage Example

```c
#include "Types.h"
#include "RCC_Interface.h"
#include "GPIO.Interface.h"

int main()
{

	RCC_u8InitSysClk();
	RCC_u8EnablePeriphiralClk(RCC_AHB1_BUS,RCC_AHB1ENR_GPIOA);
	GPIO_u8SetPinMode		(GPIO_PORTA,GPIO_PIN0,GPIO_PINMODE_OUTPUT);
	GPIO_u8SetPinOutputMode	(GPIO_PORTA,GPIO_PIN0,GPIO_PINOUT_MODE_PushPull);
	GPIO_u8SetPinOutputSpeed(GPIO_PORTA,GPIO_PIN0,GPIO_PINOUT_SPD_MedSpeed);
	GPIO_u8PinOutputValue	(GPIO_PORTA,GPIO_PIN0,GPIO_PINOUT_SET);

	GPIO_u8SetPinMode		(GPIO_PORTA,GPIO_PIN5,GPIO_PINMODE_OUTPUT);
	GPIO_u8SetPinOutputMode	(GPIO_PORTA,GPIO_PIN5,GPIO_PINOUT_MODE_PushPull);
	GPIO_u8SetPinOutputSpeed(GPIO_PORTA,GPIO_PIN5,GPIO_PINOUT_SPD_MedSpeed);
	GPIO_u8PinOutputValue	(GPIO_PORTA,GPIO_PIN5,GPIO_PINOUT_SET);

  // Infinite loop
  while (1)
    {

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
stm32f401cc GPIO Driver
      └── includes/         # This file Include all needed header files for GPIO
      |   |  └── GPIO_Private.h    # This file include the physical addresses
      |   |  └── GPIO_Config.h     # This file include any needed configuration
      |   |  └── GPIO_Interface.h  # This file has all the interfaces that the user may need
      |   |  └── GPIO_Types.h      # This File has all specific needed types for GPIO Driver 
      |   |
      └──  src/      
      |      └── GPIO_Program.c     # This file has all the implementation for the GPIO Driver
   
````

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss any changes.

## Authors

- [Omar Barakat](https://github.com/omarbarakota)

## Acknowledgements

- Inspired by the STM32 HAL library and CMSIS.

