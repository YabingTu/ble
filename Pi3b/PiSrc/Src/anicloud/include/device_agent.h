/*
 * ============================================================================
 * Name          : device_agent.h
 * Version       : 0.0.1
 * Author        : ben
 * Created on    : 2016/6/21
 * Last Modified : 2016/8/23
 * Copyright     : Anicloud Limited ©2016
 * Description   :
 * ============================================================================
 */

#ifndef ANI_DEVICE_AGENT_H_
#define ANI_DEVICE_AGENT_H_
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include <time.h>

#include "device.h"

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/**
 * 调用接口返回的状态
 */
typedef enum Status {
	//调用接口函数成功
	SUCCESSFULLY,

	//调用接口所给参数错误
	PARAMETER_ERROR,

	//函数使用逻辑不正确，一般是指没有满足执行函数所需的先决条件
	LOGIC_ERROR,

	//初始化错误
	INIT_ERROR,

	//与平台连接错误
	CONNECT_ERROR,

	//注册过程出错
	REGISTER_ERROR,

	//认证过程出错
	AUTH_ERROR,

	//更新过程出错
	UPDATE_ERROR,

	//关闭连接出错
	CLOSE_ERROR,

	//调用过程出错
	INVOKE_ERROR,

	//未知错误
	UNKNOWN_ERROR
} Status;
////////////////////////////////////////////////////////////////////////////////

/**
 * 获取Status对应的字符串
 */
const char* strstatus(Status s);

Status InitAgent(const DeviceMaster *dm, const FunctionInstance *funcs, int funcnt);

Status ConnectToAnicloud();

Status RegisterDevice();

Status AuthDevice();

Status UpdateDevice();

Status DisConnectToAnicloud();


//Status
////////////////////////////////////////////////////////////////////////////////

/*
 * 获取当前时间距1970-1-1 0:0:0.000的毫秒数
 * TODO 目前只是近似实现，以后再看是否需要改进
 */
inline uint64_t GetCurrentTimeMillis() {
	time_t timestamp;
	time(&timestamp);
	return timestamp * 1000 + clock() % 1000;
}

////////////////////////////////////////////////////////////////////////////////

#endif /* ANI_DEVICE_AGENT_H_ */
