/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_memccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:57:38 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/30 01:01:41 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		uc;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if ((*d++ = *s++) == uc)
			return ((void *)d);
	}
	return (NULL);
}
