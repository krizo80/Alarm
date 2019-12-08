################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Scheduler/Scheduler.cpp 

OBJS += \
./Scheduler/Scheduler.o 

CPP_DEPS += \
./Scheduler/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Scheduler/Scheduler.o: ../Scheduler/Scheduler.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I/usr/include/rapidxml -I"/home/dom/Projekty/workspace/Alarm/DeviceEvents" -I"/home/dom/Projekty/workspace/Alarm/DeviceInfo" -I"/home/dom/Projekty/workspace/Alarm" -I"/home/dom/Projekty/workspace/Alarm/DeviceConfiguration" -I"/home/dom/Projekty/workspace/Alarm/Devices" -I"/home/dom/Projekty/workspace/Alarm/DeviceRegister" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"Scheduler/Scheduler.d" -o "$@" "$<" -pthread
	@echo 'Finished building: $<'
	@echo ' '


