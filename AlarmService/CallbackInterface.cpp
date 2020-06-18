/*
 * CallbackInterface.cpp
 *
 *  Created on: 17 cze 2020
 *      Author: dom
 */

#include "CallbackInterface.h"
#include "CallbackCaller.h"



		void CallbackInterface::connect()
		{
			if (progress == false)
			{
				progress = true;
				//time = 4;
				thread timerThread(CallbackCaller(this),3);
				timerThread.detach();
			}
		}

		void CallbackInterface::clear()
		{
			progress = false;
		}
