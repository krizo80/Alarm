/*
 * ReadingConverter.h
 *
 *  Created on: 8 gru 2019
 *      Author: dom
 */

#ifndef DEVICEINFO_READINGCONVERTER_H_
#define DEVICEINFO_READINGCONVERTER_H_

#include "CommonDefs.h"
#include <memory>
#include <array>
#include <functional>


class ReadingConverter
{
	private:
		array<function<string(int)>, READING_MAX> readingConverterToStringArray;
		array<function<bool(int, int)>, READING_MAX> readingConverterToAlarmArray;

	public:
		ReadingConverter() : readingConverterToStringArray(
		{
			[](int value)->string { return to_string(value); },
			[](int value)->string { return to_string(value >> 12) + "." + to_string(value & 0xFFF);  },
			[](int value)->string { return to_string(value & 0x01); }
		}),
		readingConverterToAlarmArray(
		{
			[](int value, int thr)->bool { return (value > thr) ? true : false; },
			[](int value, int thr)->bool { return (value > (thr << 12) )? true : false; },
			[](int value, int thr)->bool { return (thr == (value & thr)) ? true : false; }
		})
		{}

		string ConvertReadingToString(SensorReading reading);
		string ConvertStatusToString(SensorReading rading);
		bool   ConvertReadingToAlarm(SensorReading reading, int thresholdValue);

};


#endif /* DEVICEINFO_READINGCONVERTER_H_ */
