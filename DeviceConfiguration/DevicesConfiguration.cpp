/*
 * DevicesConfiguration.cpp
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */


#include "DevicesConfiguration.h"

using namespace std;


DevicesConfiguration::DevicesConfiguration(shared_ptr<Parser> parser)
{
	int deviceId = DeviceIDNotInitialized;
	SensorParameters sensorParam = parser->getFirstSensorEntry();

	configurationEntries.clear();
	currentElementIndex = 0;

	//read configuration file and prepare configuration structure
	while (sensorParam.status != STATUS_XML_NO_MORE_SENSORS)
	{
		deviceId++;
		configurationEntries.push_back(make_shared<ConfigurationEntry>(deviceId, sensorParam));
		cout << sensorParam.sensorName << endl;
		sensorParam = parser->getNextSensorEntry();
	}
}

list<shared_ptr<ConfigurationEntry>> DevicesConfiguration::getDevicesConfiguration() const
{
	return configurationEntries;
}

ConfigurationEntry DevicesConfiguration::getConfigByDeviceId(const int deviceId) const
{


}

DevicesConfiguration* DevicesConfiguration::getInstance()
{
	synch.lock();

	if (configInstace == nullptr)
	{
		configInstace = new DevicesConfiguration(make_shared<XmlParser>("Alarm.xml"));
	}

	synch.unlock();
	return configInstace;
}


ConfigurationEntry DevicesConfiguration::getFirstConfigElement()
{
	currentElementIndex = 0;
	//configurationEntries.
}

ConfigurationEntry DevicesConfiguration::getNextConfigElement()
{

}



DevicesConfiguration *DevicesConfiguration::configInstace = nullptr;
mutex DevicesConfiguration::synch;

