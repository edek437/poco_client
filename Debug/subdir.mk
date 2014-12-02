################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Help.cpp \
../Inbox.cpp \
../Message.cpp \
../Nick.cpp \
../Quit.cpp \
../Receiver.cpp \
../Who.cpp \
../get_command.cpp \
../handle_option.cpp \
../option_factory.cpp \
../poco_client.cpp 

OBJS += \
./Help.o \
./Inbox.o \
./Message.o \
./Nick.o \
./Quit.o \
./Receiver.o \
./Who.o \
./get_command.o \
./handle_option.o \
./option_factory.o \
./poco_client.o 

CPP_DEPS += \
./Help.d \
./Inbox.d \
./Message.d \
./Nick.d \
./Quit.d \
./Receiver.d \
./Who.d \
./get_command.d \
./handle_option.d \
./option_factory.d \
./poco_client.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


