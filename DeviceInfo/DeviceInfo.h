/*
 * DeviceInfo.h
 *
 *  Created on: 13 lis 2019
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICEINFO_H_
#define DEVICEINFO_DEVICEINFO_H_

#include "CommonDefs.h"

class DeviceInfo
{
	public:
		virtual DeviceInfoData getData(const int deviceId) = 0;
		virtual Status setData(const int deviceId, DeviceInfoData data) = 0;

};


#endif /* DEVICEINFO_DEVICEINFO_H_ */
