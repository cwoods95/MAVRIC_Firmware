//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include <math.h>
#include "msp.h"

#include "timer.hpp"
#include "TimerPWM_Servo.hpp"
#include "PCA9685.hpp"
#include "clocks.h"

using namespace Peripherials;
using namespace Externals;

void main(void) {

	WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

	P2->DIR = 0xFF;
	P2->SEL0 = 1 << 4;
	P2->OUT = 0;
	PA->DS = 0;
	PB->DS = 0;

	P10->DIR = (1 << 2) | (1 << 3);
	P10->SEL0 = (1 << 2) | (1 << 3);
	/*
	struct internal_servo_cal_point cal_low = { -90, 0.0005 };
	struct internal_servo_cal_point cal_high = { 0, 0.0015 };
    InternalServoControl tmp = InternalServoControl(TA0, CC1, cal_low, cal_high);
	//InternalServoControl* servo = &tmp;
	*/
	struct pca9685_servo_cal_point cal_low = { -90, 100 };
	struct pca9685_servo_cal_point cal_high = { 90, 490 };
	PCA9685 driver = PCA9685(EUSCI_B3, 0x40);
	driver.Port0.SetCalibration(cal_low, cal_high);
	driver.Port1.SetCalibration(cal_low, cal_high);

	Servo* servo = &driver.Port0;
	Servo* servo1 = &driver.Port1;

	servo->Resume();
	servo1->Resume();
	float i, high = 90, low = -90;
	while (true) {
		for (i = low; i < high; i+= 2) {
			servo->GoTo(i);
			servo1->GoTo(i);
			__delay_cycles(fSMCLK/100);
		}
		//servo->Suspend();
		__delay_cycles(fSMCLK/3);
		servo->Resume();
		for (i = high; i > low; i-= 2) {
			servo->GoTo(i);
			servo1->GoTo(i);
			__delay_cycles(fSMCLK/100);
		}
		//servo->Suspend();
		__delay_cycles(fSMCLK/3);
		servo->Resume();
		servo1->Resume();
	}
}
