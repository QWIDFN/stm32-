#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "Ecode.h"

uint8_t encoder_enabled = 0;  // 0=旋转编码器关闭，1=旋转编码器开启
int16_t num = 0;              // 旋转编码器的计数值

int main(void)
{
	OLED_Init();
	//OLED_ShowString(1, 1, "PB11:");
	
	//初始化led
	led_init();
	led_off();
   
	//初始化按钮
	key_init();
	
	Encoder_Init();
	OLED_ShowString(1, 1, "Num:");
    OLED_ShowString(2, 1, "State: OFF");
	
      while(1)
	{
		 // 4. 检测按键
		if(key_getnum()==1)         
		{
		   //初始化旋转编码器，让其使能
		  
		   encoder_enabled =!encoder_enabled;           // 切换编码器状态
		   if(encoder_enabled)                          // 开启编码器
		   {
			   led_on();
			   OLED_ShowString(2, 8, "ON ");
			   // 关键：清零计数器
               num = 0;                                // 清零显示值
               Encoder_Get();                          // 清零编码器内部计数器
               OLED_ShowSignedNum(1, 5, num, 5);       // 显示0
		   }
		   else                                        // 关闭编码器
		   {
			   led_off();
			   OLED_ShowString(2, 8, "OFF ");
		   }
		    // 按键消抖延时
            Delay_ms(200);
		  }
		
		if(encoder_enabled)                             //如果编码器使能
		{
			//显示当前的计数值
			num+=Encoder_Get();
			OLED_ShowSignedNum(1, 5, num, 5);
		}
		
		//OLED_ShowNum(1, 6, GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11), 1);
	}
   
}

//控制PA9的led
void led_init(void);
void led_on(void);
void led_off(void);

//初始化PB11的按钮
void key_init(void);
uint32_t key_getnum(void);
	
//旋转编码器代码
void Encoder_Init(void);
int16_t Encoder_Get(void);
