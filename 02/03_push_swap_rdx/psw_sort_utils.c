/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:20:51 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 18:40:19 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_offset(t_stat *stat, char which, int tgt_idx)
{
	int	offset;
	int	qty;

	qty = stat->qty_a;
	if (which == 'b')
		qty = stat->qty_all - stat->qty_a;
	offset = tgt_idx;
	if (qty - tgt_idx < tgt_idx)
		offset = tgt_idx - qty;
	return (offset);
}

int	get_min_idx(t_stat *stat, char which)
{
	int		min_elem;
	int		i;
	int		qty;
	int		min_idx;
	t_stack	*stack;

	min_elem = stat->qty_all;
	stack = stat->top_a;
	qty = stat->qty_a;
	if (which == 'b')
	{
		stack = stat->top_b;
		qty = stat->qty_all - stat->qty_a;
	}
	i = 0;
	while (i++ < qty)
	{
		if (stack->elem < min_elem)
		{
			min_elem = stack->elem;
			min_idx = i - 1;
		}
		stack = stack->next;
	}
	return (get_offset(stat, which, min_idx));
}

int	get_max_idx(t_stat *stat, char which)
{
	int		max_elem;
	int		i;
	int		qty;
	int		max_idx;
	t_stack	*stack;

	max_elem = 0;
	stack = stat->top_a;
	qty = stat->qty_a;
	if (which == 'b')
	{
		stack = stat->top_b;
		qty = stat->qty_all - stat->qty_a;
	}
	i = 0;
	while (i++ < qty)
	{
		if (stack->elem > max_elem)
		{
			max_elem = stack->elem;
			max_idx = i - 1;
		}
		stack = stack->next;
	}
	return (get_offset(stat, which, max_idx));
}

int	get_max_num(t_stat *stat, char which)
{
	int		max;
	int		qty;
	t_stack	*stack;

	max = 0;
	qty = stat->qty_a;
	stack = stat->top_a;
	if (which == 'b')
	{
		qty = stat->qty_all - stat->qty_a;
		stack = stat->top_b;
	}
	while (qty-- > 0)
	{
		if (max < stack->elem)
			max = stack->elem;
		stack = stack->next;
	}
	return (max);
}

int	get_min_num(t_stat *stat, char which)
{
	int		min;
	int		qty;
	t_stack	*stack;

	min = stat->qty_all;
	qty = stat->qty_a;
	stack = stat->top_a;
	if (which == 'b')
	{
		qty = stat->qty_all - stat->qty_a;
		stack = stat->top_b;
	}
	while (qty-- > 0)
	{
		if (min > stack->elem)
			min = stack->elem;
		stack = stack->next;
	}
	return (min);
}
