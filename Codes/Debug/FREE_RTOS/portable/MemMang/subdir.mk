################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FREE_RTOS/portable/MemMang/heap_4.c 

OBJS += \
./FREE_RTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./FREE_RTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FREE_RTOS/portable/MemMang/heap_4.o: ../FREE_RTOS/portable/MemMang/heap_4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/portable/MemMang/heap_4.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

