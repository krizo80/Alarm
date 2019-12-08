################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DeviceRegister/DeviceRegister.cpp 

OBJS += \
./DeviceRegister/DeviceRegister.o 

CPP_DEPS += \
./DeviceRegister/DeviceRegister.d 


# Each subdirectory must supply rules for building sources it contributes
DeviceRegister/DeviceRegister.o: ../DeviceRegister/DeviceRegister.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++17 -I/usr/include/rapidxml -I"/home/dom/Projekty/workspace/Alarm/DeviceInfo" -I"/home/dom/Projekty/workspace/Alarm/DeviceConfiguration" -I"/home/dom/Projekty/workspace/Alarm/Devices" -I"/home/dom/Projekty/workspace/Alarm" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"DeviceRegister/DeviceRegister.d" -o "$@" "$<" -pthread
	@echo 'Finished building: $<'
	@echo ' '


