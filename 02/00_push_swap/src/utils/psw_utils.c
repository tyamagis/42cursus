/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:12:42 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/22 00:02:37 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*psw_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*new_str;
	char	*tmp_str;

	if (s1 == NULL)
		size = 0;
	else
		size = psw_strlen(s1);
	new_str = (char *)malloc(size + psw_strlen(s2) + 1);
	if (new_str == NULL)
		psw_exit_with_msg(ERR_MALLOC);
	tmp_str = new_str;
	if (s1 != NULL)
	{
		while (*s1 != '\0')
			*tmp_str++ = *s1++;
	}
	while (*s2 != '\0')
		*tmp_str++ = *s2++;
	*tmp_str = '\0';
	return (new_str);
}

size_t	psw_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}

void	psw_exit_with_msg(char *msg)
{
	size_t	err_size;
	size_t	msg_size;

	err_size = psw_strlen(ERR);
	msg_size = psw_strlen(msg);
	write(2, ERR, err_size);
	write(2, msg, msg_size);
	exit(EXIT_FAILURE);
}
