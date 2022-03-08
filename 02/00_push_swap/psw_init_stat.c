/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_init_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:02:12 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 18:38:53 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	*psw_argv_to_num(char *s, int *num)
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

static void	psw_check_duparg(t_stat *stat, int *argnum)
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

t_stack	*psw_init_stat(t_stat *stat, int ac, char **av)
{
	int		*arg_num;
	int		i;
	t_stack	*stack;

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
	stat->top_a = stack;
	stat->top_b = NULL;
	psw_set_stack(stat, arg_num, stack); // <--- WIP
	stat->is_sorted = psw_is_sorted(stat, stack);
	return (stack);
}
