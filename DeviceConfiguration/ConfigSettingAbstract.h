/*
 * ConfigSettingAbstract.h
 *
 *  Created on: 7 lut 2020
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_CONFIGSETTINGABSTRACT_H_
#define DEVICECONFIGURATION_CONFIGSETTINGABSTRACT_H_


#include "CommonDefs.h"

using namespace std;

class ConfigSettingAbstract
{
	public:
		virtual SettingParameters getSettingValue(string name) = 0;
};


#endif /* DEVICECONFIGURATION_CONFIGSETTINGABSTRACT_H_ */
