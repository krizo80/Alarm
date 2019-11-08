/*
 * ConfigurationEntry.h
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_CONFIGURATIONENTRY_H_
#define DEVICECONFIGURATION_CONFIGURATIONENTRY_H_

#include <string>
#include "CommonDefs.h"

using namespace std;


class ConfigurationEntry
{
	private:
		int deviceId;
		SensorParameters parameters;

	public:
		ConfigurationEntry(int deviceId, SensorParameters parameters);
		SensorParameters getSensorParameters() const { return parameters; }
		int getDeviceId() const { return deviceId;}

};
#endif /* DEVICECONFIGURATION_CONFIGURATIONENTRY_H_ */
