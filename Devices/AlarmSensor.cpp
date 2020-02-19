/*
 * AlarmSensor.cpp
 *
 *  Created on: 10 gru 2019
 *      Author: dom
 */



#include "AlarmSensor.h"


SensorReading AlarmSensor::getDeviceReading()
{
	SensorReading reading;

	reading.readingType = this->readingType;
	reading.lastReadingValue = 0;

	reading.status = STATUS_OK;

	cout << "ALARM SENSOR with address = " << deviceAddress << endl;
	return reading;
}
