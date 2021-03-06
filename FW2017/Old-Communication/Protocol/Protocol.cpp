/*
 * Protocol.c
 *
 *  Created on: Oct 1, 2016
 *      Author: James
 */

#include "ProtocolData.h"

bool IsComplete(IncomingHeader header, int count) {
	int needed = 0;
	if (header.wheels) {
		needed += 2;
	}
	if (header.mastCamera) {
		needed += 1;
	}
	if (header.modulePower) {
		needed += 1;
	}
	if (header.soilControl) {
		needed += 1;
	}
	/* a byte for the sensor requests */
	needed++;

	return needed <= count;
}

Incoming Decode(unsigned char* data) {
	Incoming packet;
	packet.header.raw = data[0];
	int i = 1;
	if (packet.header.wheels) {
		packet.command.wheels[0] = data[i++];
		packet.command.wheels[1] = data[i++];
	}
	if (packet.header.mastCamera) {
		packet.command.camera.raw = data[i++];
	}
	if (packet.header.modulePower) {
		packet.command.enables.raw = data[i++];
	}
	if (packet.header.soilControl) {
		packet.command.soilCtl.raw = data[i++];
	}
	return packet;
}
