/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:27:04 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/30 04:58:17 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*ep;

	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	ep = new;
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&ep, del);
			return (NULL);
		}
		tmp->next = new;
		tmp = new;
	}
	return (ep);
}
