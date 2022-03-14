/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:41:49 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 16:06:43 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stat	stat;

	if (ac < 2)
		psw_exit_with_msg(ERR_FEW_ARGS);
	psw_init_stat(&stat, ac, av);
	fool_sort(&stat);
	//psw_sort(&stat);
	psw_output_operation(stat.op_history);
	//printf("\n >> [ %d ] ops.\n", stat.op_times);
	return (0);
}
