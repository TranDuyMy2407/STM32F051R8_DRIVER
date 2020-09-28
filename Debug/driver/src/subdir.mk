################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/USART_api.c \
../driver/src/clock_api.c \
../driver/src/gpio_api.c 

OBJS += \
./driver/src/USART_api.o \
./driver/src/clock_api.o \
./driver/src/gpio_api.o 

C_DEPS += \
./driver/src/USART_api.d \
./driver/src/clock_api.d \
./driver/src/gpio_api.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/USART_api.o: ../driver/src/USART_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F051R8Tx -c -I"D:/workspace/my_driver/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/src/USART_api.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
driver/src/clock_api.o: ../driver/src/clock_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F051R8Tx -c -I"D:/workspace/my_driver/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/src/clock_api.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
driver/src/gpio_api.o: ../driver/src/gpio_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F051R8Tx -c -I"D:/workspace/my_driver/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/src/gpio_api.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

