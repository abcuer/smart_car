//#include "stm32f10x.h"                  // Device header


//void Timer_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);			//??TIM2???
//	
//	TIM_InternalClockConfig(TIM4);		//??TIM2?????,???????,TIM????????
//	
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;		
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	
//	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;				
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;				
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;			
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);				
//	
//	/*??????*/
//	TIM_ClearFlag(TIM4, TIM_FLAG_Update);						
//	
//	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);					
//	
//	/*NVIC????*/
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				
//	
//	/*NVIC??*/
//	NVIC_InitTypeDef NVIC_InitStructure;						
//	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			
//	NVIC_Init(&NVIC_InitStructure);						
//	
//	/*TIM??*/
//	TIM_Cmd(TIM4, ENABLE);			
//}

///*
//void TIM2_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//	{
//		
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//}
//*/
#include "stm32f10x.h"                  // Device header

//#define tim1 TIM2

//????->1s
void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//1??
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//????
	TIM_TimeBaseInitStruct.TIM_Period= 1000 - 1;//ARR
	TIM_TimeBaseInitStruct.TIM_Prescaler=7200-1;//PSC
	/* 100ms ÖÐ¶Ï*/
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;//???????
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStruct);
	
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM4, ENABLE);
}
