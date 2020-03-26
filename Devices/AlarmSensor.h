/*
 * AlarmSensor.h
 *
 *  Created on: 10 gru 2019
 *      Author: dom
 */

#ifndef DEVICES_ALARMSENSOR_H_
#define DEVICES_ALARMSENSOR_H_


#include <DeviceInterface.h>
#include "CommonDefs.h"
#include "AlarmTriggerInterface.h"
#include <iostream>

using namespace std;

class AlarmSensor : public DeviceInterface, public AlarmTriggerInterface
{
	private:
		const int deviceAddress;
		const ReadingType readingType;


    public:
		//TODO: reading type is hardcoded here, but also used in alarm.xml file - shall be used one of them (the same for rest devices)
		AlarmSensor(int address) : deviceAddress(address), readingType(READING_STATE) {}
		virtual ~AlarmSensor() {}

		SensorReading getDeviceReading() override;
		Status triggerAlarm() override { cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;}
		Status disableAlarm() override {}
};



#endif /* DEVICES_ALARMSENSOR_H_ */
