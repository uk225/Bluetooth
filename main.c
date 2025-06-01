#include<reg51.h>
#include<string.h>
#include<stdio.h>
#include "delay.h"
#include "lcd.h"
#include "uart.h"

void main()
{
	unsigned char buff[20]={0};
	unsigned char sbuff[20]={0};
	int count = 0;
	lcd_init();
	init();
	
	while(1)
	{
		lcd_cmd(0x80);
		receive(buff);
		count = buff_size(buff);
		sprintf(sbuff,"size:%d",count);
		if(strcmp(buff,"clear")==0)
		{
			lcd_cmd(0x01);
			// 
			memset(buff,0,sizeof(buff));
			memset(sbuff,0,sizeof(sbuff));
		}
		lcd_data(buff);
		lcd_cmd(0xc0);
		lcd_data(sbuff);
		
		memset(buff,0,sizeof(buff));
		memset(sbuff,0,sizeof(buff));
		delay(500);
	}
}