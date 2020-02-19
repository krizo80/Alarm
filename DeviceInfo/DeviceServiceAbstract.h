/*
 * DeviceServiceAbstract.h
 *
 *  Created on: 5 lut 2020
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICESERVICEABSTRACT_H_
#define DEVICEINFO_DEVICESERVICEABSTRACT_H_


#include "DeviceInfo.h"
#include "DeviceSetup.h"

class DeviceServiceAbstract : public DeviceInfo, public DeviceSetup
{
public:
	virtual Status enableService() = 0;
	virtual Status disableService(string code) = 0;
};

#endif /* DEVICEINFO_DEVICESERVICEABSTRACT_H_ */
