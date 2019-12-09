/*
 * CommonDefs.h
 *
 *  Created on: 29 paź 2019
 *      Author: dom
 */

#ifndef COMMONDEFS_H_
#define COMMONDEFS_H_

#include <string>
#include <any>

using namespace std;

typedef enum Status
{
	STATUS_OK,
	STATUS_SENSOR_NOT_EXIST,
	STATUS_READING_EXCEPTION,
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

typedef enum SensorType
{
	MOVE_SENSOR,
	TEMP_SENSOR,
	CO2_SENSOR,
	CAMERA_SENSOR,
	WATER_SENSOR,
	SENSOR_MAX
} SensorType;

typedef struct SensorParameters
{
	string sensorName;
	int scanningPeriod;
	SensorType sensorType;
	int sensorAddress;
	int enableThresholdValue;
	bool enabled;
	Status status;
} SensorParameters;


typedef struct SensorReading
{
	int lastReadingValue;
	ReadingType readingType;
	Status status;
} SensorReading;


typedef any DeviceInfoData;


#endif /* COMMONDEFS_H_ */
