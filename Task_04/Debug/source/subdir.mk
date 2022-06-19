################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/task04.c 

OBJS += \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/task04.o 

C_DEPS += \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/task04.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_04/freertos/freertos_kernel/portable/GCC/ARM_CM0" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


