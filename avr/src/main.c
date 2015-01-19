#include <util/delay.h>

#include "pinconfig.h"
#include "usart.h"


int main(){
	USART_init(UBRR);
	USART_Transmit();
	return 0;
}
