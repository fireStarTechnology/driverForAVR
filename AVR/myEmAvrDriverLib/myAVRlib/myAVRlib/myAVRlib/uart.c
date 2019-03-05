/*
 * uart.c
 *
 * Created: 10-07-2018 18:40:18
 *  Author: shrijith
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
//#include "uart.c"
//#include <util/delay.h>


/*
need to ask Mahesh about electronic re thing
unsigned char recieveUart (void)
{
	while (! (UCSR0A & (1 << RXC0)) );       // waiting untill u recieve something
    return UDR0;                            // return whatever is there in the buffer back to the program
}

void transmitUart (unsigned char data)
{
	while (! (UCSR0A & (1 << UDRE0)) );   // wit untill transmitter is ready
	UDR0 = data;                          // data o/p  here 
}

*/

bool uartInit(uint8_t uartNum, uint16_t baudRate,  uint8_t dataBit,  uint8_t parity,  uint8_t stopBit)
{
	uint16_t UBBRValue = lrint(( F_CPU / (16L * baudRate) ) - 1);   //Baud calculator formula
	// change 0 to 1 if u need 1st channel UART arduino-uno has only one I guess
	UBRR0H = (unsigned char) (UBBRValue >> 8);   //   Put the upper part of the baud number here (bits 8 to 11)

	UBRR0L = (unsigned char) UBBRValue;          //   Put the remaining part of the baud number here
	
	UCSR0B = (1 << RXEN0)  | (1 << TXEN0);      //    Enabling Rx,Tx 
	
	// The data bit part
	if (dataBit == 6)
	{
		UCSR0C |= (1 << UCSZ00);      //  6 Length of data bits	
	}
	if (dataBit == 7)
	{
		UCSR0C |= (2 << UCSZ00);      //  6 Length of data bits
	}
	if (dataBit == 8)
	{
		UCSR0C |= (3 << UCSZ00);      //  6 Length of data bits
	}
	if (dataBit == 9)
	{
		UCSR0C |= (7 << UCSZ00);      //  6 Length of data bits
	}
	
	
	// The parity Part	
	if (parity == EVEN)
	{
		UCSR0C |=(1 << UPM01);        //   Even parity setting
	}
	if (parity == ODD)
	{
		UCSR0C |=(3 << UPM00);        //   Odd Parity setting
	}
	
	
	//Stop bit part 
	if (stopBit == 2)
	{
		UCSR0C |= (1 << USBS0);      //  set 2 STOP bits	
	}
	if (stopBit == 1)
	{
		UCSR0C &= ~(1 << USBS0);      //clears the USBS for 1 stop bit    
	}
	return 0;
}