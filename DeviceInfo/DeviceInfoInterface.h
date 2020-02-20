/*
 * DeviceInfo.h
 *
 *  Created on: 13 lis 2019
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICEINFOINTERFACE_H_
#define DEVICEINFO_DEVICEINFOINTERFACE_H_

#include <DeviceInterface.h>
#include <memory>
#include "CommonDefs.h"

class DeviceInfoInterface
{
	public:
		virtual DeviceInfoData getData(const int deviceId) = 0;
		virtual Status setData(const int deviceId, DeviceInfoData data) = 0;
};


#endif /* DEVICEINFO_DEVICEINFOINTERFACE_H_ */
