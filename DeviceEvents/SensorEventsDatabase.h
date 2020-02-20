/*
 * SensorEventsDatabase.h
 *
 *  Created on: 16 lis 2019
 *      Author: dom
 */

#ifndef DEVICEEVENTS_SENSOREVENTSDATABASE_H_
#define DEVICEEVENTS_SENSOREVENTSDATABASE_H_

#include <DeviceServiceInterface.h>
#include <map>
#include <any>

class SensorEventsDatabase : public DeviceServiceInterface
{
	private:
		static map<int, SensorReading> lastSensorsEvents;

	public:
		DeviceInfoData getData(const int deviceId) override;
		Status setData(const int deviceId, DeviceInfoData data) override;

		void prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device) override{};
		Status enableService() override{ return STATUS_OK; };
		Status disableService(string code) override{ return STATUS_OK; };

		virtual ~SensorEventsDatabase() {}
};



#endif /* DEVICEEVENTS_SENSOREVENTSDATABASE_H_ */
