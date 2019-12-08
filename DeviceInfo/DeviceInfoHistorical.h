/*
 * DeviceInfoHistorical.h
 *
 *  Created on: 29 lis 2019
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICEINFOHISTORICAL_H_
#define DEVICEINFO_DEVICEINFOHISTORICAL_H_


#include "CommonDefs.h"

class DeviceInfoHistorical
{
	public:
		virtual DeviceInfoData getHistoricalData(const int deviceId) = 0;
};



#endif /* DEVICEINFO_DEVICEINFOHISTORICAL_H_ */
