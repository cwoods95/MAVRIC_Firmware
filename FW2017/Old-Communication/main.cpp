//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"

#include "clocks.h"
#include "uart.hpp"
#include "ProtocolData.h"
#include "Protocol.hpp"
#include "TimerPWM_Servo.hpp"
#include "timer.hpp"

int ramp(int leftWheel, unsigned char data) {
	if (leftWheel < data) {
		if (leftWheel + 10 < data) {
			leftWheel += 10;
		} else {
			leftWheel = data;
		}
	} else {
		if (leftWheel - 10 > data) {
			leftWheel -= 10;
		} else {
			leftWheel = data;
		}
	}
	return leftWheel;
}

void main(void) {

	WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
	//<left right # # # # # # # # # # # # #>
	//Peripherials::UART uart(*EUSCI_A1, 9600, txQueue);

	P2->DIR |= 7;

	P3->SEL0 |= 0x0C;
	P3->DIR |= 0x08;

	P8->OUT |= 4;
	P8->DIR |= 4;
	P8->SEL0 |= 4;

	P10->SEL0 |= 1 << 5;
	P10->DIR |= 1 << 5;

	//EUSCI_A1->STATW |= UCLISTEN;

	NVIC_EnableIRQ(EUSCIA2_IRQn);
	NVIC_EnableIRQ(TA3_0_IRQn);
	NVIC_EnableIRQ(TA3_N_IRQn);

	Incoming packet;
	packet.header.raw = 0;
	packet.header.ding = 1;

	internal_servo_cal_point low = { 0, 0.0012 };
	internal_servo_cal_point high = { 255, 0.0018 };

//	internal_servo_cal_point low = { 0, 0.001 };
//	internal_servo_cal_point high = { 255, 0.002 };

	Servo& Left = *new InternalServoControl(Peripherials::TA3,
			Peripherials::CC1, low, high);
	Servo& Right = *new InternalServoControl(Peripherials::TA3,
			Peripherials::CC2, low, high);

	Left.GoTo(127);
	Right.GoTo(127);

	Left.Resume();
	Right.Resume();
	int last_time = Peripherials::TA3.GetOverflowCount();
	Peripherials::UART& RFD900 = Peripherials::UART_A2;
	int leftWheel = 127;
	int rightWheel = 127;
	while (1) {

		while (RFD900.GetBufferLength() < 4) {
			int new_time = Peripherials::TA3.GetOverflowCount();
			// 2 Seconds
			if (new_time - last_time > 50 * 1) {
				Left.GoTo(127);
				Right.GoTo(127);
			}
		}
		unsigned char* data = RFD900.GetBuffer().GetData();
		if (data[0] == '<') {
			last_time = Peripherials::TA3.GetOverflowCount();
			RFD900.ClearBuffer();
			leftWheel = ramp(leftWheel, data[1]);
			rightWheel = ramp(rightWheel, data[2]);
			Left.GoTo(leftWheel);
			Right.GoTo(rightWheel);
		} else {
			int count = 4;
			char c = data[3];
			while (c != '>') {
				if (count < RFD900.GetBufferLength()) {
					c = data[count++];
				}
			}
			RFD900.ClearBuffer();
		}
	}
	/*
	 while (1) {
	 int start = 0;
	 while (RFD900.GetBufferLength() < start+1)
	 ;
	 while (RFD900.GetBuffer().GetData()[start] != '<') {
	 if (start < RFD900.GetBufferLength()) {
	 start++;
	 RFD900.Send(0x55);
	 }
	 }
	 while (RFD900.GetBufferLength() < start + 2)
	 ;
	 unsigned char left = RFD900.GetBuffer().GetData()[start + 1];
	 while (RFD900.GetBufferLength() < start + 3)
	 ;
	 unsigned char right = RFD900.GetBuffer().GetData()[start + 2];
	 int end = start + 3;
	 while (RFD900.GetBufferLength() < end + 1)
	 ;
	 while (RFD900.GetBuffer().GetData()[end] != '>') {
	 if (end < RFD900.GetBufferLength()) {
	 end++;
	 }
	 }
	 RFD900.ClearBuffer();
	 Left.GoToAngle(left);
	 Right.GoToAngle(right);
	 }
	 */
	while (1)
		;
}
