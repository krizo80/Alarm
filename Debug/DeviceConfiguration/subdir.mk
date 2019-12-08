################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DeviceConfiguration/ConfigurationEntry.cpp \
../DeviceConfiguration/DevicesConfiguration.cpp \
../DeviceConfiguration/XmlParser.cpp 

OBJS += \
./DeviceConfiguration/ConfigurationEntry.o \
./DeviceConfiguration/DevicesConfiguration.o \
./DeviceConfiguration/XmlParser.o 

CPP_DEPS += \
./DeviceConfiguration/ConfigurationEntry.d \
./DeviceConfiguration/DevicesConfiguration.d \
./DeviceConfiguration/XmlParser.d 


# Each subdirectory must supply rules for building sources it contributes
DeviceConfiguration/%.o: ../DeviceConfiguration/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I"/home/dom/Projekty/workspace/Alarm/DeviceInfo" -I"/home/dom/Projekty/workspace/Alarm/DeviceEvents" -I/usr/include/rapidxml -I"/home/dom/Projekty/workspace/Alarm/RestService" -I"/home/dom/Projekty/workspace/Alarm/Scheduler" -I"/home/dom/Projekty/workspace/Alarm" -I"/home/dom/Projekty/workspace/Alarm/DeviceConfiguration" -I"/home/dom/Projekty/workspace/Alarm/Devices" -I"/home/dom/Projekty/workspace/Alarm/DeviceRegister" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -pthread
	@echo 'Finished building: $<'
	@echo ' '

DeviceConfiguration/DevicesConfiguration.o: ../DeviceConfiguration/DevicesConfiguration.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I/usr/include/rapidxml -I"/home/dom/Projekty/workspace/Alarm/RestService" -I"/home/dom/Projekty/workspace/Alarm/Scheduler" -I"/home/dom/Projekty/workspace/Alarm" -I"/home/dom/Projekty/workspace/Alarm/DeviceConfiguration" -I"/home/dom/Projekty/workspace/Alarm/Devices" -I"/home/dom/Projekty/workspace/Alarm/DeviceRegister" -I"/home/dom/Projekty/workspace/Alarm/DeviceInfo" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"DeviceConfiguration/DevicesConfiguration.d" -o "$@" "$<" -pthread
	@echo 'Finished building: $<'
	@echo ' '


