#include "Device.h"

#include <map>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class DevicesRegister
{
	private:
		map<int, shared_ptr<Device>> deviceRegister;
		static constexpr int deviceTypes = SENSOR_MAX;
		static array<function<shared_ptr<Device>(int)>, deviceTypes> deviceType;

	public:
		DevicesRegister();
		void registerDevices();
		const vector<int> getRegistredDevicesId();
		const shared_ptr<Device> getRegisteredDevice(const int deviceId);
};
