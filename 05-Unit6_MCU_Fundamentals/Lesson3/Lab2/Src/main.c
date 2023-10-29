/*
 * Learn in depth
 * Mohamed Ahmed Salama
 * LAB 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned int u32;

#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile u32*) (0x40010800+0x04)
#define GPIOA_ODR    *(volatile u32*) (0x40010800+0x0C)

#define RCC_BASE       0x40021000
#define RCC_CR    	   *(volatile u32*) (RCC_BASE)
#define RCC_APB2ENR    *(volatile u32*) (0x40021018)
#define RCC_APB1ENR    *(volatile u32*) (RCC_BASE+0x1C)
#define RCC_CFGR  *(volatile uint32_t *)(RCC_BASE + 0x04)

void clock_init();
int main(void)
{
	clock_init();
	while(1)
	{
	}
}
void clock_init()
{
	/*
	 * Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	 * Set and cleared by software to control the division factor of the APB low-speed clock
	   (PCLK1).
	 * Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	 * 0xx: HCLK not divided
	 * 100: HCLK divided by 2
	 * 101: HCLK divided by 4
	 * 110: HCLK divided by 8
	 * 111: HCLK divided by 16
	 */
	RCC_CFGR |= (0b100<<8);
	/*
	 * Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	 * Set and cleared by software to control the division factor of the APB high-speed clock
	   (PCLK2).
	 * 0xx: HCLK not divided
	 * 100: HCLK divided by 2
	 * 101: HCLK divided by 4
	 * 110: HCLK divided by 8
	 * 111: HCLK divided by 16
	 */
	RCC_CFGR |= (0b101<<11);
}
