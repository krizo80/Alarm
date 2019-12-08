/*
 * TempSensor.h
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

#include "Device.h"
#include "CommonDefs.h"
#include <iostream>

using namespace std;

class TempSensor : public Device
{
	private:
		const int deviceAddress;
		const ReadingType readingType;


    public:
		TempSensor(int address) : deviceAddress(address), readingType(READING_STATE) {}
		SensorReading getDeviceReading() override;
};



#endif /* TEMPSENSOR_H_ */
