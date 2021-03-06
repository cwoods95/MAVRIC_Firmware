/*
 * ProtocolData.h
 *
 *  Created on: Oct 1, 2016
 *      Author: James
 */

#ifndef PROTOCOL_PROTOCOLDATA_H_
#define PROTOCOL_PROTOCOLDATA_H_

/* typedef'd in case we want to change it later */
typedef signed char WheelSpeed;

typedef union {
	struct {
		unsigned char wheels :1;
		unsigned char mastCamera :1;
		unsigned char modulePower :1;
		unsigned char soilControl :1;

		unsigned char ding :1;

	};
	unsigned char raw;
} IncomingHeader;

typedef union {
	struct {
		signed char mastTilt :2;
		signed char mastPan :2;
		signed char zoomCtl :2;

		unsigned char camSel :2;
	};
	char raw;

} CameraControl;

typedef union {
	struct {
		unsigned char arm :1;
		unsigned char wheels :1;
		unsigned char soil :1;
		unsigned char mast :1;
	};
	char raw;
} HW_Modules;

typedef union {
	struct {

	/* Need info from the soil team */
	};
	char raw;
} SoilControl;

typedef struct {
	/* wheels */
	union {
		WheelSpeed wheels[2];
		struct {
			WheelSpeed lWheel;
			WheelSpeed rWheel;
		};
	};

	CameraControl camera;
	HW_Modules enables;
	SoilControl soilCtl;

} Command;

typedef struct {
	unsigned char GPS :1;
	unsigned char SoilPH :1;
	unsigned char SoilMoisture :1;
	unsigned char SoilTemp :1;
	unsigned char PowerSystem :1;
	/* address for camera system */
	unsigned char SystemTemps :3;

} Request;

typedef struct {
	IncomingHeader header;
	Command command;
	Request request;

} Incoming;

#endif /* PROTOCOL_PROTOCOLDATA_H_ */
