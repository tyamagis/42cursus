/*
 - which is faster <use pow(x, 2)> OR <calc x * x> ?
*/

#include <sys/time.h>
#include <stdio.h>
#include <math.h>

void	printtime(struct timeval *tv)
{
	printf("%lu\n", (tv[1].tv_sec * 1000000 + tv[1].tv_usec) - (tv[0].tv_sec * 1000000 + tv[0].tv_usec));
	return ;
}

int	main(void)
{
	struct timeval	tv[2];
	int				i;
	int				ans;
	double			d;

	printf("1-1. pow(int, 2);");
	i = 1;
	gettimeofday(&tv[0], NULL);
	while (i < 5000000)
	{
		ans = pow(i, 2);
		i++;
	}
	gettimeofday(&tv[1], NULL);
	printtime(tv);

	printf("1-2. int * int;");
	i = 1;
	gettimeofday(&tv[0], NULL);
	while (i < 5000000)
	{
		ans = i * i;
		i++;
	}
	gettimeofday(&tv[1], NULL);
	printtime(tv);

	printf("2-1. pow(double, 2);");
	i = 1;
	gettimeofday(&tv[0], NULL);
	while (i < 5000000)
	{
		d = i;
		ans = pow(d, 2);
		i++;
	}
	gettimeofday(&tv[1], NULL);
	printtime(tv);

	printf("2-2. double * double;");
	i = 1;
	gettimeofday(&tv[0], NULL);
	while (i < 5000000)
	{
		d = i;
		ans = d * d;
		i++;
	}
	gettimeofday(&tv[1], NULL);
	printtime(tv);

	printf("3-1. pow(int, 10);");
	i = 1;
	gettimeofday(&tv[0], NULL);
	while (i < 5000000)
	{
		ans = pow(i, 10);
		i++;
	}
	gettimeofday(&tv[1], NULL);
	printtime(tv);

	printf("3-2. int ^ 10;");
	i = 1;
	gettimeofday(&tv[0], NULL);
	while (i < 5000000)
	{
		ans = i * i * i * i * i * i * i * i * i * i;
		i++;
	}
	gettimeofday(&tv[1], NULL);
	printtime(tv);

	return (0);
}
