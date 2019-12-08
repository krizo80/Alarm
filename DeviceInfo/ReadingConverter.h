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
		array<function<int(int)>, READING_MAX> readingConverterArray;

	public:
		ReadingConverter() : readingConverterArray(
		{
			[](int value)->int { return value; },
			[](int value)->int { return value; },
			[](int value)->int { return value; }
		})
		{}
		string ConvertReadingToString(SensorReading reading);
		string ConvertStatusToString(SensorReading rading);

};


#endif /* DEVICEINFO_READINGCONVERTER_H_ */
