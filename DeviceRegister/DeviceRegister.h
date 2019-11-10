#include "Device.h"
#include "MoveSensor.h"
#include "TempSensor.h"
#include "DevicesConfiguration.h"
#include <map>
#include <vector>
#include <functional>

using namespace std;

class DevicesRegister
{
	private:
		map<int, shared_ptr<Device>> deviceRegister;
		//static array<shared_ptr<Device>, 5> deviceType;
		static array<function<shared_ptr<Device>(int)>, 5> deviceType;

	public:
		DevicesRegister();
		void registerDevices();
		const vector<int> getRegistredDevicesId();
		const shared_ptr<Device> getRegisteredDevice(const int deviceId);
};
