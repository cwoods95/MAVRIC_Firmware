//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"

void main(void) {

	WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

	P2->DIR = 0x07;
	P2->OUT = 0x07;

	while (true) {
		__delay_cycles(100000);
		P2->OUT = 0x00;
		__delay_cycles(100000);
		P2->OUT = 0x07;
	}
}