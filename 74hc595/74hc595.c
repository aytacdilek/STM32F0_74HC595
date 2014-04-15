#include "74hc595.h"

void M74HC595_Init(void)
{
	RCC_AHBPeriphClockCmd(M74HC595_PORT_RCC, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = (M74HC595_G_NOT | M74HC595_RCK | M74HC595_SCK | M74HC595_SCLR_NOT | M74HC595_SI);
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
	GPIO_Init(M74HC595_PORT, &GPIO_InitStructure);

	M74HC595_ClearData();
}

void M74HC595_ClearData(void)
{
	GPIO_ResetBits(M74HC595_PORT, M74HC595_SCLR_NOT);
	GPIO_SetBits(M74HC595_PORT, M74HC595_SCLR_NOT);
}

void M74HC595_EnableData(void)
{
	GPIO_ResetBits(M74HC595_PORT, M74HC595_G_NOT);
}

void M74HC595_WriteData(const unsigned char data)
{
	unsigned char i;
	for(i=0; i < 8; i++)
	{
		GPIO_WriteBit(M74HC595_PORT, M74HC595_SI, ((0b00000001 << i) & data));	//bit by bit send the 8-bit data to SI
		GPIO_ResetBits(M74HC595_PORT, M74HC595_SCK);
		GPIO_SetBits(M74HC595_PORT, M74HC595_SCK);		//low to high transition allows data to be registered in shift register
	}
	GPIO_ResetBits(M74HC595_PORT, M74HC595_RCK);
	GPIO_SetBits(M74HC595_PORT, M74HC595_RCK);			//lw to high transition allows data in shift register to be transfered to storage register

	M74HC595_EnableData();
}
