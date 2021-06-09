/*
 * MoveSensor.h
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#ifndef MOVESENSOR_H_
#define MOVESENSOR_H_

#include <DeviceInterface.h>
#include "CommonDefs.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

class MoveSensor : public DeviceInterface
{
	private:
		int deviceAddress;
		ReadingType readingType;


	public:
		MoveSensor(string address);
		virtual ~MoveSensor() {}
		SensorReading getDeviceReading() override;
};




#endif /* MOVESENSOR_H_ */
