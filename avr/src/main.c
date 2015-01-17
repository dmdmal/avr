#include <util/delay.h>

#include "pinconfig.h"
#include "usart.h"


int main()
{
	int a;
	if(a) USART_init(MYUBRR);
	return 0;
}
