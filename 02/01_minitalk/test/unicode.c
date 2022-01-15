#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int		i;

	printf("%%s : [%s]\n", av[1]);
	i = 0;
	while (av[1][i] != '\0')
	{
		printf("i : %d, %%c : [%c](%x)\n", i, av[1][i], av[1][i]);
		i++;
	}
	write(1, av[1], i);
	return (0);
}
