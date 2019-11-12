/*
 * RestApiService.cpp
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */



#include "RestApiService.h"
#include "CommonDefs.h"
#include "Device.h"

using namespace std;

void RestApiService::onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response)
{
	string apiResponse;
	map<string,string> apiParameters;
	string cmd;

	cmd = this->getCommand(request.resource());
	apiParameters = this->getParameters(request.resource());

	apiResponse = apiCommands[cmd](apiParameters);
	response.send(Pistache::Http::Code::Ok, apiResponse);
}

string RestApiService::getCommand(const string inputQuery)
{
	const string commandPattern = "command=";
	string command;
	int cmdStringBegin = -1;
	int paramSeparatorIdx = -1;

	cmdStringBegin = inputQuery.find(commandPattern);
	cmdStringBegin+=commandPattern.length();
	paramSeparatorIdx = inputQuery.find("&");
	if (-1 == paramSeparatorIdx)
	{
		command = inputQuery.substr(cmdStringBegin);
	}
	else
	{
		command = inputQuery.substr(cmdStringBegin, paramSeparatorIdx - cmdStringBegin);
	}
	return command;
}

map<string,string> RestApiService::getParameters(const string inputQuery)
{
	map<string,string> apiParams;
	const string paramSeparatorPattern = "&";
	const string paramValuePattern     = "=";
	string paramName;
	string paramValue;
	int paramNameBeginIdx = 0;
	int paramValueBeginIdx = -1;
	int paramSeparatorIdx = -1;

	paramNameBeginIdx  = inputQuery.find("/") + 1;

	while ( paramNameBeginIdx != 0 )
	{
		paramValueBeginIdx = inputQuery.find(paramValuePattern,paramNameBeginIdx) + 1;
		paramSeparatorIdx = inputQuery.find(paramSeparatorPattern, paramValueBeginIdx);

		paramName  = inputQuery.substr(paramNameBeginIdx, inputQuery.find(paramValuePattern, paramNameBeginIdx)-paramNameBeginIdx);
		if (-1 == paramSeparatorIdx)
		{
			paramValue = inputQuery.substr(paramValueBeginIdx);
		}
		else
		{
			paramValue = inputQuery.substr(paramValueBeginIdx, inputQuery.find(paramSeparatorPattern, paramNameBeginIdx)-paramValueBeginIdx);
		}
		apiParams[paramName] = paramValue;

		paramNameBeginIdx  = inputQuery.find(paramSeparatorPattern, paramNameBeginIdx) + 1;
	}

	return apiParams;
}

string RestApiService::GetVersion(map<string,string> parameters)
{
	return "<version>1.0</version>";
}

string RestApiService::GetReading(map<string,string> parameters)
{
	string sensorId;

	sensorId = parameters["id"];

	return "<sensorId>"+sensorId+"</sensorId>";
}


map<string,function<string(map<string,string>)>> RestApiService::apiCommands =
{
		{"GetVersion", GetVersion},
		{"GetReading", GetReading}

};
