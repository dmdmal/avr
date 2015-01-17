#include <avr/io.h>

#include "usart.h"
#include "pinconfig.h"

void USART_Init(unsigned int ubrr){
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<USBS)|(3<<UCSZ0);
} // USART_Init

void USART_Transmit(unsigned char data){
	/* Wait for empty transmit buffer */
	while ( !( UCSRnA & (1<<UDREn)) )
	;
	/* Put data into buffer, sends the data */
	UDRn = data;
}
