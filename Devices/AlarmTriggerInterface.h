/*
 * AlarmTriggerInterface.h
 *
 *  Created on: 5 lut 2020
 *      Author: dom
 */

#ifndef DEVICES_ALARMTRIGGERINTERFACE_H_
#define DEVICES_ALARMTRIGGERINTERFACE_H_


#include <string>
#include "CommonDefs.h"

using namespace std;

class AlarmTriggerInterface
{

    public:
        virtual Status triggerAlarm() = 0;
        virtual Status disableAlarm() = 0;
};


#endif /* DEVICES_ALARMTRIGGERINTERFACE_H_ */
