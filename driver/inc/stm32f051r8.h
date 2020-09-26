/*
 * stm32f051r8.h
 *
 *  Created on: Sep 19, 2020
 *      Author: Duy My
 */


#ifndef INC_BASE_ADDR_H_
#define INC_BASE_ADDR_H_

#include "peripheral_structures.h"


/*==============================SYSTEM=========================== */
#define SRAM			0x20000000u
#define OPTION_BYTE		0x1FFFF800u
#define SYSTEM_MEMORY	0x1FFFEC00u
#define MAIN_FLASH		0x08000000u


/*==============================AHB2 BUS=========================== */

#define GPIOF			(GPIO_reg*)0x48001400u
#define GPIOE			(GPIO_reg*)0x48001000u
#define GPIOD			(GPIO_reg*)0x48000C00u
#define GPIOC			(GPIO_reg*)0x48000800u
#define GPIOB			(GPIO_reg*)0x48000400u
#define GPIOA			(GPIO_reg*)0x48000000u

/*==============================AHB1 BUS=========================== */
#define TSC				0x40024000u
#define CRC				0x40023000u
#define FLASH_INTERFACE	0x40022000u
#define RCC				(RCC_reg*)0x40021000u
#define DMA2			0x40020400u
#define DMA				0x40020000u

/*==============================APB BUS=========================== */

#define DBGMCU			0x40015800u
#define TIM17			0x40014800u
#define TIM16			0x40014400u
#define TIM15			0x40014000u
#define SPI1			0x40013000
#define USART1			(USART_reg*)0x40013800u
#define TIM1			0x40012C00u
#define ADC				0x40012400u
#define USART8			0x40011C00u
#define USART7			0x40011800u
#define USART6			0x40011400u
#define EXTI			(EXTI_reg*)0x40010400u
#define SYSCFG			(SYSCFG_reg*)0x40010000u
#define CEC				0x40007800u
#define DAC				0x40007400u
#define PWR				0x40007000u
#define CRS				0x40006C00u
#define CAN				0x40006400u
#define USB				0x40005C00u
#define I2C2			0x40005800u
#define I2C1			0x40005400u
#define USART5			0x40005000u
#define USART4			0x40004C00u
#define USART3			0x40004800u
#define USART2			0x40004400u
#define SPI2			0x40003800u
#define IWDG			0x40003000u
#define WWDG			0x40002C00u
#define RTC				0x40002800u
#define TIM14			0x40002000u
#define TIM7			0x40001400u
#define TIM6			0x40001000u
#define TIM3			0x40000400u
#define TIM2			0x40000000u




/*======================================GENERIC MACROS========================================= */

#define ENABLE 				1
#define DISABLE 			0

#define SET 				1
#define RESET				0


/*==============================GPIO MACROS====================================== */
//MODER
#define GPIO_INPUT			0
#define GPIO_OUTPUT			1
#define GPIO_ALT_FUNCTION 	2
#define GPIO_ANALOG			3
#define GPIO_EXTI			4

//ALTERNATE FUNCTION MODE

#define GPIO_AF0			0
#define GPIO_AF1			1
#define GPIO_AF2			2
#define GPIO_AF3			3
#define GPIO_AF4			4
#define GPIO_AF5			5
#define GPIO_AF6			6
#define GPIO_AF7			7




//IRQ edge
#define GPIO_IRQ_FT			0
#define GPIO_IRQ_RT			1
#define GPIO_IRQ_BT			2


//OUTPUT TYPE
#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

//GPIO speed
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

//GPIO pull up/down
#define GPIO_NO_PUPD		0
#define GPIO_PU				1
#define GPIO_PD				2



/*==================================================================================== */

/*===================================USART MACROS==================================== */

//USART mode
#define USART_TX_MODE				(1<<3)
#define USART_RX_MODE				(1<<2)
#define USART_TX_RX					(USART_TX_MODE | USART_RX_MODE)

//word length
#define USART_DATA_BIT_8			0
#define USART_DATA_BIT_9			1


//stop bit
#define USART_STOP_1				0
#define USART_STOP_0_5				1
#define USART_STOP_2				2
#define USART_STOP_1_5				3

//baudrate
#define USART_BAUD_9600				0x341

//oversampling
#define USART_OVERSAMPLING_16		0
#define USART_OVERSAMPLING_8		1



/*===================================END_USART==================================== */



/*===================================CORE MACROS==================================== */

//NVIC
#define NVIC_ISER			(uint32_t*)0xE000E100
#define NVIC_ICER			(uint32_t*)0XE000E180
#define NVIC_ISPR			(uint32_t*)0XE000E200
#define NVIC_ICPR			(uint32_t*)0XE000E280
#define NVIC_IPR			(uint32_t*)0xE000E400



#endif /* INC_BASE_ADDR_H_ */
