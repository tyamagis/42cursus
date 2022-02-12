#include <stdio.h>

int main(void)
{
	int	a[100];

	printf("a(%d %p), &a(%p), *a(%d)\n", a, a, &a, *a);
	for (int i = 0; i < 20; i++)
	{
		*a = i;
		a++;
	}
	printf("a(%d %p), &a(%p), *a(%d)\n", a, a, &a, *a);
	return (0);
}
