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

	Incoming packet;
	packet.header.raw = 0;
	packet.header.ding = 1;

	internal_servo_cal_point low = { 0, 0.001 };
	internal_servo_cal_point high = { 255, 0.002 };

	Servo& Left = *new InternalServoControl(Peripherials::TA3,
			Peripherials::CC1, low, high);
	Servo& Right = *new InternalServoControl(Peripherials::TA3,
			Peripherials::CC2, low, high);

	Left.Resume();
	Right.Resume();

	Peripherials::UART& RFD900 = Peripherials::UART_A2;

	while (1) {
		while (RFD900.GetBufferLength() < 4)
			;
		unsigned char* data = RFD900.GetBuffer().GetData();
		if (data[0] == '<') {
			RFD900.ClearBuffer();
			Left.GoToAngle(data[1]);
			Right.GoToAngle(data[2]);
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