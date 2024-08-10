

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#include "GPIO_Types.h"


/*GPIO Base Addresses*/
#define GPIOA_Base_Address		0x40020000
#define GPIOB_Base_Address		0x40020400
#define GPIOC_Base_Address		0x40020800



//Register GPIOx_MODER BITS  mask
#define GPIOX_MODER_MODER0		0x00000003

//Register GPIOX_OTYPER BITS  mask
#define GPIOX_OTYPER_OT0		0x00000001


//Register GPIOX_OSPEEDR BITS  mask
#define GPIOX_OSPEEDR_OSPEEDR0	0x00000003


//Register GPIOX_PUPDR BITS  mask
#define GPIOX_PUPDR_PUPDR0		0x00000003


//Register GPIOX_IDR BITS  mask
#define GPIOX_IDR_IDR0			0x00000001

//Register GPIOX_ODR BITS  mask
#define GPIOX_ODR_ODR0			0x00000001

//Register GPIOX_BSRR BITS  mask
#define GPIOX_BSRR_BS0			0x00000001
#define GPIOX_BSRR_BY0			0x00010000

//Register GPIOX_ODR BITS  mask
#define GPIOX_LCKR_LCK0			0x00000001

// Port Modification Constants

#define PORT_INPUT				0x00000000
#define PORT_OUTPUT				0x55555555
#define PORT_ALTERNATE			0xaaaaaaaa
#define PORT_ANALOG				0xffffffff


#define PORT_OUT_MODE_PUSHPULL	0x00000000
#define PORT_OUT_MODE_OPENDRAIN	0x0000ffff

#define PORT_SPEED_LOW			0x00000000
#define PORT_SPEED_MED			0x55555555
#define PORT_SPEED_HIGH			0xaaaaaaaa
#define PORT_SPEED_VERYHIGH		0xffffffff

#define PORT_PULLDOWN			0x00000000
#define PORT_PULLUP				0x15555555


#define GPIOA						((GPIO_MemMap_t*)(GPIOA_Base_Address))
#define GPIOB						((GPIO_MemMap_t*)(GPIOB_Base_Address))
#define GPIOC						((GPIO_MemMap_t*)(GPIOC_Base_Address))


#define RESET_OFFSET	16



#endif /* GPIO_PRIVATE_H_ */
