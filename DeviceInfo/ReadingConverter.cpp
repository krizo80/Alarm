/*
 * ReadingConverter.cpp
 *
 *  Created on: 8 gru 2019
 *      Author: dom
 */


#include "ReadingConverter.h"


string ReadingConverter::ConvertReadingToString(SensorReading reading)
{
	string result;
	try
	{
		auto callback = readingConverterArray.at(reading.readingType);
		result = to_string(callback(reading.lastReadingValue));
	}
	catch (const std::out_of_range &exception)
	{
		result = "INTERNAL ERROR";
	}

	return result;
}

string ReadingConverter::ConvertStatusToString(SensorReading reading)
{
	string result;

	switch (reading.status)
	{
		case STATUS_OK:
			result = "OK";
			break;
		case STATUS_SENSOR_NOT_EXIST:
			result = "WRONG SENSOR_ID";
			break;
		default:
			result = "GENERIC ERROR";
	}

	return result;
}
