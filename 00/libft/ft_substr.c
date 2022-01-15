/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:15:18 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/27 03:16:55 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*p_sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	len = ((len > s_len - start) ? s_len - start : len);
	if (!(sub = (char *)ft_calloc(len + 1, 1)))
		return (NULL);
	if (start < s_len)
	{
		s += start;
		p_sub = sub;
		while (len-- > 0)
			*p_sub++ = *s++;
		*p_sub = '\0';
	}
	return (sub);
}
