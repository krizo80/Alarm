/*
 * Scheduler.h
 *
 *  Created on: 17 paź 2019
 *      Author: dom
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


#include <iostream>
#include <memory>
#include "DeviceRegister.h"
#include "DeviceInfo.h"
#include "CommonDefs.h"
//todo: only relative path
#include "../DeviceEvents/SensorEventsDatabase.h"
#include "array"

using namespace std;

class Scheduler
{

	private:
		array<shared_ptr<DeviceInfo>,1> readingSources;
		int  schedulerThreadFunction();
		const int scanningTimer = 100;

	public:
		Scheduler() : readingSources(
				{make_shared<SensorEventsDatabase>()}
		){}

		void operator()(int x);
};

#endif /* SCHEDULER_H_ */
