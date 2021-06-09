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
		auto callback = readingConverterToStringArray.at(reading.readingType);
		result = callback(reading.lastReadingValue);
	}
	catch (const std::out_of_range &exception)
	{
		result = "INTERNAL ERROR";
	}

	return result;
}

string ReadingConverter::ConvertReadingToString(bool reading)
{
	string result;
	if (reading) result = "yes";
	    else result = "no";

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
			result = "WRONG_SENSOR_ID";
			break;
		case STATUS_READING_NOT_READY:
			result = "READING_NOT_READY";
			break;
		case STATUS_WRONG_READING:
			result = "READING_CRC_ERROR";
			break;
		default:
			result = "GENERIC ERROR";
	}

	return result;
}


bool ReadingConverter::ConvertReadingToAlarm(SensorReading reading, int thresholdValue)
{
	bool result;
	try
	{
		auto callback = readingConverterToAlarmArray.at(reading.readingType);
		result = callback(reading.lastReadingValue, thresholdValue);
	}
	catch (const std::out_of_range &exception)
	{
		result = false;
	}

	return result;
}
