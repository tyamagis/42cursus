/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:53:19 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/05 15:15:33 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
}	t_stack;

typedef struct s_status
{
	int		is_sorted;
	int		qty_all;
	t_stack	*top_a;
	int		qty_a;
}	t_status;

#endif

/*
 * -> last_a
 * last_a = top_a + (qty_a - 1);
 *
 * -> qty_b
 * qty_b = qty_all - qty_a;
 *
 * -> top_b
 * if (qty_all - qty_a)
 * 		top_b = top_a - 1;
 * 
 * -> last_b
 * last_b = top_b - (qty_b - 1);
 * last_b = (top_a - 1) - (qty_all - qty_a);
 *
 * 
 */
