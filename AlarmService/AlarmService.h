/*
 * AlarmService.h
 *
 *  Created on: 9 gru 2019
 *      Author: dom
 */

#ifndef ALARMSERVICE_ALARMSERVICE_H_
#define ALARMSERVICE_ALARMSERVICE_H_

#include "DeviceInfo.h"
#include "CommonDefs.h"
#include "DevicesConfiguration.h"

class AlarmService: public DeviceInfo
{
	private:
		DeviceInfo *deviceConfiguration;

	public:
		AlarmService();
		DeviceInfoData getData(const int deviceId);
		Status setData(const int deviceId, DeviceInfoData data);
};


#endif /* ALARMSERVICE_ALARMSERVICE_H_ */
