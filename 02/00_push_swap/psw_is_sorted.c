/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:06:20 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 18:12:30 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	psw_is_sorted(t_stat *stat)
{
	int	i;
	t_stack	*stack_a;

	stack_a = stat->top_a;
	if (stat->qty_all != stat->qty_a)
	{
		stat->is_sorted = false;
		printf("qty checked >> false\n");
		return (false);
	}
	i = 0;
	while (i < stat->qty_all - 1)
	{
		if (stack_a->elem > stack_a->next->elem)
		{
			stat->is_sorted = false;
			printf("elem checked >> false\n");
			return (false);
		}
		i++;
		stack_a = stack_a->next;
	}
	stat->is_sorted = true;
	printf("elem checked >> true\n");
	return (true);
}