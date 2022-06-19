################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/HELLO_RTOS_freertos_hello/freertos/freertos_kernel/portable/GCC/ARM_CM0" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


