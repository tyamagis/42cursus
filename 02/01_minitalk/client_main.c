/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:29:18 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/15 01:13:32 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	err_exit(void)
{
	write(1, "Something wrong, retry.\n", 24);
	exit(0);
}

pid_t	arg_to_pid(char *s)
{
	pid_t	ret;

	ret = 0;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		ret *= 10;
		ret += *s - '0';
		s++;
	}
	return (ret);
}

void	send_arglen(char *s, pid_t pid)
{
	size_t	len;
	size_t	bit;

	len = 0;
	while (*s++ != '\0')
		len++;
	bit = 64;
	while (bit-- != 0)
	{
		if (len >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
	}
	usleep(42);
}

void	send_str(char *s, pid_t pid)
{
	int	i;

	while (*s != '\0')
	{
		i = 8;
		while (i-- != 0)
		{
			if ((*s >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(42);
		}
		s++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(42);
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac != 3)
		err_exit();
	pid = arg_to_pid(av[1]);
	if (pid == 0)
		err_exit();
	if (kill(pid, 0) != 0)
		err_exit();
	send_arglen(av[2], pid);
	send_str(av[2], pid);
	return (0);
}
