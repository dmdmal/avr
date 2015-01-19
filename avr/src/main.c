#include <util/delay.h>

#include "pinconfig.h"
#include "usart.h"


int main(){
	/*USART Initialization*/
	USART_init(UBRR);
	/* Sending Frames with 5 to 8 Data Bit */
	USART_Transmit();
	return 0;
}
