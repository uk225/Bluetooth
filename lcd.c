#include<reg51.h>

#include "delay.h"
#define LCDPORT P2

sbit rs = P0^0;
sbit rw = P0^1;
sbit en = P0^2;


void lcd_cmd(unsigned char ch)
{
	LCDPORT = ch;
	rs = 0;
	rw = 0;
	en = 1;
	delay(1);
	en = 0;

}

void lcd_init()
{
	//lcd_cmd(0x38);
	//lcd_cmd(0x01);
	//lcd_cmd(0x06);
	//lcd_cmd(0x80);
	//lcd_cmd(0x0a);
	
	lcd_cmd(0x38); //8bit mode
	lcd_cmd(0x0c); //display on cursor off
	lcd_cmd(0x80);
	lcd_cmd(0x06);
	lcd_cmd(0x01); //clear screen
	
	//lcd_cmd(0x38);// make 5*7 matrix of each character
	//lcd_cmd(0x01); //clear screan
	//lcd_cmd(0x0A); // display off cursor on
	//lcd_cmd(0x06); //increment cursor to righit
  //lcd_cmd(0x80); // force cursor to begin first line
}


void lcd_char(unsigned char ch)
{
	LCDPORT = ch;
	rs = 1;
	rw = 0;
	en = 1;
	delay(1);
	en = 0;
}




void lcd_data(unsigned char *ch)
{
	while(*ch!='\0')
	{
		lcd_char(*ch++);
	}
	
}

int buff_size(unsigned char *ch)
{
	int count=0;
	while(*ch!='\0')
	{
		count++;
		ch++;
	}
	return count;
	
}