/*
 * TempSensor.cpp
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */

#include "TempSensor.h"

SensorReading TempSensor::getDeviceReading()
{
	SensorReading reading;

	reading.readingType = this->readingType;
	reading.lastReadingValue = (31 << 12);
	reading.status = STATUS_OK;
	cout << "TEMPERATURE SENSOR with address = " << deviceAddress << endl;
	return reading;
}



