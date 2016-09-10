//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include <math.h>
#include "msp.h"

#include "timer.hpp"
#include "TimerPWM_Servo.hpp"
#include "clocks.h"

using namespace Peripherials;

void ClearRed() {
	P2->OUT &= ~1;
}

void SetRed() {
	P2->OUT |= 1;
}

void ToggleGreen() {
	P2->OUT ^= 2;
}

void CycleRGB() {
	static int phase = 0;
	static const int divider = 10;
	static int counter = 0;
	counter = (counter + 1) % divider;
	if (!counter) {
		P2->OUT = (P2->OUT & ~0x07) | (1 << phase);
		phase = (phase + 1) % 3;
	}
}

void main(void) {

	WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

	P2->DIR = 0xFF;
	P2->SEL0 = 1 << 4;
	P2->OUT = 0;
	PA->DS = 0;
	PB->DS = 0;
	struct internal_servo_cal_point cal_low = { -90, 0.0005 };
	struct internal_servo_cal_point cal_high = { 0, 0.0015 };
    InternalServoControl tmp = InternalServoControl(TA0, CC1, cal_low, cal_high);
	//InternalServoControl* servo = &tmp;
	Servo* servo = &tmp;
	TA0.AttachInterrupt(CC0, CycleRGB);
	servo->Resume();
	float i, high = 90, low = -90;
	while (true) {
		for (i = low; i < high; i+= .1) {
			servo->GoToAngle(i);
			__delay_cycles(fSMCLK/1000);
		}
		//servo->Suspend();
		__delay_cycles(fSMCLK/3);
		servo->Resume();
		for (i = high; i > low; i-=.1) {
			servo->GoToAngle(i);
			__delay_cycles(fSMCLK/1000);
		}
		//servo->Suspend();
		__delay_cycles(fSMCLK/3);
		servo->Resume();
	}
}
