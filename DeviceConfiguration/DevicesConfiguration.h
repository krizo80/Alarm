/*
 * DevicesConfiguration.h
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_DEVICESCONFIGURATION_H_
#define DEVICECONFIGURATION_DEVICESCONFIGURATION_H_

#include "ConfigurationEntry.h"
#include "Parser.h"
#include "XmlParser.h"
#include "CommonDefs.h"
#include <mutex>
#include <thread>
#include <list>
#include <iostream>
#include <iterator>



using namespace std;


class DevicesConfiguration
{
	private:
		static constexpr int DeviceIDNotInitialized = -1;
		static DevicesConfiguration *configInstace;
		static mutex synch;

		list<shared_ptr<ConfigurationEntry>> configurationEntries;
		int currentElementIndex;
		//DevicesConfiguration(Parser &parser);
		DevicesConfiguration(shared_ptr<Parser> parser);

	public:
		list<shared_ptr<ConfigurationEntry>> getDevicesConfiguration() const;
		ConfigurationEntry getConfigByDeviceId(const int deviceId) const;
		ConfigurationEntry getFirstConfigElement();
		ConfigurationEntry getNextConfigElement();
		static DevicesConfiguration *getInstance();
};



#endif /* DEVICECONFIGURATION_DEVICESCONFIGURATION_H_ */
