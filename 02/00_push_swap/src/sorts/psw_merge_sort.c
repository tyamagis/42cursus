/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_merge_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:58:16 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/13 12:36:02 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	m2s_push_first(t_stat *stat, t_record *record)
{
	int		tgt;
	int		max;
	int		min;
	int		idx;
	t_stack	*stack;

	tgt = stat->top_a->elem;
	max = psw_get_max_num(stat, 'b');
	min = psw_get_min_num(stat, 'b');
	idx = psw_get_min_idx(stat, 'b');
	printf("\n\n======\n\n");
	printf("tgt %d max %d min %d\n", tgt, max, min);
	print_stack(stat);
	if (tgt > max)
	{
		printf("tgt > max\n");
		idx = psw_get_max_idx(stat, 'b');
		idx++;	
	}
	else if (tgt < max && tgt > min)
	{
		printf("min < tgt < max\n");
		stack = stat->top_b;
		while (idx++ < stat->qty_all && !(tgt > stack->prev->elem && tgt < stack->elem))
			stack = stack->next;
	}
	printf("idx : %d\n", idx);
	psw_rotate_n(stat, record, 'b', psw_get_offset(stat, 'b', idx));
	psw_push(stat, 'b', record);
	print_stack(stat);
	return ;
}

void	psw_m2_sort(t_stat *stat, t_record *record)
{
	int	num_to_push;

	num_to_push = stat->qty_all / 2;
	while (num_to_push-- > 0)
		m2s_push_first(stat, record);
	printf("=== sort_first() DONE; ===\n");
	psw_rotate_n(stat, record, 'b', psw_get_min_idx(stat, 'b'));
	print_stack(stat);
	while (stat->qty_a != 0)
		m2s_push_first(stat, record);
	printf("=== sort_last() DONE; ===\n");
	psw_rotate_n(stat, record, 'b', psw_get_max_idx(stat, 'b'));
	print_stack(stat);
	while (stat->qty_all != stat->qty_a)
	{
		psw_rotate_n(stat, record, 'b', psw_get_max_idx(stat, 'b'));
		psw_push(stat, 'a', record);
	}
	printf("sort_end();\n");
	return ;
}

int	main(int ac, char **av)
{
	t_stat		stat;
	t_record	record;

	if (ac == 1)
		return (0);
	psw_init_stat(&stat, ac, av);
	printf("init_stat();\n");
	psw_m2_sort(&stat, &record);
	psw_output_operation(record.history);
	print_stack(&stat);
	return (0);
}