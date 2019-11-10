/*
 * CommonDefs.h
 *
 *  Created on: 29 paź 2019
 *      Author: dom
 */

#ifndef COMMONDEFS_H_
#define COMMONDEFS_H_

#include <string>

using namespace std;

typedef enum Status
{
	STATUS_OK,
	STATUS_XML_PARSE_ERROR,
	STATUS_XML_NO_MORE_SENSORS,
	STATUS_MAX
} Status;


typedef enum ReadingType
{
	READING_INT,
	READING_FIXED_INT,
	READING_STATE,
	READING_MAX
} ReadingType;

typedef struct SensorParameters
{
	string sensorName;
	int scanningPeriod;
	int readingType;
	int sensorAddress;
	bool enabled;
	Status status;
} SensorParameters;


#endif /* COMMONDEFS_H_ */
