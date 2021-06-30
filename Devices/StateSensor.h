/*
 * StateSensor.h
 *
 *  Created on: 30 cze 2021
 *      Author: krichert
 */

#ifndef DEVICES_STATESENSOR_H_
#define DEVICES_STATESENSOR_H_

#include <DeviceInterface.h>
#include "CommonDefs.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

class StateSensor : public DeviceInterface
{
	private:
		int deviceAddress;
		ReadingType readingType;


	public:
		StateSensor(string address);
		virtual ~StateSensor() {}
		SensorReading getDeviceReading() override;
		void updateDeviceReading(int reading) override;
};



#endif /* DEVICES_STATESENSOR_H_ */
