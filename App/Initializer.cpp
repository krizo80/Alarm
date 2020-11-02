/*
 * Initializer.cpp
 *
 *  Created on: 1 paź 2019
 *      Author: dom
 */
#include "Initializer.h"
#include "MoveSensor.h"
#include "Scheduler.h"
#include "RestApiService.h"
#include "pistache/endpoint.h"

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
	//todo:read input parameters ./alarm port=80 configile="Alarm.xml"
	// parse input parameters (Alarm httpPort=80 configFile=Alarm.xml)
}

void Initializer::begin()
{
	// starts all threads
	thread schedulerThread(Scheduler(), 3);
	Pistache::Http::listenAndServe<RestApiService>(static_cast<Pistache::Address>("*:9080"));

	schedulerThread.join();
}


Initializer *Initializer::initializerInstance = nullptr;
mutex Initializer::synch;


