################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/test/DefaultRuleTest.cpp \
../src/test/GridTest.cpp \
../src/test/KeepCellAliveRuleTest.cpp \
../src/test/KillCellRuleTest.cpp 

CPP_DEPS += \
./src/test/DefaultRuleTest.d \
./src/test/GridTest.d \
./src/test/KeepCellAliveRuleTest.d \
./src/test/KillCellRuleTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/test/%.o: ../src/test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


