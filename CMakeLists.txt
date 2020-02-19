cmake_minimum_required(VERSION 2.8)
project(AlarmApp)


set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(App)
include_directories(Devices)
include_directories(Scheduler)
include_directories(DeviceRegister)
include_directories(DeviceInfo)
include_directories(DeviceEvents)
include_directories(AlarmService)
include_directories(RestService)
include_directories(DeviceConfiguration)
#code and header for library rapidxml
include_directories(/usr/include/rapidxml)
#header for pistache library
include_directories(/usr/local/include/pistache)


add_subdirectory(Scheduler)
add_subdirectory(DeviceRegister)
add_subdirectory(DeviceInfo)
add_subdirectory(AlarmService)
add_subdirectory(RestService)
add_subdirectory(DeviceConfiguration)
add_subdirectory(Devices)
add_subdirectory(DeviceEvents)
add_subdirectory(App)


