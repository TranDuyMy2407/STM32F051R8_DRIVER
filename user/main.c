#include "gpio_api.h"
#include "USART_api.h"
#include <string.h>
#include "clock_api.h"
#include<stdlib.h>

char tx_buffer[] = "hello world";
char rx_buffer[100];

GPIO_handle *LED, *LED_2, *BTN  ;
USART_handle *pUSART;





int main(void) {

	PLL_clk(PLLMUL_4);
	memset(rx_buffer,0,sizeof(rx_buffer));

	LED = (GPIO_handle*)(malloc(sizeof(GPIO_handle)));
	memset(LED,0,sizeof(GPIO_handle));
	LED->GPIO_addr = GPIOC;
	LED->GPIO_pin_config.GPIO_pin_number = 9;
	LED->GPIO_pin_config.GPIO_pin_mode = GPIO_OUTPUT;
	LED->GPIO_pin_config.GPIO_pin_speed =  GPIO_SPEED_HIGH;
	LED->GPIO_pin_config.GPIO_pin_OP_type = GPIO_OP_TYPE_PP;
	GPIO_init(LED);


	LED_2 = (GPIO_handle*) (malloc(sizeof(GPIO_handle)));
	memset(LED_2, 0, sizeof(GPIO_handle));
	LED_2->GPIO_addr = GPIOC;
	LED_2->GPIO_pin_config.GPIO_pin_number = 8;
	LED_2->GPIO_pin_config.GPIO_pin_mode = GPIO_OUTPUT;
	LED_2->GPIO_pin_config.GPIO_pin_speed = GPIO_SPEED_HIGH;
	LED_2->GPIO_pin_config.GPIO_pin_OP_type = GPIO_OP_TYPE_PP;
	GPIO_init(LED_2);


	BTN  = (GPIO_handle*)(malloc(sizeof(GPIO_handle)));
	memset(BTN,0,sizeof(GPIO_handle));
	BTN->GPIO_addr = GPIOA;
	BTN->GPIO_pin_config.GPIO_pin_number = 0;
	BTN->GPIO_pin_config.GPIO_pin_mode = GPIO_EXTI;
	BTN->GPIO_pin_config.GPIO_IRQ_edge = GPIO_IRQ_FT;
	BTN->GPIO_pin_config.GPIO_IRQ_mode = ENABLE;
	BTN->GPIO_pin_config.GPIO_IRQ_number = 5;
	BTN->GPIO_pin_config.GPIO_IRQ_priority = 10;
	GPIO_init(BTN);


	GPIO_IRQ_config(BTN);


	pUSART = (USART_handle*)(malloc(sizeof(USART_handle)));
	memset(pUSART,0,sizeof(USART_handle));
	pUSART->base_addr = USART1;
	pUSART->config.USART_mode = USART_TX_RX;
	pUSART->config.USART_oversampling= USART_OVERSAMPLING_16;
	pUSART->config.USART_baudrate = 0x682;
	pUSART->config.USART_parity = DISABLE;
	pUSART->config.USART_word_len = USART_DATA_BIT_8;
	pUSART->config.USART_stop = USART_STOP_1;
	pUSART->config.USART_IRQ_number = 27;
	USART_init(pUSART);
	USART_IRQ_config(pUSART);



	while (1);
}


void USART1_IRQHandler()
{
	rx_buffer[strlen(rx_buffer)] = (char) pUSART->base_addr->USART_RDR;
	pUSART->base_addr->USART_RQR |= 1 << 3;
}

void EXTI0_1_IRQHandler()
{

	for(int i = 0;i<100000;i++);
	EXTI_reg *pREG = EXTI;
	pREG->EXTI_PR |= 1<<0;
	USART_send(rx_buffer, pUSART);
	GPIO_toggle(LED_2);
}



