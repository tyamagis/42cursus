#include <stdio.h>

typedef struct s_list
{
	int		i;
	char	c;
} t_list;

t_list *st_list(void)
{
	static t_list	li;

	li.i += 1;
	printf("st_list() : &li = %p\n", &li);
	printf("li.i = %d (%p)\n", li.i, &li.i);
	return (&li);
}

int	main(void)
{
	t_list	*l;

	l = st_list();
	printf("main : l = %p\n", l);
	printf("l->i = %d (%p)\n", l->i, &l->i);
	l = st_list();
	printf("main : l = %p\n", l);
	printf("l->i = %d (%p)\n", l->i, &l->i);
	l = st_list();
	printf("main : l = %p\n", l);
	printf("l->i = %d (%p)\n", l->i, &l->i);
	return (0);
}
