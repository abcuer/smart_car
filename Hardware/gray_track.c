#include "stm32f10x.h"   
#include "global.h"

int basic_speed = 0;
int err = 0;
uint8_t Line_flag = 0;
uint8_t Line_flag_time = 0;

void gray_init()
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	  GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void Get_Light_TTL(void)
{
	
	if(L3 == 1 || L2== 1 || L1 == 1 || C1 == 1 || R1 == 1 || R2 == 1 || R3 == 1)
	{
		Line_flag = 1;
	}
//	else
//	{
//		Line_flag_time ++;
//		if(Line_flag_time >= 10)
//		{
//			Line_flag = 0;
//		}
//	}
}

//void track(void)
//{
//	basic_speed = 20;
//	if((L3==1&&L2==1&&L1==1&&C1==1&&R1==1&&R2==1&&R3==1)
//	||(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0))
//	{	
//		motor_speed_control(0,0);
//	}
//	else
//	{		
//		if(L3==0&&L2==0&&L1==0&&C1==1&&R1==0&&R2==0&&R3==0)							// 000 1 000
//		{
//			err = 0;
//		}
//		//偏右
//		else if(L3==0&&L2==0&&L1==1&&C1==1&&R1==0&&R2==0&&R3==0)							// 001 1 000
//		{
//			err = -3;
//		}
//		//偏左
//		else if(L3==0&&L2==0&&L1==0&&C1==1&&R1==1&&R2==0&&R3==0)							// 000 1 100
//		{
//			err = 3;
//		}
//		else if(L3==0&&L2==0&&L1==1&&C1==0&&R1==0&&R2==0&&R3==0)							// 001 0 000
//		{
//			err = -4;
//		}
//		else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==1&&R2==0&&R3==0)							// 000 0 100
//		{
//			err = 4;
//		}
//		else if(L3==0&&L2==1&&L1==1&&C1==0&&R1==0&&R2==0&&R3==0)							// 011 0 000
//		{
//			err = -5;
//		}
//		else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==1&&R2==1&&R3==0)							// 000 0 110
//		{
//			err = 5;
//		}				
//		else if(L3==0&&L2==1&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 010 0 000 1
//		{
//			err = -6;
//		}
//		else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==1&&R3==0)							// 000 0 010	
//		{	
//			err =	6; 
//		}
//		else if(L3==1&&L2==1&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 110 0 000
//		{
//			err = -7;
//		}
//		else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==1&&R3==1)							// 000 0 011
//		{
//			err = 7;
//		}
//		else if(L3==1&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 100 0 000 	
//		{
//			err = -8;
//		}
//		else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==1)							// 000 0 001 
//		{
//			err = 8;
//		}
//		motor_speed_control(basic_speed, err);
//	}
//}

