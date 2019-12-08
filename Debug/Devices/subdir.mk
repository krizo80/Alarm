################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Devices/MoveSensor.cpp \
../Devices/TempSensor.cpp 

OBJS += \
./Devices/MoveSensor.o \
./Devices/TempSensor.o 

CPP_DEPS += \
./Devices/MoveSensor.d \
./Devices/TempSensor.d 


# Each subdirectory must supply rules for building sources it contributes
Devices/%.o: ../Devices/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I"/home/dom/Projekty/workspace/Alarm/Devices" -I"/home/dom/Projekty/workspace/Alarm" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -pthread
	@echo 'Finished building: $<'
	@echo ' '


