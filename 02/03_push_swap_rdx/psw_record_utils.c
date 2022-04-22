/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_record_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:48:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 19:37:52 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_n(t_stat *stat, char which, int offset)
{
	int	qty_a;
	int	qty_all;

	qty_a = stat->qty_a;
	qty_all = stat->qty_all;
	if ((which == 'a' && qty_a == 0) || (which == 'b' && qty_all == qty_a))
		return ;
	if (offset > 0)
	{
		while (offset-- > 0)
			rotate(stat, which, ORDER);
	}
	else
	{
		while (offset++ < 0)
			rotate(stat, which, REVERSE);
	}
	return ;
}

void	output_operation(char *s)
{
	size_t	size;

	if (s == NULL)
		size = 0;
	else
		size = psw_strlen(s);
	write(1, s, size);
	return ;
}

void	save_operation(t_stat *stat, char *s)
{
	char	*new_str;

	new_str = psw_strjoin(stat->history, s);
	if (new_str == NULL)
		exit_with_msg(stat, ERR_MALLOC);
	free(stat->history);
	stat->history = new_str;
	stat->op_times++;
	return ;
}
