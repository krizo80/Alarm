/*
 * XmlParser.h
 *
 *  Created on: 28 paź 2019
 *      Author: dom
 */

#ifndef DEVICECONFIGURATION_XMLPARSER_H_
#define DEVICECONFIGURATION_XMLPARSER_H_

#include "Parser.h"
#include "ConfigurationEntry.h"
#include <rapidxml.hpp>
#include "rapidxml_utils.hpp"

class XmlParser: public Parser
{
	private:
		rapidxml::xml_document<> xmlDocument;
		rapidxml::xml_node<> *sensorsNode;
		SensorParameters readSensorParameters();

	public:
		XmlParser(string fileName);
		SensorParameters getFirstSensorEntry() override;
		SensorParameters getNextSensorEntry() override;

};


#endif /* DEVICECONFIGURATION_XMLPARSER_H_ */

/*
 *
     rapidxml::file<> xmlFile("Alarm.xml"); // Default template is char
    rapidxml::xml_document<> doc;
    //cout << xmlFile.data();
    doc.parse<rapidxml::parse_full>(xmlFile.data());

    rapidxml::xml_node<> *root = doc.first_node("sensors",7);
    cout << root->first_node("sensor", 6)->first_attribute("name")->value() << endl;
 *
 */
