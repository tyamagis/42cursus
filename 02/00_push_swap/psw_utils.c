/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:12:42 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/01 21:56:24 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*psw_free_stack(t_stack *stack)
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

size_t	psw_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}

void	psw_exit_with_msg(char *msg)
{
	size_t	err_size;
	size_t	msg_size;

	err_size = psw_strlen(ERR);
	msg_size = psw_strlen(msg);
	write(2, ERR, err_size);
	write(2, msg, msg_size);
	exit(EXIT_FAILURE);
}
