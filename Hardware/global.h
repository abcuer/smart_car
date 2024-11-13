#ifndef __GLOBAL_H
#define __GLOBAL_H
#include "Delay.h"
#include "Key.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
#include "Motor_Run.h"
#include "Serial.h"
#include "pid.h"


#define MAX_DUTY 100

extern uint8_t motorA_dir;
extern uint8_t motorB_dir;

extern int16_t Encoder_countA;
extern int16_t Encoder_countB;

extern pid_t motorA;
extern pid_t motorB;

extern int16_t SpdA;
extern int16_t SpdB;

extern int16_t targetA;
extern int16_t targetB;
#endif
