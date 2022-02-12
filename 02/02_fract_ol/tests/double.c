#include <stdio.h>
#include <math.h>

int	main(void)
{
	double	d;
	long double	ld;
	unsigned long ul;

	printf("size : double %lu, -long double %lu\n", sizeof(double), sizeof(long double));
	ul = pow(1.25, 150);
	printf("pow(1.25, 150) = %lu\n", ul);
	ul = pow(1.25, 170);
	printf("pow(1.25, 170) = %lu\n", ul);
	return (0);
}
