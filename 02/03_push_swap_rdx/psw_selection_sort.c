/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_selection_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:54:49 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 17:54:49 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sort(t_stat *stat)
{
	t_stack	*stack;

	stack = stat->top_a;
	while (stack->elem != 1)
		stack = stack->next;
	if (stack->next->elem == 0)
		swap(stat, 'a');
	selection_sort(stat);
	return ;
}

void	selection_sort(t_stat *stat)
{
	while (is_sorted(stat) == false)
	{
		rotate_n(stat, 'a', get_min_idx(stat, 'a'));
		if (is_sorted(stat) != false)
			break ;
		push(stat, 'b');
	}
	if (stat->is_sorted == A_SHIFT_SORTED)
		rotate_n(stat, 'a', get_min_idx(stat, 'a'));
	while (stat->qty_a != stat->qty_all)
		push(stat, 'a');
	return ;
}
