/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:46:27 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/24 11:24:02 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *uc1;
	unsigned char *uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*uc1 == *uc2)
		{
			uc1++;
			uc2++;
		}
		else
			return (*uc1 - *uc2);
	}
	return (0);
}
