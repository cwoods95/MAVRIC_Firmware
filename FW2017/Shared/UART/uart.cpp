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

UART UART_A1(*EUSCI_A1, 9600, A1_txQueue, A1_rxBuffer, true);

Buffers::AutoBuffer<300> A2_rawTx;
Buffers::BaseBuffer A2_txBuffer(A2_rawTx.GetData(), A2_rawTx.GetSize());
Buffers::RollingBuffer A2_txQueue(A2_txBuffer);

Buffers::AutoBuffer<300> A2_rawRx;
Buffers::BaseBuffer A2_rxBuffer(A2_rawRx.GetData(), A2_rawRx.GetSize());

UART UART_A2(*EUSCI_A2, 9600, A2_txQueue, A2_rxBuffer, false);

Buffers::AutoBuffer<300> A3_rawTx;
Buffers::BaseBuffer A3_txBuffer(A3_rawTx.GetData(), A3_rawTx.GetSize());
Buffers::RollingBuffer A3_txQueue(A3_txBuffer);

Buffers::AutoBuffer<300> A3_rawRx;
Buffers::BaseBuffer A3_rxBuffer(A3_rawRx.GetData(), A3_rawRx.GetSize());

UART UART_A3(*EUSCI_A3, 9600, A3_txQueue, A3_rxBuffer, false);

UART::UART(EUSCI_A_Type& instance, int baud, Buffers::RollingBuffer backingTx,
		Buffers::BaseBuffer backingRx, bool msb) :
		regs(instance), txBuffer(backingTx), rxBuffer(backingRx), rxIndex(0) {

	regs.CTLW0 = /*UCPEN | UCPAR | */(msb ? UCMSB : 0) | (1 << 7) | UCSWRST;

	int N = (fSMCLK * 256 / baud);
	int NReg = N / 256;
	int F = (N % 16);
	int FReg = (F / 256);

	regs.BRW = (NReg / 16) - 1;
	regs.MCTLW = ((N % 256) << EUSCI_A_MCTLW_BRS_OFS)
			| (FReg << EUSCI_A_MCTLW_BRF_OFS) | UCOS16;
	regs.CTLW0 &= ~UCSWRST;
	regs.IE |= EUSCI_A_IE_RXIE;
}

void UART::Send(char c) {
	txBuffer.Enqueue(c);
	regs.IE |= EUSCI_A_IE_TXIE;
}

void UART::Send(char* str) {
	while (*str != 0) {
		txBuffer.Enqueue(*(str++));
	}
	regs.IE |= 0x02;
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
		// TX complete interrupt
		if (!txBuffer.IsEmpty()) {
			regs.TXBUF = txBuffer.Dequeue();
		} else {
			regs.IE &= ~(0x02);
			regs.IFG |= (0x02);
		}
		break;
	default:
		break;
	}
}

namespace {
extern "C" {
void EUSCIA1_IRQHandler() {
	UART_A1.OnInterrupt();
}
void EUSCIA2_IRQHandler() {
	UART_A2.OnInterrupt();
}
void EUSCIA3_IRQHandler() {
	UART_A3.OnInterrupt();
}
}
}
}

