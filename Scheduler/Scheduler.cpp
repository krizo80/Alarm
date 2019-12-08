/*
 * Scheduler.cpp
 *
 *  Created on: 17 paź 2019
 *      Author: dom
 */


#include "Scheduler.h"
#include "DevicesConfiguration.h"
#include "SensorEventsDatabase.h"



int  Scheduler::schedulerThreadFunction()
{
	int tenthOfmilisec = 0;
	DevicesRegister devRegister;
	DeviceInfo *deviceConfiguration = DevicesConfiguration::getInstance();
	vector<int> devicesId;
	int scanningPeriod = 0;

	devRegister.registerDevices();
	devicesId = devRegister.getRegistredDevicesId();

	//start to read sensors
	while(1)
	{

		for (auto &deviceId : devicesId)
		{
			try
			{
				scanningPeriod = any_cast<SensorParameters>(deviceConfiguration->getData(deviceId)).scanningPeriod;
			}
			catch(bad_any_cast &e)
			{
				//todo:wrong reading - log it
			}

			if (0 == (tenthOfmilisec % scanningPeriod))
			{
				///todo:handle the status (may return value different then success)
				//feed all connected sources
				for (auto &source : readingSources)
					source->setData(deviceId,devRegister.getRegisteredDevice(deviceId)->getDeviceReading());
			}
		}
		this_thread::sleep_for(chrono::milliseconds(scanningTimer));
		tenthOfmilisec = (tenthOfmilisec % 10);
		tenthOfmilisec++;
	}

	return STATUS_OK;
}

void Scheduler::operator ()(int x)
{
	schedulerThreadFunction();
	cout << "Scheduler : end thread" << x << endl;
}
