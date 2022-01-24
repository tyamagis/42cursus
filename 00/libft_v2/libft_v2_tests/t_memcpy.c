#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	set_a(void *a)
{
	char	*ca;
	int	i = 0;
	ca = (char *)a;
	while (i++ < 15)
		*ca++ = 'a';
	*ca = 0;
}

void	set_b(void *b)
{
	char	*cb;
	int	i = 0;
	cb = (char *)b;
	while (i++ < 15)
		*cb++ = 'b';
	*cb = 0;
}

int main(void)
{
	void *a = malloc(16);
	void *b = malloc(16);

	set_a(a);
	set_b(b);
	printf("setting : \n");
	printf("a [%s] (%p)\nb [%s] (%p)\n", a, a, b, b);

	memcpy(a, b, 5);
	printf("memcpy(a, b, 5);\n")
	printf("a [%s] (%p)\nb [%s] (%p)\n", a, a, b, b);

	set_a(a);
	set_b(b);

	memcpy(b + 3, a, 5);
	printf("memcpy(b + 3, a, 5);\n");
	printf("a [%s] (%p)\nb [%s] (%p)\n", a, a, b, b);

	set_a(a);
	set_b(b);

	memcpy(a + 6, b, 10);
	printf("memcpy(a + 6, b, 5);\n");
	printf("a [%s] (%p)\nb [%s] (%p)\n", a, a, b, b);

	return (0);
}
