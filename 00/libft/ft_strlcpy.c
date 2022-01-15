/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:33:31 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/24 16:08:40 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t l;

	l = ft_strlen(src);
	if (dstsize == 0)
		return (l);
	while ((*src != 0) && (dstsize-- > 1))
		*dst++ = *src++;
	*dst = '\0';
	return (l);
}
