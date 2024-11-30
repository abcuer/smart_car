#ifndef __MPU6050_H
#define __MPU6050_H

void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data);				/* ������д��Ĵ��� */
uint8_t MPU6050_ReadReg(uint8_t RegAddress);										/* ��ȡ�Ĵ��������� */

void MPU6050_Init(void);																				/* ��ʼ��MPU6050 */
uint8_t MPU6050_GetID(void);																		/* ȷ�������豸��MPU6050 */
void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,  /*��ȡ���ٶȼƺ����������� */
						int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);

#endif
