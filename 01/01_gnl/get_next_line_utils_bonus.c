/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:45:29 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/09 17:32:01 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
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

char	*find_nl(char *str, char **nl)
{
	if (!str)
		return (NULL);
	while (*str != '\n')
	{
		if (*str++ == '\0')
			return (NULL);
	}
	*nl = str;
	return (*nl);
}

void	*free_store(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
