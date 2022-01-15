/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_tests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:35:42 by tyamagis          #+#    #+#             */
/*   Updated: 2021/02/15 12:31:01 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ----------------
** how to comment
** LIKE THIS.
** ----------------
** - english (ascii) only
** - it must be out of func scope.
** - no space at the end of line.
*/

/*
** if NOT ascii char in comment, then
** = = = = = = = = = = = = =
** >> /usr/bin/norminette:110:in `encode': "\xE3" on US-ASCII
** >> (Encoding::InvalidByteSequenceError)
** = = = = = = = = = = = = =
** and 8 lines start with
** = = = = = = = = = = = = =
** >> from /usr/bin/norminette:.....
** = = = = = = = = = = = = =
** will be printed.
*/

void	f1(void)
{
}

void	f2(void)
{
}

void	f3(void)
{
}

void	f4(void)
{
}

/*
** -----------------------
** 6th func is forbidden.
** -----------------------
** void	f5(void)
** {
** }
*/

int		main(void)
{
	return (0);
}
