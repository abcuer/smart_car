#include "stm32f10x.h"                  // Device header
#include "global.h"

uint16_t turn = 0;
uint16_t baise_time1 = 0;
uint16_t baise_time2 = 0;
uint16_t heise_time = 0;
uint8_t Line_flag_task2 = 0;
uint16_t baise_time_task2 = 0;
int16_t speed_err;
<<<<<<< HEAD
=======
float offset = 0;
>>>>>>> master

void SoundLight(void)
{
	if(SoundLight_flag == 0)
	{
		Buzzer_ON();
		LED_Blue_ON();
		SoundLight_flag = 1;
	}
}

<<<<<<< HEAD
=======
void angle_detect(void)
{
	angle.target = 90;
	angle.now = yaw_Kalman;
	offset = angle.now-angle.target;
	if(offset >= 0)
		if(offset > 3)
		{
			pid_cal(&angle);
			motor_target_set(-angle.out, +angle.out);
		}
		else
		{
			motor_target_set(0,0);
		}
	else
	{
		offset = -offset;
		if(offset > 3)
		{
			pid_cal(&angle);
			motor_target_set(-angle.out, +angle.out);
		}
		else
		{
			motor_target_set(0,0);
		}
	}
}

>>>>>>> master
void duanlu(void) // 角度环控制
{
	if(angle.target>=0)
	{
		if(angle.target<=yaw_Kalman) yaw_Kalman = angle.target;
	}
	else
	{
		if(angle.target>=yaw_Kalman) yaw_Kalman = angle.target;
	}
	angle.now = yaw_Kalman;
	pid_cal(&angle);
	float offset = 	angle.target - angle.now;
	if(offset<0) offset = -offset;
	if(offset>0 && offset<1)	motor_target_set(basespeed, basespeed);
	float Speed1 = basespeed + angle.out;
	float Speed2 = basespeed - angle.out;
	if(Speed1 < 0) Speed1 = 0;
	if(Speed1 < 0) Speed2 = 0;
	if(angle.target>=0) 
	{	
		if(angle.now<=angle.target)
		{
			motor_target_set(Speed1, Speed2);		
		}
		else if(angle.now> angle.target)
		{
			motor_target_set(Speed2, Speed1);
		}
	}
	else if(angle.target<0)
	{
		if(angle.now > angle.target)
		{
			motor_target_set(Speed1, Speed2);	
		}
		else if(angle.now < angle.target)
		{
			motor_target_set(Speed2, Speed1);
		}
	} 	
	Get_Light_TTL();
}
//		if(angle.target >= 0)
//		{
//			if(angle.target <= yaw_Kalman) yaw_Kalman = angle.target;
//		}
//		else if(angle.target < 0)
//		{
//			if(angle.target >= yaw_Kalman) yaw_Kalman = angle.target;
//		}
//		angle.now = yaw_Kalman;
//		pid_cal(&angle);
//	
//		float offset = 	angle.target - angle.now;
////	if(offset<=0) offset = -offset;
////	if(offset<1)
////	{
////		motor_target_set(basespeed, basespeed);
////	}
////	else
////	{
//		// 直行
//			if(angle.target>=0)
//			{
//				SpeedL = basespeed + angle.out; 
//				SpeedR = basespeed - angle.out;
//				motor_target_set(SpeedL, -SpeedR);	
//			}
//			else if(angle.target<0)
//			{
//				SpeedL = basespeed - angle.out; 
//				SpeedR = basespeed + angle.out;
//				motor_target_set(-SpeedL, SpeedR);	
//			}
//			if(SpeedL <= 0)         SpeedL = 0;
//			else if(SpeedL >= 100)  SpeedL = 100;
//			if(SpeedR <= 0)         SpeedR = 0;
//			else if(SpeedR >= 100)  SpeedR = 100;
//	}
//	Get_Light_TTL();
//  Delay_ms(10);
//}

void Trace(void)	
{
<<<<<<< HEAD
	Get_Light_TTL();
	Line_flag = 1;
	if(L3==1&&L2==1&&L1==1&&C1==1&&R1==1&&R2==1&&R3==1) // 1:检测到黑线 0:白色
	{
		heise_time ++;
		if(heise_time >= 40)
		{
			heise_time = 0;
			Line_flag = 1;
		}
	}
	else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)
	{
		if(workstep == 2)
		{
			baise_time1 ++;
//			baiseTime = baise_time1;
			if(baise_time1 >= 9570) // 数值超过100，Ling_flag = 0, 进入下一状态 
														// 必须根据电机速度来调整大小	
														// 打开串口，看看变化速度
			{
				Line_flag = 0;
				baise_time1 = 0;
			}
		}
		if(workstep == 4)
		{
			//baise_time_task2 ++;
			baise_time2 ++;
			if(baise_time2 >= 9600)
			{
				Line_flag = 0;
				baise_time2 = 0;
	//			baise_time_task2 = 0;
	//			Line_flag_task2 = 0;
			}
		}
	}
=======
	
//	if(L3==1&&L2==1&&L1==1&&C1==1&&R1==1&&R2==1&&R3==1) // 1:检测到黑线 0:白色
//	{
//		heise_time ++;
//		if(heise_time >= 40)
//		{
//			heise_time = 0;
//			Line_flag = 1;
//		}
//	}
//	else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)
//	{
//		if(workstep == 2)
//		{
//			baise_time1 ++;
////			baiseTime = baise_time1;
//			if(baise_time1 >= 9570) // 数值超过100，Ling_flag = 0, 进入下一状态 
//														// 必须根据电机速度来调整大小	
//														// 打开串口，看看变化速度
//			{
//				Line_flag = 0;
//				baise_time1 = 0;
//			}
//		}
//		if(workstep == 4)
//		{
//			//baise_time_task2 ++;
//			baise_time2 ++;
//			if(baise_time2 >= 9600)
//			{
//				Line_flag = 0;
//				baise_time2 = 0;
	//			baise_time_task2 = 0;
	//			Line_flag_task2 = 0;
//			}
//		}
//	}
>>>>>>> master
//	else
//	{
//		if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)
//		{
//			baise_time ++;
//			if(baise_time >= 50)
//			{
//				baise_time = 0;
//				if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)
//				{
//					Line_flag = 0;
//				}
//			}
//		}
//		else
//		{
<<<<<<< HEAD
			if(L3==0&&L2==0&&L1==0&&C1==1&&R1==0&&R2==0&&R3==0)											// 000 1 000
			{
				speed_err = 0;
			}
			else
			{
				if(L3==0&&L2==0&&L1==1&&C1==1&&R1==0&&R2==0&&R3==0)										// 001 1 000
				{
					speed_err = -3;
				}
				else if(L3==0&&L2==0&&L1==0&&C1==1&&R1==1&&R2==0&&R3==0)							// 000 1 100
				{
					speed_err = 3;
				}
				else if(L3==0&&L2==0&&L1==1&&C1==0&&R1==0&&R2==0&&R3==0)							// 001 0 000
				{
					speed_err = -4;
				}
				else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==1&&R2==0&&R3==0)							// 000 0 100
				{
					speed_err = 4;
				}
				else if(L3==0&&L2==1&&L1==1&&C1==0&&R1==0&&R2==0&&R3==0)							// 011 0 000
				{
					speed_err = -5;
				}
				else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==1&&R2==1&&R3==0)							// 000 0 110
				{
					speed_err = 5;
				}				
				else if(L3==0&&L2==1&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 010 0 000 
				{
					speed_err = -5;
				}
				else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==1&&R3==0)							// 000 0 010	
				{	
					speed_err =	5;
					; 
				}
				else if(L3==1&&L2==1&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 110 0 000
				{
					speed_err = -6;
				}
				else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==1&&R3==1)							// 000 0 011
				{
					speed_err = 6;
				}
				else if(L3==1&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 100 0 000 	
				{
					speed_err = -6;
				}
				else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==1)							// 000 0 001 
				{
					speed_err = 6;
				}
			}
			motor_speed_control(basespeed, speed_err);
		}
=======
			Get_Light_TTL();
			baise_time1 ++;
			if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)
			{
				if(baise_time1 > 2800)
				{
					Line_flag = 0;
				}
			}
			if(L3==0&&L2==0&&L1==0&&C1==1&&R1==0&&R2==0&&R3==0)											// 000 1 000
			{
				speed_err = 0;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==1&&C1==1&&R1==0&&R2==0&&R3==0)										// 001 1 000
			{
				speed_err = -4;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==0&&C1==1&&R1==1&&R2==0&&R3==0)							// 000 1 100
			{
				speed_err = 4;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==1&&C1==0&&R1==0&&R2==0&&R3==0)							// 001 0 000
			{
				speed_err = -5;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==1&&R2==0&&R3==0)							// 000 0 100
			{
				speed_err = 5;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==1&&L1==1&&C1==0&&R1==0&&R2==0&&R3==0)							// 011 0 000
			{
				speed_err = -6;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==1&&R2==1&&R3==0)							// 000 0 110
			{
				speed_err = 6;
				baise_time1 = 0;
			}				
			else if(L3==0&&L2==1&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 010 0 000 
			{
				speed_err = -7;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==1&&R3==0)							// 000 0 010	
			{	
				speed_err =	7;
				baise_time1 = 0;
				; 
			}
			else if(L3==1&&L2==1&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 110 0 000
			{
				speed_err = -8;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==1&&R3==1)							// 000 0 011
			{
				speed_err = 8;
				baise_time1 = 0;
			}
			else if(L3==1&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==0)							// 100 0 000 	
			{
				speed_err = -9;
				baise_time1 = 0;
			}
			else if(L3==0&&L2==0&&L1==0&&C1==0&&R1==0&&R2==0&&R3==1)							// 000 0 001 
			{
				speed_err = 9;
				baise_time1 = 0;
			}
			motor_speed_control(basespeed, speed_err);
}

//					else
//					{
//						baise_time1 = 0;
//					}
				

			
>>>>>>> master
//}
