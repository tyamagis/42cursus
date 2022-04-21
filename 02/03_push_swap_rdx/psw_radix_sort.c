/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_radix_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:41:28 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 18:44:04 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_b_idx(t_stat *stat)
{
	int	b_idx;
	int	num;

	b_idx = 0;
	num = stat->qty_all;
	while (num != 0)
	{
		num >>= 1;
		b_idx++;
	}
	return (b_idx);
}

void	radix_sort(t_stat *stat)
{
	int		b_idx;
	int		mask;
	int		qty;

	mask = 1;
	b_idx = count_b_idx(stat);
	while (b_idx-- > 0)
	{
		qty = 0;
		while (qty != stat->qty_all)
		{
			if ((stat->top_a->elem & mask) == 0)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
			qty++;
		}
		while (stat->qty_all != stat->qty_a)
			push(stat, 'a');
		mask <<= 1;
	}
	return ;
}
