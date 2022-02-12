#include <stdio.h>

typedef struct s_a
{
	int		i;
	char	c;
} t_a

typedef struct s_b
{
	int		i;
	char	c;
} t_b

typedef struct s_c
{
	t_a		*a;
	t_b		*b;
} t_c

typedef struct s_d
{
	t_c		*c;
} t_d

int main(void)
{
	t_a		a;
	t_b		b;
	t_c		c;
