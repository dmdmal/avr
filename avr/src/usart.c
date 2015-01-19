#include "usart.h"
#include "pinconfig.h"

/* USART Initialization */
void USART_Init(unsigned int ubrr){
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
} /* USART_Init */

/* Sending Frames with 5 to 8 Data Bit */
void USART_Transmit(unsigned char data){
	/* Wait for empty transmit buffer */
	while ( !(UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
} /* USART_Transmit */

/* Sending Frames with 9 Data Bit */
void USART_Transmit(unsigned int data){
	/* Wait for empty transmit buffer */
	while ( !(UCSR0A & (1<<UDRE0)) );
	/* Copy 9th bit to TXB8 */
	UCSR0B &= ~(1<<TXB80);
	if ( data & 0x0100 )
	UCSR0B |= (1<<TXB80);
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

/* Receiving Frames with 5 to 8 Data Bits */
unsigned char USART_Receive(void){
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )	;
	/* Get and return received data from buffer */
	return UDR0;
}

/* Receiving Frames with 9 Data Bits */
unsigned int USART_Receive(void){
	unsigned char status, resh, resl;
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSR0A;
	resh = UCSR0B;
	resl = UDR0;
	/* If error, return -1 */
	if ( status & (1<<FE0)|(1<<DOR0)|(1<<UPE0) )
		return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}
