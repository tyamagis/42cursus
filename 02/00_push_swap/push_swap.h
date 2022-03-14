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
# define ERR_DUP " >> including duplicate arguments.\n"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PLUS 1
# define MINUS -1
# define ORDER 0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

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
	int		qty_a;
	t_stack	*top_a;
	t_stack	*top_b;
	char	*op_history;
}	t_stat;

void	psw_init_stat(t_stat *stat, int ac, char **av);
void	psw_set_stack(t_stat *stat, int *argnum);
bool	psw_is_sorted(t_stat *stat);

void	psw_push(t_stat *stat, char dir);
void	psw_swap(t_stat *stat, char which);
void	psw_rotate(t_stat *stat, char which, char dir);

void	psw_free_stack(t_stack *stack);
size_t	psw_strlen(char *s);
void	psw_exit_with_msg(char *msg);
void	psw_save_operation(t_stat *stat, char *s);
void	psw_output_operation(char *s);

void	fool_sort(t_stat *stat);
void	print_stack(t_stat *stat);

void	tests(t_stat *stat);

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
