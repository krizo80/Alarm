/*
 * DeviceInfoRegister.h
 *
 *  Created on: 14 lis 2019
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICEINFOREGISTER_H_
#define DEVICEINFO_DEVICEINFOREGISTER_H_

#include <DeviceInfoInterface.h>
#include <vector>
#include <map>
#include <memory>
#include <array>
#include <functional>

using namespace std;

class DeviceInfoRegister
{
	private:
		vector<shared_ptr<DeviceInfoInterface>> deviceInfoSource;

	public:
		DeviceInfoRegister();
		map<string,string> getConfigurationDeviceInfo(int deviceId);
		map<string,string> getReadingDeviceInfo(int deviceId);

		map<string,string> getPresenceDeviceInfo(int deviceId);
};


#endif /* DEVICEINFO_DEVICEINFOREGISTER_H_ */
