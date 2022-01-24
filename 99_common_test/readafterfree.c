#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char	*p = malloc(10);

	int i = 0;
	while (i < 9)
	{
		p[i] = i + '0';
		i++;
	}
	p[9] = '\0';
	printf("%s\n", p);
	free(p);
	printf("%s\n", p);
	return (0);
}
