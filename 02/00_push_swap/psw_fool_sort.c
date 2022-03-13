#include "push_swap.h"

int	search_min_in_a(t_stat *stat)
{
	int	min_elem;
	int	min_elem_idx;
	t_stack	*stack_a;

	min_elem = stat->qty_all;
	min_elem_idx = 0;
	stack_a = stat->top_a->self;
	// search minimam
	while (min_elem_idx < stat->qty_a - 1)
	{
		if (stack_a->elem < min_elem)
			min_elem = stack_a->elem;
		min_elem_idx++;
	}
	return (min_elem_idx);
}

void	fool_sort(t_stat *stat)
{
	int	min_elem_idx;
	int	i;

	i = 0;
	if (stat->qty_a > 0)
	{
		min_elem_idx = search_min_in_a(stat);
		while (min_elem_idx-- > 0)
			psw_rotate_a(stat, ORDER);
		psw_push(stat, 'b');
	}
	else
	{
		while (i++ < stat->qty_all - 1)
			psw_push(stat, 'a');
	}
	stat->is_sorted = psw_is_sorted(stat);
	return ;
}