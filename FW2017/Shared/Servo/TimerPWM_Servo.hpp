/*
 * TimerPWM_Servo.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: James
 */

#ifndef TIMER_PWM_SERVO_HPP_
#define TIMER_PWM_SERVO_HPP_

#include "Servo.hpp"
#include "Timer.hpp"

struct internal_servo_cal_point {
	float angle, period;
};

class InternalServoControl : public Servo {
private:
	Peripherials::Timer& _timer;
	Peripherials::TimerCapComUnit module;
	float angle;

	struct internal_servo_cal_point calibration[2];

public:
	/*
	 * Creates a Servo that is controlled by the given timer compare module
	 */
	InternalServoControl(Peripherials::Timer& timer,
			Peripherials::TimerCapComUnit unit,
			struct internal_servo_cal_point low,
			struct internal_servo_cal_point high);
	/*
	 * Disables the control signal to the servo
	 */
	virtual void Suspend();
	/*
	 * Enables the control signal to the servo.
	 */
	virtual void Resume();
	/*
	 * Sets the control to the angle given
	 */
	virtual void GoTo(float angle);
	/*
	 * Moves to the center of the calibrated range
	 */
	virtual void Center();
};

#endif

