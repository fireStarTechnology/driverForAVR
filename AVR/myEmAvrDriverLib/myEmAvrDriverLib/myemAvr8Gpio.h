/*
 * myemAvr8Gpio.h
 *
 * Created: 16-02-2018 19:25:46
 *  Author: maaply
 */ 


#ifndef MYEMAVR8GPIO_H_
#define MYEMAVR8GPIO_H_

#include <stdint.h>
#include <avr/io.h>

#define SETPIN(port, pin) (port|=(1<<pin))
#define CLEARPIN(port, pin) ( port&=~(1<<pin))

void gpioSetPin( volatile uint8_t *port, unsigned char pin );
void gpioClearPin ( volatile uint8_t  *port, unsigned char pin );
void gpioTogglePin ( volatile uint8_t *port, unsigned char pin );
void gpioPinDirection ( volatile uint8_t *port, unsigned char pin );

void gpioThrowPort( volatile uint8_t *port, unsigned char value );
void gpioDirectionPort(  volatile uint8_t *port, unsigned char value );

void gpioDisableAllPullUp( void );

#endif /* MYEMAVR8GPIO_H_ */