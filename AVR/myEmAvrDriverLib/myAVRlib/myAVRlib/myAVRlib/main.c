/*
 * myAVRlib.c
 *
 * Created: 10-07-2018 18:38:58
 * Author : shrijith
 */  

#include <avr/io.h>
#include "uart.h"
//#include "uart.c"

int main(void)
{
	uartInit(0,9600,8,1,1);                               //uartInit(uint8_t uartNum, uint16_t baudRate,  uint8_t dataBit,  uint8_t parity,  uint8_t stopBit)
    /* Replace with your application code */
    while (1) 
    {
    }
}

