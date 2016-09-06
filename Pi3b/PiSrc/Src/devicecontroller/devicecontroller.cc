/*************************************************************************
	> File Name:devicecontroller.cpp
	> Author:YabingTu 
	> Mail:tuyabing@anicloud.com
	> Created Time: 2016年08月26日 星期五 17时52分52秒
 ************************************************************************/

#include<iostream>
#include "devicecontroller.h"
using namespace std;

int InitController(DeviceMaster *device_master)
{
    Device &device = device_master->device;
    strcpy(device.physical_id, "m1004");
	strcpy(device.physical_address, "00-01-6C-06-C8-D5");
	strcpy(device.name, "testdevice2");
	strcpy(device.description, "for test2");
	strcpy(device.avatar_url, "testbus2.jpg");
	device.tag_num = 1;
	for (size_t i = 0; i < device.tag_num; i++) {
		strcpy(device.tags[i], "test");
	}
	device.version_id = 1;
	Status ret = InitAgent(&device_master, NULL, 0);
	if (ret == SUCCESSFULLY) {
		return true;
	} else {
		return false;
	}
}
