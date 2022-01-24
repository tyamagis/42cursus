#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 1;
	int c = 0;

	if (a > 0)
	{
		if (b > 0){c = 5;}
		else{a = b;}
	}
	printf("%d, %d, %d\n", a, b, c);
	return (0);
}
