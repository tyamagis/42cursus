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
	if (dir == 'a' && (stat->qty_all - stat->qty_a) > 0)
	{
		stat->top_a = stat->top_a->prev;
		stat->qty_a++;
	}
	else if (dir == 'b' && stat->qty_a > 0)
	{
		stat->top_a = stat->top_a->next;
		stat->qty_a--;
	}

	printf("\n [[ push %c ]]\n", dir);
	return ;
}

void	swap(t_stat *stat, char which)
{
	int		tmp;
	t_stack	*top;

	if (which == 'a' && stat->qty_a >= 2)
	{
		top = stat->top_a;
		tmp = top->elem;
		top->elem = top->next->elem;
		top->next->elem = tmp;
	}
	else if (which == 'b' && stat->qty_all - stat->qty_a >= 2)
	{
		top = stat->top_a->prev;
		tmp = top->prev->elem;
		top->prev->elem = top->elem;
		top->elem = tmp;
	}
	return ;
}

// void	rotate(t_stat *stat, t_stack *stack, char dir, char which)
// {
// 	;
// }