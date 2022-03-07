/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:06:20 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 18:12:30 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	psw_is_sorted(t_stat *stat, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stat->qty_all - 1)
	{
		if (stack[i].elem > stack[i + 1].elem)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
