/*************************************************************************
	> File Name:anible.h
	> Author:YabingTu 
	> Mail:tuyabing@anicloud.com
	> Created Time: 2016年07月29日 星期五 11时07分33秒
 ************************************************************************/

#ifndef _HAL_SEN_H
#define _HAL_SEN_H

#include <stdint.h>
typedef struct ble_list_t{
    int8_t  slave_id;
    int8_t  slave_type;
    int8_t  slave_addr[50];
    int8_t  slave_sig;
    int32_t slave_len;
    int8_t  slave_name[50];

}BleSlaveList;

//BLE Master

int BleMasterTurnOn(int ble_addr,char *ble_dev);
int BleMasterTurnOff(int ble_addr,int ble_fd);
int BleMasterSearch(int fd,int  *ble_mac);
int BleMasterConect(int ble_mac);
int BleMasterRead(int ble_mac,char *buf);
int BleMasterWrite(int  ble_mac,char *buf);





//BLE Slave
void GetSlaveTurnOn();mZvoid GetSlaveTurnOff();


