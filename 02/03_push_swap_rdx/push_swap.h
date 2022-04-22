/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:35:10 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/22 21:15:41 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Error messages */
# define ERR "Error\n"
# define ERR_FEW_ARGS " >> too few arguments.\n"
# define ERR_MALLOC " >> malloc failed.\n"
# define ERR_NOT_INT " >> including non-INT argument.\n"
# define ERR_DUP " >> including duplicate arguments.\n"

/* magic numbers */
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PLUS 1
# define MINUS -1
# define ORDER 0
# define REVERSE 1

# define SORTED 15
# define A_SORTED 1
# define A_SHIFT_SORTED 2
# define B_SORTED 4
# define B_SHIFT_SORTED 8

# define IX_RIGHT 3

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
	char	is_sorted;
	int		offset;
	int		qty_all;
	int		qty_a;
	t_stack	*top_malloced;
	t_stack	*top_a;
	t_stack	*top_b;
	char	*history;
	int		op_times;
}	t_stat;

/* SORT UTILITIES */
void	rotate_n(t_stat *stat, char which, int offset);
int		get_offset(t_stat *stat, char which, int tgt_idx);
int		get_min_idx(t_stat *stat, char which);
int		get_max_idx(t_stat *stat, char which);
int		get_min_num(t_stat *stat, char which);
int		get_max_num(t_stat *stat, char which);
int		is_sorted(t_stat *stat);
int		search_min_in_a(t_stat *stat);

/* inits */
void	init_stat(t_stat *stat, int ac, char **av);
void	set_stack(t_stat *stat, int *argnum);

/* pusu_swap OPERATIONS */
void	push(t_stat *stat, char dir);
void	swap(t_stat *stat, char which);
void	rotate(t_stat *stat, char which, char dir);

/* UTILITIES */
/* ** General */
void	free_mems(t_stat *stat);
char	*psw_strjoin(char *s1, char *s2);
size_t	psw_strlen(char *s);
void	exit_with_msg(t_stat *stat, char *msg);

/* ** stack */
void	free_stack(t_stack *stack);

/* ** sort */
void	save_operation(t_stat *stat, char *s);
void	output_operation(char *s);
void	init_record(t_stat *stat);

/* SORT ARGOS */
void	fool_sort(t_stat stat);
void	merge_sort(t_stat stat);
void	swap_sort(t_stat *stat);
void	selection_sort(t_stat *stat);
void	radix_sort(t_stat *stat);
void	radix_2_sort(t_stat *stat);

/* FOR TEST */
void	print_stack(t_stat *stat);
void	print_stat(t_stat *stat);
void	tests(t_stat *stat);

#endif
