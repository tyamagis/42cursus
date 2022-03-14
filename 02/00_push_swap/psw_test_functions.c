#include "push_swap.h"

// test print
void	print_stack(t_stat *stat)
{
	printf("\n----------\n");
	printf("Order A : ");
	int i = 0;
	int j;
	t_stack	*stk = stat->top_a;

	while (i < stat->qty_a)
	{
		printf("%d, ", stk->elem);
		stk = stk->next;
		i++;
	}
	j = 0;
	printf(" (");
	while (j++ < 5 && stk != NULL)
	{
		printf("%d, ", stk->elem);
		stk = stk->next;
	}
	printf(")");
	printf(" ||  stack B : ");
	i = 0;
	stk = stat->top_b;
	while (i < stat->qty_all - stat->qty_a)
	{
		printf("%d, ", stk->elem);
		stk = stk->next;
		i++;
	}
	j = 0;
	printf(" (");
	while (j++ < 5 && stk != NULL)
	{
		printf("%d, ", stk->elem);
		stk = stk->next;
	}
	printf(")");
	printf("\nReverse A : ");
	i = 0;
	stk = stat->top_a;

	while (i < stat->qty_a)
	{
		printf("%d, ", stk->elem);
		stk = stk->prev;
		i++;
	}
	j = 0;
	printf(" (");
	while (j++ < 5 && stk != NULL)
	{
		printf("%d, ", stk->elem);
		stk = stk->prev;
	}
	printf(")");
	printf(" ||  stack B : ");
	i = 0;
	stk = stat->top_b;
	while (i < stat->qty_all - stat->qty_a)
	{
		printf("%d, ", stk->elem);
		stk = stk->prev;
		i++;
	}
	j = 0;
	printf(" (");
	while (j++ < 5 && stk != NULL)
	{
		printf("%d, ", stk->elem);
		stk = stk->prev;
	}
	printf(")");
	printf("\n----------\n");
	printf("\n");
	return ;
}

void	test_push(t_stat *stat)
{
	int i = 10;

	while (i-- > 0)
	{
		psw_push(stat, 'a');
		print_stack(stat);
	}
	i = 10;
	while (i-- > 0)
	{
		psw_push(stat, 'b');
		print_stack(stat);
	}
	i = 10;
	while (i-- > 0)
	{
		psw_push(stat, 'a');
		print_stack(stat);
	}
}

void	push_and_swap(t_stat *stat)
{
	psw_push(stat, 'b');
	print_stack(stat);
	psw_push(stat, 'b');
	print_stack(stat);
	psw_swap(stat, 'b');
	print_stack(stat);
	psw_swap(stat, 'b');
	print_stack(stat);
	psw_swap(stat, 'a');
	print_stack(stat);
	psw_push(stat, 'b');
	print_stack(stat);
	psw_swap(stat, 'b');
	print_stack(stat);
	psw_push(stat, 'b');
	print_stack(stat);

}

void	tests(t_stat *stat)
{
	print_stack(stat);

	// test_push(stat);

	push_and_swap(stat);
	/*
	while (stat.is_sorted == FALSE)
	{
		fool_sort(&stat);
	}
	*/
	printf("\n OPERATION\n");
	printf("%s", stat->op_history);
}
