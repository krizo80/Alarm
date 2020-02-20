/*
 * ConfigSettingAbstract.h
 *
 *  Created on: 7 lut 2020
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_CONFIGSETTINGINTERFACE_H_
#define DEVICECONFIGURATION_CONFIGSETTINGINTERFACE_H_


#include "CommonDefs.h"

using namespace std;

class ConfigSettingInterface
{
	public:
		virtual SettingParameters getSettingValue(string name) = 0;
};


#endif /* DEVICECONFIGURATION_CONFIGSETTINGINTERFACE_H_ */
