/*
 * PCA9685.hpp
 *
 *  Created on: May 30, 2016
 *      Author: James
 */

#ifndef INCLUDE_PCA9685_HPP_
#define INCLUDE_PCA9685_HPP_

#include "msp.h"
#include "Servo.hpp"

namespace Externals {

struct pca9685_servo_cal_point {
	float angle;
	uint16_t counts;
};

class PCA9685 {
private:
	unsigned char _address;
	EUSCI_B_Type* _bus;

public:
	class Port: public Servo {
	private:
		int _index;
		unsigned short _offset;
		PCA9685& _parent;
		uint16_t _on, _off;

		struct pca9685_servo_cal_point calibration[2];

	public:

		unsigned short LowerLimit;
		unsigned short UpperLimit;

		Port(int index, PCA9685& parent, struct pca9685_servo_cal_point low,
				struct pca9685_servo_cal_point high);
		Port(int index, PCA9685& parent);
		void SetCalibration(struct pca9685_servo_cal_point low, struct pca9685_servo_cal_point high);
		virtual void GoTo(float percent);
		virtual void Center();
		virtual void Suspend();
		virtual void Resume();
	};
	Port Port0;
	Port Port1;
	Port Port2;
	Port Port3;
	Port Port4;
	Port Port5;
	Port Port6;
	Port Port7;
	Port Port8;
	Port Port9;
	Port Port10;
	Port Port11;
	Port Port12;
	Port Port13;
	Port Port14;
	Port Port15;

	PCA9685(EUSCI_B_Type* I2C_bus, unsigned char I2C_address);
	void SetServoCounts(int PortIndex, unsigned short OnCounts,
			unsigned short OffCounts);
};

} /* namespace Devices */

#endif /* INCLUDE_PCA9685_HPP_ */
