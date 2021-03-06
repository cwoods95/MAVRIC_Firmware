/*
 * PCA9685.cpp
 *
 *  Created on: May 30, 2016
 *      Author: James
 */

#include <PCA9685.hpp>

#include "I2C.hpp"

namespace Externals {

PCA9685::PCA9685(EUSCI_B_Type* I2C_bus, unsigned char I2C_address) :
		Port0(0, *this), Port1(1, *this), Port2(2, *this), Port3(3, *this), Port4(
				4, *this), Port5(5, *this), Port6(6, *this), Port7(7, *this), Port8(
				8, *this), Port9(9, *this), Port10(10, *this), Port11(11,
				*this), Port12(12, *this), Port13(13, *this), Port14(14, *this), Port15(
				15, *this) {
	_address = I2C_address;
	_bus = I2C_bus;

	InitI2C(_bus);

	unsigned char buffer[256];
	int index = 0;
	// Control Register (&MODE1)
	buffer[index++] = 0;
	// MODE1 Register
	buffer[index++] = (1 << 5) | (1 << 4);
	// MODE2 Register
	buffer[index++] = (1 << 3) | (1 << 2);
	// SUBADDR1
	buffer[index++] = 0;
	// SUBADDR2
	buffer[index++] = 0;
	// SUBADDR3
	buffer[index++] = 0;
	// ALLCALLADDR
	buffer[index++] = 0;

	for (int x = 0; x < 16; x++) {
		//LEDx_ON_L
		buffer[index++] = 0;
		//LEDx_ON_H
		buffer[index++] = 0;

		//LEDx_OFF_L
		buffer[index++] = 0;
		//LEDx_OFF_H
		buffer[index++] = 0;
	}

	WriteI2C(_bus, _address, buffer, index);

	index = 0;
	// Control Register (&Prescale)
	buffer[index++] = 254;
	// Prescale value
	buffer[index++] = 0x7F;

	WriteI2C(_bus, _address, buffer, index);

	index = 0;
	// Control Register (&MODE1)
	buffer[index++] = 0;
	// MODE1 Register
	buffer[index++] = (1 << 5);

	WriteI2C(_bus, _address, buffer, index);
}

void PCA9685::SetServoCounts(int ServoIndex, unsigned short OnCounts,
		unsigned short OffCounts) {
	unsigned char buffer[5];
	int index = 0;
	// Control Register (&LEDx_ON_L)
	buffer[index++] = 6 + 4 * ServoIndex;

	//LEDx_ON_L
	buffer[index++] = OnCounts & 0xFF;
	//LEDx_ON_H
	buffer[index++] = OnCounts >> 8;
	//LEDx_OFF_L
	buffer[index++] = OffCounts & 0xFF;
	//LEDx_OFF_H
	buffer[index++] = OffCounts >> 8;

	WriteI2C(_bus, _address, buffer, index);

	__delay_cycles(1000);
}

PCA9685::Port::Port(int index, PCA9685& parent,
		struct pca9685_servo_cal_point low, struct pca9685_servo_cal_point high) :
		_index(index), _offset(3500 * index), _parent(parent), _on(0), _off(0) {
	calibration[0] = low;
	calibration[1] = high;
}

PCA9685::Port::Port(int index, PCA9685& parent) :
		_index(index), _offset(3500 * index), _parent(parent) {

	calibration[0].angle = -90;
	calibration[0].counts = 100;

	calibration[1].angle = 90;
	calibration[1].counts = 500;
}

void PCA9685::Port::SetCalibration(struct pca9685_servo_cal_point low, struct pca9685_servo_cal_point high)
{
	calibration[0] = low;
	calibration[1] = high;
}

void PCA9685::Port::Center() {
	GoTo((calibration[1].angle + calibration[0].angle) / 2);
}

void PCA9685::Port::GoTo(float angle) {
	float percent_range = (angle - calibration[0].angle)
			/ (calibration[1].angle - calibration[0].angle);
	float counts = calibration[0].counts
			+ percent_range * (calibration[1].counts - calibration[0].counts);

	_on = _offset;
	_off = _offset + counts;
	_parent.SetServoCounts(_index, _on, _off);
}

void PCA9685::Port::Suspend() {
	_parent.SetServoCounts(_index, 0, 0);
}

void PCA9685::Port::Resume()
{
	_parent.SetServoCounts(_index, _on, _off);
}
} /* namespace Devices */
