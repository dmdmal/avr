#define F_CPU 16000000UL
#include <util/delay.h>

#include "pinconfig.h"
#include "usart.h"


int main()
{
	USART_init(MYUBRR);
	return 0;
}
