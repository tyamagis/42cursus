/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:48:44 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/26 07:02:55 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	char			*f_str;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (!(f_str = (char *)malloc(s_len + 1)))
		return (NULL);
	i = 0;
	while (*s)
		*f_str++ = f(i++, *s++);
	*f_str = '\0';
	return (f_str - s_len);
}
