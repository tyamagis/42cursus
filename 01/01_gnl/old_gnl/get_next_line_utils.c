/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:00:13 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/01 00:56:52 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*gnl_split_rest(char **str, char *tmp[])
{
	char	*p;

	if (tmp[0] == *str)
	{
		*str = NULL;
		return (tmp[0]);
	}
	tmp[2] = (char *)malloc(sizeof(char) * (tmp[0] - *str + 1));
	if (!tmp[2])
		return (NULL);
	p = tmp[2];
	while (**str != '\0')
		*tmp[2]++ = *(*str)++;
	*tmp[2] = '\0';
	*str = p;
	return (p);
}

char	*gnl_split_first(char **str, char *tmp[])
{
	char	*p;

	tmp[1] = (char *)malloc(sizeof(char) * (tmp[0] - *str + 2));
	if (!tmp[1])
		return (NULL);
	p = tmp[1];
	while (*str != tmp[0] + 1)
		*tmp[1]++ = *(*str)++;
	*tmp[1] = '\0';
	while (*tmp[0])
		tmp[0]++;
	tmp[1] = p;
	return (p);
}
