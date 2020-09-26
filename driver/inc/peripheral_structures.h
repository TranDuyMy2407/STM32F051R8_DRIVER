/*
 * peripheral_struct.h
 *
 *  Created on: Sep 19, 2020
 *      Author: Duy My
 */

#ifndef INC_PERIPHERAL_STRUCTURES_H_
#define INC_PERIPHERAL_STRUCTURES_H_

#include<stdint.h>





/*=====================================GPIO=======================================*/

//GPIO register
typedef struct
{
	volatile uint32_t MODER;    	//0x00
	volatile uint32_t OTYPE;	   	//0x04
	volatile uint32_t OSPEEDR;  	//0x08
	volatile uint32_t PUPDR;    	//0x0C
	volatile uint32_t IDR;			//0x10
	volatile uint32_t ODR;			//0x14
	volatile uint32_t BSRR;			//0x18
	volatile uint32_t LCKR;			//0x1C
	volatile uint32_t AFR[2];		//0x20-0x24
	volatile uint32_t BRR;			//0x28

}GPIO_reg;


//GPIO pin configuration
typedef struct
{
	uint8_t GPIO_pin_number;
	uint8_t GPIO_pin_mode;
	uint8_t GPIO_pin_speed;
	uint8_t GPIO_pin_PU_PD;
	uint8_t GPIO_pin_OP_type;
	uint8_t GPIO_pin_ALT_function;

	//IRQ mode
	uint8_t GPIO_IRQ_number;
	uint8_t GPIO_IRQ_priority;
	uint8_t GPIO_IRQ_mode;
	uint8_t GPIO_IRQ_edge;
}GPIO_pin_config;

//GPIO handle
typedef struct
{
	GPIO_reg *GPIO_addr;
	GPIO_pin_config GPIO_pin_config;

}GPIO_handle;

/*========================================END_GPIO=================================================*/



/*=====================================RCC==================================================*/

//RCC register structure
typedef struct
{
	volatile uint32_t RCC_CR;			//0x00
	volatile uint32_t RCC_CFGR;			//0x04
	volatile uint32_t RCC_CIR;			//0x08
	volatile uint32_t RCC_APB2RSTR;		//0x0C
	volatile uint32_t RCC_APB1RSTR;		//0x10
	volatile uint32_t RCC_AHBENR;		//0x14
	volatile uint32_t RCC_APB2ENR;		//0x18
	volatile uint32_t RCC_APB1ENR;		//0x1C
	volatile uint32_t RCC_BDCR;			//0x20
	volatile uint32_t RCC_CSR;			//0x24
	volatile uint32_t RCC_AHBRSTR;		//0x28
	volatile uint32_t RCC_CFGR2;		//0x2C
	volatile uint32_t RCC_CFGR3;		//0x30
	volatile uint32_t RCC_CR2;			//0x34

}RCC_reg;

/*=====================================END_RCC==================================================*/



/*=====================================EXTI==================================================*/

//external interrupt register structure
typedef struct
{
	volatile uint32_t EXTI_IMR;		//0x00
	volatile uint32_t EXTI_EMR;		//0x04
	volatile uint32_t EXTI_RTSR;	//0x08
	volatile uint32_t EXTI_FTSR;	//0x0C
	volatile uint32_t EXTI_SWIER;	//0x10
	volatile uint32_t EXTI_PR;		//0x14


}EXTI_reg;

/*=====================================END EXTI==================================================*/


/*=====================================SYSCFG==================================================*/

//system configuration register structure
typedef struct
{
	volatile uint32_t SYSCFG_CFGR1;			//0x00
	volatile uint32_t RESERVE0;				//0x04
	volatile uint32_t SYSCFG_EXTICR[4];		//0x08 - 0x14
	volatile uint32_t SYSCFG_CFGR2;			//0x18;
	volatile uint32_t RESERVE1[24];			//0x1D-0x7F
	volatile uint32_t SYSCFG_ITLINE[31];	//SYSCFG_ITLINE0 - SYSCFG_ITLINE30
}SYSCFG_reg;



/*========================================END_SYSCFG===============================================*/


/*=====================================SPI==================================================*/

//SPI register structure
typedef struct
{
	volatile uint32_t SPI_CR1;			//0x00
	volatile uint32_t SPI_CR2;			//0x04
	volatile uint32_t SPI_SR;			//0x08
	volatile uint32_t SPI_DR;			//0x0C
	volatile uint32_t SPI_CRCPR;		//0x10
	volatile uint32_t SPI_RXCRCR;		//0x14
	volatile uint32_t SPI_TXCRCR;		//0x018
	volatile uint32_t SPI_I2SCFGR;		//0x1C
	volatile uint32_t SPI_I2SPR;		//0x20

}SPI_reg;


//SPI configuration
typedef struct
{
	uint8_t SPI_device_mode;
	uint8_t SPI_bus_config;
	uint8_t SPI_sclk_speed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_config;


//SPI handle structure
typedef struct
{
	SPI_reg *base_addr;
	SPI_config SPI_config;
}SPI_handle;


/*========================================END_SPI===============================================*/


/*========================================USART===============================================*/

typedef struct
{
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_BRR;
	uint32_t USART_GTPR;
	uint32_t USART_RTOR;
	uint32_t USART_RQR;
	uint32_t USART_ISR;
	uint32_t USART_ICR;
	uint32_t USART_RDR;
	uint32_t USART_TDR;


}USART_reg;

typedef struct
{
	uint8_t		USART_mode;
	uint32_t	USART_baudrate;
	uint8_t		USART_stop;
	uint8_t		USART_parity;
	uint8_t		USART_word_len;
	uint8_t		USART_oversampling;
	uint8_t		USART_HWFlowcontrol;
	uint8_t 	USART_IRQ_number;
}USART_config;

typedef struct
{
	USART_reg *base_addr;
	USART_config config;

}USART_handle;


/*========================================END_USART===============================================*/


#endif /* INC_PERIPHERAL_STRUCTURES_H_ */
