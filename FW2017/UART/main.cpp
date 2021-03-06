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

	P9->DIR = 1 << 7;
	P9->SEL0 = 1 << 7;

	P2->DIR |= 7;

	EUSCI_A1->STATW |= UCLISTEN;

	NVIC_EnableIRQ(EUSCIA1_IRQn);
	NVIC_EnableIRQ(EUSCIA3_IRQn);

	__delay_cycles(fSMCLK / 100);

	while (true) {
		Peripherials::UART_A1.Send("Hello World, I am a MSP432 uP.");
		__delay_cycles(fMCLK * 30 * (11) / 9600);

		if (Peripherials::UART_A1.GetBufferLength() == 30) {
			P2->OUT |= 7;
		} else {
			P2->OUT &= ~7;
		}
		for (int i = 0; i < Peripherials::UART_A1.GetBufferLength(); i++) {
			Peripherials::UART_A3.Send(
					Peripherials::UART_A1.GetBuffer().GetData()[i]);
		}
		Peripherials::UART_A1.ClearBuffer();
	}
}
