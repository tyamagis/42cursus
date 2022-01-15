/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:10:35 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/01 10:39:08 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *crt;
	t_list *tmp;

	if (!(lst) || !(*del))
		return ;
	crt = *lst;
	while (*lst)
	{
		tmp = crt->next;
		ft_lstdelone(crt, *(del));
		*lst = tmp;
		crt = *lst;
	}
	*lst = NULL;
}
