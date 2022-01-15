/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_argc_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:08:40 by tyamagis          #+#    #+#             */
/*   Updated: 2021/02/07 14:42:39 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void hr(){printf("\n");}

int main(int argc, char *argv[])
{
	int i = 0;
	hr();
	printf("output argc, argv\n");
	hr();
	printf("-- argc ------\n");
	printf("argc  = %16d  (%%d) \n", argc);
	printf("&argc = %16p  (%%p) \n", &argc);
	printf("&argc = %16d  (%%d) \n", &argc);
	hr();
	printf("-- argv ------\n");
	while (i < argc)
		printf("argv[%d] = \"%s\" (%%s)\n", i, argv[i++]);
	hr();
	printf("  **argv   = %16d  (%%d) \n", argv);
	printf("  **argv   = %16x  (%%p) \n", argv);
	printf("&(**argv)  = %16d  (%%d) \n", &argv);
	hr();
	/*
	printf("-- argv ------\n");
	i = 0;
	while (i < argc)
	{
		printf("-- argv ------\n");
		printf("argv  = %d  (%%d) \n\
				argv  = %p  (%%p) \n\
				&argv = %d  (%%d) \n", argv, argv, &argv);
		hr();
		i++;
	}
	*/
	return (0);
}

