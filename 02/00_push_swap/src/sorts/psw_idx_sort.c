/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_idx_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:19:19 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/07 11:44:20 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_idx_stat
{
	int offset;
	int score;
	int num_to_push;
	int *idx_to_push;
	int	num_to_swap;
	int	*idx_to_swap;
} t_idx_stat;

t_stack	*ix_rotate_n(t_stack *stack, int start)
{
	while (start-- > 0)
		stack = stack->next;
	return (stack);
}

int	ix_get_score(t_stat *stat, t_stack *stack)
{
	int	score;
	int	i;
	int	tmp;

	score = 0;
	i = 0;
	while (i < stat->qty_all)
	{
		tmp = stack->elem - i;
		if (tmp < 0)
			tmp *= -1;
		if (tmp > (stat->qty_all / 2))
			score += stat->qty_all - tmp;
		else
			score += tmp;
		i++;
		stack = stack->next;
	}
	return (score);
}

void	ix_score_seq(t_stat *stat, t_idx_stat *i_stat)
{
	int		start;
	int		score;
	t_stack	*stack;

	start = 0;
	i_stat->score = stat->qty_all * stat->qty_all;
	while (start < stat->qty_all)
	{
		stack = ix_rotate_n(stat->top_a, start);
		score = ix_get_score(stat, stack);
		if (i_stat->score > score)
		{
			i_stat->score = score;
			i_stat->offset = start;
		}
		start++;
	}
}

void	ix_set_swap(t_stat *stat, t_idx_stat *i_stat)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = stat->top_a;
	while (i < stat->qty_all)
	{
		i_stat->idx_to_swap[i] = 0;
		if (i_stat->idx_to_push[i] == 1 && stack->elem == stack->next->elem + 1)
		{
			i_stat->idx_to_swap[i] = 1;
			i_stat->idx_to_swap[i + 1] = 0;
			i_stat->idx_to_push[i] = 1;
			i_stat->idx_to_push[i + 1] = 1;
			i_stat->num_to_swap++;
			i_stat->num_to_push += 2;
			i++;
			stack = stack->next;
		}
		i++;
		stack = stack->next;
	}
	return ;
}

void	ix_set_push(t_stat *stat, t_idx_stat *i_stat)
{
	int	i;
	int	tmp;
	t_stack	*stack;

	stack = ix_rotate_n(stat->top_a, i_stat->offset);
	i = 0;
	while (i < stat->qty_all)
	{
		tmp = stack->elem - i;
		if (tmp < 0)
			tmp *= -1;
		if (tmp > stat->qty_all / 2)
			tmp = stat->qty_all - tmp;
		if (i + i_stat->offset >= stat->qty_all)
			i -= (stat->qty_all - i_stat->offset);
		i_stat->idx_to_push[i + i_stat->offset] = 0;
		if (tmp <= IX_RIGHT)
		{
			i_stat->idx_to_push[i + i_stat->offset] = 1;
			i_stat->num_to_push++;
		}
		i++;
		stack = stack->next;
	}
	return ;
}

void	psw_idx_sort(t_stat *stat, t_record *record)
{
	t_idx_stat	i_stat;

	i_stat = (t_idx_stat){0};
	i_stat.idx_to_swap = (int *)malloc(sizeof(int) * stat->qty_all);
	i_stat.idx_to_push = (int *)malloc(sizeof(int) * stat->qty_all);
	if (i_stat.idx_to_swap == NULL || i_stat.idx_to_push == NULL)
		psw_exit_with_msg(ERR_MALLOC);
	ix_score_seq(stat, &i_stat);	//	get minimum score and right offset
	printf("score %d, offset %d\n", i_stat.score, i_stat.offset);
	ix_set_swap(stat, &i_stat);
	int i = 0;
	while (i < stat->qty_all)
	{
		printf("%d, ", i_stat.idx_to_swap[i]);
		i++;
	}
	printf("[%d]\n", i_stat.num_to_swap);

	i = 0;
	while (i < stat->qty_all)
	{
		printf("%d, ", i_stat.idx_to_push[i]);
		i++;
	}
	printf("[%d]\n", i_stat.num_to_push);
	ix_set_push(stat, &i_stat);
	// ix_push_and_swap();
	// ix_push_back();
}

int	main(int ac, char **av)
{
	t_stat		stat;
	t_record	record;

	if (ac == 1)
		return (0);
	psw_init_stat(&stat, ac, av);
	psw_idx_sort(&stat, &record);
//	psw_output_operation(record.history);
	return (0);
}