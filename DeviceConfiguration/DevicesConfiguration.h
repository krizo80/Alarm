/*
 * DevicesConfiguration.h
 *
 *  Created on: 20 paź 2019
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_DEVICESCONFIGURATION_H_
#define DEVICECONFIGURATION_DEVICESCONFIGURATION_H_

#include <ConfigSettingInterface.h>
#include <DeviceInfoInterface.h>
#include <ParserInterface.h>
#include "ConfigurationEntry.h"
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <iterator>
#include <memory>



using namespace std;


class DevicesConfiguration: public DeviceInfoInterface, public ConfigSettingInterface
{
	private:
		static constexpr int DeviceIDNotInitialized = -1;
		static shared_ptr<DevicesConfiguration> configInstace;
		static recursive_mutex synch;

		vector<shared_ptr<ConfigurationEntry>> configurationEntries;
		vector<SettingParameters> settingEntries;

		DevicesConfiguration(shared_ptr<ParserInterface> parser);
		shared_ptr<ConfigurationEntry> getConfigByDeviceId(const int deviceId) const;

	public:
		static shared_ptr<DevicesConfiguration> getInstance();

		DeviceInfoData getData(const int deviceId) override;
		Status setData(const int deviceId, DeviceInfoData data) override;

		SettingParameters getSettingValue(string name) override;

		virtual ~DevicesConfiguration() {}
};



#endif /* DEVICECONFIGURATION_DEVICESCONFIGURATION_H_ */
