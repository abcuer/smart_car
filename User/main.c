#include "stm32f10x.h"                  // Device header
#include "global.h"

int16_t Encoder_countA;
int16_t Encoder_countB;

int16_t SpdA;
int16_t SpdB;
int16_t targetA;
int16_t targetB;

uint16_t KeyNum;
uint16_t KeyNum1;

int main(void)
{
	OLED_Init();
	Key_Init();
	Timer_Init();
	EncoderA_Init();
	EncoderB_Init();
	Motor_Run_Init();
	Serial_Init();
	
	motor_target_set(200, 200);
	pid_Init(&motorA, DELTA_PID, 0.21, 0.05, 0);
	pid_Init(&motorB, DELTA_PID, 0.21, 0.05, 0);
//	
//	OLED_ShowString(1,1,"EcA:");
//	OLED_ShowString(2,1,"EcB:");
//	motorA_duty(50);
//	motorB_duty(50);
	
	while(1)
	{
		
//		KeyNum = Key_GetNum();
//		if(KeyNum == 1)
//		{
//			KeyNum1 ++;
//		}
		OLED_ShowNum(1,1,targetA,3);
		OLED_ShowNum(1,9,targetB,3);
		OLED_ShowSignedNum(2,1,motorA.now, 5);
		OLED_ShowSignedNum(2,9,motorB.now, 5);
		OLED_ShowSignedNum(3,1,SpdA,3);
		OLED_ShowSignedNum(3,9,SpdB,3);
//		Serial_Printf("SpeedB = %d\r\n", Speed2);
//	
//		switch(KeyNum1)
//		{
//			case 1: Car_Straight(); break;
//			case 2: Car_Back(); 		break;
//			case 3: Car_Left();			break;
//			case 4: Car_Right();    break;
//			case 5: Car_Stop();     break;
//			case 6: KeyNum1 = 0;    break;
//		}
	}
}

void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		Encoder_countA = EncoderA_Get();
		Encoder_countB = EncoderB_Get();
		pid_controlA();
		pid_controlB();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}
