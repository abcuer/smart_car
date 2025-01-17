#include "stm32f10x.h"                  // Device header
#include "PWM.h"
 
void Motor_Init(void)
{
	PWM_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

//void Motor_SetSpeed(int8_t Speed)
//{
//		if(Speed >= 0)
//		{
//			GPIO_SetBits(GPIOA, GPIO_Pin_4);
//			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
//			PWM_SetCompare2(Speed);
//			GPIO_SetBits(GPIOB, GPIO_Pin_14);
//			GPIO_ResetBits(GPIOB, GPIO_Pin_15);
//			PWM_SetCompare3(Speed);
//		}
//		else
//		{
//			GPIO_SetBits(GPIOA, GPIO_Pin_5);
//			GPIO_ResetBits(GPIOA, GPIO_Pin_4);
//			PWM_SetCompare2(-Speed);
//			GPIO_SetBits(GPIOB, GPIO_Pin_15);
//			GPIO_ResetBits(GPIOB, GPIO_Pin_14);
//			PWM_SetCompare3(-Speed);
//		}
//}
