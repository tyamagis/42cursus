#include "push_swap.h"

void	psw_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	stack->prev->next = NULL;
	while (stack->next != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return ;
}
