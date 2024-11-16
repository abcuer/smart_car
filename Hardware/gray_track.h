#ifndef __gray_track_h_
#define __gray_track_h_

#define Gray_1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
#define Gray_2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define Gray_3 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define Gray_4 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)
#define Gray_5 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)
#define Gray_6 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)
#define Gray_7 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9)

void gray_init(void);
void track(void);

#endif
