################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/freertos_kernel/croutine.c \
../freertos/freertos_kernel/event_groups.c \
../freertos/freertos_kernel/list.c \
../freertos/freertos_kernel/queue.c \
../freertos/freertos_kernel/stream_buffer.c \
../freertos/freertos_kernel/tasks.c \
../freertos/freertos_kernel/timers.c 

OBJS += \
./freertos/freertos_kernel/croutine.o \
./freertos/freertos_kernel/event_groups.o \
./freertos/freertos_kernel/list.o \
./freertos/freertos_kernel/queue.o \
./freertos/freertos_kernel/stream_buffer.o \
./freertos/freertos_kernel/tasks.o \
./freertos/freertos_kernel/timers.o 

C_DEPS += \
./freertos/freertos_kernel/croutine.d \
./freertos/freertos_kernel/event_groups.d \
./freertos/freertos_kernel/list.d \
./freertos/freertos_kernel/queue.d \
./freertos/freertos_kernel/stream_buffer.d \
./freertos/freertos_kernel/tasks.d \
./freertos/freertos_kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/freertos_kernel/%.o: ../freertos/freertos_kernel/%.c freertos/freertos_kernel/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_06_EVENTOS_TEMPORAIS/freertos/freertos_kernel/portable/GCC/ARM_CM0" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


