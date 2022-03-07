/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_set_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:35:10 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 18:38:52 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_non_intmin(int *argnum, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (argnum[i] != INT_MIN)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	set_intmin(t_stat *stat, int *argnum, t_stack *stack)
{
	int	i;
	int	idx_num;

	i = 0;
	idx_num = 0;
	while (i < stat->qty_all)
	{
		if (argnum[i] == INT_MIN)
			stack[i].elem = idx_num++;
		i++;
	}
	return (idx_num);
}

static void	set_addr(t_stat *stat, t_stack *stack)
{
	int i;

	i = 0;
	while (i < stat->qty_all)
	{
		if (i < stat->qty_all - 1)
			stack[i].next = &stack[i + 1];
		else
			stack[i].next = &stack[0];
		if (i > 0)
			stack[i].prev = &stack[i - 1];
		else
			stack[i].prev = &stack[stat->qty_all - 1];
		i++;
	}
	return ;
}

static void	set_elem(t_stat *stat, int *argnum, t_stack *stack)
{
	int	i;
	int	idx_num;
	int	min_num;
	int	min_idx;

	idx_num = set_intmin(stat, argnum, stack);
	while (is_non_intmin(argnum, stat->qty_all))
	{
		i = 0;
		min_num = INT_MAX;
		while (i < stat->qty_all)
		{
			if (min_num >= argnum[i] && argnum[i] != INT_MIN)
			{
				min_num = argnum[i];
				min_idx = i;
			}
			i++;
		}
		stack[min_idx].elem = idx_num++;
		argnum[min_idx] = INT_MIN;
	}
	return ;
}

void	psw_set_stack(t_stat *stat, int *argnum, t_stack *stack)
{
	set_elem(stat, argnum, stack);
	set_addr(stat, stack);

	printf("\n << set_stack() >>\n");
	printf("stack.elem >>\n");
	int i = 0;
	while (i < stat->qty_all)
	{
		printf("%d, ", stack[i].elem);
		i++;
	}
	printf("\n");

	printf("stack.next >>\n");
	i = 0;
	t_stack	*ptr = stack[0].next;
	while (i < stat->qty_all * 2)
	{
		printf("%d, ", ptr->elem);
		ptr = ptr->next;
		i++;
	}
	printf("\n");

	printf("stack.prev >>\n");
	i = 0;
	ptr = stack[0].prev;
	while (i < stat->qty_all * 2)
	{
		printf("%d, ", ptr->elem);
		ptr = ptr->prev;
		i++;
	}
	printf("\n");

	return ;
}
