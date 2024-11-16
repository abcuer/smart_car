#include "stm32f10x.h"   
#include "global.h"

void gray_init()
{
//	gpio_init(GPIO_B, Pin_12, IU);   // D1
//	gpio_init(GPIO_B, Pin_13, IU);   // D2
//	gpio_init(GPIO_B, Pin_14, IU);   // D3
//	gpio_init(GPIO_B, Pin_15, IU);   // D4
//	gpio_init(GPIO_A, Pin_8, IU);    // D5
//	gpio_init(GPIO_C, Pin_13, IU);   // D6
//	gpio_init(GPIO_C, Pin_14, IU);   // D7
//	gpio_init(GPIO_C, Pin_15, IU);   // D8
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

void track(void)												// 765 4 321
{																	
	if(Gray_4 == 0) 											// 111 0 111
	{
		motor_target_set(100, 100);
	}
	else if(Gray_4 != 0 && Gray_5 == 0)		// 110 1 111
	{
		motor_target_set(100, 120);
	}
	else if(Gray_4 != 0 && Gray_3 == 0)		// 111 1 011
	{
		motor_target_set(120, 100);
	}
	else if(Gray_4 == 0 && Gray_5 == 0)		// 110 0 111
	{
		motor_target_set(90, 130);
	}
	else if(Gray_4 == 0 && Gray_3 == 0)		// 111 0 011
	{
		motor_target_set(130, 90);					
	}
	else if(Gray_4 != 0 && Gray_5 == 0)		// 110 1 111
	{
		motor_target_set(90, 130);
	}
	else if(Gray_4 != 0 && Gray_3 == 0)		// 111 1 011
	{
		motor_target_set(130, 90);
	}
	else if(Gray_6 == 0 && Gray_5 == 0)		// 100 1 111
	{
		motor_target_set(80, 150);
	}
	else if(Gray_3 == 0 && Gray_2 == 0)		// 111 1 001
	{
		motor_target_set(150, 80);
	}
	else if(Gray_6 == 0 && Gray_5 != 0)  	// 101 1 111
	{
		motor_target_set(80, 160);
	}
	else if(Gray_3 !=0 && Gray_2 == 0) 		// 111 1 101
	{
		motor_target_set(160, 80);
	}
	else if(Gray_7 == 0 && Gray_6 == 0)		// 001 1 111
	{
		motor_target_set(70,170);
	}
	else if(Gray_2 == 0 && Gray_1 == 0)		// 111 1 100
	{
		motor_target_set(170, 70);
	}
	else if(Gray_7 == 0 && Gray_6 != 0)		// 011 1 111
	{
		motor_target_set(60, 180);
	}
	else if(Gray_1 == 0 && Gray_2 != 0)		// 111 1 110
	{
		motor_target_set(180, 60);
	}
	else 																	// 111 1 111		
	{
		motor_target_set(100, 100);
	}
}

//void track()                        //1234 5678
//{
//		if((D4 == 0)&&(D5 == 0))        //1110 0111
//		{
//			motor_target_set(100,100);
//		}
//		else if((D4 == 0)&&(D5 != 0))   //1110 1111
//		{
//			motor_target_set(100,120); //向右偏
//		}
//		else if((D4 != 0)&&(D5 == 0))   //1111 0111
//		{
//			motor_target_set(120,100);  
//		}
//		else if((D3 != 0)&&(D4 == 0))   //1100 1111
//		{
//			motor_target_set(90,130);
//		}
//		else if((D5 == 0)&&(D6 == 0))   //1111 0011
//		{
//			motor_target_set(130,90);
//		}
//		else if((D3 == 0)&&(D4 != 0))   //1101 1111
//		{
//			motor_target_set(90,130);
//		}
//		else if((D5 != 0)&&(D6 == 0))   //1111 1011
//		{
//			motor_target_set(130,90);
//		}
//		else if((D2 == 0)&&(D3 == 0))   //1001 1111
//		{
//			motor_target_set(80,150);
//		}
//		else if((D6 == 0)&&(D7 == 0))   //1111 1001
//		{
//			motor_target_set(150,80);
//		}
//		else if((D2 == 0)&&(D3 != 0))   //1011 1111
//		{
//			motor_target_set(80,150);
//		}
//		else if((D6 != 0)&&(D7 == 0))   //1111 1101
//		{
//			motor_target_set(150,80);
//		}
//		else if((D1 == 0)&&(D2 == 0))   //0011 1111
//		{
//			motor_target_set(60,180);
//		}
//		else if((D7 == 0)&&(D8 == 0))   //1111 1100
//		{
//			motor_target_set(180,60);
//		}
//		else if((D1 == 0)&&(D2 != 0))   //0111 1111
//		{
//			motor_target_set(40,180);
//		}	
//		else if((D7 !=0)&&(D8 == 0))    //1111 1110
//		{
//			motor_target_set(180,40);
//		}
//		else                            //1111 1111
//		{
//			motor_target_set(100,100);
//		}
//}

//unsigned char digtal(unsigned char channel)//1-8	  ��ȡXͨ������ֵ
//{
//	u8 value = 0;
//	switch(channel) 
//	{
//		case 1:  
//			if(gpio_get(GPIO_B, Pin_12) == 1) value = 1;
//			else value = 0;  
//			break;  
//		case 2: 
//			if(gpio_get(GPIO_B, Pin_13) == 1) value = 1;
//			else value = 0;  
//			break;  
//		case 3: 
//			if(gpio_get(GPIO_B, Pin_14) == 1) value = 1;
//			else value = 0;  
//			break;   
//		case 4:  
//			if(gpio_get(GPIO_B, Pin_15) == 1) value = 1;
//			else value = 0;  
//			break;   
//		case 5:
//			if(gpio_get(GPIO_A, Pin_8) == 1) value = 1;
//			else value = 0;  
//			break;
//		case 6:  
//			if(gpio_get(GPIO_C, Pin_13) == 1) value = 1;
//			else value = 0;  
//			break;  
//		case 7: 
//			if(gpio_get(GPIO_C, Pin_14) == 1) value = 1;
//			else value = 0;  
//			break;  
// 		case 8: 
// 			if(gpio_get(GPIO_C, Pin_15) == 1) value = 1;
// 			else value = 0;  
// 			break;   
//	}
//	return value; 
//}

