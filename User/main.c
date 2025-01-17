#include "stm32f10x.h"                  // Device header
#include "global.h"

<<<<<<< HEAD
int16_t Encoder_countA;
int16_t Encoder_countB;
=======
uint8_t Key1 = 0;	//按键1 Task
uint8_t Key2 = 0; //按键2 start_flag

int16_t Encoder_countA = 0;
int16_t Encoder_countB = 0;
>>>>>>> master

int16_t SpeedA_now;
int16_t SpeedB_now;

int16_t SpdA;
int16_t SpdB;
int16_t targetA;
int16_t targetB;

<<<<<<< HEAD
uint16_t KeyNum;

int16_t AX,AY,AZ,GX,GY,GZ;

float basespeed;
float roll_gyro, pitch_gyro, yaw_gyro; 
float roll_acc, pitch_acc, yaw_acc; 	 
float yaw_hmc;												 
=======
int16_t AX,AY,AZ,GX,GY,GZ;

float basespeed = 0;
float roll_gyro, pitch_gyro, yaw_gyro; 
float roll_acc, pitch_acc, yaw_acc; 	 												 
>>>>>>> master
float roll_Kalman, pitch_Kalman, yaw_Kalman;
float angle_tar;
float angle_out;
// 任务指令 
uint16_t Task = 0;
uint16_t first_flag = 0;
<<<<<<< HEAD
=======
uint16_t start_flag = 0;
>>>>>>> master
uint16_t SoundLight_flag = 0;
uint16_t SoundLight_time = 0;
uint16_t workstep = 0;
uint16_t angle_record1 = 0, angle_record2 = 0, angle_record3 = 0, angle_record4 = 0;
float baiseTime = 0;
<<<<<<< HEAD
float p = 0.94;
float	i = 0;
float d = 0.03;
=======
float p = 0.22;
float	i = 0.0;
float d = 0.01;
>>>>>>> master

int main(void)
{
	LED_Init();
	Key_Init();
	Timer4_Init();
	EncoderA_Init();
	EncoderB_Init();
	Motor_Run_Init();
	Serial_Init();
	gray_init();
	MyI2C_Init();
	MPU6050_Init();
	Buzzer_Init();
<<<<<<< HEAD
=======
	HMCI2C_Init();
	HMC5883L_Init();
>>>>>>> master
//	
//	angle_tar = 20;
	
	pid_Init(&motorA, DELTA_PID, 0.1428, 0.052, 0);
	pid_Init(&motorB, DELTA_PID, 0.14, 0.052, 0);
<<<<<<< HEAD
//	pid_Init(&angle, POSITION_PID, p, i, d);
	
	while(1)
	{
//		Serial_Printf("%d %d %d %d %d %d %d\r\n", L3, L2, L1, C1, R1,R2,R3);
//		Serial_Printf("flag:%d\r\n", Line_flag);

		
=======
	pid_Init(&angle, POSITION_PID, p, i, d);
	
	while(1)
	{
		Serial_Printf("%.2f, %.2f\r\n", yaw_Kalman,angle.target);
//		angle_detect();
//		Serial_Printf("%d %d %d %d %d %d %d\r\n", L3, L2, L1, C1, R1,R2,R3);
//		Serial_Printf("yaw_hmc:%.2f\r\n", yaw_hmc);
//		Serial_Printf("roll_acc:%d\r\n", (int16_t)roll_acc);
//		Serial_Printf("roll_acc:%d\r\n", (int16_t)roll_acc);
//		Serial_Printf("pitch_acc:%.2f\r\n", pitch_acc);
//		Serial_Printf("%d %d %d %d %d %d %d\r\n", GX,GY,GZ,AX,AY,AZ);
>>>>>>> master
// 		检查Line_flag能否变化，并且引起声光反馈		
//		Get_Light_TTL();
//		if(Line_flag == 1)
//		{
//			motor_target_set(0,0);
//			SoundLight();
//		}	
		
//		motor_target_set(10, 10); // 检查是否是同轮同方向转动，确认寻迹正常工作

		
		
// 		检查转向环能否工作	
//		angle.target = 10;
//		angle.now = yaw_Kalman;
//		basespeed = 10;
//		duanlu();
//		Serial_Printf("%.2f,%.2f,%d\r\n", angle.target, angle.now,GZ);
//		Serial_Printf("L:%.2f,R:%.2f\r\n", SpeedL,SpeedR);
//		LED_Blue_ON();
		//LED_Green_ON();
		//LED_Green_OFF();
//		Delay_ms(100);
//		LED_Blue_OFF();
//		Delay_ms(100);
//		
//		if(first_flag == 0)
//		{
//			LED_Green_ON();
//			Delay_ms(200);
//			float ang1 = yaw_Kalman;
//			Delay_ms(200);
//			float ang2 = yaw_Kalman;
//			Delay_ms(200);
//			float ang3 = yaw_Kalman;
//			angle.now = (ang1 + ang2 + ang3)/3.0;
//			first_flag = 1;
//			LED_Green_OFF();
//		}
//		if(Task == 0)
//		{
//			LED_Green_ON();
//			Delay_ms(200);
//			Task = 1;
//			LED_Green_OFF();
//		}
//		if(Task == 1)
//		{
//			switch(workstep)
//			{
//				case 0:
//					SoundLight_flag = 0;
//					Line_flag = 0;
//					basespeed = 20;
//					angle.target = 0;
//					Get_Light_TTL();
//					pid_Init(&angle, POSITION_PID, 0.94, 0 ,0.03);
//					while(Line_flag == 0) duanlu();
//					workstep ++;
//					break;
//				
//				case 1:
//					if(Line_flag == 1)
//					{
//						motor_target_set(0, 0);
//						SoundLight();
//					}
//					workstep ++;
//					break;
//			}
//		}
<<<<<<< HEAD
		if(Task == 2)
		{
			Serial_Printf("%.2f\r\n", baiseTime);
		//	workstep = 0;
			switch(workstep)
			{
				case 0:
					angle.target = 0;
					basespeed = 22;
					pid_Init(&angle, POSITION_PID, p, i, d);
					angle_record1 = angle.target - 180;
					workstep ++;
					break;
				
				case 1: //断路1
					SoundLight_flag = 0;
					Line_flag = 0;
					Get_Light_TTL();
					while(Line_flag == 0)
					{
						duanlu(); 
					}
					workstep ++;
					break;

				case 2: // 圆弧1
					SoundLight();
					Line_flag = 1;
					Get_Light_TTL();
					while(Line_flag == 1) 
					{	
						//baise_time1 ++;
						Trace();
					}
					workstep ++;
					break;
					
				case 3:	// 断路2
					Line_flag = 0;
					SoundLight();
					angle.target = angle_record1;
					pid_Init(&angle, POSITION_PID, p, i, d);
					while(Line_flag == 0)
					{
						duanlu();
					}
					workstep ++;
					break;
					
				case 4:	// 圆弧2
					SoundLight();
					Line_flag = 1;
					Get_Light_TTL();
					while(Line_flag == 1)
					{		
						//baise_time2 ++;
						Trace();
					}
					workstep ++;
					break;
					
				case 5:	// 停止
					SoundLight();
					motor_target_set(0, 0);
					workstep ++;
					break;
			}
		}
	}	
=======

//		if(start_flag == 1)
//		{
//			if(first_flag == 1)
//			{
//				if(Task == 1)
//				{
//					LED_Green_ON();
//					SoundLight();
//					Task = 0;
//					start_flag = 0;
//					first_flag = 0;
//					Line_flag = 0;
//					angle_record1 = 0, angle_record2 = 0, angle_record3 = 0, angle_record4 = 0;
//					pid_Init(&motorA, DELTA_PID, 0.1428, 0.052, 0);
//					pid_Init(&motorB, DELTA_PID, 0.14, 0.052, 0);
//				}
//				if(Task == 2)
//				{
//					Serial_Printf("%.2f\r\n", baiseTime);
//				//	workstep = 0;
//					switch(workstep)
//					{
//						case 0:
//							angle.target = 0;
//							basespeed = 65;
//							pid_Init(&angle, POSITION_PID, p, i, d);
//							angle_record1 = angle.target - 180;
//							workstep ++;
//							break;
//						
//						case 1: //断路1
//							SoundLight_flag = 0;
//							Line_flag = 0;
//							Get_Light_TTL();
//							while(Line_flag == 0)
//							{
//								duanlu(); 
//							}
//							workstep ++;
//							break;

//						case 2: // 圆弧1
//							SoundLight();
//							Line_flag = 1;
//							motor_target_set(0, 0);
//							Get_Light_TTL();
//							basespeed = 30;
//							while(Line_flag == 1) 
//							{	
//								//baise_time1 ++;
//								Trace();
//							}
//							workstep ++;
//							break;
//							
//						case 3:	// 断路2
//							Line_flag = 0;
//							SoundLight();
//							angle.target = angle_record1;
//							pid_Init(&angle, POSITION_PID, p, i, d);
//							while(Line_flag == 0)
//							{
//								motor_target_set(0, 0);
//								/*
//									调整角度的函数 角度环
//								*/
//								/*
//									保持角度走直线
//								*/
//								//duanlu();
//							}
//							workstep ++;
//							break;
//							
//						case 4:	// 圆弧2
//							SoundLight();
//							Line_flag = 1;
//							Get_Light_TTL();
//							while(Line_flag == 1)
//							{		
//								//baise_time2 ++;
//								Trace();
//							}
//							workstep ++;
//							break;
//							
//						case 5:	// 停止
//							SoundLight();
//							motor_target_set(0, 0);
//							workstep = 0;
//							Task = 0;
//							start_flag = 0;
//							first_flag = 0;
//							Line_flag = 0;
//							angle_record1 = 0, angle_record2 = 0, angle_record3 = 0, angle_record4 = 0;
//							pid_Init(&motorA, DELTA_PID, 0.1428, 0.052, 0);
//							pid_Init(&motorB, DELTA_PID, 0.14, 0.052, 0);
//							break;
//					}
//				}
//			}	
//		}
	}
>>>>>>> master
}


void TIM4_IRQHandler(void)
{
<<<<<<< HEAD
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		GZ -= 17.5;
		
		roll_gyro += (float)GX/ 16.4 * 0.01;
		pitch_gyro += (float)GY/ 16.4 * 0.01;	
		yaw_gyro += (float)GZ/ 16.4 * 0.01;		
		
		roll_acc = atan((float)AY/AZ) * 57.296;
		pitch_acc = -atan((float)AX/AZ) * 57.296;
		yaw_acc = atan((float)AY/AX) * 57.296;
		
		roll_Kalman = Kalman_Filter(&KF_Roll, roll_acc, (float)GX/ 16.4);
		pitch_Kalman = Kalman_Filter(&KF_Pitch, pitch_acc, (float)GY/ 16.4);
		yaw_Kalman = Kalman_Filter(&KF_Yaw, yaw_gyro, (float)GZ/ 16.4);
		
		if(first_flag == 0)
		{
			LED_Green_ON();
			Delay_ms(200);
			yaw_Kalman = 0;
			float ang1 = yaw_Kalman;
			Delay_ms(200);
			float ang2 = yaw_Kalman;
			Delay_ms(200);
			float ang3 = yaw_Kalman;
			angle.target = (ang1 + ang2 + ang3)/3.0;
			first_flag = 1;
			LED_Green_OFF();
			Delay_ms(200);
		}
		if(Task == 0)
		{
			LED_Blue_ON();
			Delay_ms(1000);
			Task = 2;
			LED_Blue_OFF();
		}
=======
	Key1 = Key_GetNum1();
	Key2 = Key_GetNum2();
	if(Key1 == 1) Task ++;
	if(Key2 == 1) start_flag = 1; // 任务执行完毕，startflag = 0;
	if(Task > 4) Task = 0;
	
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		HMC5883L_GetData();

		// 陀螺仪角度
		roll_gyro += (float)GX/ 16.4 * 0.005;
		pitch_gyro += (float)GY/ 16.4 * 0.005;	
		yaw_gyro += (float)GZ/ 16.4 * 0.005;	
		
		// 加速度计角度
		roll_acc = atan((float)AY/AZ) * 57.296;
		pitch_acc = - atan((float)AX/AZ) * 57.296;
		yaw_acc = atan((float)AY/AX) * 57.296;
		
		// 磁力计角度
		yaw_hmc = atan2((float)hmc_x, (float)hmc_y) * 57.296;
		
		// 卡尔曼滤波融合
		roll_Kalman = Kalman_Filter(&KF_Roll, roll_acc, (float)GX/ 16.4);
		pitch_Kalman = Kalman_Filter(&KF_Pitch, pitch_acc, (float)GY/ 16.4);
		yaw_Kalman = Kalman_Filter(&KF_Yaw, yaw_hmc, (float)GZ/ 16.4);
		
		angle_detect();
		
		if(start_flag == 1)
		{
			if(first_flag == 0)
			{
				LED_Blue_ON();
				Delay_ms(1000);
				LED_Blue_OFF();
				LED_Green_ON();
				Delay_ms(200);
				yaw_Kalman = 0;
				float ang1 = yaw_Kalman;
				Delay_ms(200);
				float ang2 = yaw_Kalman;
				Delay_ms(200);
				float ang3 = yaw_Kalman;
				angle.target = (ang1 + ang2 + ang3)/3.0;
				first_flag = 1;
				LED_Green_OFF();
				Delay_ms(200);
			}
		}
//		if(Task > 0)
//		{
//			LED_Blue_ON();
//			Delay_ms(1000);
//			LED_Blue_OFF();
//		}
>>>>>>> master
//		if(Task == 1)
//		{
//			switch(workstep)
//			{
//				case 0:
//					SoundLight_flag = 0;
//					Line_flag = 0;
//					basespeed = 10;
//					angle.target = 0;
//					pid_Init(&angle, POSITION_PID, 0.94, 0 ,0.03);
//					while(Line_flag == 0) duanlu();
//					Get_Light_TTL();
//					workstep ++;
//				
//				case 1:
//					if(Line_flag == 1)
//					{
//						motor_target_set(0, 0);
//						SoundLight();
//					}
//					workstep ++;
//			}
//		}

		
		Encoder_countA = EncoderA_Get();
		Encoder_countB = EncoderB_Get();
		pid_control();
		
		if(SoundLight_flag == 1)
		{
			SoundLight_time ++;
			if(SoundLight_time >= 10)
			{
					Buzzer_OFF();
					LED_Blue_OFF();
					SoundLight_flag = 0;
					SoundLight_time = 0;
			}
		}
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}
