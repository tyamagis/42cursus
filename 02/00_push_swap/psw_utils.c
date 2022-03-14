/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:12:42 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/03 21:07:54 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psw_output_operation(char *s)
{
	size_t	size;

	if (s == NULL)
		size = 0;
	else
		size = psw_strlen(s);
	write(1, s, size);
	return ;
}

void	psw_save_operation(t_stat *stat, char *s)
{
	size_t	size;
	char	*old_str;
	char	*new_str;
	char	*tmp_str;

	/* test */
	write(1, s, psw_strlen(s));
	/* ---- */
	old_str = stat->op_history;
	if (old_str == NULL)
		size = 0;
	else
		size = psw_strlen(old_str);
	new_str = (char *)malloc(size + psw_strlen(s) + 1);
	if (new_str == NULL)
		psw_exit_with_msg(ERR_MALLOC);
	tmp_str = new_str;
	if (old_str != NULL)
	{
		while (*old_str != '\0')
			*tmp_str++ = *old_str++;
	}
	while (*s != '\0')
		*tmp_str++ = *s++;
	*tmp_str = '\0';
	free(stat->op_history);
	stat->op_history = new_str;
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
