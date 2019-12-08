/*
 * XmlParser.cpp
 *
 *  Created on: 28 paź 2019
 *      Author: dom
 */


#include "XmlParser.h"


XmlParser::XmlParser(string fileName)
{
	rapidxml::file<> xmlFile(fileName.c_str());
	this->xmlDocument.parse<rapidxml::parse_full>(xmlFile.data());
	sensorsNode = xmlDocument.first_node("sensors");
}

SensorParameters XmlParser::readSensorParameters()
{
	SensorParameters sensorData;
	if (sensorsNode != nullptr)
	{
		try
		{
			sensorData.sensorName = sensorsNode->first_attribute("name")->value();
			sensorData.sensorType = static_cast<SensorType>(stoi(sensorsNode->first_attribute("sensorType")->value()));
			sensorData.scanningPeriod = stoi(sensorsNode->first_attribute("scanningPeriod")->value());
			sensorData.sensorAddress = stoi(sensorsNode->first_attribute("address")->value());
			sensorData.enabled = static_cast<bool>(stoi(sensorsNode->first_attribute("scanningPeriod")->value()));
			sensorData.status = STATUS_OK;
		}
		catch (invalid_argument& e)
		{
			//todo: logg it - wrong configuration
			sensorData.status = STATUS_XML_PARSE_ERROR;
		}
	}
	else
	{
		sensorData.status = STATUS_XML_NO_MORE_SENSORS;
	}

	return sensorData;
}

SensorParameters XmlParser::getFirstSensorEntry()
{
	sensorsNode = xmlDocument.first_node("sensors");
	sensorsNode = sensorsNode->first_node("sensor");
	return readSensorParameters();
}

SensorParameters XmlParser::getNextSensorEntry()
{
	sensorsNode = sensorsNode->next_sibling("sensor");
	return readSensorParameters();
}
