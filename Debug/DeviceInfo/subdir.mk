################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DeviceInfo/DeviceInfoRegister.cpp \
../DeviceInfo/ReadingConverter.cpp 

OBJS += \
./DeviceInfo/DeviceInfoRegister.o \
./DeviceInfo/ReadingConverter.o 

CPP_DEPS += \
./DeviceInfo/DeviceInfoRegister.d \
./DeviceInfo/ReadingConverter.d 


# Each subdirectory must supply rules for building sources it contributes
DeviceInfo/%.o: ../DeviceInfo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I"/home/dom/Projekty/workspace/Alarm/DeviceRegister" -I/usr/include/rapidxml -I"/home/dom/Projekty/workspace/Alarm/AlarmService" -I"/home/dom/Projekty/workspace/Alarm" -I"/home/dom/Projekty/workspace/Alarm/DeviceConfiguration" -I"/home/dom/Projekty/workspace/Alarm/DeviceEvents" -I"/home/dom/Projekty/workspace/Alarm/DeviceInfo" -I"/home/dom/Projekty/workspace/Alarm/Devices" -I"/home/dom/Projekty/workspace/Alarm/RestService" -I"/home/dom/Projekty/workspace/Alarm/Scheduler" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


