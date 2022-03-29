/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_merge_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:58:16 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/30 02:01:03 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_offset_score(int num, int i, int half_max)
{
	int	sub;

	sub = num - i;
	if (sub < 0)
		sub *= -1;
	if (sub > half_max)
		sub -= half_max;
	printf("%d - %d = %d ", num, i, sub);
	return (sub);
}

t_stack	*rotate_n(t_stack *stack, int n)
{
	while (n-- > 0)
		stack = stack->next;
	return (stack);
}

int	get_offset(t_stat *stat)
{
	int		score;
	int 	min;
	int		imin;
	int		start;
	int 	i;
	t_stack	*stack;

	start =	0;
	min = stat->qty_all * 3;
	while (start < stat->qty_all)
	{
		score =	0;
		i = 0;
		stack = rotate_n(stat->top_a, start);
		printf("top_elem : %d, ", stack->elem);
		while (i < stat->qty_all)
		{
			score += get_offset_score(stack->elem, i, stat->qty_all / 2);
			i++;
			stack = stack->next;
		}
		printf("start : %d, score : %d\n", start, score);
		if (score < min)
		{
			min = score;
			imin = start;
		}
		start++;
	}
	return (imin);
}

void	psw_merge_sort(t_stat stat, t_record *record)
{
	int	offset;
	
	offset = get_offset(&stat);
	record->times = 6;
	printf("offset : %d\n", offset);
}