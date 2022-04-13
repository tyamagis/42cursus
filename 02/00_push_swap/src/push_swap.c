/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:41:49 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/06 22:16:20 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stat		stat;
	t_record	fs_record;
	// t_record	ms_record;
	//t_record	x_record;
	//t_record	xx_record;

	if (ac == 1)
		return (0);
	stat.min_times = INT_MAX;
	psw_init_stat(&stat, ac, av);
	// must copy stat as many of SORTs
	// print_stack(&stat);
	psw_fool_sort(stat, &fs_record);
	psw_output_operation(fs_record.history);
	/*psw_init_stat(&stat, ac, av);
	print_stack(&stat);
	psw_merge_sort(stat, &ms_record);
	//x_sort(stat[x], x_record);
	//xx_sort(stat[xx], xx_record);
	//xxx_sort(stat[xxx], xxx_record);

	// compare each times,
	// and output the least sort's operation history.

	 TEST 
	printf("fool_sort >> [ %d ] ops.\n", fs_record.times);
	psw_output_operation(fs_record.history);
	printf("\n\n_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n\n");
	*/
	// psw_output_operation(x_record.history);
	// printf("x_sort >> [ %d ] ops.\n", x_record.times);

	// psw_output_operation(xx_record.history);
	// printf("xx_sort >> [ %d ] ops.\n", xx_record.times);

	/* ===== */
	return (0);
}