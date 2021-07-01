/*
 * SwitchSensor.h
 *
 *  Created on: 1 lip 2021
 *      Author: krichert
 */

#ifndef DEVICES_SWITCHSENSOR_H_
#define DEVICES_SWITCHSENSOR_H_


#include <DeviceInterface.h>
#include "CommonDefs.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

class SwitchSensor : public DeviceInterface
{
	private:
		int deviceAddress;
		ReadingType readingType;
		std::chrono::milliseconds beginTime;



	public:
		SwitchSensor(string address);
		virtual ~SwitchSensor() {}
		SensorReading getDeviceReading() override;
		void updateDeviceReading(int reading) override;
};



#endif /* DEVICES_SWITCHSENSOR_H_ */
