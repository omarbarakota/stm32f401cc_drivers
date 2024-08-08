# ARM MCAL Drivers for stm32f401cc 

These drivers are made for all students for learning porposes **ONLY**

by: [Omar Barakat](https://www.linkedin.com/in/omarbarakota/)

Feel free to use these drivers 

## Table Of Content

[1- Description](#1--description)

[2- Installation](#2--installation)

- [2.1- Install Drivers](#install-drivers)

- [2.2- Run Application](#run-application)

[Folder Structure](#folder-structure)

## 1- Description

## 2- Installation

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


## folder-structure

````bash
stm32f401cc Drivers
      │
      └── RCC/                  # This folder has the GPIO Driverfile
      │   └── includes/         # This file Include all needed header files for RCC
      |   |    └── RCC_Private.h    # This file include the physical addresses
      |   |    └── RCC_Config.h     # This file include any needed configuration
      |   |    └── RCC_Interface.h  # This file has all the interfaces that the user may need
      |   |
      └── └── src/      
      |       └── RCC_Program.c     # This file has all the implementation for the RCC Driver
      |
      ├── GPIO/             # This folder has the GPIO Driver
      │   └── includes/         # This file Include all needed header files for GPIO
      |   |    └── GPIO_Private.h    # This file include the physical addresses
      |   |    └── GPIO_Config.h     # This file include any needed configuration
      |   |    └── GPIO_Interface.h  # This file has all the interfaces that the user may need
      |   |
      └── └── src/       
      |       └── GPIO_Program.c     # This file has all the implementation for the RCC Driver
      └── etc...
````

