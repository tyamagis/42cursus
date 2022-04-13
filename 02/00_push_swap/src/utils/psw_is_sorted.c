/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:06:20 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/08 01:34:37 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	psw_is_shift_sorted(t_stat *stat)
{
	t_stack	*stack;
	int		i;

	stack = stat->top_a;
	i = 0;
	stat->is_sorted = SHIFT_SORTED;
	while (i < stat->qty_a)
	{
		if (stack->elem + 1 != stack->next->elem)
		{
			if (!((stack->elem == stat->qty_all - 1) && stack->next->elem == (stat->qty_all - stat->qty_a)))
				stat->is_sorted = false;
		}
		i++;
		stack = stack->next;
	}
	if (stat->is_sorted == SHIFT_SORTED)
		stat->offset = psw_get_min_idx(stat, 'a');
	return (stat->is_sorted);
}

int	psw_is_a_sorted(t_stat *stat)
{
	int		i;
	t_stack	*stack_a;
	
	i = 0;
	stack_a = stat->top_a;
	while (i < stat->qty_a - 1)
	{
		if (stack_a->elem > stack_a->next->elem)
			return (stat->is_sorted = false);
		i++;
		stack_a = stack_a->next;
	}
	if (stat->qty_all == stat->qty_a)
		return (stat->is_sorted = SORTED);
	else
		return (stat->is_sorted = A_SORTED);
}

int	psw_is_sorted(t_stat *stat)
{
	stat->is_sorted = SORTED;
	stat->offset = 0;
	psw_is_a_sorted(stat);
	if (stat->is_sorted == false)
		psw_is_shift_sorted(stat);
	// printf("IS_SORTED() >>\n");
	// print_stack(stat);
	return (stat->is_sorted);
}
