/*
 * Scheduler.h
 *
 *  Created on: 17 paź 2019
 *      Author: dom
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_


#include <iostream>
#include "DeviceRegister.h"

using namespace std;

class Scheduler
{

	private:
		int  schedulerThreadFunction();
		const int scanningTimer = 100;
		DevicesRegister devRegister;

	public:
		Scheduler();
		void operator()(int x);
};

#endif /* SCHEDULER_H_ */
