/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:04:56 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/26 07:48:53 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	char	*s;
	size_t	ndl_len;

	s = (char *)hs;
	ndl_len = ft_strlen(ndl);
	if (ndl_len == 0)
		return (s);
	while (ft_strncmp(s++, ndl, ndl_len) != 0)
	{
		if ((ft_strlen(s) < ndl_len) || (len-- < 2))
			return (NULL);
	}
	if (ndl_len > len)
		return (NULL);
	return (--s);
}
