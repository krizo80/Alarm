/*
 * DeviceRegister.cpp
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */


#include "DeviceRegister.h"

DevicesRegister::DevicesRegister()
{
	deviceRegister.clear();
}


void DevicesRegister::registerDevices()
{
	DevicesConfiguration *config = DevicesConfiguration::getInstance();

	for (auto &configElement : config->getDevicesConfiguration())
	{
		deviceRegister[configElement->getDeviceId()] = deviceType[configElement->getSensorParameters().readingType];
	}

	//only for debug purpose
	for (auto el : deviceRegister)
	{
		cout << el.first << " " << el.second->getDeviceReading() << endl;
	}
}

/*
 * void DevicesRegister::printDeviceList()
{
	for (auto it :devRegister)
	{
		it->getDeviceReading();
	}
}
 */



array<shared_ptr<Device>, 5> DevicesRegister::deviceType =
{
		[]()->shared_ptr<Device> { return make_shared<MoveSensor>(); }(),
		[]()->shared_ptr<Device> { return make_shared<MoveSensor>(); }(),
		[]()->shared_ptr<Device> { return make_shared<MoveSensor>(); }(),
		[]()->shared_ptr<Device> { return make_shared<MoveSensor>(); }(),
		[]()->shared_ptr<Device> { return make_shared<MoveSensor>(); }()
};
