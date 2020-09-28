/*
 * clock_api.c
 *
 *  Created on: Sep 27, 2020
 *      Author: Duy My
 */

#include "clock_api.h"


void PLL_clk(uint8_t multiplier_value)
{
	RCC_reg *pRCC = RCC;

	 /*use HSI */
	pRCC->RCC_CR |= 1<<0;


	  /*wait for HSI switched  */
	  while( !(pRCC->RCC_CR & 1<<1) ) ;


	  /*disable PLL*/
	  pRCC->RCC_CR &= ~(1<<24);


	  /*set PLL muiltiplier  */
	  pRCC->RCC_CFGR &= ~(0xF<<18);
	  pRCC->RCC_CFGR |= multiplier_value<<18;

	  /*enable PLL*/
	  pRCC->RCC_CR |= 1<<24;

	  /*wait PLL flag set*/
	  while(!(pRCC->RCC_CR & 1<<25));

	  /*use PLL as system clock*/
	  pRCC->RCC_CFGR &= ~(3<<0);
	  pRCC->RCC_CFGR |= 1<<1;

	  /*wait*/
	  while((pRCC->RCC_CFGR & 3<<2) != (2<<2));


}



