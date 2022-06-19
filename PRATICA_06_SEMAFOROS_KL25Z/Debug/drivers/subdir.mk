################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_lpsci_freertos.c \
../drivers/fsl_lptmr.c \
../drivers/fsl_pit.c \
../drivers/fsl_smc.c \
../drivers/fsl_tpm.c \
../drivers/fsl_tsi_v4.c \
../drivers/fsl_uart.c \
../drivers/fsl_uart_freertos.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_lpsci_freertos.o \
./drivers/fsl_lptmr.o \
./drivers/fsl_pit.o \
./drivers/fsl_smc.o \
./drivers/fsl_tpm.o \
./drivers/fsl_tsi_v4.o \
./drivers/fsl_uart.o \
./drivers/fsl_uart_freertos.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_lpsci_freertos.d \
./drivers/fsl_lptmr.d \
./drivers/fsl_pit.d \
./drivers/fsl_smc.d \
./drivers/fsl_tpm.d \
./drivers/fsl_tsi_v4.d \
./drivers/fsl_uart.d \
./drivers/fsl_uart_freertos.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/freertos" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/startup" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

