/*
 * AlarmService.cpp
 *
 *  Created on: 9 gru 2019
 *      Author: dom
 *
 */

#include <iostream>

#include "AlarmService.h"
#include "AlarmSensor.h"

using namespace std;

Status AlarmService::enableAlarm()
{
	Status status = STATUS_OK;

	synch.lock();

	if (isAlarmArmed)
	{
		for (auto &sensor : alarmSensors)
		{
			sensor->triggerAlarm();
		}
	}

	synch.unlock();

	return status;
}


Status AlarmService::disableAlarm()
{
	Status status = STATUS_OK;

	synch.lock();

	for (auto &sensor : alarmSensors)
		if (STATUS_OK != sensor->disableAlarm())
			status = STATUS_GENERIC_ERR;

	synch.unlock();

	return status;
}

Status AlarmService::enableService()
{
	synch.lock();

	isAlarmArmed = true;

	synch.unlock();

	return STATUS_OK;
}

Status AlarmService::disableService(string code)
{
	synch.lock();
	Status status = STATUS_OK;
	SettingParameters configCode = dynamic_pointer_cast<DevicesConfiguration>(deviceConfiguration)->getSettingValue("code");

	if ((configCode.status == STATUS_OK) && ( 0 == code.compare(configCode.value)))
	{
		status = disableAlarm();
		if (STATUS_OK == status)
			isAlarmArmed = false;
	}
	else
	{
		status = STATUS_AUTH_ERR;
	}

	synch.unlock();

	return status;
}

DeviceInfoData AlarmService::getData(const int deviceId)
{
	//todo: this function shall report if threshold for particular sensor is exceeded.
}

Status AlarmService::setData(const int deviceId, DeviceInfoData data)
{
	Status status = STATUS_OK;

	synch.lock();

	try
	{
		SensorParameters configData = any_cast<SensorParameters>(deviceConfiguration->getData(deviceId));
		SensorReading readingData = any_cast<SensorReading>(data);

		cout << "SensorId ( " << configData.sensorName << ") = " << deviceId << " Value =" <<  readingData.lastReadingValue << " threshold = " <<  configData.enableThresholdValue << endl;
		if((readingData.status == STATUS_OK) && (readingData.lastReadingValue > configData.enableThresholdValue))
		{
			enableAlarm();
		}
		else if (readingData.status != STATUS_OK)
		{
			//todo: log critical event - sensor issue
		}
	}
	catch (bad_any_cast &e)
	{
		//todo: log this unexpected case
	}

	synch.unlock();

	return status;
}

void AlarmService::prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device)
{
	SensorParameters sensorConfiguration;

	synch.lock();

	auto sensor = dynamic_pointer_cast<AlarmSensor>(device);

	if (sensor != nullptr)
	{
		alarmSensors.push_back(sensor);
	}

	synch.unlock();
}

AlarmService::AlarmService()
{
	deviceConfiguration = DevicesConfiguration::getInstance();
	isAlarmArmed = false;
}

shared_ptr<AlarmService> AlarmService::getInstance()
{
	synch.lock();

	if (nullptr == instance)
	{
		instance = static_cast<shared_ptr<AlarmService> >(new AlarmService());
	}

	synch.unlock();

	return instance;
}

shared_ptr<AlarmService> AlarmService::instance = nullptr;
recursive_mutex AlarmService::synch;
