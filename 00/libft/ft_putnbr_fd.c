/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:27:33 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/26 23:39:10 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char c;
	long l;

	l = n;
	if (l < 0)
	{
		l *= -1;
		ft_putchar_fd('-', fd);
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	c = '0' + l % 10;
	ft_putchar_fd(c, fd);
}
