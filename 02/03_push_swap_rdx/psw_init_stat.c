/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_init_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:02:12 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 19:06:50 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_overflow(t_stat *stat, int *num, int sign, int digit)
{
	int	digit_num;
	int	tmp_num;

	if ((*num >= 0 && sign == MINUS) || (*num < 0 && sign == PLUS))
		exit_with_msg(stat, ERR_NOT_INT);
	digit_num = 0;
	tmp_num = *num * sign;
	if (tmp_num == 0)
		digit_num = 1;
	while (tmp_num != 0)
	{
		digit_num++;
		tmp_num /= 10;
	}
	if (digit != digit_num)
		exit_with_msg(stat, ERR_NOT_INT);
	return ;
}

static int	*argv_to_num(t_stat *stat, char *s, int *num)
{
	int	sign;
	int	digit;

	*num = 0;
	digit = 0;
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
			exit_with_msg(stat, ERR_NOT_INT);
		s++;
		digit++;
	}
	check_overflow(stat, num, sign, digit);
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
				exit_with_msg(stat, ERR_DUP);
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
		exit_with_msg(stat, ERR_MALLOC);
	i = 0;
	while (i++ < ac - 1)
		argv_to_num(stat, av[i], &argnum[i - 1]);
	check_duparg(stat, argnum);
	return (argnum);
}

void	init_stat(t_stat *stat, int ac, char **av)
{
	int		*argnum;

	stat->qty_all = ac - 1;
	stat->qty_a = ac - 1;
	stat->history = NULL;
	stat->op_times = 0;
	argnum = set_argnum(stat, ac, av);
	set_stack(stat, argnum);
	free(argnum);
	is_sorted(stat);
	return ;
}
