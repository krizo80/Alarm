/*
 * SensorEventsDatabase.cpp
 *
 *  Created on: 16 lis 2019
 *      Author: dom
 */



#include "SensorEventsDatabase.h"
#include "ReadingConverter.h"
#include <chrono>
#include <ratio>

using namespace std;

DeviceInfoData SensorEventsDatabase::getData(const int deviceId)
{
	DatabaseReadingEntry readingEntry = {};

	if (lastSensorsEvents.find(deviceId) == lastSensorsEvents.end())
	{
		if (deviceId > lastDeviceIdx)
		{
			readingEntry.reading.status = STATUS_XML_NO_MORE_SENSORS;
		}
		else
		{
			readingEntry.reading.status = STATUS_SENSOR_NOT_EXIST;
		}
	}
	else
	{
		readingEntry = lastSensorsEvents[deviceId];
	}

	return readingEntry;
}

void SensorEventsDatabase::prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device)
{
	DatabaseReadingEntry data;

	//initialize sensors reading data
	data.reading = device->getDeviceReading();
	data.isSensorGeneratingAlarm = false;
	lastSensorsEvents[deviceId] = data;
}

Status SensorEventsDatabase::setData(const int deviceId, DeviceInfoData data)
{
	Status status = STATUS_OK;
	ReadingConverter reading;
	auto timeStamp = chrono::high_resolution_clock::now();
    //todo: deviceId is not checked against overflow
	auto duration_msec = chrono::duration_cast<chrono::milliseconds>(timeStamp  - lastSensorsEvents[deviceId].lastExecedThrReadingTimestamp);

	try
	{
		if (lastSensorsEvents[deviceId].reading.status == STATUS_OK)
		{
			auto thresholdExceded = reading.ConvertReadingToAlarm(any_cast<SensorReading>(data), any_cast<SensorParameters>(deviceConfiguration->getData(deviceId)).enableThresholdValue);
			if( true == thresholdExceded )
			{
				if (false == lastSensorsEvents[deviceId].isValidExecedTimeStamp)
				{
					lastSensorsEvents[deviceId].lastExecedThrReadingTimestamp = timeStamp;
					lastSensorsEvents[deviceId].isValidExecedTimeStamp = true;
				}
				lastSensorsEvents[deviceId].isSensorGeneratingAlarm = true;
			}
			else if ((true == lastSensorsEvents[deviceId].isValidExecedTimeStamp) &&
					(duration_msec.count() > timeOfPresenceSec))
			{
				lastSensorsEvents[deviceId].isValidExecedTimeStamp = false;
				lastSensorsEvents[deviceId].isSensorGeneratingAlarm = false;
			}

			lastSensorsEvents[deviceId].readingTimestamp = timeStamp;
			lastSensorsEvents[deviceId].reading = any_cast<SensorReading>(data);

			if(lastDeviceIdx < deviceId)
			{
				lastDeviceIdx = deviceId;
			}
		}
	}
	catch(bad_any_cast &e)
	{
		status = STATUS_READING_EXCEPTION;
	}

	return status;
}

SensorEventsDatabase::SensorEventsDatabase()
{
	deviceConfiguration = DevicesConfiguration::getInstance();
	try
	{
		timeOfPresenceSec = 0;
		timeOfPresenceSec = stoi(deviceConfiguration->getSettingValue("timeOfPresenceSec").value);
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

