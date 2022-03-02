/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:59:01 by tyamagis          #+#    #+#             */
/*   Updated: 2022/03/02 19:06:31 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// GLOBAL
char g_c1;
char g_c2 = 'a';
int g_i1 = 255;
int g_i2;
g1 = 127;
g2;
char g_c3;
char *g_s = "abcde";

// GLOBAL STRUCT w/ bit field
typedef struct s_g_static
{
	char	g_st_c;
	int		g_st_i1;
	int		g_st_bf1 : 1;
	int		g_st_bf2 : 1;
	int		g_st_i2;
	int		g_st_bf3 : 1;
} t_g_struct;

t_g_struct	t_st;

// FUNCTION
void func(char c, int i, t_g_struct t_st){
	int j = 0;
	printf("---- in func() ----\n");
	printf("int i\t\t%d\t%p\n", i, &i);
	return ;
}

// MAIN
int main(int argc, char *argv[])
{
	// LOCAL
	// var
	static int l_st_int;
	static int li_st_int = 63;
	int l_int = 1023;
	char l_char = 63;

	// ARRAY & POINTER w/ LITERAL
	static char st_a1[128];
	static char st_a2[128] = "this is the static char array.";
	char a1[128];
	char a2[128] = "this is the char array.";
	char *str1 = "this is the char pointer [LITERAL].";
	char *str_m = malloc(128);

	t_g_struct	l_st;

	// print address -------------
	printf("---- MAIN() ----\n");
	int i = 0;
	int j = 0;
	printf("main() %p [%p]\n", main, &main);
	printf("argc = %d [%p]\n", argc, &argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			printf("argv[%d][%d] = %c(%d) : [%p]\n", i, j, argv[i][j], argv[i][j], &argv[i][j]);
			j++;
		}
		i++;
	}

	printf("-- VAR ----\n");
	printf("---- global variable\n");
	printf("[name] | [value] | [address]\n");
	printf("char g_c1, only declare | [%16p]\n", &g_c1);
	printf("char g_c2, assign 'a' | [%16p]\n", &g_c2);
	printf("int g_i1, assign 255 | [%16p]\n", &g_i1);
	printf("int g_i2, only declare | [%16p]\n", &g_i2);
	printf("g1, without type & assign 127 | [%16p]\n", &g1);
	printf("g2, without type only declare | [%16p]\n", &g2);
	printf("char g_c3, only declare | [%16p]\n", &g_c3);
	printf("char *g_s, assign literal | [%16p]\n", &g_s);
	printf("\n");
	printf("---- gloabl static\n");
	printf("t_g_struct | [%16p]\n", &t_st);
	printf("t_g_struct.char | [%16p]\n", &t_st.g_st_c);
	printf("t_g_struct.int1  | [%16p]\n", &t_st.g_st_i1);
	/*
	printf("t_g_struct.bf1:1 | [%16p]\n", &t_st.g_st_bf1);
	printf("t_g_struct.bf2:1 | [%16p]\n", &t_st.g_st_bf2);
	*/
	printf("t_g_struct.int2 | [%16p]\n", &t_st.g_st_i2);
	/*
	printf("t_g_struct.bf3:1 | [%16p]\n", &t_st.g_st_bf3);
	*/
	printf("\n");
	printf("---- main() vars\n");
	printf("l_st_int | [%16p]\n", &l_st_int);
	printf("li_st_int | [%16p]\n", &li_st_int);
	printf("l_int | [%16p]\n", &l_int);
	printf("l_char | [%16p]\n", &l_char);
	printf("i | [%16p]\n", &i);
	printf("j | [%16p]\n", &j);
	printf("local static | [%16p]\n", l_st);
	printf("\n");
	printf("---- ARRAY ----\n");
	printf("st_a1 | %16p\n", st_a1);
	printf("st_a2 | %16p\n", st_a2);
	printf("a1 | %16p\n", a1);
	printf("a2 | %16p\n", a2);
	printf("*str1 | %16p\n", str1);
	printf("*str_m | %16p\n", str_m);
	printf("\n");
	printf("---- FUNCTIONS ----\n");
	printf("main\t\t%10p\t%10p\n", main, &main);
	printf("printf\t\t%10p\t%10p\n", printf, &printf);
	printf("malloc\t\t%10p\t%10p\n", malloc, &malloc);
	printf("func\t\t%10p\t%10p\n", func, &func);
	func(l_char, l_int, l_st);
	return (0);
}
