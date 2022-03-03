/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_init_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:02:12 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/03 21:13:21 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*psw_argv_to_num(char *s, int *num)
{
	int	sign;

	*num = 0;
	sign = PLUS;
	if (*s == '-')
	{
		sign = MINUS;
		s++;
	}
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			*num = *num * 10 + (*s - '0') * sign;
		else
			psw_exit_with_msg(ERR_NOT_INT);
		s++;
	}
	if ((*num >= 0 && sign == MINUS) || (*num < 0 && sign == PLUS))
		psw_exit_with_msg(ERR_NOT_INT);
	return (num);
}

void	psw_check_duparg(t_stat *stat, int *argnum)
{
	int	i;
	int	j;

	i = 0;
	while (i < stat->qty_all - 1)
	{
		j = i + 1;
		while (j < stat->qty_all)
		{
			if (argnum[i] == argnum[j])
				psw_exit_with_msg(ERR_DUP);
			j++;
		}
		i++;
	}
	return ;
}

void	psw_convert_args(t_stat *stat, int *argnum, t_stack *stack)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < stat->qty_all - 1)
	{
		min_idx = 0;
		j = i + 1;
		while (j < stat->qty_all)
		{
			if (argnum[j] < argnum[min_idx])
				min_idx = j;
			j++;
		}
		argnum[j] = INT_MAX;
		stack[min_idx].elem = i;
		i++;
	}
}

t_stack	*psw_init_stat(t_stat *stat, int ac, char **av)
{
	int		*arg_num;
	int		i;
	t_stack	*stack;

	stat->is_sorted = 0;
	stat->qty_all = ac - 1;
	stat->qty_a = ac - 1;
	arg_num = (int *)malloc(sizeof(int) * (ac - 1));
	if (arg_num == NULL)
		psw_exit_with_msg(ERR_MALLOC);
	i = 0;
	while (i++ < ac - 1)
		psw_argv_to_num(av[i], &arg_num[i - 1]);
	psw_check_duparg(stat, arg_num);
	stack = (t_stack *)malloc(sizeof(t_stack) * (ac - 1));
	if (stack == NULL)
		psw_exit_with_msg(ERR_MALLOC);
	psw_convert_args(stat, arg_num, stack); // <--- WIP
	/* test */
	i = 0;
	printf("argnums\n");
	while (i++ < ac - 1)
		printf("%d, ", arg_num[i - 1]);
	i = 0;
	printf("\nstack.elems\n");
	while (i++ < stat->qty_all)
		printf("%d, ", stack[i].elem);

	return (stack);
}
