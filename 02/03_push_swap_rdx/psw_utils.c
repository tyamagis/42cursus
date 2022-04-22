/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:12:42 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/21 19:38:16 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mems(t_stat *stat)
{
	if (stat->top_malloced != NULL)
		free(stat->top_malloced);
	if (stat->history != NULL)
		free(stat->history);
	return ;
}

size_t	psw_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}

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

void	exit_with_msg(t_stat *stat, char *msg)
{
	size_t	err_size;
	size_t	msg_size;

	err_size = psw_strlen(ERR);
	msg_size = psw_strlen(msg);
	write(2, ERR, err_size);
	write(2, msg, msg_size);
	free_mems(stat);
	exit(EXIT_FAILURE);
}
