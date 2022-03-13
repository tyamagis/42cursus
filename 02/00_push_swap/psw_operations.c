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

void	psw_push(t_stat *stat, char dir)
{
	t_stack	*dst_top;
	t_stack	*src_top;

	if (dir == 'a' && (stat->qty_all - stat->qty_a) != 0)
	{
		dst_top = stat->top_a;
		src_top = stat->top_b;
		stat->top_a = src_top;
		stat->top_b = src_top->next;
		stat->qty_a++;
	}
	else if (dir == 'b' && stat->qty_a != 0)
	{
		dst_top = stat->top_b;
		src_top = stat->top_a;
		stat->top_a = src_top->next;
		stat->top_b = src_top;
		stat->qty_a--;
	}
	src_top->next->prev = src_top->prev;
	src_top->prev->next = src_top->next;
	dst_top->prev->next = src_top;
	src_top->next = dst_top;
	src_top->prev = dst_top->prev;
	dst_top->prev = src_top;
	printf("\n [[ push %c ]]\n", dir);
	return ;
}

void	psw_swap(t_stat *stat, char which)
{
	t_stack	*new_top;
	t_stack	*old_top;

	if (which == 'a')
	{
		old_top = stat->top_a;
		stat->top_a = old_top->next;
	}
	else
	{
		old_top = stat->top_b;
		stat->top_b = old_top->next;
	}
	new_top = old_top->next;
	last = old_top->prev;
	new_top->next->prev = old_top;
	last->next = new_top;
	new_top->prev = last;
	old_top->next = new_top->next;
	new_top->next = old_top;
	old_top->prev = new_top;
	printf("\n [[ swap %c ]]\n", which);
	return ;
}

void	psw_rotate(t_stat *stat, char which)
{
	if (which == 'a')
		stat->top_a = stat->top_a->next;
	else
		stat->top_b = stat->top_b->next;
	printf("\n [[ rotate a %c ]]\n", dir);
	return ;
}

void	psw_r_rotate(t_stat *stat, char which)
{
	if (which == 'a')
		stat->top_a = stat->top_a->prev;
	else
		stat->top_b = stat->top_b->prev;
	printf("\n [[ rotate a %c ]]\n", dir);
	return ;
}
