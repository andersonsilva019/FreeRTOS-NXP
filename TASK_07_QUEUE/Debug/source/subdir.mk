################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/task07.c \
../source/task07_main.c 

OBJS += \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/task07.o \
./source/task07_main.o 

C_DEPS += \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/task07.d \
./source/task07_main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFRDM_KL43Z -DFREEDOM -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/freertos/freertos_kernel/include" -I"/home/anderson/setimo-semestre/RTOS/praticas/TASK_07_QUEUE/freertos/freertos_kernel/portable/GCC/ARM_CM0" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


