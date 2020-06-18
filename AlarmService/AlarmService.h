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
#include <map>
#include <mutex>
#include "CommonDefs.h"
#include "DevicesConfiguration.h"
#include "AlarmTriggerInterface.h"
#include "CallbackCaller.h"
#include "CallbackInterface.h"

using namespace std;

class AlarmService: public DeviceServiceInterface, CallbackInterface
{
	private:
		shared_ptr<DeviceInfoInterface> deviceConfiguration;
		list<shared_ptr<AlarmTriggerInterface> > alarmSensors;
		bool isAlarmArmed;
		int maxSensorIdx;
		int waitingTimeInSec;
		int countOfAlarmTiggerInSec;
		map<int, AlarmReading> alerts;
		static shared_ptr<AlarmService> instance;
		static recursive_mutex synch;



		AlarmService();

		Status disableAlarm();
		Status enableAlarm();
		Status callbackFunction();


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
