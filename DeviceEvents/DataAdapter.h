/*
 * DataAdapter.h
 *
 *  Created on: 20 lis 2019
 *      Author: dom
 */

#ifndef DEVICEEVENTS_DATAADAPTER_H_
#define DEVICEEVENTS_DATAADAPTER_H_


class DataAdater
{
	public:
		void setData(int sensorId, int reading) = 0;
		int getData(int sensorId) = 0;
};


#endif /* DEVICEEVENTS_DATAADAPTER_H_ */
