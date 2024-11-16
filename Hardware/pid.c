#include "stm32f10x.h" 
#include "pid.h"
#include "Motor_Run.h"
#include "global.h"

pid_t motorA;
pid_t motorB;

void pid_Init(pid_t *pid, uint32_t mode, float p, float i, float d)
{
                 // Device header
	pid->pid_mode = mode;
	pid->p = p;
	pid->i = i;
	pid->d = d;
}

void motor_target_set(int tarA, int tarB)
{
	targetA = tarA;
	targetB = tarB;
	if(tarA >= 0) 
	{
		motorA_dir = 0;
		motorA.target = tarA;
	}
	else
	{
		motorA_dir = 1;
		motorA.target = -tarA;
	}
	if(tarB >= 0) 
	{
		motorB_dir = 0;
		motorB.target = tarB;
	}
	else
	{
		motorB_dir = 1;
		motorB.target = -tarB;
	}
}


void pid_controlA(void)
{
	track();
	if(motorA_dir) motorA.now = Encoder_countA;
	else motorA.now = -Encoder_countA;
	SpeedA_now = Encoder_countA;		//当前速度，调试
	Encoder_countA = 0;
	pid_cal(&motorA);
	motorA_duty(motorA.out);
	SpdA = motorA.out;			//占空比
}

void pid_controlB(void)
{
	if(motorB_dir) motorB.now = Encoder_countB;
	else motorB.now = -Encoder_countB;
	SpeedB_now = Encoder_countB;
	Encoder_countB = 0;
	pid_cal(&motorB);
	motorB_duty(motorB.out);
	SpdB = motorB.out;
}

void pid_cal(pid_t *pid)
{
	// ���㵱ǰƫ��
	pid->error[0] = pid->target - pid->now;

	// �������
	if(pid->pid_mode == DELTA_PID)  // ����ʽ
	{
		pid->pout = pid->p * (pid->error[0] - pid->error[1]);
		pid->iout = pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
		pid->out += pid->pout + pid->iout + pid->dout;
	}
	else if(pid->pid_mode == POSITION_PID)  // λ��ʽ
	{
		pid->pout = pid->p * pid->error[0];
		pid->iout += pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - pid->error[1]);
		pid->out = pid->pout + pid->iout + pid->dout;
	}

	// ��¼ǰ����ƫ��
	pid->error[2] = pid->error[1];
	pid->error[1] = pid->error[0];

	// ����޷�
	if(pid->out>=MAX_DUTY)	
		pid->out=MAX_DUTY;
	if(pid->out<=0)	
		pid->out=0;
	
}

