/*
 * SensorEventsDatabase.cpp
 *
 *  Created on: 16 lis 2019
 *      Author: dom
 */



#include "SensorEventsDatabase.h"

using namespace std;

DeviceInfoData SensorEventsDatabase::getData(const int deviceId)
{
	SensorReading reading = {};

	if (lastSensorsEvents.find(deviceId) == lastSensorsEvents.end())
	{
		reading.status = STATUS_SENSOR_NOT_EXIST;
	}
	else
	{
		reading = lastSensorsEvents[deviceId].reading;
	}

	return reading;
}

void SensorEventsDatabase::prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device)
{
	DatabaseReadingEntry data;

	//initialize sensors reading data
	data.reading = device->getDeviceReading();
	data.isSensorGeneratingAlarm = false;
	data.readingTimestamp= 0;

	lastSensorsEvents[deviceId] = data;
}

Status SensorEventsDatabase::setData(const int deviceId, DeviceInfoData data)
{
	Status status = STATUS_OK;
	try
	{
		lastSensorsEvents[deviceId].reading = any_cast<SensorReading>(data);

		//if readingTimestamp + time_from_config > current_ts
		lastSensorsEvents[deviceId].isSensorGeneratingAlarm = false;
		//else if reading is status_ok && reading_type alarm && readng == 1
		lastSensorsEvents[deviceId].isSensorGeneratingAlarm = true;

		lastSensorsEvents[deviceId].readingTimestamp = 0;
		//todo: add timestamp, and calculate isSensorGeneratingAlarm depends settings
	}
	catch(bad_any_cast &e)
	{
		status = STATUS_READING_EXCEPTION;
	}

	return status;
}

SensorEventsDatabase::SensorEventsDatabase()
{
	shared_ptr<ConfigSettingInterface> configurationSettings = DevicesConfiguration::getInstance();

	try
	{
		timeOfPresenceSec = stoi(configurationSettings->getSettingValue("timeOfPresenceSec").value);
	}
	catch (invalid_argument& e)
	{
		timeOfPresenceSec = 0;
		//todo: log error
	}
}

shared_ptr<SensorEventsDatabase> SensorEventsDatabase::getInstance()
{
	synch.lock();

	if (nullptr == instance)
	{
		instance = static_cast<shared_ptr<SensorEventsDatabase> >(new SensorEventsDatabase());
	}

	synch.unlock();

	return instance;
}


shared_ptr<SensorEventsDatabase> SensorEventsDatabase::instance = nullptr;
recursive_mutex SensorEventsDatabase::synch;

