/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 03:45:59 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/30 13:23:06 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *end;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		end = ft_lstlast(*lst);
		end->next = new;
	}
}
