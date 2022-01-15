/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:37:18 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/25 18:41:34 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *s)
{
	char	*r;
	size_t	len;

	len = ft_strlen(s);
	if (!(r = malloc(len)))
		return (NULL);
	while (len-- > 0)
		*r++ = *((s++) + len);
	return (r);
}
