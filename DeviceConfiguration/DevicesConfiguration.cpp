/*
 * DevicesConfiguration.cpp
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */


#include "DevicesConfiguration.h"
#include "XmlParser.h"
#include <any>

using namespace std;


DevicesConfiguration::DevicesConfiguration(shared_ptr<Parser> parser)
{
	int deviceId = DeviceIDNotInitialized;

	try
	{
		SensorParameters sensorParam = parser->getFirstSensorEntry();

		configurationEntries.clear();
		currentElementIndex = 0;

		//read configuration file and prepare configuration structure
		while (sensorParam.status != STATUS_XML_NO_MORE_SENSORS)
		{
			deviceId++;
			configurationEntries.push_back(make_shared<ConfigurationEntry>(deviceId, sensorParam));
			sensorParam = parser->getNextSensorEntry();
		}
	}
	catch (exception &e)
	{
		throw;
	}
}

vector<shared_ptr<ConfigurationEntry>> DevicesConfiguration::getDevicesConfiguration() const
{
	return configurationEntries;
}

shared_ptr<ConfigurationEntry> DevicesConfiguration::getConfigByDeviceId(const int deviceId) const
{
	shared_ptr<ConfigurationEntry> configEntry;

	synch.lock();

	if (deviceId >= configurationEntries.size())
	{
		SensorParameters errorResult = {};
		errorResult.status = STATUS_SENSOR_NOT_EXIST;
		configEntry = make_shared<ConfigurationEntry>(deviceId,errorResult);
	}
	else
	{
		configEntry = configurationEntries[deviceId];
	}

	synch.unlock();

	return configEntry;
}



DevicesConfiguration* DevicesConfiguration::getInstance()
{
	synch.lock();

	try
	{
		if (configInstace == nullptr)
		{
			configInstace = new DevicesConfiguration(make_shared<XmlParser>("Alarm.xml"));
		}
	}
	catch(const exception &e)
	{
		std::cerr << e.what();
	}

	synch.unlock();
	return configInstace;
}


DeviceInfoData DevicesConfiguration::getData(const int deviceId)
{
	DeviceInfoData config;

	synch.lock();
	config = this->getConfigByDeviceId(deviceId)->getSensorParameters();
	synch.unlock();

	return config;
}

//todo: change configuration settings
Status DevicesConfiguration::setData(const int deviceId, DeviceInfoData data)
{
	Status status = STATUS_OK;
	synch.lock();

	synch.unlock();
	return status;
}

DevicesConfiguration *DevicesConfiguration::configInstace = nullptr;
recursive_mutex DevicesConfiguration::synch;

