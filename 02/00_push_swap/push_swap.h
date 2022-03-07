/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:53:19 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/07 18:35:10 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR "Error\n"
# define ERR_FEW_ARGS " >> too few arguments.\n"
# define ERR_MALLOC " >> malloc failed.\n"
# define ERR_NOT_INT " >> including non-INT argument.\n"
# define ERR_DUP " >> including duplicate arguments\n"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PLUS 1
# define MINUS -1
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stat
{
	int		is_sorted;
	int		qty_all;
	t_stack	*top_a;
	int		qty_a;
}	t_stat;

t_stack	*psw_init_stat(t_stat *stat, int ac, char **av);
void	psw_free_stack(t_stack *stack);
size_t	psw_strlen(char *s);
void	psw_exit_with_msg(char *msg);
void	psw_set_stack(t_stat *stat, int *argnum, t_stack *stack);
int		psw_is_sorted(t_stat *stat, t_stack *stack);

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
