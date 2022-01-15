/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:52:09 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/27 22:51:36 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trmsize;
	char	*trm;
	char	*t;

	if ((trmsize = ft_strlen(s1)) > 0)
	{
		while (ft_strrchr(set, *(s1 + trmsize - 1)) && trmsize > 0)
			trmsize--;
	}
	if (trmsize != 0)
	{
		while (ft_strchr(set, *s1++))
			trmsize--;
		s1--;
	}
	if (!(trm = (char *)malloc(trmsize + 1)))
		return (NULL);
	t = trm;
	while (trmsize-- > 0)
		*t++ = *s1++;
	*t = '\0';
	return (trm);
}
