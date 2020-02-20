/*
 * DeviceSetup.h
 *
 *  Created on: 5 lut 2020
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICETSETUPINTERFACE_H_
#define DEVICEINFO_DEVICETSETUPINTERFACE_H_

#include <DeviceInterface.h>
#include <memory>
#include "CommonDefs.h"

class DeviceSetupInterface
{
	public:
		virtual void prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device) = 0;
};



#endif /* DEVICEINFO_DEVICETSETUPINTERFACE_H_ */
