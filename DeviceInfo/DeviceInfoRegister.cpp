/*
 * DeviceInfoRegister.cpp
 *
 *  Created on: 14 lis 2019
 *      Author: dom
 */


#include <DeviceInfoRegister.h>
#include "DevicesConfiguration.h"
#include "SensorEventsDatabase.h"
#include "ReadingConverter.h"

using namespace std;

DeviceInfoRegister::DeviceInfoRegister()
{
	deviceInfoSource.push_back(DevicesConfiguration::getInstance());
	//todo: provide deconstructor
	deviceInfoSource.push_back(SensorEventsDatabase::getInstance());
}

xmlResponse DeviceInfoRegister::getConfigurationDeviceInfo(int deviceId)
{
	xmlResponse result;
	SensorParameters config = any_cast<SensorParameters>(deviceInfoSource[0]->getData(deviceId));

	result[deviceId].insert((pair<string, string>("sensorName", config.sensorName)));
	result[deviceId].insert((pair<string, string>("enable", to_string(static_cast<int>(config.enabled)))));
	result[deviceId].insert((pair<string, string>("address", to_string(config.sensorAddress))));
	result[deviceId].insert((pair<string, string>("sensorType", to_string(config.sensorType))));
	result[deviceId].insert((pair<string, string>("scanningPeriod", to_string(config.scanningPeriod))));
	result[deviceId].insert((pair<string, string>("status", to_string(config.status))));

	return result;
}

xmlResponse DeviceInfoRegister::getReadingDeviceInfo(int deviceId)
{
	xmlResponse result;
	ReadingConverter converter;
	SensorReading reading = any_cast<DatabaseReadingEntry>(deviceInfoSource[1]->getData(deviceId)).reading;

	result[deviceId].insert((pair<string, string>("value", converter.ConvertReadingToString(reading))));
	result[deviceId].insert((pair<string, string>("status", converter.ConvertStatusToString(reading))));

	return result;
}

xmlResponse DeviceInfoRegister::getPresenceDeviceInfo()
{
	xmlResponse result;
	ReadingConverter converter;
	int sensorIdx = 0;
	DatabaseReadingEntry readingEntry;
	SensorParameters sensorParam;

	do
	{
		readingEntry = any_cast<DatabaseReadingEntry>(deviceInfoSource[1]->getData(sensorIdx));
		if((STATUS_OK == readingEntry.reading.status) && ( true == readingEntry.isSensorGeneratingAlarm))
		{
			sensorParam = any_cast<SensorParameters>(deviceInfoSource[0]->getData(sensorIdx));
			result[sensorIdx].insert(pair<string, string>("sensorName", sensorParam.sensorName));
		}
		sensorIdx++;
	}
	while (readingEntry.reading.status != STATUS_XML_NO_MORE_SENSORS);


	return result;
}


xmlResponse DeviceInfoRegister::getTemperatureDeviceInfo()
{
	xmlResponse result;
	ReadingConverter converter;
	int sensorIdx = 0;
	DatabaseReadingEntry readingEntry;
	SensorParameters sensorParam;

	do
	{
		readingEntry = any_cast<DatabaseReadingEntry>(deviceInfoSource[1]->getData(sensorIdx));
		sensorParam = any_cast<SensorParameters>(deviceInfoSource[0]->getData(sensorIdx));

		if((STATUS_OK == readingEntry.reading.status) && ( TEMP_SENSOR == sensorParam.sensorType))
		{/*
			map<string,string> elements;
			elements.clear();
			elements.insert(pair<string, string>("sensorName", sensorParam.sensorName));
			elements.insert(pair<string, string>("Temperature", converter.ConvertReadingToString(readingEntry.reading)));
			result[sensorIdx] = elements;
*/
			result[sensorIdx].insert(pair<string, string>("Temperature", converter.ConvertReadingToString(readingEntry.reading)));
			result[sensorIdx].insert(pair<string, string>("sensorName", sensorParam.sensorName));


//			result["sensorId_" + to_string(sensorIdx) + "_Name"] = sensorParam.sensorName;
//			result["sensorId_" + to_string(sensorIdx) + "_Temp"] = converter.ConvertReadingToString(readingEntry.reading);
		}
		sensorIdx++;
	}
	while (readingEntry.reading.status != STATUS_XML_NO_MORE_SENSORS);


	return result;
}
