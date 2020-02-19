/*
 * DeviceSetup.h
 *
 *  Created on: 5 lut 2020
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICESETUP_H_
#define DEVICEINFO_DEVICESETUP_H_

#include <memory>
#include "CommonDefs.h"
#include "Device.h"

class DeviceSetup
{
	public:
		virtual void prepareDeviceInfoSetup(const int deviceId, const shared_ptr<Device> device) = 0;
};



#endif /* DEVICEINFO_DEVICESETUP_H_ */
