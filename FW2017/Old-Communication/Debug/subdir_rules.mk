################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Buffers.obj: G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers/Buffers.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Buffers.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

I2C.obj: G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C/I2C.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="I2C.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

PCA9685.obj: G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo/PCA9685.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="PCA9685.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

TimerPWM_Servo.obj: G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo/TimerPWM_Servo.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="TimerPWM_Servo.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup_msp432p401r_ccs.obj: ../startup_msp432p401r_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="startup_msp432p401r_ccs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

system_msp432p401r.obj: ../system_msp432p401r.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="system_msp432p401r.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer/timer.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="timer.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart.obj: G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART/uart.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -Ooff --opt_for_speed=0 --fp_mode=strict --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication/Protocol" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Old-Communication" --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power="all" --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="uart.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


