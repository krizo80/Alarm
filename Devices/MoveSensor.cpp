/*
 * MoveSensor.cpp
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#include "MoveSensor.h"


int MoveSensor::getDeviceReading()
{
	cout << "MOVE SENSOR with address = " << deviceAddress << endl;
	return 0;
}


ReadingType MoveSensor::getReadingType() const
{
	return readingType;
}

