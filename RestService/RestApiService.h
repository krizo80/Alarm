/*
 * RestApiService.h
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */

#ifndef RESTSERVICE_RESTAPISERVICE_H_
#define RESTSERVICE_RESTAPISERVICE_H_

#include <iostream>
#include "pistache/endpoint.h"
#include <functional>
#include <map>
#include <vector>

using namespace std;

class RestApiService: public Pistache::Http::Handler
{
	private:
		static map<string, function<string(map<string,string>)>> apiCommands;
		static string GetVersion(map<string,string> parameters);
		static string GetReading(map<string,string> parameters);

		string getCommand(const string inputQuery);
		map<string,string> getParameters(const string inputQuery);
	public:
    	HTTP_PROTOTYPE(RestApiService)

		void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response);
};




#endif /* RESTSERVICE_RESTAPISERVICE_H_ */
