/*
 * SensorEventsDatabase.h
 *
 *  Created on: 16 lis 2019
 *      Author: dom
 */

#ifndef DEVICEEVENTS_SENSOREVENTSDATABASE_H_
#define DEVICEEVENTS_SENSOREVENTSDATABASE_H_

#include <DeviceServiceInterface.h>
#include "DevicesConfiguration.h"
#include <map>
#include <iostream>
#include <any>

class SensorEventsDatabase : public DeviceSetupInterface
{
	private:
		map<int, DatabaseReadingEntry> lastSensorsEvents;
		int timeOfPresenceSec;
		int lastDeviceIdx;
		shared_ptr<DevicesConfiguration> deviceConfiguration;

		static shared_ptr<SensorEventsDatabase> instance;
		static recursive_mutex synch;

		SensorEventsDatabase();

	public:
		DeviceInfoData getData(const int deviceId) override;
		Status setData(const int deviceId, DeviceInfoData data) override;

		void prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device) override;

		static shared_ptr<SensorEventsDatabase> getInstance();
		virtual ~SensorEventsDatabase() {}
};



#endif /* DEVICEEVENTS_SENSOREVENTSDATABASE_H_ */
