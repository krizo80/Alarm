/*
 * ConfigurationEntry.cpp
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */



#include "ConfigurationEntry.h"

ConfigurationEntry::ConfigurationEntry(int deviceId, SensorParameters parameters)
{
	this->deviceId = deviceId;
	this->parameters = parameters;
}

