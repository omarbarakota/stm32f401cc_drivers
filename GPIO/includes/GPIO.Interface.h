
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "Types.h"








typedef enum{
	GPIO_PINMODE_INPUT,
	GPIO_PINMODE_OUTPUT,
	GPIO_PINMODE_Alternative,
	GPIO_PINMODE_Analog
}PINx_Mode_Type;

typedef enum{
	GPIO_PINOUT_MODE_PushPull,
	GPIO_PINOUT_MODE_OpenDrain
}PINx_OutputMode_Types;
typedef enum{
	GPIO_PINOUT_SPD_LowSpeed,
	GPIO_PINOUT_SPD_MedSpeed,
	GPIO_PINOUT_SPD_HighSpeed,
	GPIO_PINOUT_SPD_VeryHighSpeed
}PINx_OutputSpeed_Types;

typedef enum{
	GPIO_PININ_NoPull,
	GPIO_PININ_PullUp,
	GPIO_PININ_PullDown
}PINx_PullMode_Types;

typedef enum{
	GPIO_PINOUT_RESET,
	GPIO_PINOUT_SET
}PINx_BS_BR_Types;
typedef enum{
	GPIO_PINLOCK_OFF,
	GPIO_PINLOCK_ON
}PINx_LockConfig_Type;

typedef enum{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15
}PINx_Num_Type;
typedef enum{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
}PORTx_Value_Type;

/*Alternative functions Values*/
typedef enum{
	GPIO_AF0,
	GPIO_AF1,
	GPIO_AF2,
	GPIO_AF3,
	GPIO_AF4,
	GPIO_AF5,
	GPIO_AF6,
	GPIO_AF7,
	GPIO_AF8,
	GPIO_AF9,
	GPIO_AF10,
	GPIO_AF11,
	GPIO_AF12,
	GPIO_AF13,
	GPIO_AF14,
	GPIO_AF15,
}GPIO_AF_Values_Type;


/*Func name: GPIO_u8SetPinMode
 * Description: Set the specified pin mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinMode:
 *								 	GPIO_PINMODE_INPUT		GPIO_PINMODE_Alternative
 *								 	GPIO_PINMODE_OUTPUT		GPIO_PINMODE_Analog
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinMode				(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_Mode_Type 			  PinMode);

/*Func name: GPIO_u8SetPinOutputMode
 * Description: Set output pin mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinOutMode:
 *								 	GPIO_PINOUT_MODE_PushPull
 *								 	GPIO_PINOUT_MODE_OpenDrain
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinOutputMode			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_OutputMode_Types  	  PinOutMode);

/*Func name: GPIO_u8SetPinOutputSpeed
 * Description: Set output pin speed
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinOutSpeed:
 *								 	GPIO_PINOUT_SPD_LowSpeed		GPIO_PINOUT_SPD_HighSpeed
 *								 	GPIO_PINOUT_SPD_MedSpeed		GPIO_PINOUT_SPD_VeryHighSpeed
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinOutputSpeed			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_OutputSpeed_Types 	  PinOutSpeed);

/*Func name: GPIO_u8SetPinPullMode
 * Description: Set input pin pull mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinPullMode:
 *								 	GPIO_PININ_NoPull		GPIO_PININ_PullDown
 *								 							GPIO_PININ_PullUp
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinPullMode			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_PullMode_Types 	  PinPullMode);

/*Func name: GPIO_u8GetPinValue
 * Description:Get the input pin value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 *				return:PinValue
 */
u8 GPIO_u8GetPinValue				(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum	);

/*Func name: GPIO_u8ChangePinOutputMode
 * Description:Direct atomic change of OP Mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	GPIP_PINOUT_MODE_RESET		//GPIO PIN Output Reset
 *								 	GPIO_PINOUT_MODE_SET			//GPIO PIN Output Set
 *
 *
 *
 *				return: PinValue
 */
u8 GPIO_u8PinOutputValue		(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_BS_BR_Types 	  	  PinValue);

/*Func name: GPIO_u8TogglePinOutputMode
 * Description: Toggle outpin value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 *				return:Local_Error_state
 */
u8 GPIO_u8TogglePinOutputMode		(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum);

/*Func name: GPIO_u8DirectSetPinOutMode
 * Description:Direct atomic change of OP Mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	GPIO_u8_OP_MODE_RESET		//GPIO PIN Output Reset
 *								 	GPIO_u8_OP_MODE_SET			//GPIO PIN Output Set
 *				return:Local_Error_state
 */
u8 GPIO_u8DirectSetPinOutputMode	(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_BS_BR_Types 		  PinValue);

/*Func name: GPIO_u8SetPinConfigLock
 * Description: Lock Pin Configurations
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinLockMode:
 *								 	GPIO_PINLOCK_OFF		GPIO_PINLOCK_ON
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinConfigLock			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_LockConfig_Type   	  PinLockMode);

/*Func name: GPIO_u8SetPinAlternativeFunction
 * Description:Set Pin alternative function
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinValue: GPIO_AF0 -> GPIO_AF15
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinAlternativeFunction	(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	GPIO_AF_Values_Type 	  PinValue);

/****************************************PORT FUNCTIONS**********************************************/
/*Func name: GPIO_u8SetPortMode
 * Description: Set the specified Port mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinMode:
 *								 	GPIO_PINMODE_INPUT		GPIO_PINMODE_Alternative
 *								 	GPIO_PINMODE_OUTPUT		GPIO_PINMODE_Analog
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortMode				(PORTx_Value_Type PortNum,	PINx_Mode_Type 			  PortMode);
/*Func name: GPIO_u8SetPortOutputMode
 * Description: Set output Port mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinOutMode:
 *								 	GPIO_PINOUT_MODE_PushPull
 *								 	GPIO_PINOUT_MODE_OpenDrain
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortOutputMode			(PORTx_Value_Type PortNum,	PINx_OutputMode_Types  	  PortOutMode);
/*Func name: GPIO_u8SetPinOutputSpeed
 * Description: Set output port speed
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinOutSpeed:
 *								 	GPIO_PINOUT_SPD_LowSpeed		GPIO_PINOUT_SPD_HighSpeed
 *								 	GPIO_PINOUT_SPD_MedSpeed		GPIO_PINOUT_SPD_VeryHighSpeed
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortOutputSpeed		(PORTx_Value_Type PortNum,	PINx_OutputSpeed_Types 	  PinOutSpeed);
/*Func name: GPIO_u8SetPortPullMode
 * Description: Set input port pull mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinPullMode:
 *								 	GPIO_PININ_NoPull		GPIO_PININ_PullDown
 *								 							GPIO_PININ_PullUp
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortPullMode			(PORTx_Value_Type PortNum,	PINx_PullMode_Types 	  PortPullMode);
/*Func name: GPIO_u8ChangePortOutValue
 * Description: Set port output value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				copy_u16PortOutVal: Data to be written on port
 *				return:Local_Error_state
 */
u8 GPIO_u8PortOutputValue		(PORTx_Value_Type PortNum,u16 copy_u16PortOutVal);

/*Func name: GPIO_u8GetPortValue
 * Description: Get port Input value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 *				return: u16 Data
 */
u16 GPIO_u8GetPortValue				(u8 PortNum);

#endif /* GPIO_INTERFACE_H_ */
