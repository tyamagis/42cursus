/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis </var/mail/tyamagis>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:41:49 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/09 19:20:57 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack->next);
		stack = tmp;
	}
	return (NULL);
}

int	err_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

t_stack	*new_stack(int ac)
{
	t_stack	*new;
	t_stack	*top;

	top = (t_stack *)malloc(sizeof(t_stack));
	if (top == NULL)
		err_exit();
	new = top;
	while (--ac)
	{
		new->next = (t_stack *)malloc(sizeof(t_stack));
		if (new->next == NULL)
			err_exit();
		new = new->next;
	}
	return (top);
}

void	set_stack(t_stat *stat, t_stack **stack, int ac, char **av)
{
	int	idx;
	int	ch_idx;
	int	num;

	idx = 1;
	while (ac--)
	{
		num = 0;
		ch_idx = 0;
		while (av[idx][ch_idx] != '\0')
		{
			if ('0' <= av[idx][ch_idx] && av[idx][ch_idx] <= '9')
			{
				num += av[idx][ch_idx] - '0';
				num *= 10;
				ch_idx++;
			}
			else
				err_exit();
		}
		idx++;
		stack->elem = num;
		stack = stack->next;
	}
	return ;
}

void	init_stat(t_stat *stat, t_stack **stack, int ac, char **av)
{
	int	idx;
	int	num;
	int	ch_idx;

	*stack = new_stack(ac);
	if (stack == NULL)
		err_exit();
	stat->is_sorted = 0;
	stat->top_a = *stack;
	stat->qty_all = ac - 1;
	stat->qty_a = ac - 1;
	set_stack(stat, &stack, ac, av)
}

int	main(int ac, char *av[])
{
	t_status	*stat;
	t_stack		*stack;

	if (ac < 2)
		err_exit();

	/*
	create struct for stack and stat
	*/
	stat = (t_status *)malloc(sizeof(t_struct));
	if (stat == NULL)
		err_exit();
	init_stat(stat, &stack, ac);

	/*
	convert av(char *[]) to int[]
	 */
	set_stack(ac, av, stack_a);

	// sort
	//  - think
	//
	// output
	return (0);
}
