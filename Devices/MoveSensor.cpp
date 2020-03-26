/*
 * MoveSensor.cpp
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#include "MoveSensor.h"


SensorReading MoveSensor::getDeviceReading()
{
	SensorReading reading;


	reading.readingType = this->readingType;
	reading.lastReadingValue = 3;
	reading.status = STATUS_OK;

	cout << "MOVE SENSOR with address = " << deviceAddress << endl;
	return reading;
}

