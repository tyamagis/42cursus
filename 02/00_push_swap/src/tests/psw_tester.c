#include <stdio.h>
#include <stdlib.h>

void	show_usage(void)
{
	printf("\n\
	this is push_swap tester program.\n\
	\n\
	./tester N(int) M(int)\n\
	will run push_swap M times with N args.\n\
	M should be smaller than (N! - 1).\n\
	\n\
	./testre N(int)\n\
	will run push_swap N times with N args.\n");
	exit(0);
}

void	gen_cmd_set(int *arg_set, char **cmd_set)
{
	**cmd_set = *arg_set;
	return ;
}

void	do_test(int n, int m)
{
	int		arg_set[m][n];
	char	*cmd_set[m];
	int		ret;
	int		i;
	int		min, max, avg;

	gen_cmd_set(arg_set[m], cmd_set);
	avg = 0;
	while (i < m)
	{
		ret = system("./push_swap 5 3 7"); // "./push_swap a b c d ..."
		//ret >>= 8;
		printf("%d / %d : Operation %d .\n", i, m, ret);
		avg += ret;
		if (i == 1)
		{
			min = ret;
			max = ret;
		}
		if (ret < min)
			min = ret;
		if (ret > max)
			max = ret;
		i++;
	}
	avg /= m;
	printf("\n ===== RESULT =====\n");
	printf("avg : %d (min : %d, max : %d)\n", avg, min, max);
	return ;
}

int main(int ac, char **av)
{
	if (ac == 1 || ac > 3)
		show_usage();
	else if (ac == 2)
		do_test(atoi(av[1]), atoi(av[1]));
	else
		do_test(atoi(av[1]), atoi(av[2]));
	return (0);
}