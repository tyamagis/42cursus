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

#include "./push_swap.h"

// test print
void	print_stack(t_stat *stat)
{
	printf("----------\n");
	printf("stack A : ");
	int i = 0;
	t_stack	*stk = stat->top_a;
	while (i < stat->qty_a)
	{
		printf("%d, ", stk->elem);
		stk = stk->next;
		i++;
	}
	printf("\nstack B : ");
	i = 0;
	stk = stat->top_a->prev;
	while (i < stat->qty_all - stat->qty_a)
	{
		printf("%d, ", stk->elem);
		stk = stk->prev;
		i++;
	}
	printf("\n");
	return ;
}

void	test_push(t_stat *stat)
{
	psw_push(stat, 'b');
	print_stack(stat);

	psw_push(stat, 'b');
	print_stack(stat);

	psw_push(stat, 'b');
	print_stack(stat);

	psw_push(stat, 'b');
	print_stack(stat);

	psw_push(stat, 'b');
	print_stack(stat);

	psw_push(stat, 'b');
	print_stack(stat);

	psw_push(stat, 'a');
	print_stack(stat);

	psw_push(stat, 'a');
	print_stack(stat);
}

int	main(int ac, char *av[])
{
	t_stat	stat;
	t_stack	*stack;

	if (ac < 2)
		psw_exit_with_msg(ERR_FEW_ARGS);
	stack = psw_init_stat(&stat, ac, av);

	// TEST
	printf("arg status : ");
	if (stat.is_sorted == TRUE)
	{
		printf(">> sorted\n");
		int i = 0;
		while (ac-- > 1)
		{
			printf("%d, ", stack[i].elem);
			i++;
		}
	}
	else
	{
		printf(">> NOT sorted\n");
		int i = 0;
		while (ac-- > 1)
		{
			printf("%d, ", stack[i].elem);
			i++;
		}
	}
	printf("\n");
	print_stack(&stat);
	test_push(&stat);
	return (0);
}
