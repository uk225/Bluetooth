#ifndef __LCD_H__
#define __LCD_H__


  void lcd_cmd(unsigned char ch);
	void lcd_init();
  void lcd_char(unsigned char ch);
	void lcd_data(unsigned char *ch);
	int buff_size(unsigned char *ch);
#endif