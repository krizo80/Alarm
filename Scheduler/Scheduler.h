/*
 * Scheduler.h
 *
 *  Created on: 17 paź 2019
 *      Author: dom
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


#include <DeviceRegister.h>
#include <DeviceService.h>
#include <iostream>
#include <memory>
#include "CommonDefs.h"
#include "array"
//todo: only relative path
#include "SensorEventsDatabase.h"
#include "AlarmService.h"



using namespace std;

class Scheduler
{
	private:
		static constexpr int maxSources = 2;
		array<shared_ptr<DeviceServiceAbstract>,maxSources> readingSources;
		int  schedulerThreadFunction();
		const int scanningTimer = 100;

	public:
		Scheduler() : readingSources(
				{
					make_shared<SensorEventsDatabase>(),
					AlarmService::getInstance()
				}
		){}

		void operator()(int x);
};

#endif /* SCHEDULER_H_ */
