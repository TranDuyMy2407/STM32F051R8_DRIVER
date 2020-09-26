/*
 * gpio_api.h
 *
 *  Created on: Sep 20, 2020
 *      Author: Duy My
 */

#include"peripheral_structures.h"
#include "stm32f051r8.h"
#include<stdint.h>

//clock control
void GPIO_clk_control(GPIO_handle *pGPIO, uint8_t mode);

//pin initialization
void GPIO_init(GPIO_handle *pGPIO);


//data read/write
uint8_t GPIO_read_pin(GPIO_handle *pGPIO);
void GPIO_write_pin(GPIO_handle *pGPIO , uint8_t value);
void GPIO_toggle(GPIO_handle *pGPIO);

//IRQ configuration
void GPIO_IRQ_config(GPIO_handle *pGPIO_irq);


