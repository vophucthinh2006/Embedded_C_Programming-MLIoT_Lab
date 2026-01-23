################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/ML&IoT\ Lab/STM32/Driver/Source/ADC.c \
D:/ML&IoT\ Lab/STM32/Driver/Source/GPIO.c \
D:/ML&IoT\ Lab/STM32/Driver/Source/RCC.c \
D:/ML&IoT\ Lab/STM32/Driver/Source/UART.c 

OBJS += \
./Driver/Source/ADC.o \
./Driver/Source/GPIO.o \
./Driver/Source/RCC.o \
./Driver/Source/UART.o 

C_DEPS += \
./Driver/Source/ADC.d \
./Driver/Source/GPIO.d \
./Driver/Source/RCC.d \
./Driver/Source/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Source/ADC.o: D:/ML&IoT\ Lab/STM32/Driver/Source/ADC.c Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ML&IoT Lab/STM32/Driver/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Driver/Source/GPIO.o: D:/ML&IoT\ Lab/STM32/Driver/Source/GPIO.c Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ML&IoT Lab/STM32/Driver/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Driver/Source/RCC.o: D:/ML&IoT\ Lab/STM32/Driver/Source/RCC.c Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ML&IoT Lab/STM32/Driver/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Driver/Source/UART.o: D:/ML&IoT\ Lab/STM32/Driver/Source/UART.c Driver/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ML&IoT Lab/STM32/Driver/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Source

clean-Driver-2f-Source:
	-$(RM) ./Driver/Source/ADC.cyclo ./Driver/Source/ADC.d ./Driver/Source/ADC.o ./Driver/Source/ADC.su ./Driver/Source/GPIO.cyclo ./Driver/Source/GPIO.d ./Driver/Source/GPIO.o ./Driver/Source/GPIO.su ./Driver/Source/RCC.cyclo ./Driver/Source/RCC.d ./Driver/Source/RCC.o ./Driver/Source/RCC.su ./Driver/Source/UART.cyclo ./Driver/Source/UART.d ./Driver/Source/UART.o ./Driver/Source/UART.su

.PHONY: clean-Driver-2f-Source

