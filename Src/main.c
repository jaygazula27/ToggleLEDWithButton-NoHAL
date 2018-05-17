#include "stm32f4xx.h" // CMSIS headers

int main(void)
{
	int i = 10;
	i += 542;
	i += 204215;
	while (1) {
		i += 5530;
	}
	return 0;
}
