################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/lpuart_adapter.c 

OBJS += \
./component/uart/lpuart_adapter.o 

C_DEPS += \
./component/uart/lpuart_adapter.d 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c component/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/Task_05/freertos/freertos_kernel/portable/GCC/ARM_CM0" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


