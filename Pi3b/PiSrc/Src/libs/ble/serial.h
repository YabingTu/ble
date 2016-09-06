/*************************************************************************
	> File Name: serial.h
	> Author:Yabing Tu
	> Mail:tuyabing@anicloud.com 
	> Created Time: 2016年09月06日 星期二 13时45分02秒
 ************************************************************************/

#ifndef _SERIAL_H
#define _SERIAL_H

#define UART_NAME  "/dev/ttyAMA0"
#define UART_SPEED 115200
#define UART_FLOW   0
#define UART_BITS   8
#define UART_STOP   1
#define UART_PARITY 'N'

int UART_Open(int fd,char* port);
void UART_Close(int fd);
int UART_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity);
int UART_Init(int fd, int speed,int flow_ctrlint ,int databits,int stopbits,char parity);
int UART_Recv(int fd, char *rcv_buf,int data_len);
int UART_Send(int fd, char *send_buf,int data_len);
#endif
