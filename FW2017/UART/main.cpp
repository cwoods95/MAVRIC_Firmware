//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"

#include "clocks.h"
#include "uart.hpp"

void main(void) {

	WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

	//Peripherials::UART uart(*EUSCI_A1, 9600, txQueue);

	P2->DIR = 1 << 3;
	P2->SEL0 = 1 << 3;

	__delay_cycles(fSMCLK/100);

	while (true) {
		Peripherials::UART_A1.Send("Hello World, I am a MSP432 uP.");
		__delay_cycles(fMCLK*17*(11)/9600);
	}
}
