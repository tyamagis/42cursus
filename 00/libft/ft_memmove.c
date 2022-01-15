/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:47:25 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/25 01:30:14 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (s < d && s + len > d)
	{
		while (len-- > 0)
			*(d + len) = *(s + len);
	}
	else if (s != d)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}
