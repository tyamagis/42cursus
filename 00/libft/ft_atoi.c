/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:42:36 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/13 15:08:16 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	l;
	long	l_tmp;
	int		minus;
	int		idx;

	l = 0;
	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	idx = 0;
	while (ft_isdigit(*str))
	{
		l_tmp = l;
		l = l * 10 + (*str - '0');
		str++;
		if (idx++ > 18 || l_tmp > l)
			return ((minus == 1) ? -1 : 0);
	}
	return ((int)l * minus);
}
