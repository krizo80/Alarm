/*
 * Device.h
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>

using namespace std;

class Device
{

    public:
        virtual int getDeviceReading() = 0;
};



#endif /* DEVICE_H_ */
