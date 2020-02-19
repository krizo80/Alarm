/*
 * Parser.h
 *
 *  Created on: 28 paź 2019
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_PARSER_H_
#define DEVICECONFIGURATION_PARSER_H_

#include "ConfigurationEntry.h"
#include "CommonDefs.h"

using namespace std;

class Parser
{
	public:
		virtual SensorParameters getFirstSensorEntry() = 0;
		virtual SensorParameters getNextSensorEntry() = 0;
		virtual SettingParameters getFirstSettingEntry() = 0;
		virtual SettingParameters getNextSettingEntry() = 0;
};


#endif /* DEVICECONFIGURATION_PARSER_H_ */
