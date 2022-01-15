/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:20:21 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/04 22:31:59 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*gnl_split(char **str, char *tmp[])
{
	tmp[3] = *str;
	if (!gnl_split_first(str, tmp))
		return (NULL);
	if (!gnl_split_rest(str, tmp))
	{
		free(tmp[1]);
		return (NULL);
	}
	free(tmp[3]);
	return (tmp[1]);
}

char	*find_nl(char *str, char *tmp[])
{
	if (!str)
		return (NULL);
	while (*str != '\n')
	{
		if (*str++ == '\0')
			return (NULL);
	}
	tmp[0] = str;
	return (str);
}

char	*gnl_strcat(char *str, char *buf, size_t buf_len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (str)
		i = gnl_strlen(str);
	ret = (char *)malloc(sizeof(char) * (i + buf_len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			ret[i] = str[i];
			i++;
		}
		free(str);
	}
	while (*buf)
		ret[i++] = *buf++;
	ret[i] = '\0';
	return (ret);
}

char	*read_buf(int fd, char **str, char *tmp[])
{
	char	*buf;
	ssize_t	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
		{
			tmp[1] = *str;
			*str = NULL;
			free(buf);
			return (tmp[1]);
		}
		buf[read_size] = '\0';
		*str = gnl_strcat(*str, buf, read_size);
		free(buf);
		if (find_nl(*str, tmp))
			return (gnl_split(str, tmp));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*store[256];
	char		*tmp[4];

	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (NULL);
	if (store[fd])
	{
		if (find_nl(store[fd], tmp))
			return (gnl_split(&store[fd], tmp));
	}
	return (read_buf(fd, &store[fd], tmp));
}
