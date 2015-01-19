#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/interrupt.h>

void USART_Init(unsigned int ubrr);

void USART_Transmit(unsigned char data );

#endif //USART_H
