/*
 * CallbackCaller.cpp
 *
 *  Created on: 16 cze 2020
 *      Author: dom
 */

#include "CallbackCaller.h"
#include <iostream>



CallbackCaller::CallbackCaller(CallbackInterface *clbkInterface)
{
	this->clbkInterface = clbkInterface;
}


void CallbackCaller::operator()(int x)
{

	std::cout << "!!!!!!!!!!!!!!!!! START "<< endl;
	this_thread::sleep_for(chrono::seconds(5));
	clbkInterface->callbackFunction();
	std::cout << "!!!!!!!!!!!!!!!!! END "<< endl;
	clbkInterface->clear();
}



