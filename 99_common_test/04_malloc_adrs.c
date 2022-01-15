/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_adrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:04:11 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/22 19:18:17 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
/* ------------------
** TEST CASE 1
** too many malloc() then how to allocate mems.
** ------------------

	char *ptr;
	int i = 0;
	int j;

	while (i < 64)
	{
		ptr = malloc(1000000000);
		j = 0;
		while (j < 10)
		{
			printf("i = %3d, j = %4d : ptr = %10x\n", i, j, &ptr[j]);
			j++;
		}
		printf("----------\n");
		i++;
	}
**
*/

/* ------------------
** TEST CASE 2
** max malloc size ??
// N O T C O M P L E T E
 ** ------------------

	char *ptr;

	ptr = malloc(140737488000000);
	printf("ptr : %10x", ptr);
	return (0);
*/

/* ------------------
** TEST CASE 3
** malloc and free
** ------------------
*/
	char *ptr1;
	char *ptr2;

	printf("char *ptr1;\n");
	printf("char *ptr2;\n");
	printf(" - ptr1 : %x\n", ptr1);
	printf(" - ptr2 : %x\n", ptr2);
	/* ptr2 is always 0, but ptr1 is not. why??? */
	ptr1 = malloc(16);
	ptr2 = ptr1 + 8;
	printf("ptr1 = malloc(16);\nptr2 = ptr1 + 8\n");
	printf(" - ptr1 : %x\n", ptr1);
	printf(" - ptr2 : %x\n", ptr2);
	int i = 0;
	while (i < 20){
		*(ptr1 + i) = i;
		printf(" - ptr1 + i : %x, *(ptr1 + i) : %d, i : %d\n", (ptr1 + i), *(ptr1 + i), i);
		i++;
	}
	ptr1[26] = 'A';
	/* we can access and write over the allocated range.(there are no warning.) */
	printf("%c", ptr1[26]);
	// free(ptr2);
	/* free function cannot free the not malloced pointer. this cause abort. */
	printf(" - ptr1 : %x\n", ptr1);
	printf(" - ptr2 : %x\n", ptr2);
	return (0);
}
