################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/modbus/rtu/mbcrc.c \
../Middlewares/Third_Party/modbus/rtu/mbrtu_m.c 

OBJS += \
./Middlewares/Third_Party/modbus/rtu/mbcrc.o \
./Middlewares/Third_Party/modbus/rtu/mbrtu_m.o 

C_DEPS += \
./Middlewares/Third_Party/modbus/rtu/mbcrc.d \
./Middlewares/Third_Party/modbus/rtu/mbrtu_m.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/modbus/rtu/%.o Middlewares/Third_Party/modbus/rtu/%.su: ../Middlewares/Third_Party/modbus/rtu/%.c Middlewares/Third_Party/modbus/rtu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/aHoang/STM32F4_MODBUS_RTU/Middlewares/Third_Party/modbus/include" -I"D:/aHoang/STM32F4_MODBUS_RTU/Middlewares/Third_Party/modbus/include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I/STM32F4_MODBUS_RTU/Middlewares/Third_Party/modbus/include -I"D:/Modbusrtu_stm32/STM32_RTU/STM32_HAL_FREEMODBUS_RTU-master/Middlewares/Third_Party/modbus/rtu" -I"D:/Modbusrtu_stm32/STM32_RTU/STM32_HAL_FREEMODBUS_RTU-master/Middlewares/Third_Party/modbus/include" -I"D:/Modbusrtu_stm32/STM32_RTU/STM32_HAL_FREEMODBUS_RTU-master/Middlewares/Third_Party/modbus/port" -I"D:/aHoang/STM32F4_MODBUS_RTU/Middlewares/Third_Party/modbus/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-modbus-2f-rtu

clean-Middlewares-2f-Third_Party-2f-modbus-2f-rtu:
	-$(RM) ./Middlewares/Third_Party/modbus/rtu/mbcrc.d ./Middlewares/Third_Party/modbus/rtu/mbcrc.o ./Middlewares/Third_Party/modbus/rtu/mbcrc.su ./Middlewares/Third_Party/modbus/rtu/mbrtu_m.d ./Middlewares/Third_Party/modbus/rtu/mbrtu_m.o ./Middlewares/Third_Party/modbus/rtu/mbrtu_m.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-modbus-2f-rtu

