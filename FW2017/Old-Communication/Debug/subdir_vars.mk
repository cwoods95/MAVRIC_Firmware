################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers/Buffers.cpp \
G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C/I2C.cpp \
G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo/PCA9685.cpp \
G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo/TimerPWM_Servo.cpp \
../main.cpp \
G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer/timer.cpp \
G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART/uart.cpp 

CMD_SRCS += \
../msp432p401r.cmd 

C_SRCS += \
../startup_msp432p401r_ccs.c \
../system_msp432p401r.c 

OBJS += \
./Buffers.obj \
./I2C.obj \
./PCA9685.obj \
./TimerPWM_Servo.obj \
./main.obj \
./startup_msp432p401r_ccs.obj \
./system_msp432p401r.obj \
./timer.obj \
./uart.obj 

CPP_DEPS += \
./Buffers.d \
./I2C.d \
./PCA9685.d \
./TimerPWM_Servo.d \
./main.d \
./timer.d \
./uart.d 

C_DEPS += \
./startup_msp432p401r_ccs.d \
./system_msp432p401r.d 

CPP_DEPS__QUOTED += \
"Buffers.d" \
"I2C.d" \
"PCA9685.d" \
"TimerPWM_Servo.d" \
"main.d" \
"timer.d" \
"uart.d" 

C_DEPS__QUOTED += \
"startup_msp432p401r_ccs.d" \
"system_msp432p401r.d" 

OBJS__QUOTED += \
"Buffers.obj" \
"I2C.obj" \
"PCA9685.obj" \
"TimerPWM_Servo.obj" \
"main.obj" \
"startup_msp432p401r_ccs.obj" \
"system_msp432p401r.obj" \
"timer.obj" \
"uart.obj" 

CPP_SRCS__QUOTED += \
"G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Buffers/Buffers.cpp" \
"G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/I2C/I2C.cpp" \
"G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo/PCA9685.cpp" \
"G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Servo/TimerPWM_Servo.cpp" \
"../main.cpp" \
"G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/Timer/timer.cpp" \
"G:/Data/MAVRIC/MAVRIC_Firmware/FW2017/Shared/UART/uart.cpp" 

C_SRCS__QUOTED += \
"../startup_msp432p401r_ccs.c" \
"../system_msp432p401r.c" 


