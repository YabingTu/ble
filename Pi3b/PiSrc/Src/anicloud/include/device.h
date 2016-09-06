/*
 * ============================================================================
 * Name          : device.h
 * Version       : 0.0.1
 * Author        : ben
 * Created on    : 2016/6/21
 * Last Modified : 2016/8/25
 * Copyright     : Anicloud Limited ©2016
 * Description   :
 * ============================================================================
 */
#ifndef ANI_INCLUDE_DEVICE_H_
#define ANI_INCLUDE_DEVICE_H_

////////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#include "aniconst.h"
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//TODO	字段长度是否提前固定好,确定数值
const int MAX_PHYSICAL_ID_SIZE = 100;
const int MAX_PHYSICAL_ADDRESS_SIZE = 100;
const int MAX_NAME_SIZE = 100;
const int MAX_DESCRIPTION_SIZE = 100;
const int MAX_AVATAR_URL_SIZE = 256;
const int MAX_TAGS_LEN = 8;
const int MAX_TAGS_NUM = 100;

const int MAX_SLAVE_NUM = 1024;

/* function definition */
const int MAX_FUNC_COUNT = 256;
const int MAX_FUNC_NAME_SIZE = 256;
const int MAX_GROUP_NAME_SIZE = 256;
const int MAX_GROUP_COUNT = 256;
////////////////////////////////////////////////////////////////////////////////

//const int
////////////////////////////////////////////////////////////////////////////////
typedef struct device_t {
	char physical_id[MAX_PHYSICAL_ID_SIZE];
	char physical_address[MAX_PHYSICAL_ADDRESS_SIZE];
	char name[MAX_NAME_SIZE];
	char description[MAX_DESCRIPTION_SIZE];
	char avatar_url[MAX_AVATAR_URL_SIZE];
	size_t tag_num;
	char tags[MAX_TAGS_NUM][MAX_TAGS_LEN];
	int64_t version_id;
} Device;

typedef struct function_t {
	int32_t function_id;
	int64_t group_id;
} Function;

/**
 * 从设备
 */
typedef struct device_slave_t {
	Device device;
	size_t function_num;
	Function functions[MAX_FUNC_COUNT];
	int32_t device_id; //TODO 请教黄斌：这里为什么用int，而master那边用的long？
	int64_t owner_id;
	uint64_t last_modified_time;
	char token[TOKEN_LEN];
	int64_t master_id;
} DeviceSlave;

/**
 * 主设备
 */
typedef struct device_master_t {
	Device device;
	size_t function_num;
	Function functions[MAX_FUNC_COUNT];
	int64_t device_id;
	int64_t owner_id;
	uint64_t last_modified_time;
	char token[TOKEN_LEN];
	size_t slave_num;
	DeviceSlave slaves[MAX_SLAVE_NUM];
	size_t account_group__num;
	int64_t account_groups[MAX_GROUP_COUNT];
//	int64_t slave_ids[MAX_SLAVE_NUM];
} DeviceMaster;
////////////////////////////////////////////////////////////////////////////////

//TODO 考虑函数的参数与返回值
typedef int (*FunctionPointer)();

typedef struct function_instance_t {
	int64_t instance_id;
	int64_t create_time;
	int64_t start_time;
	int64_t device_id;
	int32_t slave_id;
	bool async;
	bool result;
	char func_name[MAX_FUNC_NAME_SIZE];
	Function fun;
//TODO	char group_name[MAX_GROUP_NAME_SIZE];
	FunctionPointer fp;
} FunctionInstance;

#endif /* ANI_INCLUDE_DEVICE_H_ */
