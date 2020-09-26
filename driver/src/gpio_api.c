/*
 * gpio_api.c
 *
 *  Created on: Sep 20, 2020
 *      Author: Duy My
 */

#include"gpio_api.h"


//enable or disable clock
void GPIO_clk_control(GPIO_handle *pGPIO, uint8_t mode)
{
	RCC_reg *pRCC = RCC;

	if(mode > 0)
	{
		if(pGPIO->GPIO_addr == GPIOA)
			pRCC->RCC_AHBENR |= 1<<17;

		if(pGPIO->GPIO_addr  == GPIOB)
					pRCC->RCC_AHBENR |= 1<<18;

		if(pGPIO->GPIO_addr  == GPIOC)
					pRCC->RCC_AHBENR |= 1<<19;

		if(pGPIO->GPIO_addr  == GPIOD)
					pRCC->RCC_AHBENR |= 1<<20;

		if(pGPIO->GPIO_addr  == GPIOE)
					pRCC->RCC_AHBENR |= 1<<21;

		if(pGPIO->GPIO_addr  == GPIOF)
					pRCC->RCC_AHBENR |= 1<<22;

	}

	else
	{
		if(pGPIO->GPIO_addr  == GPIOA)
					pRCC->RCC_AHBRSTR |= 1<<17;

		if(pGPIO->GPIO_addr  == GPIOB)
					pRCC->RCC_AHBRSTR |= 1<<18;

		if(pGPIO->GPIO_addr  == GPIOC)
					pRCC->RCC_AHBRSTR |= 1<<19;

		if(pGPIO->GPIO_addr  == GPIOD)
					pRCC->RCC_AHBRSTR |= 1<<20;

		if(pGPIO->GPIO_addr  == GPIOE)
					pRCC->RCC_AHBRSTR |= 1<<21;

		if(pGPIO->GPIO_addr  == GPIOF)
					pRCC->RCC_AHBRSTR |= 1<<22;
	}
}

//pin init
void GPIO_init(GPIO_handle *pGPIO)
{
	GPIO_clk_control(pGPIO, ENABLE);

	if(pGPIO->GPIO_pin_config.GPIO_pin_mode != GPIO_EXTI)
	{
		pGPIO->GPIO_addr->MODER &= ~(0x3<<(pGPIO->GPIO_pin_config.GPIO_pin_number*2));
		pGPIO->GPIO_addr->MODER |= (pGPIO->GPIO_pin_config.GPIO_pin_mode)<<(pGPIO->GPIO_pin_config.GPIO_pin_number * 2 );

		if(pGPIO->GPIO_pin_config.GPIO_pin_mode == GPIO_OUTPUT)
		{
			pGPIO->GPIO_addr->OSPEEDR &= ~(GPIO_SPEED_HIGH<<(pGPIO->GPIO_pin_config.GPIO_pin_number*2));
			pGPIO->GPIO_addr->OSPEEDR |= GPIO_SPEED_HIGH<<(pGPIO->GPIO_pin_config.GPIO_pin_number*2);

			pGPIO->GPIO_addr->OTYPE &= ~(GPIO_OP_TYPE_PP<<(pGPIO->GPIO_pin_config.GPIO_pin_number));
			pGPIO->GPIO_addr->OTYPE |= GPIO_OP_TYPE_PP<<(pGPIO->GPIO_pin_config.GPIO_pin_number*2);

			pGPIO->GPIO_addr->PUPDR &= ~(GPIO_NO_PUPD<<(pGPIO->GPIO_pin_config.GPIO_pin_number));
			pGPIO->GPIO_addr->PUPDR |= GPIO_NO_PUPD<<(pGPIO->GPIO_pin_config.GPIO_pin_number*2);

		}

		else if(pGPIO->GPIO_pin_config.GPIO_pin_mode == GPIO_ALT_FUNCTION)
		{

			(pGPIO->GPIO_addr->AFR[pGPIO->GPIO_pin_config.GPIO_pin_number/8]) &= ~(0xF<<(pGPIO->GPIO_pin_config.GPIO_pin_number%8*4));
			(pGPIO->GPIO_addr->AFR[pGPIO->GPIO_pin_config.GPIO_pin_number/8]) |= (pGPIO->GPIO_pin_config.GPIO_pin_ALT_function)<<(pGPIO->GPIO_pin_config.GPIO_pin_number%8*4);


		}

	}

	else
	{
		EXTI_reg *pEXTI = EXTI;
		SYSCFG_reg *pSYSCFG = SYSCFG;

		//enable interrupt mask bit
		pEXTI->EXTI_IMR |= 1<<(pGPIO->GPIO_pin_config.GPIO_pin_number);

		/*==========SYSCFG======================*/

		//configuration port in SYSCFG (clear section)
		pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] &= ~(0xF<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4));

		//configuration port in SYSCFG (write data section)
		if(pGPIO->GPIO_addr == GPIOA)
			pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] |= 0x0<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4);

		else if(pGPIO->GPIO_addr == GPIOB)
			pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] |= 0x1<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4);


		else if(pGPIO->GPIO_addr == GPIOC)
			pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] |= 0x2<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4);

		else if(pGPIO->GPIO_addr == GPIOD)
			pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] |= 0x3<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4);

		else if(pGPIO->GPIO_addr == GPIOE)
			pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] |= 0x4<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4);

		else if(pGPIO->GPIO_addr == GPIOF)
			pSYSCFG->SYSCFG_EXTICR[pGPIO->GPIO_pin_config.GPIO_pin_number/4] |= 0x5<<(pGPIO->GPIO_pin_config.GPIO_pin_number%4*4);



		/*==========EDGE TRIGGER SELETION======================*/

		//falling edge trigger
		if(pGPIO->GPIO_pin_config.GPIO_IRQ_edge == GPIO_IRQ_FT)
		{
			pEXTI->EXTI_FTSR |= 1<<(pGPIO->GPIO_pin_config.GPIO_pin_number);
			pEXTI->EXTI_RTSR &= ~(1<<(pGPIO->GPIO_pin_config.GPIO_pin_number));
		}


		//rising edge trigger
		else if( pGPIO->GPIO_pin_config.GPIO_IRQ_edge == GPIO_IRQ_RT)
		{
			pEXTI->EXTI_RTSR |= 1<<(pGPIO->GPIO_pin_config.GPIO_pin_number);
			pEXTI->EXTI_FTSR &= ~(1<<(pGPIO->GPIO_pin_config.GPIO_pin_mode));
		}


		//rising and falling trigger
		else if(pGPIO->GPIO_pin_config.GPIO_IRQ_edge == GPIO_IRQ_BT)
		{
			pEXTI->EXTI_FTSR |= 1<<(pGPIO->GPIO_pin_config.GPIO_pin_number);
			pEXTI->EXTI_RTSR |= 1<<(pGPIO->GPIO_pin_config.GPIO_pin_number);
		}

	}


}




//data read/write
uint8_t GPIO_read_pin(GPIO_handle *pGPIO)
{
	return (pGPIO->GPIO_addr->ODR>>pGPIO->GPIO_pin_config.GPIO_IRQ_number & 0x1); //shift pin to 0 position
}


void GPIO_write_pin(GPIO_handle *pGPIO ,  uint8_t value)
{
	if(value>0)
	{
		pGPIO->GPIO_addr->ODR |= 1<<pGPIO->GPIO_pin_config.GPIO_pin_number;
	}

	else if(value == 0)
	{
		pGPIO->GPIO_addr->ODR &= ~(1<<pGPIO->GPIO_pin_config.GPIO_pin_number);
	}
}

void GPIO_toggle(GPIO_handle *pGPIO)
{
	pGPIO->GPIO_addr->ODR ^= 1<<pGPIO->GPIO_pin_config.GPIO_pin_number;
}

//IRQ configuration
void GPIO_IRQ_config(GPIO_handle *pGPIO_irq)
{

	if (pGPIO_irq->GPIO_pin_config.GPIO_IRQ_mode > 0)
	{
		//set priority
		*(NVIC_IPR + (pGPIO_irq->GPIO_pin_config.GPIO_IRQ_number / 4)) &= ~(0xFF << (pGPIO_irq->GPIO_pin_config.GPIO_IRQ_number % 4 * 8 + 4));
		*(NVIC_IPR + (pGPIO_irq->GPIO_pin_config.GPIO_IRQ_number / 4)) |=  pGPIO_irq->GPIO_pin_config.GPIO_IRQ_priority << (pGPIO_irq->GPIO_pin_config.GPIO_IRQ_number % 4 * 8 + 4);

		//enable global interrupt
		*(NVIC_ISER) |= 1<<pGPIO_irq->GPIO_pin_config.GPIO_IRQ_number;
	}
}

