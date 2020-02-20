/*
 * DeviceServiceAbstract.h
 *
 *  Created on: 5 lut 2020
 *      Author: dom
 */

#ifndef DEVICEINFO_DEVICESERVICE_H_
#define DEVICEINFO_DEVICESERVICE_H_


#include <DeviceInfoInterface.h>
#include <DevicetSetupInterface.h>

class DeviceServiceAbstract : public DeviceInfoInterface, public DeviceSetupInterface
{
public:
	virtual Status enableService() = 0;
	virtual Status disableService(string code) = 0;
};

#endif /* DEVICEINFO_DEVICESERVICE_H_ */
