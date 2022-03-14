#include "push_swap.h"

int	search_min_in_a(t_stat *stat)
{
	int		min_elem;
	int		i;
	int		min_idx;
	t_stack	*stack_a;

	min_elem = stat->qty_all;
	i = 0;
	min_idx = 0;
	stack_a = stat->top_a;
	// search minimam
	while (i < stat->qty_a)
	{
		if (stack_a->elem < min_elem)
		{
			min_elem = stack_a->elem;
			min_idx = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (min_idx);
}

void	fool_sort(t_stat *stat)
{
	int	min_idx;

	psw_is_sorted(stat);
	while (stat->is_sorted == false)
	{
		while (stat->qty_a > 1)
		{
			min_idx = search_min_in_a(stat);
			if (min_idx < stat->qty_a - min_idx)
			{
				while (min_idx-- > 0)
					psw_rotate(stat, 'a', ORDER);
			}
			else
			{
				while (min_idx++ != stat->qty_a)
					psw_rotate(stat, 'a', REVERSE);
			}
			if (psw_is_sorted(stat))
				break ;
			psw_push(stat, 'b');
		}
		while (stat->qty_a != stat->qty_all)
			psw_push(stat, 'a');
		psw_is_sorted(stat);
	}
}
