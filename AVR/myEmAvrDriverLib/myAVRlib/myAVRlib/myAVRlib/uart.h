/*
 * uart.h
 *
 * Created: 10-07-2018 18:40:46
 *  Author: shrijith
 */ 

#include <stdint.h>
#include <stdbool.h>
#ifndef UART_H_
#define UART_H_

#define EVEN 0
#define ODD 1
#include<math.h>
#define F_CPU   16000000
//int BAUD=0;   //9600
//int UART_NUM=0;

bool uartInit(uint8_t uartNum, uint16_t baudRate,  uint8_t dataBit,  uint8_t parity,  uint8_t stopBit);
bool uartInterrupt( uint8_t uartNum, uint8_t uartIntflag, bool intStatus);
bool uartPrintText(uint8_t uartNum, char * text );
bool uartPrintValue (uint8_t uartNum, uint32_t value, uint8_t format);
bool uartSendByte (uint8_t uartNum, uint8_t byte);
bool uartSendStream (uint8_t uartNum, uint8_t *stream , uint8_t size);



#endif /* UART_H_ */