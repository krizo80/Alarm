/*
 * TempSensor.cpp
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */

#include "TempSensor.h"
#include <string>
#include <fstream>
#include <streambuf>

SensorReading TempSensor::getDeviceReading()
{
	SensorReading reading;
	const string data_pattern = "t=";
	const string crc_ok = "YES";

	try
	{
		std::ifstream t(this->devices_directory+this->deviceAddress+this->reading_file);
		std::string data((std::istreambuf_iterator<char>(t)),
						 std::istreambuf_iterator<char>());

		if (data.find(crc_ok) != string::npos){
			reading.readingType = this->readingType;
			int readingValue = stoi(data.substr(data.find(data_pattern) + data_pattern.length()));
			reading.lastReadingValue = (readingValue / 1000) << 12 | (readingValue - ((static_cast<int>(readingValue / 1000)) * 1000));
			reading.status = STATUS_OK;
		}
		else{
			reading.status = STATUS_WRONG_READING;
		}
	}
	catch (...)
	{
		reading.status = STATUS_WRONG_READING;
		cout << "ERROR" << endl;
	}

	return reading;
}



