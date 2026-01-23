################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/ML&IoT\ Lab/STM32/Lib/Source/ADXL345.c 

OBJS += \
./Lib/Source/ADXL345.o 

C_DEPS += \
./Lib/Source/ADXL345.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/Source/ADXL345.o: D:/ML&IoT\ Lab/STM32/Lib/Source/ADXL345.c Lib/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ML&IoT Lab/STM32/Driver/Include" -I"D:/ML&IoT Lab/STM32/Lib/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Lib-2f-Source

clean-Lib-2f-Source:
	-$(RM) ./Lib/Source/ADXL345.cyclo ./Lib/Source/ADXL345.d ./Lib/Source/ADXL345.o ./Lib/Source/ADXL345.su

.PHONY: clean-Lib-2f-Source

