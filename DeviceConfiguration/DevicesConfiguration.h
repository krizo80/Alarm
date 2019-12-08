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
#include "DeviceInfo.h"
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <iterator>
#include <memory>



using namespace std;


class DevicesConfiguration: public DeviceInfo
{
	private:
		static constexpr int DeviceIDNotInitialized = -1;
		static DevicesConfiguration *configInstace;
		static recursive_mutex synch;


		vector<shared_ptr<ConfigurationEntry>> configurationEntries;
		int currentElementIndex;
		//DevicesConfiguration(Parser &parser);
		DevicesConfiguration(shared_ptr<Parser> parser);

	public:
		vector<shared_ptr<ConfigurationEntry>> getDevicesConfiguration() const;
		shared_ptr<ConfigurationEntry> getConfigByDeviceId(const int deviceId) const;
		static DevicesConfiguration *getInstance();
		DeviceInfoData getData(const int deviceId) override;
		Status setData(const int deviceId, DeviceInfoData data) override;
};



#endif /* DEVICECONFIGURATION_DEVICESCONFIGURATION_H_ */
