/*
 * CallbackCaller.h
 *
 *  Created on: 16 cze 2020
 *      Author: dom
 */

#ifndef ALARMSERVICE_CALLBACKCALLER_H_
#define ALARMSERVICE_CALLBACKCALLER_H_

#include "CommonDefs.h"
#include "CallbackInterface.h"
#include <thread>

class CallbackCaller
{
	private:
	CallbackInterface *clbkInterface;



	public:

	CallbackCaller(CallbackInterface *clbkInterface);

	void operator()(int x);
};


#endif /* ALARMSERVICE_CALLBACKCALLER_H_ */
