/*
 * DeviceInfoRegister.h
 *
 *  Created on: 14 lis 2019
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICEINFOREGISTER_H_
#define DEVICEINFO_DEVICEINFOREGISTER_H_

#include <vector>
#include <map>
#include <memory>
#include <array>
#include <functional>
#include "DeviceInfo.h"

using namespace std;

class DeviceInfoRegister
{
	private:
		vector<shared_ptr<DeviceInfo>> deviceInfoSource;

	public:
		DeviceInfoRegister();
		map<string,string> getConfigurationDeviceInfo(int deviceId);
		map<string,string> getReadingDeviceInfo(int deviceId);
};


#endif /* DEVICEINFO_DEVICEINFOREGISTER_H_ */
