#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void key_init(void)
{
	//PB15的按钮
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStuuct;
	GPIO_InitStuuct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStuuct.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitStuuct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStuuct);
}

//读取按键对应引脚的电平
uint32_t key_getnum(void)
{
	uint32_t key_num=0;
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)   //按钮按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0);
		Delay_ms(20);
		key_num=1;
	}
	return key_num;
}


