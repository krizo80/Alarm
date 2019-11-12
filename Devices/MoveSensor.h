/*
 * MoveSensor.h
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#ifndef MOVESENSOR_H_
#define MOVESENSOR_H_

#include "Device.h"
#include "CommonDefs.h"
#include <iostream>

using namespace std;

class MoveSensor : public Device
{
	private:
		const int deviceAddress;
		const ReadingType readingType;


    public:
		MoveSensor(int address) : deviceAddress(address), readingType(READING_FIXED_INT) {}
        int getDeviceReading() override;
        ReadingType getReadingType() const override;
};




#endif /* MOVESENSOR_H_ */
