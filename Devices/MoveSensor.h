/*
 * MoveSensor.h
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#ifndef MOVESENSOR_H_
#define MOVESENSOR_H_

#include "Device.h"
#include <iostream>

using namespace std;

class MoveSensor : public Device
{
    public:
        int getDeviceReading() override;
};




#endif /* MOVESENSOR_H_ */
