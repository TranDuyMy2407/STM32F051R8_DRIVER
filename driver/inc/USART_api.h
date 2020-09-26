/*
 * USART_api.h
 *
 *  Created on: Sep 23, 2020
 *      Author: Duy My
 */

#ifndef INC_USART_API_H_
#define INC_USART_API_H_

#include "peripheral_structures.h"
#include "USART_api.h"
#include "stm32f051r8.h"
#include "gpio_api.h"
#include <string.h>
#include <stdlib.h>

void USART_init(USART_handle *pUSART);
void USART_send(char *msg, USART_handle *pUSART);
void USART_IRQ_config(USART_handle *pUSART);



#endif /* INC_USART_API_H_ */
