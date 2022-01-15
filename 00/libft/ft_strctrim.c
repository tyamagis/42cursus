/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 06:50:09 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/27 02:52:34 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strctrim(char const *s, char const c)
{
	size_t	trmsize;

	while (*s && (*s == c))
		s++;
	trmsize = ft_strlen(s);
	while ((*(s + trmsize - 1) == c) && (trmsize > 0))
		trmsize--;
	return ((char *)s);
}
