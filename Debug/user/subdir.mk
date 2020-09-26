################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user/main.c 

OBJS += \
./user/main.o 

C_DEPS += \
./user/main.d 


# Each subdirectory must supply rules for building sources it contributes
user/main.o: ../user/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F051R8Tx -c -I"D:/workspace/my_driver/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"user/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

