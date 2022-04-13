/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_fool_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:17:15 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/21 16:17:15 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	idx_to_elem(t_stack *stack, int min_idx)
{
	while (min_idx-- > 0)
		stack = stack->next;
	return (stack->elem);
}

void	min_to_top(t_stat *stat, t_record *record)
{
	int	min;
	int	min_idx;
	int	count;
	int	tmp;

	min_idx = search_min_in_a(stat);
	min = idx_to_elem(stat->top_a, min_idx);
	if (min_idx > stat->qty_a - min_idx)
		min_idx = min_idx - stat->qty_a;
	count = min_idx;
	if (min_idx < 0)
		count *= -1;
	while (count-- > 0)
	{
		tmp = stat->top_a->elem - stat->top_a->next->elem;
		if (tmp > 0 && tmp * 3 <= stat->qty_all)
			psw_swap(stat, 'a', record);
		if (stat->top_a->elem == min)
			break ;
		if (psw_is_sorted(stat) == SORTED || psw_is_sorted(stat) == A_SORTED)
			break ;
		if (min_idx > 0)
			psw_rotate(stat, 'a', ORDER, record);
		else
			psw_rotate(stat, 'a', REVERSE, record);
		if (psw_is_sorted(stat) == SORTED || psw_is_sorted(stat) == A_SORTED)
			break ;
	}
	return ;
}

void	shift_stack(t_stat *stat, t_record *record)
{
	if (stat->offset > 0)
	{
		while (stat->offset-- > 0)
			psw_rotate(stat, 'a', ORDER, record);
	}
	else
	{
		while (stat->offset++ < 0)
			psw_rotate(stat, 'a', REVERSE, record);
	}
	psw_is_sorted(stat);
	return ;
}

void	psw_fool_sort(t_stat stat, t_record *record)
{
	psw_init_record(record);
	psw_is_sorted(&stat);
	while (stat.is_sorted != SORTED)
	{
		while (stat.is_sorted == false)
		{
			min_to_top(&stat, record);
			if (stat.is_sorted == SORTED || stat.is_sorted == A_SORTED)
				break ;
			psw_push(&stat, 'b', record);
		}
		psw_is_sorted(&stat);
		if (stat.is_sorted == SHIFT_SORTED)
			shift_stack(&stat, record);
		while (stat.qty_a != stat.qty_all)
			psw_push(&stat, 'a', record);
		psw_is_sorted(&stat);
		// print_stack(&stat);
		// psw_output_operation(record->history);
		// printf("\n\n\n_/_/_/_/_/_/_/_/_/\n\n");
		// sleep(1);
	}
}
