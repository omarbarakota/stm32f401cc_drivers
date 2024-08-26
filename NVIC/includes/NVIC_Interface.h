/*
 * NVIC_Interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Barakat
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_




typedef enum{

	/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
	NVIC_IRQ_NMI				=-14,	/*!< 2 Non Maskable Interrupt                                          */
	NVIC_IRQ_HardFault			=-13,	/*!< 3 Cortex-M4 Hard Fault Interrupt		                           */
	NVIC_IRQ_MemManage			=-12,   /*!< 4 Cortex-M4 Memory Management Interrupt                           */
	NVIC_IRQ_BusFault			=-11,   /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
	NVIC_IRQ_UsageFault			=-10,   /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
	NVIC_IRQ_SVCall				=-5,    /*!< 11 Cortex-M4 SV Call Interrupt                                    */
	NVIC_IRQ_Debug_Monitor		=-4,    /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
	NVIC_IRQ_PendSV				=-2,    /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
	NVIC_IRQ_Systick			=-1,    /*!< 15 Cortex-M4 System Tick Interrupt                                */
	/******  STM32 specific Interrupt Numbers **********************************************************************/
	NVIC_IRQ_WWDG				=0,        /*!< Window WatchDog Interrupt                                         */
	NVIC_IRQ_EXTI16=1,NVIC_IRQ_PVD=1,      /*!< PVD through EXTI Line detection Interrupt                         */
	NVIC_IRQ_EXTI21=2,NVIC_IRQ_TAMP_STAMP=2,		/*!< Tamper and TimeStamp interrupts through the EXTI line    */
	NVIC_IRQ_EXTI22=3,NVIC_IRQ_RTC_WKUP=3,        	/*!< RTC Wakeup interrupt through the EXTI line               */
	NVIC_IRQ_FLASH				=4,        /*!< FLASH global Interrupt                                            */
	NVIC_IRQ_RCC				=5,        /*!< RCC global Interrupt                                              */
	NVIC_IRQ_EXTI0				=6,        /*!< EXTI Line0 Interrupt                                              */
	NVIC_IRQ_EXTI1				=7,        /*!< EXTI Line1 Interrupt                                              */
	NVIC_IRQ_EXTI2				=8,        /*!< EXTI Line2 Interrupt                                              */
	NVIC_IRQ_EXTI3				=9,        /*!< EXTI Line3 Interrupt                                              */
	NVIC_IRQ_EXTI4				=10,       /*!< EXTI Line4 Interrupt                                              */
	NVIC_IRQ_DMA1_Stream0		=11,       /*!< DMA1 Stream0 Interrupt                                            */
	NVIC_IRQ_DMA1_Stream1		=12,       /*!< DMA1 Stream1 Interrupt                                            */
	NVIC_IRQ_DMA1_Stream2		=13,       /*!< DMA1 Stream2 Interrupt                                            */
	NVIC_IRQ_DMA1_Stream3		=14,       /*!< DMA1 Stream3 Interrupt                                            */
	NVIC_IRQ_DMA1_Stream4		=15,       /*!< DMA1 Stream4 Interrupt                                            */
	NVIC_IRQ_DMA1_Stream5		=16,       /*!< DMA1 Stream5 Interrupt                                            */
	NVIC_IRQ_DMA1_Stream6		=17,       /*!< DMA1 Stream6 Interrupt                                            */
	NVIC_IRQ_ADC				=18,       /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
	NVIC_IRQ_EXTI9_5			=23,       /*!< External Line[9:5] Interrupts                                     */
	NVIC_IRQ_TIM1_BRK_TIM9		=24,       /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
	NVIC_IRQ_TIM1_UP_TIM10		=25,       /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
	NVIC_IRQ_TIM1_TRG_COM_TIM11	=26,       /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
	NVIC_IRQ_TIM1_CC			=27,       /*!< TIM1 Capture Compare Interrupt                                    */
	NVIC_IRQ_TIM2				=28,       /*!< TIM2 global Interrupt                                             */
	NVIC_IRQ_TIM3				=29,       /*!< TIM3 global Interrupt                                             */
	NVIC_IRQ_TIM4				=30,       /*!< TIM4 global Interrupt                                             */
	NVIC_IRQ_I2C1_EV			=31,       /*!< I2C1 Event Interrupt                                              */
	NVIC_IRQ_I2C1_ER			=32,       /*!< I2C1 Error Interrupt                                              */
	NVIC_IRQ_I2C2_EV			=33,       /*!< I2C2 Event Interrupt                                              */
	NVIC_IRQ_I2C2_ER			=34,       /*!< I2C2 Error Interrupt                                              */
	NVIC_IRQ_SPI1				=35,       /*!< SPI1 global Interrupt                                             */
	NVIC_IRQ_SPI2				=36,       /*!< SPI2 global Interrupt                                             */
	NVIC_IRQ_USART1				=37,       /*!< USART1 global Interrupt                                           */
	NVIC_IRQ_USART2				=38,       /*!< USART2 global Interrupt                                           */
	NVIC_IRQ_EXTI15_10			=40,       /*!< External Line[15:10] Interrupts                                   */
	NVIC_IRQ_EXTI17=41, NVIC_IRQ_RTC_Alarm=41,       /*!< RTC Alarm (A and B) through EXTI Line Interrupt         */
	NVIC_IRQ_EXTI18=42,NVIC_IRQ_OTG_FS_WKUP=42,       /*!< USB OTG FS Wakeup through EXTI line interrupt          */
	NVIC_IRQ_DMA1_Stream7		=47,       /*!< DMA1 Stream7 Interrupt                                            */
	NVIC_IRQ_SDIO				=49,       /*!< SDIO global Interrupt                                             */
	NVIC_IRQ_TIM5				=50,       /*!< TIM5 global Interrupt                                             */
	NVIC_IRQ_SPI3				=51,       /*!< SPI3 global Interrupt                                             */
	NVIC_IRQ_DMA2_Stream0		=56,       /*!< DMA2 Stream 0 global interrupt                                    */
	NVIC_IRQ_DMA2_Stream1		=57,       /*!< DMA2 Stream 1 global interrupt                                    */
	NVIC_IRQ_DMA2_Stream2		=58,       /*!< DMA2 Stream 2 global interrupt                                    */
	NVIC_IRQ_DMA2_Stream3		=59,       /*!< DMA2 Stream 3 global interrupt                                    */
	NVIC_IRQ_DMA2_Stream4		=60,       /*!< DMA2 Stream 4 global interrupt                                    */
	NVIC_IRQ_OTG_FS				=67,       /*!< USB OTG FS global Interrupt                                       */
	NVIC_IRQ_DMA2_Stream5		=68,       /*!< DMA2 Stream 5 global interrupt                                    */
	NVIC_IRQ_DMA2_Stream6		=69,       /*!< DMA2 Stream 6 global interrupt                                    */
	NVIC_IRQ_DMA2_Stream7		=70,       /*!< DMA2 Stream 7 global interrupt                                    */
	NVIC_IRQ_USART6				=71,       /*!< USART6 global interrupt                                           */
	NVIC_IRQ_I2C3_EV			=72,       /*!< I2C3 event interrupt                                              */
	NVIC_IRQ_I2C3_ER			=73,       /*!< I2C3 error interrupt                                              */
	NVIC_IRQ_FPU				=81,       /*Priority_Group_Config_t!< FPU global interrupt                                              */
	NVIC_IRQ_SPI4				=84        /*!< SPI4 global Interrupt                                             */
}IRQn_t;

typedef enum{
	NVIC_Group16_0Sub	=0b000,
	NVIC_Group8_2Sub	=0b100,
	NVIC_Group4_4Sub	=0b101,
	NVIC_Group2_8Sub	=0b110,
	NVIC_Group0_16Sub	=0b111,
}Priority_Group_Config_t;

typedef enum{
	NVIC_GroupNoGroup=0,
	NVIC_Group0=0,
	NVIC_Group1,
	NVIC_Group2,
	NVIC_Group3,
	NVIC_Group4,
	NVIC_Group5,
	NVIC_Group6,
	NVIC_Group7,
	NVIC_Group8,
	NVIC_Group9,
	NVIC_Group10,
	NVIC_Group11,
	NVIC_Group12,
	NVIC_Group13,
	NVIC_Group14,
	NVIC_Group15,
}Priority_Group_t;

typedef enum{
	NVIC_SubGroupNoSub=0,
	NVIC_SubGroup0=0,
	NVIC_SubGroup1,
	NVIC_SubGroup2,
	NVIC_SubGroup3,
	NVIC_SubGroup4,
	NVIC_SubGroup5,
	NVIC_SubGroup6,
	NVIC_SubGroup7,
	NVIC_SubGroup8,
	NVIC_SubGroup9,
	NVIC_SubGroup10,
	NVIC_SubGroup11,
	NVIC_SubGroup12,
	NVIC_SubGroup13,
	NVIC_SubGroup14,
	NVIC_SubGroup15,
}Priority_SubGroup_t;


Error_Types NVIC_eEnableIRQ				(IRQn_t IRQn);
Error_Types NVIC_eDisableIRQ			(IRQn_t IRQn);
u8 			NVIC_u8GetStateIRQ			(IRQn_t IRQn);

Error_Types NVIC_eSetPendingIRQ			(IRQn_t IRQn);
Error_Types NVIC_eClearPendingIRQ		(IRQn_t IRQn);
u8 			NVIC_u8GetPendingIRQ		(IRQn_t IRQn);


Error_Types NVIC_eSetPriorityConfig		(Priority_Group_Config_t Priority_Config);
Error_Types NVIC_eSetPriority			(IRQn_t IRQn, Priority_Group_t GroupNum,Priority_SubGroup_t SubGroupNum);
Error_Types NVIC_eGetPriority			(IRQn_t IRQn, Priority_Group_t *GroupNum,Priority_SubGroup_t *SubGroupNum);



#endif /* NVIC_INTERFACE_H_ */
