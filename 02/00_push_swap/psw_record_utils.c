/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_record_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:48:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/22 20:33:05 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psw_init_record(t_record *record)
{
	record->history = NULL;
	record->times = 0;
	return ;
}

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

void	psw_save_operation(t_record *record, char *s)
{
	char	*new_str;

	new_str = psw_strjoin(record->history, s);
	free(record->history);
	record->history = new_str;
	record->times++;
	return ;
}
