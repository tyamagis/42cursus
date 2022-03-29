/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:08:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/24 13:57:13 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	psw_push_remove_from_src(t_stat *stat, char dir)
{
	t_stack *src;

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

static void	psw_push_add_to_dst(t_stack *dst, t_stack *src)
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

void	psw_push(t_stat *stat, char dir, t_record *record)
{
	t_stack	*src;

	if ((dir == 'a' && stat->qty_all - stat->qty_a == 0) ||
		(dir == 'b' && stat->qty_a == 0))
			return ;
	else if (dir == 'a')
	{
		src = stat->top_b;
		psw_push_remove_from_src(stat, dir);
		psw_push_add_to_dst(stat->top_a, src);
		stat->top_a = src;
		stat->qty_a++;
		psw_save_operation(record, "pa\n");
	}
	else
	{
		src = stat->top_a;
		psw_push_remove_from_src(stat, dir);
		psw_push_add_to_dst(stat->top_b, src);
		stat->top_b = src;
		stat->qty_a--;
		psw_save_operation(record, "pb\n");
	}
	psw_is_sorted(stat);
	return ;
}

void	psw_swap(t_stat *stat, char which, t_record *record)
{
	int		tmp;
	t_stack	*tgt;

	if ((which == 'a' && stat->qty_a < 2) ||
		(which == 'b' && stat->qty_all - stat->qty_a < 2))
		return ;
	if (which == 'a')
	{
		tgt = stat->top_a;
		psw_save_operation(record, "sa\n");
	}
	else
	{
		tgt = stat->top_b;
		psw_save_operation(record, "sb\n");
	}
	tmp = tgt->elem;
	tgt->elem = tgt->next->elem;
	tgt->next->elem = tmp;
	psw_is_sorted(stat);
	return ;
}

void	psw_rotate(t_stat *stat, char which, char dir, t_record *record)
{
	if (which == 'a' && dir == ORDER)
	{
		stat->top_a = stat->top_a->next;
		psw_save_operation(record, "ra\n");
	}
	else if (which == 'b' && dir == ORDER)
	{
		stat->top_b = stat->top_b->next;
		psw_save_operation(record, "rb\n");
	}
	else if (which == 'a' && dir != ORDER)
	{
		stat->top_a = stat->top_a->prev;
		psw_save_operation(record, "rra\n");
	}
	else
	{
		stat->top_b = stat->top_b->prev;
		psw_save_operation(record, "rrb\n");
	}
	psw_is_sorted(stat);
	return ;
}
