#include <stdio.h>

int main(void)
{
	int i;
	long l;

	i = -2147483648;
	l = i;
	printf("i = -2147483648, l = i, i : %d, l : %ld\n", i, l);
	l *= -1;
	printf("i = -2147483648, l *= -1, i : %d, l : %ld\n", i, l);
	return (0);
}
