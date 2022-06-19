################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/lists/generic_list.c 

OBJS += \
./component/lists/generic_list.o 

C_DEPS += \
./component/lists/generic_list.d 


# Each subdirectory must supply rules for building sources it contributes
component/lists/%.o: ../component/lists/%.c component/lists/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/freertos/freertos_kernel/portable/GCC/ARM_CM0" -Os -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


