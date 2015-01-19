#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/interrupt.h>

/*USART Initialization*/
void USART_Init(unsigned int ubrr);

/* Sending Frames with 5 to 8 Data Bit */
void USART_Transmit(unsigned char data );

/* Sending Frames with 9 Data Bit */
void USART_Transmit(unsigned int data);

/* Receiving Frames with 5 to 8 Data Bits */
unsigned char USART_Receive(void);

/* Receiving Frames with 9 Data Bits */
unsigned int USART_Receive(void){

#endif //USART_H
