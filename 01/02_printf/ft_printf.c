/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 23:13:48 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/06 23:06:50 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptf_putnbr(unsigned long l, unsigned int base, char caseflag)
{
	long	n;
	int		ret;
	char	c;

	ret = 0;
	n = 1;
	while (l / n >= base)
		n *= base;
	while (n != 0)
	{
		if ((l / n) < 10)
			c = (l / n) + '0';
		else if (caseflag == 1)
			c = (l / n) - 10 + 'A';
		else
			c = (l / n) - 10 + 'a';
		ret += write(1, &c, 1);
		l %= n;
		n /= base;
	}
	return (ret);
}

int	ft_ptf_p(void *p)
{
	write(1, "0x", 2);
	return (2 + ft_ptf_putnbr((unsigned long)p, 16, 0));
}

int	ft_ptf_di(int num)
{
	int		ret;
	long	l;

	ret = 0;
	l = num;
	if (num < 0)
	{
		l *= -1;
		ret += write(1, "-", 1);
	}
	return (ret + ft_ptf_putnbr(l, 10, 0));
}

int	ft_ptf_fmt(va_list *l, const char *fmt)
{
	char	c;

	if (*fmt == 'c')
	{
		c = va_arg(*l, int);
		return (write(1, &c, 1));
	}
	else if (*fmt == 's')
		return (ft_ptf_s(va_arg(*l, char *)));
	else if (*fmt == 'p')
		return (ft_ptf_p(va_arg(*l, void *)));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_ptf_di(va_arg(*l, int)));
	else if (*fmt == 'u')
		return (ft_ptf_putnbr(va_arg(*l, unsigned int), 10, 0));
	else if (*fmt == 'x')
		return (ft_ptf_putnbr(va_arg(*l, unsigned int), 16, 0));
	else if (*fmt == 'X')
		return (ft_ptf_putnbr(va_arg(*l, unsigned int), 16, 1));
	else if (*fmt == '%')
		return (write(1, "%", 1));
	else
		return (write(1, fmt, 1));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	vl;
	int		ret;
	int		ret_buf;

	va_start(vl, fmt);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ret_buf = ft_ptf_fmt(&vl, fmt);
			if (ret_buf < 0)
				return (ret_buf);
			ret += ret_buf;
		}
		else
			ret += write(1, fmt, 1);
		fmt++;
	}
	va_end(vl);
	return (ret);
}
