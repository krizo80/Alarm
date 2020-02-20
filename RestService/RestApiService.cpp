/*
 * RestApiService.cpp
 *
 *  Created on: 10 lis 2019
 *      Author: dom
 */



#include <DeviceInterface.h>
#include <DeviceService.h>
#include "RestApiService.h"
#include "CommonDefs.h"
#include "AlarmService.h"


using namespace std;

void RestApiService::onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response)
{
	string apiResponse;
	map<string,string> apiParameters;
	string cmd;

	cmd = this->getCommand(request.resource());
	apiParameters = this->getParameters(request.resource());

	if (apiCommands.find(cmd) != apiCommands.end())
	{
		apiResponse = apiCommands[cmd](apiParameters);
	}
	else
	{
		apiResponse = generateErrorResponse("-1","Invalid command");
	}
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

string RestApiService::generateResponse(string sensorId, map<string,string> responseElements)
{
	string response;

	//prepare response
	response = "<sensosId>" + sensorId + "</sensorId>";

	for (auto &element : responseElements)
	{
		response += "<" + element.first +">" + element.second + "</" + element.first +">";
	}

	return response;
}

string RestApiService::generateErrorResponse(string sensorId, string message)
{
	string response;

	//prepare response
	response = "<sensosId>" + sensorId + "</sensorId>";
	response += "<error>" +message + "</error>";
	return response;
}

string RestApiService::getVersion(map<string,string> parameters)
{
	return "<version>1.0</version>";
}

string RestApiService::getReading(map<string,string> parameters)
{
	int sensorId;
	string response;

	try
	{
		sensorId = stoi(parameters["id"]);
		response = generateResponse(parameters["id"], deviceRegister.getReadingDeviceInfo(sensorId));
	}
	catch (invalid_argument& e)
	{
		response = generateErrorResponse(parameters["id"], "Invalid parameter");
	}

	return response;
}

string RestApiService::getConfig(map<string,string> parameters)
{
	int sensorId;
	string response;

	try
	{
		sensorId = stoi(parameters["id"]);
		response = generateResponse(parameters["id"], deviceRegister.getConfigurationDeviceInfo(sensorId));
	}
	catch (invalid_argument& e)
	{
		response = generateErrorResponse(parameters["id"], "Invalid parameter");
	}

	return response;
}

string RestApiService::enableAlarm(map<string,string> parameters)
{
	shared_ptr<DeviceServiceAbstract> alarmService = AlarmService::getInstance();

	alarmService->enableService();

	return "<enabled>1</enabled>";
}

string RestApiService::disableAlarm(map<string,string> parameters)
{
	shared_ptr<DeviceServiceAbstract> alarmService = AlarmService::getInstance();
	string code = parameters["code"];
	Status status = STATUS_OK;
	string response = "<enabled>0</enabled>";

	status = alarmService->disableService(code);
	if (status != STATUS_OK)
	{
		response = "<enabled>1</enabled>";
	}

	return response;
}

map<string,function<string(map<string,string>)>> RestApiService::apiCommands =
{
		{"GetVersion", getVersion},
		{"GetReading", getReading},
		{"GetConfig" , getConfig },
		{"EnableAlarm" , enableAlarm },
		{"DisableAlarm" , disableAlarm }
};

DeviceInfoRegister RestApiService::deviceRegister;

