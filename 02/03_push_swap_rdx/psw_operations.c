/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:08:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 18:53:00 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_remove_from_src(t_stat *stat, char dir)
{
	t_stack	*src;

	if (dir == 'a')
	{
		src = stat->top_b;
		if (stat->qty_all - stat->qty_a == 1)
		{
			stat->top_b = NULL;
			return ;
		}
		stat->top_b = src->next;
	}
	else
	{
		src = stat->top_a;
		if (stat->qty_a == 1)
		{
			stat->top_a = NULL;
			return ;
		}
		stat->top_a = src->next;
	}
	src->next->prev = src->prev;
	src->prev->next = src->next;
	return ;
}

static void	push_add_to_dst(t_stack *dst, t_stack *src)
{
	if (dst == NULL)
	{
		src->next = src;
		src->prev = src;
	}
	else
	{
		src->next = dst;
		src->prev = dst->prev;
		dst->prev->next = src;
		dst->prev = src;
	}
}

void	push(t_stat *stat, char dir)
{
	t_stack	*src;

	if ((dir == 'a' && stat->qty_all - stat->qty_a == 0)
		|| (dir == 'b' && stat->qty_a == 0))
		return ;
	else if (dir == 'a')
	{
		src = stat->top_b;
		push_remove_from_src(stat, dir);
		push_add_to_dst(stat->top_a, src);
		stat->top_a = src;
		stat->qty_a++;
		save_operation(stat, "pa\n");
	}
	else
	{
		src = stat->top_a;
		push_remove_from_src(stat, dir);
		push_add_to_dst(stat->top_b, src);
		stat->top_b = src;
		stat->qty_a--;
		save_operation(stat, "pb\n");
	}
	is_sorted(stat);
	return ;
}

void	swap(t_stat *stat, char which)
{
	int		tmp;
	t_stack	*tgt;

	if ((which == 'a' && stat->qty_a < 2)
		|| (which == 'b' && stat->qty_all - stat->qty_a < 2))
		return ;
	if (which == 'a')
	{
		tgt = stat->top_a;
		save_operation(stat, "sa\n");
	}
	else
	{
		tgt = stat->top_b;
		save_operation(stat, "sb\n");
	}
	tmp = tgt->elem;
	tgt->elem = tgt->next->elem;
	tgt->next->elem = tmp;
	is_sorted(stat);
	return ;
}

void	rotate(t_stat *stat, char which, char dir)
{
	if (which == 'a' && dir == ORDER)
	{
		stat->top_a = stat->top_a->next;
		save_operation(stat, "ra\n");
	}
	else if (which == 'b' && dir == ORDER)
	{
		stat->top_b = stat->top_b->next;
		save_operation(stat, "rb\n");
	}
	else if (which == 'a' && dir != ORDER)
	{
		stat->top_a = stat->top_a->prev;
		save_operation(stat, "rra\n");
	}
	else
	{
		stat->top_b = stat->top_b->prev;
		save_operation(stat, "rrb\n");
	}
	is_sorted(stat);
	return ;
}
