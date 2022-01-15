/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:06:14 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/26 23:58:37 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	cnt_index(long l)
{
	char idx;

	idx = 1;
	while (l > 9)
	{
		l /= 10;
		idx++;
	}
	return (idx);
}

char		*ft_itoa(int n)
{
	char	*s;
	long	l;
	int		idx;
	int		minus;

	l = n;
	minus = 0;
	if (l < 0)
	{
		l *= -1;
		minus = 1;
	}
	idx = cnt_index(l);
	if (!(s = (char *)malloc(idx + minus + 1)))
		return (NULL);
	s += idx + minus;
	*s = '\0';
	while (idx-- > 0)
	{
		*--s = '0' + l % 10;
		l /= 10;
	}
	if (minus)
		*--s = '-';
	return (s);
}
