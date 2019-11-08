#include "Device.h"
#include "MoveSensor.h"
#include "DevicesConfiguration.h"
#include <map>

using namespace std;

class DevicesRegister
{
	private:
		map<int, shared_ptr<Device>> deviceRegister;
		static array<shared_ptr<Device>, 5> deviceType;

	public:
		DevicesRegister();
		void registerDevices();
};
