/*
 * EnergySensor.h
 *
 *  Created on: 2 czerw 2021
 *      Author: dom
 */

#include <DeviceInterface.h>
#include "CommonDefs.h"
#include <iostream>
#include <mutex>
#include <thread>


using namespace std;


class EnergySensor : public DeviceInterface
{
    private:
		string deviceAddress;
		SensorReading reading;

    public:
		EnergySensor(string address);
		string getDeviceAddress() { return deviceAddress;}
		void setNewReading(SensorReading reading);

		SensorReading getDeviceReading() override;
		virtual ~EnergySensor() {}
};


class EnergyReadingThread
{
	private:
		EnergySensor *energySensor;

	public:
		static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
		EnergyReadingThread(EnergySensor *sensor) : energySensor(sensor) {}
		void operator()(int param);
};


