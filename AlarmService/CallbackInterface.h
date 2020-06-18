/*
 * CallbackInterface.h
 *
 *  Created on: 16 cze 2020
 *      Author: dom
 */

#ifndef ALARMSERVICE_CALLBACKINTERFACE_H_
#define ALARMSERVICE_CALLBACKINTERFACE_H_

#include "CommonDefs.h"
#include <thread>
#include <memory>

using namespace std;

class CallbackInterface
{
	public:
		virtual Status callbackFunction() = 0;
		void connect();
		void clear();

	private:
		bool progress;
};


#endif /* ALARMSERVICE_CALLBACKINTERFACE_H_ */
