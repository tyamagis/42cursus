/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:26:00 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/24 12:17:17 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*s1 != *s2++)
			return (int)(*(unsigned char *)(s1) - *(unsigned char *)(s2 - 1));
		else if (*s1++ == 0)
			break ;
	}
	return (0);
}
