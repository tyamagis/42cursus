#include "push_swap.h"

t_stack	*psw_get_last(t_stat *stat, char tgt)
{
	t_stack	*last;
	int		i;

	if (tgt == 'a')
	{
		last = stat->top_a;
		i = stat->qty_a;
	}
	else
	{
		last = stat->top_b;
		i = stat->qty_all - stat->qty_a;
	}
	while (i-- > 0 && last != NULL)
		last = last->next;
	return (last);
}

void	psw_free_all_stack(t_stack *stack)
{
	t_stack	*tmp;

	stack->prev->next = NULL;
	while (stack->next != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}
