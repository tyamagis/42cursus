/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:29:55 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/22 05:51:46 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void){
/*
**	single array
*/
	int i = 0;
	int a_i[10];

	while (i < 10)
	{
		a_i[i] = i;
		i++;
	}
	i = 0;
	printf("SINGLE ARRAY : a_i[10]\n");
	printf("[i, a_i[i]]\n");
	while (i < 10)
	{
		printf("[%d, %d], ", i, a_i[i]);
		i++;
	}
	printf("\n");
/*
** -----------------
**	Test 1 : try to print a_i[10-]
** -----------------
**
**	--> <<enable>>,
**		but WARN when compiled.
**		-W flags make WARN to ERR.
**
**	printf("a_i[10] = %d @ %d", a_i[10], &a_i[10]);
**	printf("a_i[11] = %d @ %d", a_i[11], &a_i[11]);
*/

/*
** -----------------
**	Test 2 : 2D-array - Part 1 : int array
** -----------------
*/
	int a_i_2d[10][10];
	i = 0;
	printf("TEST 2 : 2D-Array\n");
	int j;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			a_i_2d[i][j] = 100 - ((i * 10) + j);
			printf("[%d, %d, %d]", i, j, a_i_2d[i][j]);
			j++;
		}
		i++;
	}

	i = 0;
	printf("\n\nprintf(*(*a_i_2d + i))\n");
	while (i < 100)
	{
		printf("%d, ", *(*a_i_2d + i));
		i++;
	}

/*
**	a[i][j]  =  *(a[i] + j)  =  *(*a + (i_max * i) + j)
*/



	return (0);
}
