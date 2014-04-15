#ifndef __74HC595_H__
#define	__74HC595_H__

#include "main.h"

#define M74HC595_PORT		GPIOA
#define M74HC595_PORT_RCC	RCC_AHBPeriph_GPIOA
#define M74HC595_G_NOT		GPIO_Pin_0
#define M74HC595_RCK		GPIO_Pin_1
#define M74HC595_SCLR_NOT	GPIO_Pin_2
#define M74HC595_SCK		GPIO_Pin_3
#define M74HC595_SI			GPIO_Pin_4

GPIO_InitTypeDef GPIO_InitStructure;

void M74HC595_Init(void);
void M74HC595_ClearData(void);
void M74HC595_EnableData(void);
void M74HC595_WriteData(const unsigned char data);

#endif
