/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:49:23 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/04 17:40:26 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_ptf_putnbr(unsigned long l, unsigned int base, char caseflag);
int	ft_ptf_s(char *s);
int	ft_ptf_p(void *p);
int	ft_ptf_di(int num);
int	ft_ptf_fmt(va_list *l, const char *fmt);
int	ft_printf(const char *fmt, ...);

#endif
