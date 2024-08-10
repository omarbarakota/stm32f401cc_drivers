/*
 * GPIO_Program.c
 *	GPIO
 *  Created on: Aug 7, 2023
 *      Author: Barakat
 */

#include "Types.h"
#include "BitMath.h"

#include "GPIO_Conf.h"
#include "GPIO_Private.h"
#include "GPIO.Interface.h"







/*Func name: GPIO_u8SetPinMode
 * Description: Set the specified pin mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinMode:
 *								 	GPIO_PINMODE_INPUT		GPIO_PINMODE_Alternative
 *								 	GPIO_PINMODE_OUTPUT		GPIO_PINMODE_Analog
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinMode				(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_Mode_Type 			  PinMode)
{
	Error_Types Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15 && PinMode<=GPIO_PINMODE_Analog) {
		if ((PortNum == GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				//USE modify register to modify the value of corresponding GPIOXModer bits
				MODIFY_REG(GPIOA->MODER.REG, (PinMode << PinNum*2),(GPIOX_MODER_MODER0<<PinNum*2));
				break;
			case GPIO_PORTB:
				MODIFY_REG(GPIOB->MODER.REG, (PinMode << PinNum*2),(GPIOX_MODER_MODER0<<PinNum*2));
				break;
			case GPIO_PORTC:
				MODIFY_REG(GPIOC->MODER.REG, (PinMode << PinNum*2),(GPIOX_MODER_MODER0<<PinNum*2));
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}

/*Func name: GPIO_u8SetPinOutputMode
 * Description: Set output pin mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinOutMode:
 *								 	GPIO_PINOUT_MODE_PushPull
 *								 	GPIO_PINOUT_MODE_OpenDrain
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinOutputMode			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_OutputMode_Types  	  PinOutMode){
u8 Local_Error_state = Types_OK;
if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15 && PinOutMode<=GPIO_PINOUT_MODE_OpenDrain ) {
		if ((PortNum == GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				//USE modify register to modify the value of corresponding GPIOXModer bits
				MODIFY_REG(GPIOA->OTYPER.REG, (PinOutMode << PinNum),(GPIOX_OTYPER_OT0<<PinNum));
				break;
			case GPIO_PORTB:
				MODIFY_REG(GPIOB->OTYPER.REG, (PinOutMode << PinNum),(GPIOX_OTYPER_OT0<<PinNum));
				break;
			case GPIO_PORTC:
				MODIFY_REG(GPIOC->OTYPER.REG, (PinOutMode << PinNum),(GPIOX_OTYPER_OT0<<PinNum));
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
return Local_Error_state;
}

/*Func name: GPIO_u8SetPinOutputSpeed
 * Description: Set output pin speed
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinOutSpeed:
 *								 	GPIO_PINOUT_SPD_LowSpeed		GPIO_PINOUT_SPD_HighSpeed
 *								 	GPIO_PINOUT_SPD_MedSpeed		GPIO_PINOUT_SPD_VeryHighSpeed
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinOutputSpeed			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_OutputSpeed_Types 	  PinOutSpeed){
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15&&PinOutSpeed<=GPIO_PINOUT_SPD_VeryHighSpeed) {
		if ((PortNum == GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				//USE modify register to modify the value of corresponding GPIOXModer bits
				MODIFY_REG(GPIOA->OSPEEDR.REG, (PinOutSpeed << PinNum*2),(GPIOX_OSPEEDR_OSPEEDR0<<PinNum*2));
				break;
			case GPIO_PORTB:
				MODIFY_REG(GPIOB->OSPEEDR.REG, (PinOutSpeed << PinNum*2),(GPIOX_OSPEEDR_OSPEEDR0<<PinNum*2));
				break;
			case GPIO_PORTC:
				MODIFY_REG(GPIOC->OSPEEDR.REG, (PinOutSpeed << PinNum*2),(GPIOX_OSPEEDR_OSPEEDR0<<PinNum*2));
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}

/*Func name: GPIO_u8SetPinPullMode
 * Description: Set input pin pull mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinPullMode:
 *								 	GPIO_PININ_NoPull		GPIO_PININ_PullDown
 *								 							GPIO_PININ_PullUp
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinPullMode			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_PullMode_Types 	  PinPullMode)
{

	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15&&PinPullMode<=GPIO_PININ_PullDown) {
		if ((PortNum == GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				//USE modify register to modify the value of corresponding GPIOXModer bits
				MODIFY_REG(GPIOA->PUPDR.REG, (PinPullMode << PinNum*2),(GPIOX_PUPDR_PUPDR0<<PinNum*2));
				break;
			case GPIO_PORTB:
				MODIFY_REG(GPIOB->PUPDR.REG, (PinPullMode << PinNum*2),(GPIOX_PUPDR_PUPDR0<<PinNum*2));
				break;
			case GPIO_PORTC:
				MODIFY_REG(GPIOC->PUPDR.REG, (PinPullMode << PinNum*2),(GPIOX_PUPDR_PUPDR0<<PinNum*2));
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}
/*Func name: GPIO_u8GetPinValue
 * Description:Get the input pin value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 *				return:PinValue
 */
u8 GPIO_u8GetPinValue				(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum	){
	u8 Local_PinValue=0;
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15) {
		if ((PortNum == GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				Local_PinValue=GET_BIT(GPIOA->IDR.REG,PinNum);
				break;
			case GPIO_PORTB:
				Local_PinValue=GET_BIT(GPIOB->IDR.REG,PinNum);
				break;
			case GPIO_PORTC:
				Local_PinValue=GET_BIT(GPIOC->IDR.REG,PinNum);
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_PinValue;
}

/*Func name: GPIO_u8ChangePinOutputMode
 * Description:Direct atomic change of OP Mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	GPIP_PINOUT_MODE_RESET		//GPIO PIN Output Reset
 *								 	GPIO_PINOUT_MODE_SET			//GPIO PIN Output Set
 *
 *
 *
 *				return: PinValue
 */
u8 GPIO_u8PinOutputValue		(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_BS_BR_Types 	  	  PinValue){
u8 Local_Error_state = Types_OK;
if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15	&&		PinValue<=GPIO_PINOUT_SET) {
	if ((PortNum >= GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
		Local_Error_state = Types_NOK;
	} else {
		switch (PortNum) {
		case GPIO_PORTA:
			MODIFY_REG(GPIOA->ODR.REG, (PinValue << PinNum),(GPIOX_ODR_ODR0<<PinNum));
			break;
		case GPIO_PORTB:
			MODIFY_REG(GPIOB->ODR.REG, (PinValue << PinNum),(GPIOX_ODR_ODR0<<PinNum));
			break;
		case GPIO_PORTC:
			MODIFY_REG(GPIOC->ODR.REG, (PinValue << PinNum),(GPIOX_ODR_ODR0<<PinNum));
			break;
		default:
			Local_Error_state = Types_NOK;
			break;
		}
	}
}
else{
	Local_Error_state = Types_NOK;
}
return Local_Error_state;
}
/*Func name: GPIO_u8TogglePinOutputMode
 * Description: Toggle outpin value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 *				return:Local_Error_state
 */
u8 GPIO_u8TogglePinOutputMode		(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum){
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15) {
		if ((PortNum == GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				TOGGLE_BIT(GPIOA->ODR.REG,PinNum);
				break;
			case GPIO_PORTB:
				TOGGLE_BIT(GPIOB->ODR.REG,PinNum);
				break;
			case GPIO_PORTC:
				TOGGLE_BIT(GPIOC->ODR.REG,PinNum);
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}
/*Func name: GPIO_u8SetPinConfigLock
 * Description: Lock Pin Configurations
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinNum: specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				PinLockMode:
 *								 	GPIO_PINLOCK_OFF		GPIO_PINLOCK_ON
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinConfigLock			(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	PINx_LockConfig_Type   	  PinLockMode){
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PinNum <= GPIO_PIN15	&&		PinLockMode<=GPIO_PINLOCK_ON) {
		if ((PortNum >= GPIO_PORTC) && (PinNum < GPIO_PIN13)) {
			Local_Error_state = Types_NOK;
		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				MODIFY_REG(GPIOA->LCKR.REG, (PinLockMode << PinNum),(GPIOX_LCKR_LCK0<<PinNum));
				break;
			case GPIO_PORTB:
				MODIFY_REG(GPIOB->LCKR.REG, (PinLockMode << PinNum),(GPIOX_LCKR_LCK0<<PinNum));
				break;
			case GPIO_PORTC:
				MODIFY_REG(GPIOC->LCKR.REG, (PinLockMode << PinNum),(GPIOX_LCKR_LCK0<<PinNum));
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
	}
	return Local_Error_state;
}
u8 GPIO_u8SetPinAlternativeFunction	(PORTx_Value_Type PortNum,	PINx_Num_Type PinNum,	GPIO_AF_Values_Type 	  AFPinValue){
	Error_Types Local_Error_state = Types_OK;
	if (PortNum > GPIO_PORTC || PinNum > GPIO_PIN15|| AFPinValue > GPIO_AF15) {
		Local_Error_state = Types_NOK;
	} else {
		if (PinNum <= GPIO_PIN7) {
			switch (PortNum) {
			case GPIO_PORTA:
				switch(PinNum)
				{
				case GPIO_PIN0:
					GPIOA->AFRL.BITS.AFRL0=AFPinValue;
					break;
				case GPIO_PIN1:
					GPIOA->AFRL.BITS.AFRL1=AFPinValue;
					break;
				case GPIO_PIN2:
					GPIOA->AFRL.BITS.AFRL2=AFPinValue;
					break;
				case GPIO_PIN3:
					GPIOA->AFRL.BITS.AFRL3=AFPinValue;
					break;
				case GPIO_PIN4:
					GPIOA->AFRL.BITS.AFRL4=AFPinValue;
					break;
				case GPIO_PIN5:
					GPIOA->AFRL.BITS.AFRL5=AFPinValue;
					break;
				case GPIO_PIN6:
					GPIOA->AFRL.BITS.AFRL6=AFPinValue;
					break;
				case GPIO_PIN7:
					GPIOA->AFRL.BITS.AFRL7=AFPinValue;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
				break;
			case GPIO_PORTB:
				switch(PinNum)
				{
				case GPIO_PIN0:
					GPIOB->AFRL.BITS.AFRL0=AFPinValue;
					break;
				case GPIO_PIN1:
					GPIOB->AFRL.BITS.AFRL1=AFPinValue;
					break;
				case GPIO_PIN2:
					GPIOB->AFRL.BITS.AFRL2=AFPinValue;
					break;
				case GPIO_PIN3:
					GPIOB->AFRL.BITS.AFRL3=AFPinValue;
					break;
				case GPIO_PIN4:
					GPIOB->AFRL.BITS.AFRL4=AFPinValue;
					break;
				case GPIO_PIN5:
					GPIOB->AFRL.BITS.AFRL5=AFPinValue;
					break;
				case GPIO_PIN6:
					GPIOB->AFRL.BITS.AFRL6=AFPinValue;
					break;
				case GPIO_PIN7:
					GPIOB->AFRL.BITS.AFRL7=AFPinValue;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}

		} else {
			switch (PortNum) {
			case GPIO_PORTA:
				switch(PinNum)
				{
				case GPIO_PIN8:
					GPIOA->AFRH.BITS.AFRH8=AFPinValue;
					break;
				case GPIO_PIN9:
					GPIOA->AFRH.BITS.AFRH9=AFPinValue;
					break;
				case GPIO_PIN10:
					GPIOA->AFRH.BITS.AFRH10=AFPinValue;
					break;
				case GPIO_PIN11:
					GPIOA->AFRH.BITS.AFRH11=AFPinValue;
					break;
				case GPIO_PIN12:
					GPIOA->AFRH.BITS.AFRH12=AFPinValue;
					break;
				case GPIO_PIN13:
					GPIOA->AFRH.BITS.AFRH13=AFPinValue;
					break;
				case GPIO_PIN14:
					GPIOA->AFRH.BITS.AFRH14=AFPinValue;
					break;
				case GPIO_PIN15:
					GPIOA->AFRH.BITS.AFRH15=AFPinValue;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
				break;

			case GPIO_PORTB:
				switch(PinNum)
				{
				case GPIO_PIN8:
					GPIOB->AFRH.BITS.AFRH8=AFPinValue;
					break;
				case GPIO_PIN9:
					GPIOB->AFRH.BITS.AFRH9=AFPinValue;
					break;
				case GPIO_PIN10:
					GPIOB->AFRH.BITS.AFRH10=AFPinValue;
					break;
				case GPIO_PIN11:
					GPIOB->AFRH.BITS.AFRH11=AFPinValue;
					break;
				case GPIO_PIN12:
					GPIOB->AFRH.BITS.AFRH12=AFPinValue;
					break;
				case GPIO_PIN13:
					GPIOB->AFRH.BITS.AFRH13=AFPinValue;
					break;
				case GPIO_PIN14:
					GPIOB->AFRH.BITS.AFRH14=AFPinValue;
					break;
				case GPIO_PIN15:
					GPIOB->AFRH.BITS.AFRH15=AFPinValue;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
				break;

				case GPIO_PORTC:
				switch(PinNum)
				{
				case GPIO_PIN13:
					GPIOB->AFRH.BITS.AFRH13=AFPinValue;
					break;
				case GPIO_PIN14:
					GPIOB->AFRH.BITS.AFRH14=AFPinValue;
					break;
				case GPIO_PIN15:
					GPIOB->AFRH.BITS.AFRH15=AFPinValue;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}

	}
	return Local_Error_state;
}

/********************************** * Same Functions For ports	* **********************************/



/*Func name: GPIO_u8SetPortMode
 * Description: Set the specified Port mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinMode:
 *								 	GPIO_PINMODE_INPUT		GPIO_PINMODE_Alternative
 *								 	GPIO_PINMODE_OUTPUT		GPIO_PINMODE_Analog
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortMode				(PORTx_Value_Type PortNum,	PINx_Mode_Type 			  PortMode)
{
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PortMode<=GPIO_PINMODE_Analog )
	{
		Local_Error_state = Types_NOK;
		if(GPIO_PORTA)
		{
			switch (PortMode) {
			case GPIO_PINMODE_INPUT:
				GPIOA->MODER.REG=PORT_INPUT;
				break;
			case GPIO_PINMODE_OUTPUT:
				GPIOA->MODER.REG=PORT_OUTPUT;
				break;
			case GPIO_PINMODE_Alternative:
				GPIOA->MODER.REG=PORT_ALTERNATE;
				break;
			case GPIO_PINMODE_Analog:
				GPIOA->MODER.REG=PORT_ANALOG;
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
		else if(GPIO_PORTB)
		{
			switch (PortMode) {
			case GPIO_PINMODE_INPUT:
				GPIOB->MODER.REG=PORT_INPUT;
				break;
			case GPIO_PINMODE_OUTPUT:
				GPIOB->MODER.REG=PORT_OUTPUT;
				break;
			case GPIO_PINMODE_Alternative:
				GPIOB->MODER.REG=PORT_ALTERNATE;
				break;
			case GPIO_PINMODE_Analog:
				GPIOB->MODER.REG=PORT_ANALOG;
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
		else if(GPIO_PORTC)
		{
			switch (PortMode) {
			case GPIO_PINMODE_INPUT:
				GPIOC->MODER.REG=PORT_INPUT;
				break;
			case GPIO_PINMODE_OUTPUT:
				GPIOC->MODER.REG=PORT_OUTPUT;
				break;
			case GPIO_PINMODE_Alternative:
				GPIOC->MODER.REG=PORT_ALTERNATE;
				break;
			case GPIO_PINMODE_Analog:
				GPIOC->MODER.REG=PORT_ANALOG;
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
		else{
			Local_Error_state = Types_NOK;
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}

/*Func name: GPIO_u8SetPortOutputMode
 * Description: Set output Port mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinOutMode:
 *								 	GPIO_PINOUT_MODE_PushPull
 *								 	GPIO_PINOUT_MODE_OpenDrain
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortOutputMode			(PORTx_Value_Type PortNum,	PINx_OutputMode_Types  	  PortOutMode){
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PortOutMode<=GPIO_PINOUT_MODE_OpenDrain )
	{
		Local_Error_state = Types_NOK;
		if(GPIO_PORTA)
		{
			switch (PortOutMode) {
			case GPIO_PINOUT_MODE_PushPull:
				GPIOA->OTYPER.REG=PORT_OUT_MODE_PUSHPULL;
				break;
			case GPIO_PINOUT_MODE_OpenDrain:
				GPIOA->OTYPER.REG=PORT_OUT_MODE_OPENDRAIN;
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
		else if(GPIO_PORTB)
		{
			switch (PortOutMode) {
			case GPIO_PINOUT_MODE_PushPull:
				GPIOB->OTYPER.REG=PORT_OUT_MODE_PUSHPULL;
				break;
			case GPIO_PINOUT_MODE_OpenDrain:
				GPIOB->OTYPER.REG=PORT_OUT_MODE_OPENDRAIN;
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
		else if(GPIO_PORTC)
		{
			switch (PortOutMode) {
			case GPIO_PINOUT_MODE_PushPull:
				GPIOC->OTYPER.REG=PORT_OUT_MODE_PUSHPULL;
				break;
			case GPIO_PINOUT_MODE_OpenDrain:
				GPIOC->OTYPER.REG=PORT_OUT_MODE_OPENDRAIN;
				break;
			default:
				Local_Error_state = Types_NOK;
				break;
			}
		}
		else{
			Local_Error_state = Types_NOK;
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}
/*Func name: GPIO_u8SetPinOutputSpeed
 * Description: Set output port speed
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinOutSpeed:
 *								 	GPIO_PINOUT_SPD_LowSpeed		GPIO_PINOUT_SPD_HighSpeed
 *								 	GPIO_PINOUT_SPD_MedSpeed		GPIO_PINOUT_SPD_VeryHighSpeed
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortOutputSpeed			(PORTx_Value_Type PortNum,	PINx_OutputSpeed_Types 	  PinOutSpeed){
	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC &&	PinOutSpeed<=GPIO_PINOUT_SPD_VeryHighSpeed) {
		 {
			Local_Error_state = Types_NOK;
			if(GPIO_PORTA)
			{
				switch (PinOutSpeed) {
				case GPIO_PINOUT_SPD_LowSpeed:
					//USE modify register to modify the value of corresponding GPIOXModer bits
					GPIOA->OSPEEDR.REG=PORT_SPEED_LOW;
					break;
				case GPIO_PINOUT_SPD_MedSpeed:
					GPIOA->OSPEEDR.REG=PORT_SPEED_MED;
					break;
				case GPIO_PINOUT_SPD_HighSpeed:
					GPIOA->OSPEEDR.REG=PORT_SPEED_HIGH;
					break;
				case GPIO_PINOUT_SPD_VeryHighSpeed:
					GPIOA->OSPEEDR.REG=PORT_SPEED_VERYHIGH;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
			}
			else if(GPIO_PORTB)
			{
				switch (PinOutSpeed) {
				case GPIO_PINOUT_SPD_LowSpeed:
					//USE modify register to modify the value of corresponding GPIOXModer bits
					GPIOB->OSPEEDR.REG=PORT_SPEED_LOW;
					break;
				case GPIO_PINOUT_SPD_MedSpeed:
					GPIOB->OSPEEDR.REG=PORT_SPEED_MED;
					break;
				case GPIO_PINOUT_SPD_HighSpeed:
					GPIOB->OSPEEDR.REG=PORT_SPEED_HIGH;
					break;
				case GPIO_PINOUT_SPD_VeryHighSpeed:
					GPIOB->OSPEEDR.REG=PORT_SPEED_VERYHIGH;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
			}
			else if(GPIO_PORTC)
			{
				switch (PinOutSpeed) {
				case GPIO_PINOUT_SPD_LowSpeed:
					//USE modify register to modify the value of corresponding GPIOXModer bits
					GPIOC->OSPEEDR.REG=PORT_SPEED_LOW;
					break;
				case GPIO_PINOUT_SPD_MedSpeed:
					GPIOC->OSPEEDR.REG=PORT_SPEED_MED;
					break;
				case GPIO_PINOUT_SPD_HighSpeed:
					GPIOC->OSPEEDR.REG=PORT_SPEED_HIGH;
					break;
				case GPIO_PINOUT_SPD_VeryHighSpeed:
					GPIOC->OSPEEDR.REG=PORT_SPEED_VERYHIGH;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
			}
			else{
				Local_Error_state = Types_NOK;
			}
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}

/*Func name: GPIO_u8SetPortPullMode
 * Description: Set input port pull mode
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				PinPullMode:
 *								 	GPIO_PININ_NoPull		GPIO_PININ_PullDown
 *								 							GPIO_PININ_PullUp
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPortPullMode			(PORTx_Value_Type PortNum,	PINx_PullMode_Types 	  PortPullMode)
{

	u8 Local_Error_state = Types_OK;
	if (PortNum <= GPIO_PORTC && PortPullMode<=GPIO_PININ_PullDown) {

		switch (PortNum) {
		case GPIO_PORTA:
			if(PortPullMode==GPIO_PININ_PullUp)
			{
				GPIOA->PUPDR.REG=PORT_PULLDOWN;
			}
			else if(PortPullMode==GPIO_PININ_PullDown)
			{
				GPIOA->PUPDR.REG=PORT_PULLUP;
			}
			else{
				Local_Error_state = Types_NOK;
			}
			break;
		case GPIO_PORTB:
			if(PortPullMode==GPIO_PININ_PullUp)
			{
				GPIOB->PUPDR.REG=PORT_PULLDOWN;
			}
			else if(PortPullMode==GPIO_PININ_PullDown)
			{
				GPIOB->PUPDR.REG=PORT_PULLUP;
			}
			else{
				Local_Error_state = Types_NOK;
			}
			break;
		case GPIO_PORTC:
			if(PortPullMode==GPIO_PININ_PullUp)
			{
				GPIOC->PUPDR.REG=PORT_PULLDOWN;
			}
			else if(PortPullMode==GPIO_PININ_PullDown)
			{
				GPIOC->PUPDR.REG=PORT_PULLUP;
			}
			else{
				Local_Error_state = Types_NOK;
			}
			break;
			default:
			Local_Error_state = Types_NOK;
			break;
		}
	}
	else{
		Local_Error_state = Types_NOK;
	}
	return Local_Error_state;
}
/*Func name: GPIO_u8ChangePortOutValue
 * Description: Set port output value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 * 				copy_u16PortOutVal: Data to be written on port
 *				return:Local_Error_state
 */
u8 GPIO_u8PortOutputValue(PORTx_Value_Type PortNum,u16 copy_u16PortOutVal){
	u8 Local_Error_state = Types_OK;
		if (PortNum <= GPIO_PORTC ) {
			 {
				switch (PortNum) {
				case GPIO_PORTA:
					GPIOA->ODR.REG=copy_u16PortOutVal;
					break;
				case GPIO_PORTB:
					GPIOB->ODR.REG=copy_u16PortOutVal;
					break;
				case GPIO_PORTC:
					GPIOC->ODR.REG=copy_u16PortOutVal;
					break;
				default:
					Local_Error_state = Types_NOK;
					break;
				}
			}
		}
		else{
			Local_Error_state = Types_NOK;
		}
		return Local_Error_state;
}

/*Func name: GPIO_u8GetPortValue
 * Description: Get port Input value
 * I/P arguments:
 * 				PortNum: specifies the required port:  GPIO_PORTA			GPIO_PORTB				GPIO_PORTC
 *				return: u16 Data
 */
u16 GPIO_u8GetPortValue(u8 PortNum)
{
	u32 Data=0;
	if (PortNum <= GPIO_PORTC )
	{
			switch (PortNum) {
			case GPIO_PORTA:
				Data=GPIOA->IDR.REG;
				break;
			case GPIO_PORTB:
				Data=GPIOB->IDR.REG;
				break;
			case GPIO_PORTC:
				Data=GPIOC->IDR.REG;
				break;
			}
	}
	return (u16)Data;
}

