################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/PRATICA_06_SEMAFOROS_KL25Z.c \
../source/mtb.c \
../source/semihost_hardfault.c 

OBJS += \
./source/PRATICA_06_SEMAFOROS_KL25Z.o \
./source/mtb.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/PRATICA_06_SEMAFOROS_KL25Z.d \
./source/mtb.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_OS_FREE_RTOS -DFSL_RTOS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/board" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/source" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/freertos" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/startup" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/CMSIS" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/drivers" -I"/home/anderson/setimo-semestre/RTOS/praticas/PRATICA_06_SEMAFOROS_KL25Z/utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


