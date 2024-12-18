################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/ULTRASONIC_SENSOR/ULTRASONIC.c 

OBJS += \
./HAL/ULTRASONIC_SENSOR/ULTRASONIC.o 

C_DEPS += \
./HAL/ULTRASONIC_SENSOR/ULTRASONIC.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/ULTRASONIC_SENSOR/ULTRASONIC.o: ../HAL/ULTRASONIC_SENSOR/ULTRASONIC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/ULTRASONIC_SENSOR/ULTRASONIC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

