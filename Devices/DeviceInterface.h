/*
 * Device.h
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>
#include "CommonDefs.h"

using namespace std;

class DeviceInterface
{

    public:
        virtual SensorReading getDeviceReading() = 0;
        virtual void updateDeviceReading(int reading) {}
};



#endif /* DEVICE_H_ */
