#ifndef __GLOBAL_H
#define __GLOBAL_H
#include "Delay.h"
#include "LED.h"
#include "Key.h"
//#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
#include "Motor_Run.h"
#include "Serial.h"
#include "pid.h"
#include "gray_track.h"
#include "MyI2C.h"
#include "MPU6050.h"
#include <math.h>
#include "filter.h"
#include "Buzzer.h"
#include "detect_position.h"
<<<<<<< HEAD
=======
#include "HMCI2C.h"
#include "hmc5883l.h"
>>>>>>> master

#define MAX_DUTY 100

extern uint8_t motorA_dir;
extern uint8_t motorB_dir;

extern int16_t Encoder_countA;
extern int16_t Encoder_countB;

extern pid_t motorA;
extern pid_t motorB;
extern pid_t angle;

extern int16_t SpdA;
extern int16_t SpdB;

extern int16_t targetA;
extern int16_t targetB;

extern int16_t SpeedA_now;
extern int16_t SpeedB_now;

extern int16_t AX,AY,AZ,GX,GY,GZ;
extern float roll_gyro, pitch_gyro, yaw_gyro;
extern float roll_acc, pitch_acc, yaw_acc;
extern float yaw_hmc;
extern float roll_Kalman, pitch_Kalman, yaw_Kalman;

extern float angle_tar;
extern float angle_out;

extern uint8_t Line_flag;
extern uint16_t SoundLight_flag;
extern float basespeed;
extern float baiseTime;
extern uint16_t workstep;
#endif
