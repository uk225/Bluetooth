#include<reg51.h>
#include<string.h>
#include "lcd.h"
void init()
{
	TMOD = 0x20; //8 bit auto reload
	SCON = 0x50; //8 bit buffer
	TH1  = 0xfd; //baudrate:9600 bits per sec
	TR1  = 1; //start timer 1 
}

/*
void send_char(unsigned char ch)
{
	SBUF = ch;
	while(TI == 0);
	TI = 0;
}
*/

void receive(unsigned char *tmp_buff)
{
	int t=0;
	unsigned char ch1;
	unsigned char buff[20];
	while(1)
	{
	while(RI==0);
	ch1 = SBUF;
	RI=0;
		if(ch1 == '\n')
		{
			break;
		}
	buff[t++]=ch1;
	}
	strncpy(tmp_buff,buff,t-1);
}

/*
void send_str(unsigned char *ch)
{
	while(*ch != '\0')
	{
		send_char(*ch++);
	}
}
*/