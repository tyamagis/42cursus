#include <stdio.h>

int main(void)
{
	char c = 1;

	int i = 0;
	while (i < 10)
	{
		printf("c : %d, c & 'a' = %d\n", c, c&'a');
		c <<= 1;
		i++;
	}
	return (0);
}
