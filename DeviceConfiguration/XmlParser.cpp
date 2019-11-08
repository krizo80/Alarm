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
		sensorData.sensorName = sensorsNode->first_attribute("name")->value();
		sensorData.readingType = 0;
		sensorData.status = STATUS_OK;
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
