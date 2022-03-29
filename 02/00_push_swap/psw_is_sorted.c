/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:06:20 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/24 13:19:36 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	psw_get_offset(t_stat *stat)
{
	int	min_idx;

	min_idx = search_min_in_a(stat);
	stat->offset = min_idx;
	if (stat->qty_all - min_idx < min_idx)
		stat->offset = min_idx - stat->qty_all;
	return (stat->offset);
}

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
		psw_get_offset(stat);
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
