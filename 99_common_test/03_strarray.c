/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 06:29:14 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/22 07:09:00 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* string array tests */
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char line[4][4];
	line[0][0] = 'a';
	line[0][1] = 'b';
	line[0][2] = 'c';
	line[0][3] = 'd';
	line[1][0] = 'e';
	line[1][1] = 'f';
	line[1][2] = 'g';
	line[1][3] = 'h';
	line[2][0] = 'i';
	line[2][1] = 'j';
	line[2][2] = 'k';
	line[2][3] = 'l';
	line[3][0] = 'm';
	line[3][1] = 'n';
	line[3][2] = 'o';
	line[3][3] = '\0';

	printf("%s", line);
	return (0);
}
