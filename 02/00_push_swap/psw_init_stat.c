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

static int	*argv_to_num(char *s, int *num)
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

static void	check_duparg(t_stat *stat, int *argnum)
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

static int	*set_argnum(t_stat *stat, int ac, char **av)
{
	int	*argnum;
	int	i;

	argnum = (int *)malloc(sizeof(int) * (ac - 1));
	if (argnum == NULL)
		psw_exit_with_msg(ERR_MALLOC);
	i = 0;
	while (i++ < ac - 1)
		argv_to_num(av[i], &argnum[i - 1]);
	check_duparg(stat, argnum);
	return (argnum);
}

t_stack	*psw_init_stat(t_stat *stat, int ac, char **av)
{
	int		*argnum;
	t_stack	*stack;

	argnum = set_argnum(stat, ac, av);
	stat->qty_all = ac - 1;
	stat->qty_a = ac - 1;
	stat->last_b = NULL;
	stack = psw_set_stack(stat, argnum);
	stat->top_a = stack;
	stat->last_a = stat->top_a->prev;
	stat->is_sorted = psw_is_sorted(stat, stack);
	return (stack);
}