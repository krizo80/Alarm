/*
 * SensorEventsDatabase.h
 *
 *  Created on: 16 lis 2019
 *      Author: dom
 */

#ifndef DEVICEEVENTS_SENSOREVENTSDATABASE_H_
#define DEVICEEVENTS_SENSOREVENTSDATABASE_H_

#include "DeviceInfo.h"
#include <map>
#include <any>

class SensorEventsDatabase : public DeviceInfo
{
	private:
		static map<int, SensorReading> lastSensorsEvents;

	public:
		DeviceInfoData getData(const int deviceId) override;
		Status setData(const int deviceId, DeviceInfoData data) override;


};



#endif /* DEVICEEVENTS_SENSOREVENTSDATABASE_H_ */
