#include <stdlib.h>
#include <stdio.h>

char	*f(char *p)
{
	p = malloc(10);
	printf("%p", p);
	for (int i = 0; i < 9; i++)
		p[i] = 'a';
	p[9] = '\0';
	return (p);
}

int main(void)
{
	char	*p;
	int		i = 0;
	char	*s;

	s = f(p);
	return (0);
}
