/*************************************************************************
	> File Name:anible.c
	> Author:YabingTu 
	> Mail:tuyabing@anicloud.com
	> Created Time: 2016年07月29日 星期五 11时16分13秒
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "anible.h"
#include "serial.h"
#define MAXTIMINGS  85
#define DHTPIN  5
int BleMasterTurnOn()
{
    int fd = FALSE;
    fd = UART0_Open(fd,UART_NAME);
    UART_Init(fd,UART_SPEED,UART_FLOW,UART_BITS,UART_STOP,UART_PARITY);
    return fd;
}
int  BleMasterTurnOff(int ble_fd)
{
    UART_Close(ble_fd);
}

static void SearchAnalysis(int ble_fd,BleSlaveList *slave)
{
    while(1){
        UART_Recv(ble_fd,rev_buf,1);
        if(rev_buf[0] == '+'){
            UART_Recv(ble_fd,rev_buf,1);
            if(rev_buf[0] == 'S'){
                UART_Recv(ble_fd,rev_buf,1);
                if(rev_buf[0] == 'C'){
                    UART_Recv(ble_fd,rev_buf,1);
                    if(rev_buf[0] == 'A'){
                        UART_Recv(ble_fd,rev_buf,1);
                        if(rev_buf[0] == 'N'){
                            UART_Recv(ble_fd,rev_buf,1);
                                if(rev_buf[0] == '='){
                                    SearchAnalysis(fd);
                            }
                        }
                    }
                }
            }
        }
    }
}
int BleMasterSearch(int ble_fd,char * scan_cmd,int scan_len,BleSlaveList *slave)
{
    char rev_buf[2];
    int sym_count = 0;
    UART_Send(ble_fd,scan_cmd,scan_len);
    UART_Recv(ble_fd,rev_buf,1);
    if(rev_buf[0] == 'O'){
            UART_Recv(ble_fd,rev_buf,1);
            if(rev_buf[0] == 'K'){
                SearchAnalysis(ble_fd,slave);
            }
        }
}

int BleMasterConect(int ble_mac)
{
}
int BleMasterRead(int  ble_mac,char *buf)
{
}
int BleMasterWrite(int ble_mac,char *buf)
{
}
void main()
{
    int fd;
}
