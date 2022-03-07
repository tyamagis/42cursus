/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatrions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:08:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 20:19:59 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psw_push(t_stat *stat, t_stack *stack, char dir)
{
	if (dir == 'a' && (stat->qty_all - stat->qty_a) > 0)
	{
		stat->top_a = stat->top_a->prev;
		stat->qty_a++;
	}
	else if (dir == 'b' && qty_a > 0)
	{
		stat->top_a = stat->top_a->next;
		stat->qty_a--;
	}
	return ;
}

void	swap(t_stat *stat, t_stack *stack, char which)
{
	int		tmp;
	t_stack	*top_b;

	top_b = stat->top_a->prev;
	if (which == 'a' && stat->qty_a >= 2)
	{
		tmp = stat->top_a->elem;
		stat->top_a->elem = stat->top_a->next->elem;
		stat->top_a->next->elem = tmp;
	}
	else if (which == 'b' && stat->qty_all - stat->qty_a >= 2)
	{
		tmp = top_b->prev->elem;
		top_b->prev->elem = top_b->elem;
		top_b->elem = tmp;
	}
	return ;
}

void	rotate(t_stat *stat, t_stack *stack, char dir, char which)
{
	;
}

