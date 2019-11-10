/*
 * TempSensor.cpp
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */

#include "TempSensor.h"

int TempSensor::getDeviceReading()
{
	cout << "TEMPERATURE SENSOR with address = " << deviceAddress << endl;
	return 0;
}


ReadingType TempSensor::getReadingType() const
{
	return readingType;
}



