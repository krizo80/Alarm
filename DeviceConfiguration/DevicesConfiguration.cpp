/*
 * DevicesConfiguration.cpp
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */


#include <XmlParser.h>
#include "DevicesConfiguration.h"
#include <any>

using namespace std;


DevicesConfiguration::DevicesConfiguration(shared_ptr<ParserInterface> parser)
{
	int deviceId = DeviceIDNotInitialized;

	try
	{
		SensorParameters sensorParam = parser->getFirstSensorEntry();

		configurationEntries.clear();

		//read configuration file and prepare sensors structure
		while (sensorParam.status != STATUS_XML_NO_MORE_SENSORS)
		{
			deviceId++;
			configurationEntries.push_back(make_shared<ConfigurationEntry>(deviceId, sensorParam));
			sensorParam = parser->getNextSensorEntry();
		}

		SettingParameters settingParam = parser->getFirstSettingEntry();
		settingEntries.clear();

		//read configuration file and prepare settings structure
		while (settingParam.status != STATUS_XML_NO_MORE_SETTINGS)
		{
			settingEntries.push_back(settingParam);
			settingParam = parser->getNextSettingEntry();
		}

	}
	catch (exception &e)
	{
		//todo: make clean - remove throw
		throw;
	}
}

shared_ptr<ConfigurationEntry> DevicesConfiguration::getConfigByDeviceId(const int deviceId) const
{
	shared_ptr<ConfigurationEntry> configEntry;

	synch.lock();

	if (deviceId >= static_cast<int>(configurationEntries.size()))
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



shared_ptr<DevicesConfiguration> DevicesConfiguration::getInstance()
{
	synch.lock();

	try
	{
		if (configInstace == nullptr)
		{
			configInstace = static_cast<shared_ptr<DevicesConfiguration>  >(new DevicesConfiguration(make_shared<XmlParser>("Alarm.xml")));
		}
	}
	catch(const exception &e)
	{
		//todo: report exception
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

SettingParameters DevicesConfiguration::getSettingValue(string name)
{
	SettingParameters retValue;

	synch.lock();

	retValue.status = STATUS_SETTING_NOT_EXIST;
	for (auto setting: settingEntries)
	{
		if (setting.settingName == name)
			retValue = setting;
	}

	synch.unlock();

	return retValue;

}

shared_ptr<DevicesConfiguration> DevicesConfiguration::configInstace = nullptr;
recursive_mutex DevicesConfiguration::synch;

