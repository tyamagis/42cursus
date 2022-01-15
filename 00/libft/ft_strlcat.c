/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:15:35 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/25 00:54:33 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t ld;
	size_t ls;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (dstsize < ld)
		return (ls + dstsize);
	dst += ld;
	dstsize -= ld;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (ld + ls);
}
