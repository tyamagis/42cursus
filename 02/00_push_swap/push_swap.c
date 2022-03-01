/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:41:49 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/01 21:53:15 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char *av[])
{
	t_stat	stat;
	t_stack	*stack;

	if (ac < 2)
		psw_exit_with_msg(ERR_FEW_ARGS);
	stack = psw_init_stat(&stat, ac, av);
	/*
	check args & convert av(char *[]) to int[]
	 */
	// set_stack(ac, av, stack_a);
	// sort
	//  - think
	//
	// output

	/* test */
	return (0);
}
