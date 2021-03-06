/*
 * Servo.hpp
 *
 *  Created on: Sep 6, 2016
 *      Author: James
 */

#ifndef SERVO_SERVO_HPP_
#define SERVO_SERVO_HPP_


class Servo
{
public:
	/*
	 * Disables the control signal to the servo
	 */
	virtual void Suspend() = 0;
	/*
	 * Enables the control signal to the servo.
	 */
	virtual void Resume() = 0;
	/*
	 * Sets the control to the angle given
	 */
	virtual void GoTo(float point) = 0;
	/*
	 * Moves to the center of the calibrated range.
	 */
	virtual void Center() = 0;
};


#endif /* SERVO_SERVO_HPP_ */
