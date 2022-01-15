/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:34:12 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/09 17:26:11 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*gnl_trim_store(char **str, char *nl, char **line)
{
	char	*next_str;
	char	*tmp;

	while (*nl != '\0')
		nl++;
	if (nl == *str)
		return (NULL);
	next_str = (char *)malloc(sizeof(char) * (nl - *str + 1));
	if (next_str == NULL)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	tmp = next_str;
	while (*(*str - 1) != '\0')
		*tmp++ = *(*str)++;
	return (next_str);
}

char	*gnl_trim_line(char **str, char *nl)
{
	char	*line;
	char	*tmp;

	line = (char *)malloc(sizeof(char) * (nl - *str + 2));
	if (line == NULL)
		return (NULL);
	tmp = line;
	while (nl + 1 != *str)
		*tmp++ = *(*str)++;
	*tmp = '\0';
	return (line);
}

char	*gnl_split(char **str, char *nl)
{
	char	*line;
	char	*old_str;

	old_str = *str;
	line = gnl_trim_line(str, nl);
	if (line == NULL)
		return (free_store(str));
	*str = gnl_trim_store(str, nl, &line);
	free(old_str);
	if (*str == NULL)
		return (line);
	return (line);
}

char	*read_buf(int fd, char **str, char **nl, char *buf)
{
	ssize_t	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		*str = gnl_strcat(*str, buf, read_size);
		if (find_nl(*str, nl))
			return (gnl_split(str, *nl));
	}
	if (read_size < 0)
		return (free_store(str));
	else
	{
		buf = *str;
		*str = NULL;
		return (buf);
	}
}

char	*get_next_line(int fd)
{
	static char	*store[256];
	char		*line;
	char		*nl;
	char		*buf;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (store[fd] != NULL && find_nl(store[fd], &nl))
		return (gnl_split(&store[fd], nl));
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free_store(&store[fd]));
	line = read_buf(fd, &store[fd], &nl, buf);
	free(buf);
	if (line == NULL)
		return (free_store(&store[fd]));
	return (line);
}
