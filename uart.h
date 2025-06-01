#ifndef __UART_H__
#define __UART_H__

void init();
//void send_str(unsigned char *ch);
//void send_char(unsigned char ch);
void receive(unsigned char *tmp_buff);
#endif 