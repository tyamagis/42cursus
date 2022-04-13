/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:35:10 by tyamagis          #+#    #+#             */
/*   Updated: 2022/04/12 22:17:09 by tyamagis         ###   ########.fr       */
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

# define SORTED 1
# define A_SORTED 2
# define SHIFT_SORTED 3

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

typedef struct s_record
{
	char	*history;
	int		times;
}	t_record;

typedef struct s_stat
{
	char	is_sorted;
	int		offset;
	int		qty_all;
	int		qty_a;
	t_stack	*top_a;
	t_stack	*top_b;
	int		min_times;
}	t_stat;

/* SORT UTILITIES */
void	psw_rotate_n(t_stat *stat, t_record *rec, char which, int offset);
int		psw_get_offset(t_stat *stat, char which, int tgt_idx);
int		psw_get_min_idx(t_stat *stat, char which);
int		psw_get_max_idx(t_stat *stat, char which);
int		psw_get_min_num(t_stat *stat, char which);
int		psw_get_max_num(t_stat *stat, char which);
int		psw_is_sorted(t_stat *stat);
int		search_min_in_a(t_stat *stat);

/* inits */
void	psw_init_stat(t_stat *stat, int ac, char **av);
void	psw_set_stack(t_stat *stat, int *argnum);

/* pusu_swap OPERATIONS */
void	psw_push(t_stat *stat, char dir, t_record *r);
void	psw_swap(t_stat *stat, char which, t_record *r);
void	psw_rotate(t_stat *stat, char which, char dir, t_record *r);

/* UTILITIES */
/* ** General */
char	*psw_strjoin(char *s1, char *s2);
size_t	psw_strlen(char *s);
void	psw_exit_with_msg(char *msg);

/* ** stack */
void	psw_free_stack(t_stack *stack);

/* ** sort */
void	psw_save_operation(t_record *record, char *s);
void	psw_output_operation(char *s);
void	psw_init_record(t_record *record);

/* SORT ARGOS */
void	psw_fool_sort(t_stat stat, t_record *record);
void	psw_merge_sort(t_stat stat, t_record *record);

/* FOR TEST */
void	print_stack(t_stat *stat);
void	print_stat(t_stat *stat);
void	tests(t_stat *stat);

#endif
