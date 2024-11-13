#ifndef __PID_h_
#define __PID_h_

enum
{
  POSITION_PID = 0,  // λ��ʽ
  DELTA_PID,         // ����ʽ
};

typedef struct
{
	float target;	
	float now;
	float error[3];		
	float p,i,d;
	float pout, dout, iout;
	float out;   
	
	uint32_t pid_mode;

}pid_t;

void pid_Init(pid_t *pid, uint32_t mode, float p, float i, float d);
void motor_target_set(int tarA, int tarB);
void pid_controlA(void);
void pid_controlB(void);

void pid_cal(pid_t *pid);

#endif
