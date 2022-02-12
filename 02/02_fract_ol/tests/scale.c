#include <stdio.h>

int main(void)
{
	int	int_max;
	unsigned int	uint_max;
	long	long_max;
	unsigned long	ulong_max;
	float	f;
	double	d;
	long double	ld;

	int_max = 0x7fffffff;
	uint_max = 0xffffffff;
	long_max = 0x7fffffffffffffff;
	ulong_max = 0xffffffffffffffff;

	printf("size\n");
	printf("int : %lu, long : %lu\n", sizeof(int), sizeof(long));
	printf("float : %lu, double : %lu, long double : %lu\n", sizeof(float), sizeof(double), sizeof(long double));
	printf("max\n");
	printf("int max = %d, unsigned int max = %u\n", int_max, uint_max);
	printf("long_max = %ld, unsigned long max = %lu\n", long_max, ulong_max);
	printf("float\n");
	int i = 0;
	f = 0;
	while (i < 32)
	{
		printf("%d : float = %f\n", i, f);
		f += 0b1;
		i++;
	}

	return (0);
}
