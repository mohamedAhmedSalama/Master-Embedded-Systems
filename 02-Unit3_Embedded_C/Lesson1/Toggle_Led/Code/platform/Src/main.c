/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Ahmed Salama
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Platform_Types.h"

#define RCC_BASE  	0x40021000
#define GPIO_BASE 	0x40010800

#define RCC_APB2ENR *(vuint32*)(RCC_BASE  + 0x18)
#define GPIOA_CRH   *(vuint32*)(GPIO_BASE + 0x04)
#define GPIOA_ODR   *(vuint32*)(GPIO_BASE + 0x0C)

#define RCC_IOPAEN (1<<2)

typedef union
{
	vuint32 allfields;
	struct
	{
		vuint32 reserved :13;
		vuint32 pin_13 :1;
	}pin;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_BASE + 0x0C);

int main(void)
{
	int i;
		RCC_APB2ENR |= RCC_IOPAEN;
		GPIOA_CRH   &= 0xFF0FFFFF;
		GPIOA_CRH   |= 0X00200000;

		while(1)
		{

			for(i=0;i<5000;i++)
			R_ODR ->pin.pin_13 = 0;
			for(i=0;i<5000;i++)
			{
			   R_ODR ->pin.pin_13=1;
			}
		}
}
