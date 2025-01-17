#ifndef __MYI2C_H
#define __MYI2C_H

void MyI2C_Init(void);			/* ��ʼ��MPU6050 SCL��SDA */
void MyI2C_Start(void); 		/* ����I2Cͨ�� */
void MyI2C_Stop(void);			/* �ر�I2Cͨ�� */
void MyI2C_SendByte(uint8_t Byte);			/* ����8λ�ֽ����� */
uint8_t MyI2C_ReceiveByte(void);				/* ����8λ�ֽ����� */
void MyI2C_SendAck(uint8_t AckBit);			/* ���շ�����Ӧ���ź���ȷ�Ͻ��յ��ź� */ 
uint8_t MyI2C_ReceiveAck(void);					/* ��ȡ���Խ��շ���Ӧ�� */

#endif
