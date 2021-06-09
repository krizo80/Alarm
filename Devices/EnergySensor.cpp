/*
 * EnergySensor.cpp
 *
 *  Created on: 2 czerw 2021
 *      Author: dom
 */

#include "EnergySensor.h"

#include <iostream>
#include <string>
#include <curl/curl.h>


SensorReading EnergySensor::getDeviceReading()
{
	//synchronization not introduced intentionally
	return reading;
}

void EnergySensor::setNewReading(SensorReading reading){
	//synchronization not introduced intentionally
	this->reading = reading;
}

EnergySensor::EnergySensor(string address){
	deviceAddress = address;
	reading.status = STATUS_READING_NOT_READY;
	thread energyThread(EnergyReadingThread(this), 3);
	energyThread.detach();
}



size_t EnergyReadingThread::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


void EnergyReadingThread::operator()(int param){
	SensorReading reading;
	CURL *curl;
	CURLcode res;
	std::string readBuffer;
	std::size_t pos = 0;
	std::string val = "";

	while(1)
	{
		try
		{
		    curl = curl_easy_init();
		    if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "http://10.10.100.254/status.html");
			curl_easy_setopt(curl, CURLOPT_USERNAME, "admin");
			curl_easy_setopt(curl, CURLOPT_PASSWORD, "admin");

			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, EnergyReadingThread::WriteCallback);
			curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
			readBuffer.clear();
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);

			if (energySensor->getDeviceAddress().find("today") != -1){
			    pos = readBuffer.find("webdata_today_e");
			}

			if (energySensor->getDeviceAddress().find("current") != -1){
			    pos = readBuffer.find("webdata_now_p");
			}

			if (energySensor->getDeviceAddress().find("total") != -1){
			    pos = readBuffer.find("webdata_total_e");
			}

			val = readBuffer.substr (pos);
			pos = val.find("\"")+1;
			val = val.substr (pos);
			pos = val.find("\"");
			val = val.substr (0,pos);


			reading.readingType = READING_INT;
			reading.lastReadingValue = stoi(val);
			reading.status = STATUS_OK;
		    }
		    else{
			reading.status = STATUS_WRONG_READING;
		    }
		    energySensor->setNewReading(reading);
		}
		catch (...)
		{
			reading.status = STATUS_WRONG_READING;
			energySensor->setNewReading(reading);
		}

		this_thread::sleep_for(chrono::milliseconds(60*1000));
	}
}







