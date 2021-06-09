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
	//synchronization not introduced intentionally
	return reading;
}

void TempSensor::setNewReading(SensorReading reading){
	//synchronization not introduced intentionally
	this->reading = reading;
}

TempSensor::TempSensor(string address){
	deviceAddress = address;
	reading.status = STATUS_READING_NOT_READY;
	thread tempThread(TempReadingThread(this), 3);
	tempThread.detach();
}



void TempReadingThread::operator()(int param){
	const string data_pattern = "t=";
	const string crc_ok = "YES";
	SensorReading reading;

	while(1)
	{
		try
		{
			std::ifstream t(this->devices_directory+tempSensor->getDeviceAddress()+this->reading_file);
			std::string data((std::istreambuf_iterator<char>(t)),
							 std::istreambuf_iterator<char>());

			if (data.find(crc_ok) != string::npos){
				reading.readingType = READING_FIXED_INT;
				int readingValue = stoi(data.substr(data.find(data_pattern) + data_pattern.length()));
				reading.lastReadingValue = (readingValue / 1000) << 12 | (readingValue - ((static_cast<int>(readingValue / 1000)) * 1000));
				reading.status = STATUS_OK;
			}
			else{
				reading.status = STATUS_WRONG_READING;
			}
			tempSensor->setNewReading(reading);
		}
		catch (...)
		{
			reading.status = STATUS_WRONG_READING;
			tempSensor->setNewReading(reading);
			cout << "ERROR" << endl;
		}


		this_thread::sleep_for(chrono::milliseconds(60*1000));
	}
}




