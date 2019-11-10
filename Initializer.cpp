/*
 * Initializer.cpp
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */
#include "Initializer.h"
#include "Devices/MoveSensor.h"
#include "Scheduler/Scheduler.h"

Initializer::Initializer() {}
Initializer * Initializer::getInstance()
{
	synch.lock();
	if (initializerInstance == nullptr)
	{
		initializerInstance = new Initializer();
	}
	synch.unlock();

	return initializerInstance;
}

void Initializer::init()
{
	synch.lock();

	synch.unlock();
}

void Initializer::begin()
{
	// starts all threads
	thread schedulerThread(Scheduler(), 3);

	schedulerThread.join();
}


Initializer *Initializer::initializerInstance = nullptr;
mutex Initializer::synch;


