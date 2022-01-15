/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:59:01 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/21 05:40:23 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// GLOBAL
int g1 = 255;
int g2;
g3 = 127;
g4;

void myFunc(void){
	int i = 0;
	printf("---- myFunc ----\n");
	printf("int i\t\t%d\t%p\n", i, &i);
	printf("myFunc\t%d\t%p\n", myFunc, &myFunc);
	return ;
}

int main(int argc, char *argv[])
{
	// LOCAL
	// var
	static int l_st_int;
	static int li_st_int = 63;
	int l_int = 1023;
	char l_char = 63;

	// ARRAY
	static char st_a1[128];
	static char st_a2[128] = "this is the static char array.";
	char a1[128];
	char a2[128] = "this is the char array.";
	char *str1 = "this is the char pointer [LITERAL].";
	char *str_m = malloc(128);

	void *main_adrs = &main;

	// memory display
	printf("---- ARGS ----\n");
	int i = 0;
	int j = 0;
	printf("argc = %d : [%p]\n", argc, &argc);
	while (i < argc){
		j = 0;
		while (argv[i][j]){
			printf("argv[%d][%d] = %c(%d) : [%p]\n", i, j, argv[i][j], argv[i][j], &argv[i][j]);
			j++;
		}
		i++;
	}

	printf("---- VAR ----\n");
	printf("[name]\t\t[value]\t\t[address]\n");
	printf("g1\t\t%8d\t[%10p]\n", g1, &g1);
	printf("g2\t\t%8d\t[%10p]\n", g2, &g2);
	printf("g3\t\t%8d\t[%10p]\n", g3, &g3);
	printf("g4\t\t%8d\t[%10p]\n", g4, &g4);
	printf("l_st_int\t%8d\t[%10p]\n", l_st_int, &l_st_int);
	printf("li_st_int\t%8d\t[%10p]\n", li_st_int, &li_st_int);
	printf("l_int\t\t%8d\t[%10p]\n", l_int, &l_int);
	printf("l_char\t\t%8d\t[%10p]\n", l_char, &l_char);
	printf("i\t\t%8d\t[%10p]\n", i, &i);
	printf("j\t\t%8d\t[%10p]\n", j, &j);

	printf("---- ARRAY ----\n");
	printf("st_a1[0]\t%8d\t%10p\n", st_a1[0], st_a1);
	printf("st_a2[0]\t%8d\t%10p\n", st_a2[0], st_a2);
	printf("a1[0]\t\t%8d\t%10p\n", a1[0], a1);
	printf("a2[0]\t\t%8d\t%10p\n", a2[0], a2);
	printf("*str1\t\t%8d\t%10p\n", *str1, str1);
	printf("*str_m\t\t%8d\t%10p\n", *str_m, str_m);

	printf("---- FUNCTIONS ----\n");
	printf("main\t\t%8d\t%10p\n", main, &main);
	printf("printf\t\t%8d\t%10p\n", printf, &printf);
	printf("malloc\t\t%8d\t%10p\n", malloc, &malloc);
	myFunc();
	return (0);
}
