/*
 * DeviceInfoRegister.cpp
 *
 *  Created on: 14 lis 2019
 *      Author: dom
 */


#include "DeviceInfoRegister.h"
#include "DevicesConfiguration.h"
#include "SensorEventsDatabase.h"
#include "ReadingConverter.h"

using namespace std;

DeviceInfoRegister::DeviceInfoRegister()
{
	deviceInfoSource.push_back(DevicesConfiguration::getInstance());
	//todo: provide destructor
	deviceInfoSource.push_back(new SensorEventsDatabase());
}

map<string,string> DeviceInfoRegister::getConfigurationDeviceInfo(int deviceId)
{
	map<string,string> result;
	SensorParameters config = any_cast<SensorParameters>(deviceInfoSource[0]->getData(deviceId));

	result["name"] = config.sensorName;
	result["enable"] = to_string(static_cast<int>(config.enabled));
	result["address"] = to_string(config.sensorAddress);
	result["sensorType"] = to_string(config.sensorType);
	result["scanningPeriod"] = to_string(config.scanningPeriod);
	result["status"] = to_string(config.status);
	return result;
}

map<string,string> DeviceInfoRegister::getReadingDeviceInfo(int deviceId)
{
	map<string,string> result;
	ReadingConverter converter;
	SensorReading reading = any_cast<SensorReading>(deviceInfoSource[1]->getData(deviceId));

	result["value"] = converter.ConvertReadingToString(reading);
	result["status"] = converter.ConvertStatusToString(reading);

	return result;
}


