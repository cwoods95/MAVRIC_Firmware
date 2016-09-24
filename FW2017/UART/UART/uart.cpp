/*
 * uart.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: James
 */

#include "uart.hpp"
#include "clocks.h"

namespace Peripherials {

Buffers::AutoBuffer<300> A1_rawTx;
Buffers::BaseBuffer A1_txBuffer(A1_rawTx.GetData(), A1_rawTx.GetSize());
Buffers::RollingBuffer A1_txQueue(A1_txBuffer);

Buffers::AutoBuffer<300> A1_rawRx;
Buffers::BaseBuffer A1_rxBuffer(A1_rawRx.GetData(), A1_rawRx.GetSize());

UART UART_A1(*EUSCI_A1, 9600, A1_txQueue, A1_rxBuffer);

UART::UART(EUSCI_A_Type& instance, int baud, Buffers::RollingBuffer backingTx,
		Buffers::BaseBuffer backingRx) :
		regs(instance), txBuffer(backingTx), rxBuffer(backingRx), rxIndex(0) {
	regs.CTLW0 = UCPEN | UCPAR | UCMSB | (1 << 7) | UCSWRST | UCSPB;

	int N = (fSMCLK * 256 / baud);
	int NReg = N / 256;
	int F = (N % 16);
	int FReg = (F / 256);

	regs.BRW = (NReg / 16);
	regs.CTLW0 &= ~UCSWRST;
	regs.MCTLW = ((N % 256) << EUSCI_A_MCTLW_BRS_OFS)
			| (FReg << EUSCI_A_MCTLW_BRF_OFS) | UCOS16;
	NVIC_EnableIRQ(EUSCIA1_IRQn);
}

void UART::Send(char c) {
	txBuffer.Enqueue(c);
	regs.IE |= 0x02 | 0x08;
}

void UART::Send(char* str) {
	while (*str != 0) {
		txBuffer.Enqueue(*(str++));
	}
	regs.IE |= 0x02 | 0x08;
}

Buffers::BaseBuffer UART::GetBuffer() {
	return rxBuffer;
}

void UART::ClearBuffer() {
	rxIndex = 0;
}

int UART::GetBufferLength() {
	return rxIndex;
}

void UART::OnInterrupt() {
	switch (regs.IV) {
	case 0:
		// no interrupt (shouldn't occur)
		break;
	case 2:
		if (rxIndex < rxBuffer.GetSize()) {
			rxBuffer.GetData()[rxIndex++] = regs.RXBUF;
		}
		break;
	case 4:
	case 8:
		// TX complete interrupt
		if (!txBuffer.IsEmpty()) {
			regs.TXBUF = txBuffer.Dequeue();
		} else {
			regs.IE &= ~(0x02 | 0x08);
		}
		break;
	}
}

namespace {
extern "C" {
void EUSCIA1_IRQHandler() {
	UART_A1.OnInterrupt();
}
}
}
}

