################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/serial_manager.c \
../component/serial_manager/serial_port_uart.c 

OBJS += \
./component/serial_manager/serial_manager.o \
./component/serial_manager/serial_port_uart.o 

C_DEPS += \
./component/serial_manager/serial_manager.d \
./component/serial_manager/serial_port_uart.d 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c component/serial_manager/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/freertos/freertos_kernel/portable/GCC/ARM_CM0" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


