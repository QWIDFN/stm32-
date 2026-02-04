#include "stm32f10x.h"                  // Device header

void led_init(void)
{
	//PA9的led亮
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStuuct;
	GPIO_InitStuuct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStuuct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStuuct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStuuct);
}

void led_on(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_9);
}

void led_off(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_9);
}

