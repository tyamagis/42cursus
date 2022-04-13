/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_test_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:19:19 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/04 22:54:37 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stat		stat;
	t_record	record;

	if (ac == 1)
		return (0);
	psw_init_stat(&stat, ac, av);
	/* input sort name */
	psw_xxx_sort(stat, &record);
	psw_output_operation(record.history);
	return (0);
}