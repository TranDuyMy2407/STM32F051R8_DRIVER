/*
 * SPI_api.h
 *
 *  Created on: Sep 22, 2020
 *      Author: Duy My
 */

#ifndef INC_SPI_API_H_
#define INC_SPI_API_H_

//clock control
void SPI_clk_control(SPI_reg *pSPI, uint8_t mode);

//pin initialization
void SPI_init(SPI_reg *pGPIO, uint8_t pin_number );

//SPI send data
void SPI_send_data(SPI_reg *pSPI, uint8_t *TX_buffer, uint32_t len );

//SPI receive data
void SPI_receive_data(SPI_reg *pSPI, uint8_t *RX_buffer, uint32_t len);

//SPI interrupt configuration
void SPI_IRQ_config(uint8_t IRQ_number, uint8_t IRQ_priority, uint8_t IRQ_mode);



#endif /* INC_SPI_API_H_ */
