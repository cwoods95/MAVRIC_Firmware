################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Timer/timer.obj: ../Timer/timer.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/TI/ccsv6/ccs_base/arm/include" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/ServoControl/I2C" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/ServoControl/Device" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/ServoControl/Servo" --include_path="G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/ServoControl/Timer" --include_path="C:/TI/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/TI/ccsv6/tools/compiler/ti-cgt-arm_16.6.0.STS/include" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Timer/timer.d" --obj_directory="Timer" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


