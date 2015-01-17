#include <util/delay.h>

#include "pinconfig.h"
#include "usart.h"


int main()
{
	int a = 0;
	if(a) USART_init(UBRR);
	return 0;
}
