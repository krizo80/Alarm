/*
 * DeviceRegister.cpp
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */
#include "DeviceRegister.h"
#include "MoveSensor.h"
#include "TempSensor.h"
#include "DevicesConfiguration.h"

DevicesRegister::DevicesRegister()
{
	deviceRegister.clear();
}


void DevicesRegister::registerDevices()
{
	DevicesConfiguration *config = DevicesConfiguration::getInstance();

	for (auto &configElement : config->getDevicesConfiguration())
	{
		if (true == configElement->getSensorParameters().enabled)
		{
			deviceRegister[configElement->getDeviceId()] =
					deviceType[configElement->getSensorParameters().readingType](configElement->getSensorParameters().sensorAddress);
		}
	}
}

const vector<int> DevicesRegister::getRegistredDevicesId()
{
	vector<int> devicesId;

	for (auto &deviceElement : deviceRegister)
	{
		devicesId.push_back(deviceElement.first);
	}

	return devicesId;
}

const shared_ptr<Device> DevicesRegister::getRegisteredDevice(const int deviceId)
{
	return deviceRegister[deviceId];
}


array<function<shared_ptr<Device>(int)>, 5> DevicesRegister::deviceType =
{
		[](int address)->shared_ptr<Device> { return make_shared<MoveSensor>(address); },
		[](int address)->shared_ptr<Device> { return make_shared<TempSensor>(address); },
		[](int address)->shared_ptr<Device> { return make_shared<MoveSensor>(address); },
		[](int address)->shared_ptr<Device> { return make_shared<MoveSensor>(address); },
		[](int address)->shared_ptr<Device> { return make_shared<MoveSensor>(address); }
};

