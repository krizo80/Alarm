/*
 * SensorEventsDatabase.cpp
 *
 *  Created on: 16 lis 2019
 *      Author: dom
 */



#include "SensorEventsDatabase.h"

DeviceInfoData SensorEventsDatabase::getData(const int deviceId)
{
	SensorReading reading = {};

	if (lastSensorsEvents.find(deviceId) == lastSensorsEvents.end())
	{
		reading.status = STATUS_SENSOR_NOT_EXIST;
	}
	else
	{
		reading = lastSensorsEvents[deviceId];
	}

	return reading;
}

Status SensorEventsDatabase::setData(const int deviceId, DeviceInfoData data)
{
	Status status = STATUS_OK;
	try
	{
		lastSensorsEvents[deviceId] = any_cast<SensorReading>(data);
	}
	catch(bad_any_cast &e)
	{
		status = STATUS_READING_EXCEPTION;
	}

	return status;
}


map<int, SensorReading> SensorEventsDatabase::lastSensorsEvents;
