################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FREE_RTOS/croutine.c \
../FREE_RTOS/event_groups.c \
../FREE_RTOS/list.c \
../FREE_RTOS/queue.c \
../FREE_RTOS/stream_buffer.c \
../FREE_RTOS/tasks.c \
../FREE_RTOS/timers.c 

OBJS += \
./FREE_RTOS/croutine.o \
./FREE_RTOS/event_groups.o \
./FREE_RTOS/list.o \
./FREE_RTOS/queue.o \
./FREE_RTOS/stream_buffer.o \
./FREE_RTOS/tasks.o \
./FREE_RTOS/timers.o 

C_DEPS += \
./FREE_RTOS/croutine.d \
./FREE_RTOS/event_groups.d \
./FREE_RTOS/list.d \
./FREE_RTOS/queue.d \
./FREE_RTOS/stream_buffer.d \
./FREE_RTOS/tasks.d \
./FREE_RTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FREE_RTOS/croutine.o: ../FREE_RTOS/croutine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FREE_RTOS/event_groups.o: ../FREE_RTOS/event_groups.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FREE_RTOS/list.o: ../FREE_RTOS/list.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FREE_RTOS/queue.o: ../FREE_RTOS/queue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FREE_RTOS/stream_buffer.o: ../FREE_RTOS/stream_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FREE_RTOS/tasks.o: ../FREE_RTOS/tasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
FREE_RTOS/timers.o: ../FREE_RTOS/timers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/include" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/FREE_RTOS/portable/GCC/ARM_CM3" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/ULTRASONIC_SENSOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/SERVO_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/HAL/DC_MOTOR" -I"D:/1 - Embedded systems/Programs/GP_Tests/GP_SELF-PARKING_APPLICATION/MCAL/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FREE_RTOS/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

