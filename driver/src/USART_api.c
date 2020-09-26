/*
 * USART_api.c
 *
 *  Created on: Sep 23, 2020
 *      Author: Duy My
 */

#include "USART_api.h"


void USART_init(USART_handle *pUSART)
{

	//enable clock for USART1
	RCC_reg *pRCC = RCC;
	pRCC->RCC_APB2ENR |= 1<<14;

	GPIO_handle *pGPIO_TX,*pGPIO_RX ;

	pGPIO_TX = (GPIO_handle*)(malloc(sizeof(GPIO_handle)));
	memset(pGPIO_TX,0,sizeof(GPIO_handle));
	pGPIO_TX->GPIO_addr =  GPIOA;
	pGPIO_TX->GPIO_pin_config.GPIO_pin_number = 9;
	pGPIO_TX->GPIO_pin_config.GPIO_pin_mode = GPIO_ALT_FUNCTION;
	pGPIO_TX->GPIO_pin_config.GPIO_pin_ALT_function = GPIO_AF1;
	GPIO_init(pGPIO_TX);


	pGPIO_RX = (GPIO_handle*)(malloc(sizeof(GPIO_handle)));
	memset(pGPIO_RX,0,sizeof(GPIO_handle));
	pGPIO_RX->GPIO_addr  =  GPIOA;
	pGPIO_RX->GPIO_pin_config.GPIO_pin_number = 10;
	pGPIO_RX->GPIO_pin_config.GPIO_pin_mode = GPIO_ALT_FUNCTION;
	pGPIO_RX->GPIO_pin_config.GPIO_pin_ALT_function = GPIO_AF1;

	GPIO_init(pGPIO_RX);

	//disable USART
	pUSART->base_addr->USART_CR1 &= ~(1<<0);

	//word length M[28:12]
	pUSART->base_addr->USART_CR1 &= ~(1<<12 | 1<<28);
	pUSART->base_addr->USART_CR1 |= pUSART->config.USART_word_len<<12;


	//parity bit
	pUSART->base_addr->USART_CR1 &= ~(1<<10);
	pUSART->base_addr->USART_CR1 |= pUSART->config.USART_parity<<10;


	//stop bit
	pUSART->base_addr->USART_CR2 &= ~(1<<13 | 1<<12);
	pUSART->base_addr->USART_CR2 |= pUSART->config.USART_stop<<12;

	//over sampling
	pUSART->base_addr->USART_CR1 &= ~(1<<15);
	pUSART->base_addr->USART_CR1 |= pUSART->config.USART_oversampling<<15;

	//baud rate
	pUSART->base_addr->USART_BRR = (uint16_t)pUSART->config.USART_baudrate;

	//enable USART
	pUSART->base_addr->USART_CR1 |= 1<<0;

	//USART mode
	pUSART->base_addr->USART_CR1 |= pUSART->config.USART_mode;




}

void USART_send(char *msg, USART_handle *pUSART)
{

	while(*msg)
	{
		if(pUSART->base_addr->USART_ISR & (1<<7))
		{
			pUSART->base_addr->USART_TDR = *msg;
			msg++;
		}

		while(!(pUSART->base_addr->USART_ISR & (1<<6)));
		pUSART->base_addr->USART_ICR |= 1<<6;

	}
}

void USART_IRQ_config(USART_handle *pUSART)
{
	//enable RXNEIE
	pUSART->base_addr->USART_CR1 |= 1<<5;

	//enable USART interrupt line
	*(NVIC_ISER) |= 1<<pUSART->config.USART_IRQ_number;

}
