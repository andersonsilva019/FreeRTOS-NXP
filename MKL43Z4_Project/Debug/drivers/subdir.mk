################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_smc.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_smc.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_smc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL43Z256VLH4 -DCPU_MKL43Z256VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/component/uart" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/component/serial_manager" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/utilities" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/component/lists" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/device" -I"/home/anderson/setimo-semestre/RTOS/praticas/MKL43Z4_Project/CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


