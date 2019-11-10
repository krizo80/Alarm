/*
 * Scheduler.cpp
 *
 *  Created on: 17 paź 2019
 *      Author: dom
 */


#include "Scheduler.h"

Scheduler::Scheduler()
{

}

int  Scheduler::schedulerThreadFunction()
{
	int tenthOfmilisec = 0;
	DevicesConfiguration *config = DevicesConfiguration::getInstance();
	vector<int> devicesId;


	devRegister.registerDevices();
	devicesId = devRegister.getRegistredDevicesId();

	//start to read sensors
	while(1)
	{
		for (auto &deviceId : devicesId)
		{
			if (0 == (tenthOfmilisec % config->getConfigByDeviceId(deviceId)->getSensorParameters().scanningPeriod))
			{
				devRegister.getRegisteredDevice(deviceId)->getDeviceReading();
			}
		}
		this_thread::sleep_for(chrono::milliseconds(scanningTimer));
		tenthOfmilisec = (tenthOfmilisec % 10);
		tenthOfmilisec++;
	}
}

void Scheduler::operator ()(int x)
{
	schedulerThreadFunction();
	cout << "Scheduler : end thread" << x << endl;
}
