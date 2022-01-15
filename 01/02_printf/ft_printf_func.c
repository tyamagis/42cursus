/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:14:37 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/01 22:40:24 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptf_s(char *s)
{
	int	ret;

	ret = 0;
	if (s == 0)
		ret += write(1, "(null)", 6);
	else
	{
		while (s[ret])
		{
			ret++;
			if (ret < 0)
				return (-1);
		}
		write(1, s, ret);
	}
	return (ret);
}
