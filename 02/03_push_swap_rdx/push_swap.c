/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:41:49 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/22 21:15:22 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stat		stat;

	if (ac == 1)
		return (0);
	init_stat(&stat, ac, av);
	if (stat.qty_all == 3)
		swap_sort(&stat);
	else if (stat.qty_all < 22)
		selection_sort(&stat);
	else
		radix_2_sort(&stat);
	output_operation(stat.history);
	free_mems(&stat);
	return (0);
}
