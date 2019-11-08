/*
 * Scheduler.cpp
 *
 *  Created on: 17 paź 2019
 *      Author: dom
 */


#include "Scheduler.h"

Scheduler::Scheduler()
{

}

int  Scheduler::schedulerThreadFunction()
{
	devRegister.registerDevices();
}

void Scheduler::operator ()(int x)
{
	schedulerThreadFunction();
	cout << "Scheduler : end thread" << x << endl;
}
