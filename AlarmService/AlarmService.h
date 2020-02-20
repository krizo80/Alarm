/*
 * AlarmService.h
 *
 *  Created on: 9 gru 2019
 *      Author: dom
 */

#ifndef ALARMSERVICE_ALARMSERVICE_H_
#define ALARMSERVICE_ALARMSERVICE_H_

#include <DeviceInterface.h>
#include <DeviceServiceInterface.h>
#include <list>
#include "CommonDefs.h"
#include "DevicesConfiguration.h"
#include "AlarmTriggerInterface.h"
#include <mutex>

using namespace std;

class AlarmService: public DeviceServiceInterface
{
	private:
		shared_ptr<DeviceInfoInterface> deviceConfiguration;
		Status enableAlarm();
		Status disableAlarm();
		list<shared_ptr<AlarmTriggerInterface> > alarmSensors;
		bool isAlarmArmed;

		AlarmService();

		static shared_ptr<AlarmService> instance;
		static recursive_mutex synch;

	public:
		virtual ~AlarmService() {}

		DeviceInfoData getData(const int deviceId) override;
		Status setData(const int deviceId, DeviceInfoData data) override;
		void prepareDeviceInfoSetup(const int deviceId, const shared_ptr<DeviceInterface> device) override;
		Status enableService() override;
		Status disableService(string code) override;

		static shared_ptr<AlarmService> getInstance();
};


#endif /* ALARMSERVICE_ALARMSERVICE_H_ */
