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

class DeviceSetupInterface :  public DeviceInfoInterface
{
	public:
		virtual void prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device) = 0;
		virtual void setupNewReadingValue(const int deviceId, const int reading) {}
		virtual void clearNewReadingValue(const int deviceId) {}
};



#endif /* DEVICEINFO_DEVICETSETUPINTERFACE_H_ */
