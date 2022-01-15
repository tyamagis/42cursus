/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:38:16 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/26 06:49:48 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s = (char *)malloc(len)))
		return (NULL);
	while (*s1)
		*s++ = (char)*s1++;
	while (*s2)
		*s++ = (char)*s2++;
	*s = '\0';
	s -= len - 1;
	return (s);
}
