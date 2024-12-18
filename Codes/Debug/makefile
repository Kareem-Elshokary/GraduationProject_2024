################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/subdir.mk
-include HAL/ULTRASONIC_SENSOR/subdir.mk
-include HAL/SERVO_MOTOR/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include FREE_RTOS/portable/MemMang/subdir.mk
-include FREE_RTOS/portable/GCC/ARM_CM3/subdir.mk
-include FREE_RTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GP_SELF-PARKING_APPLICATION.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GP_SELF-PARKING_APPLICATION.list \

OBJCOPY_BIN += \
GP_SELF-PARKING_APPLICATION.bin \


# All Target
all: GP_SELF-PARKING_APPLICATION.elf secondary-outputs

# Tool invocations
GP_SELF-PARKING_APPLICATION.elf: $(OBJS) $(USER_OBJS) D:\1\ -\ Embedded\ systems\Programs\GP_Tests\GP_SELF-PARKING_APPLICATION\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "GP_SELF-PARKING_APPLICATION.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\1 - Embedded systems\Programs\GP_Tests\GP_SELF-PARKING_APPLICATION\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GP_SELF-PARKING_APPLICATION.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GP_SELF-PARKING_APPLICATION.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GP_SELF-PARKING_APPLICATION.list"
	@echo 'Finished building: $@'
	@echo ' '

GP_SELF-PARKING_APPLICATION.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GP_SELF-PARKING_APPLICATION.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
