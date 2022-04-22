/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_radix2_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:38:10 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/22 21:35:27 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_b2_idx(t_stat *stat)
{
	int	b_idx;
	int	num;

	b_idx = 0;
	num = stat->qty_all;
	while (num != 0)
	{
		num >>= 3;
		b_idx++;
	}
	return (b_idx);
}

void	radix_2_sort(t_stat *stat)
{
	int	mask;
	int qty;
	int	b3_idx;

	mask = 7; // 0b111;
	b3_idx = count_b2_idx(stat);
	while (b3_idx-- > 0)
	{
		qty = 0;
		while (qty != stat->qty_all)
		{
			if ((stat->top_a->elem & mask) == 0) // 0b00
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
			qty++;
		}
		qty = stat->qty_a;
		while (qty-- > 0)
		{
			if ((stat->top_a->elem & mask) == 1)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
		}
		qty = stat->qty_a;
		while (qty-- > 0)
		{
			if ((stat->top_a->elem & mask) == 2)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
		}
		qty = stat->qty_a;
		while (qty-- > 0)
		{
			if ((stat->top_a->elem & mask) == 3)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
		}
		qty = stat->qty_a;
		while (qty-- > 0)
		{
			if ((stat->top_a->elem & mask) == 4)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
		}
		qty = stat->qty_a;
		while (qty-- > 0)
		{
			if ((stat->top_a->elem & mask) == 5)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
		}
		qty = stat->qty_a;
		while (qty-- > 0)
		{
			if ((stat->top_a->elem & mask) == 6)
				push(stat, 'b');
			else
				rotate(stat, 'a', ORDER);
		}
		while (stat->qty_all != stat->qty_a)
			push(stat, 'a');
		mask <<= 3;
	}
	return ;
}