/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:44:50 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/24 19:36:46 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	putpid(void)
{
	pid_t	pid;
	char	s_pid[5];
	int		n;
	int		i;

	pid = getpid();
	n = 10000;
	i = 0;
	while (n != 0)
	{
		if (i == 0 && pid / n == 0)
			s_pid[i] = ' ';
		else
			s_pid[i] = pid / n + '0';
		i++;
		pid %= n;
		n /= 10;
	}
	write(1, "\n\nServer PID is ", 16);
	write(1, s_pid, 5);
	write(1, "\n waiting...\n\n", 14);
}

char	*getlen(int signum, size_t *rcvd_bits, size_t *msg_size)
{
	char			*str;

	if (signum == SIGUSR1)
		*msg_size += 1;
	if (*rcvd_bits == 64)
	{
		str = (char *)malloc(sizeof(char) * (*msg_size + 1));
		if (str == NULL)
			return (NULL);
		return (str);
	}
	*msg_size <<= 1;
	return (NULL);
}

int	getmsg(int signum, char *str, size_t msg_size)
{
	static char	c;
	static int	i;

	if (signum == SIGUSR1)
		c += 1;
	if (++i % 8 == 0)
	{
		*(str + (i / 8) - 1) = c;
		c = 0;
		if (*(str + (i / 8) - 1) == '\0')
		{
			i = 0;
			write(1, str, msg_size);
			free(str);
			return (1);
		}
	}
	else
		c <<= 1;
	return (0);
}

void	prcs(int signum)
{
	static size_t	rcvd_bits;
	static size_t	msg_size;
	static char		*str;
	int				flag;

	rcvd_bits++;
	if (rcvd_bits <= 64)
		str = getlen(signum, &rcvd_bits, &msg_size);
	else
	{
		if (str == NULL)
		{
			write(1, "malloc err!\n", 12);
			exit(0);
		}
		flag = getmsg(signum, str, msg_size);
		if (flag == 1)
		{
			msg_size = 0;
			rcvd_bits = 0;
			putpid();
		}
	}
}

int	main(void)
{
	putpid();
	signal(SIGUSR1, prcs);
	signal(SIGUSR2, prcs);
	while (1)
		;
	return (0);
}
