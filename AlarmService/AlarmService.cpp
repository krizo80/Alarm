/*
 * AlarmService.cpp
 *
 *  Created on: 9 gru 2019
 *      Author: dom
 */



#include <iostream>
#include "AlarmService.h"

using namespace std;

DeviceInfoData AlarmService::getData(const int deviceId)
{
	//todo: this function shall report if threshold for particular sensor is exceeded.
}

Status AlarmService::setData(const int deviceId, DeviceInfoData data)
{
	cout << "!!!!!!!!!!!!! = " << deviceId << endl;
}

AlarmService::AlarmService()
{
	//1. go through devices and create list of AlarmSensors
	deviceConfiguration = DevicesConfiguration::getInstance();
}
