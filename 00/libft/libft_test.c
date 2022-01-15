/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:24:25 by tyamagis          #+#    #+#             */
/*   Updated: 2020/12/01 10:46:00 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

/* put only '\n' */
void	br(){printf("\n");}
void	hr(){printf("---------------------\n");}

/* change font color */
void	f_bk(){printf("\x1b[30m");}		// black
void	f_r(){printf("\x1b[31m");}		// red
void	f_g(){printf("\x1b[32m");}		// green
void	f_y(){printf("\x1b[33m");}		// yellow
void	f_b(){printf("\x1b[34m");}		// blue
void	f_m(){printf("\x1b[35m");}		// magenta
void	f_c(){printf("\x1b[36m");}		// cyan
void	f_w(){printf("\x1b[37m");}		// white
void	f_def(){printf("\x1b[39m");}	// default

/* change background color */
void	b_bk(){printf("\x1b[40m");}		// black
void	b_r(){printf("\x1b[41m");}		// red
void	b_g(){printf("\x1b[42m");}		// green
void	b_y(){printf("\x1b[43m");}		// yellow
void	b_b(){printf("\x1b[44m");}		// blue
void	b_m(){printf("\x1b[45m");}		// magenta
void	b_c(){printf("\x1b[46m");}		// cyan
void	b_w(){printf("\x1b[47m");}		// Gray
void	b_def(){printf("\x1b[49m");}	// default

/* ----------
** 0 mem - 
** ----------*/
void	t_mem(){
	/* memset*/
/*
	printf("void *ft_memset(void *b, int c, size_t len);\n");
	char *or;
	char *fr;
	int c = 48;
	size_t len = 0;

	while (len < 10)
	{
		c = 48;
		while (c < 200)
		{
			char op[5] = "abcd";
			char fp[5] = "abcd";
			char *or = memset(op, c, len);
			char *fr = memset(fp, c, len);

			printf("original  : %s (& : %p) [c = %d, len = %zu]", or, or, c, len);
			printf("ft_memset : %s (& : %p) [c = %d, len = %zu]", fr, fr, c, len);
			c += 50;
		}
		len++;
	}
*/

	/* bzero*/


	/* memcpy*/


	/* memccpy*/


	/* memmove*/
	hr();
	printf("memmove\n");
	hr();
	void *v1_1 = NULL;
	void *v1_2 = NULL;
	void *v1_3 = NULL;

	ft_memmove(v1_1, v1_2, 5);

	/* memchr*/


	/* memcmp*/
}

/* ----------
** 1 str - 
** ----------*/
void 	t_str(){
	/* strlen*/
	/* strlcpy*/
	/* strlcat*/
	/* strchr*/
	/* strrchr*/
	/* strnstr*/
	/* strncmp*/
}

/* ----------------------------------
** 
** Use pointer to function
**
** maybe it makes codes simpler.
**
** ----------------------------------- */

/*
** void	istest(int t, char *f_name)
** {
** 	int lib_ret = 0;
** 	int ft_ret = 0;
** 	hr();
** 	printf("is- TEST 0%d - %s\n", t, );
** 	printf("int isalpha(int c)\n\n");
** 	printf("(c, isalpha(c), ft_(c))\n");
** 	int i = -1;
** 	while (i++ < 130)
** 	{
** 		printf("(%d, %d, %d)", i, lib_ret, ft_let);
** 		if (lib_ret != ft_ret)
** 		{
** 			f_r();printf("_!_NG_!_\n");f_def();
** 		}
** 		if (i % 4)
** 			printf("\n");
** 		else
** 			printf(", ");
** 	}
** }
**--------------------------------------*/

/* ----------
** 2 is - 
** ----------*/

void	t_is(){
	/* 01. isalpha */
	hr();
	printf("is- TEST 01 - isalpha()\n");
	printf("int isalpha(int c) _ ");
	int i = -1;
	int flag = 1;
	while (i++ < 130)
	{
		if (isalpha(i) != ft_isalpha(i))
		{
			f_r();
			printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, isalpha(i), ft_isalpha(i));
			f_def();
			flag = 0;
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}

	/* 02. isdigit */
	hr();
	printf("is- TEST 02 - isdigit()\n");
	printf("int isdigit(int c) _ ");
	i = -1;
	flag = 1;
	while (i++ < 130)
	{
		if (isdigit(i) != ft_isdigit(i))
		{
			f_r();
			printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, isdigit(i), ft_isdigit(i));
			f_def();
			flag = 0;
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}

	/* 03. isalnum */
	hr();
	printf("is- TEST 03 - isalnum()\n");
	printf("int isalnum(int c) _ ");
	i = -1;
	flag = 1;
	while (i++ < 130)
	{
		if (isalnum(i) != ft_isalnum(i))
		{
			f_r();
			printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, isalnum(i), ft_isalnum(i));
			f_def();
			flag = 0;
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}

	/* 04. isascii */
	hr();
	printf("is- TEST 04 - isascii()\n");
	printf("int isascii(int c) _ ");
	i = -1;
	flag = 1;
	while (i++ < 130)
	{
		if (isascii(i) != ft_isascii(i))
		{
			f_r();
			printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, isascii(i), ft_isascii(i));
			f_def();
			flag = 0;
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}

	/* 05. isprint */
	hr();
	printf("is- TEST 05 - isprint()\n");
	printf("int isprint(int c) _ ");
	i = -1;
	flag = 1;
	while (i++ < 130)
	{
		if (isprint(i) != ft_isprint(i))
		{
			f_r();
			printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, isprint(i), ft_isprint(i));
			f_def();
			flag = 0;
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}

	/* 06. toupper */
	hr();
	printf("is- TEST 06 - toupper()\n");
	printf("int toupper(int c) _ ");
	i = -1;
	flag = 1;
	while (i++ < 130)
	{
		if (toupper(i) != ft_toupper(i))
		{
			f_r();printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, toupper(i), ft_toupper(i));
			f_def();
			flag = 0;
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}

	/* 07. tolower */
	hr();
	printf("is- TEST 07 - tolower()\n");
	printf("int tolower(int c) _ ");
	i = -1;
	flag = 1;
	while (i++ < 130)
	{
		if (tolower(i) != ft_tolower(i))
		{
			f_r();printf("_!_NG_!_\t");
			printf("(i : %d, original : %d, ft_ : %d)\n", i, tolower(i), ft_tolower(i));
			f_def();
		}
	}
	if(flag == 1){f_g();printf("OK!\n");f_def();}
}

/* ----------
** 3 atoi 
** ----------*/
void	t_a(char *at){
	if (atoi(at) != ft_atoi(at))
	{
		f_r();printf("_!_NG_!_\t");
		printf("(%s, %d, %d)\n", at, atoi(at), ft_atoi(at));
		f_def();
	} else {
		printf("CASE >> \"%s\" >> ", at);
		f_g();
		printf("OK\t\t");
		f_def();
	}
}

void	t_atoi(){
	br();hr();
	printf("standard int tests\n");
	hr();
	t_a("-2");
	t_a("-1");br();
	t_a("0");
	t_a("1");br();
	t_a("2");
	t_a("2147483646");br();
	t_a("2147483647");
	t_a("2147483648");br();
	t_a("-2147483647");
	t_a("-2147483648");br();
	t_a("-2147483649");
	br();hr();
	printf("other input tests\n");
	hr();
	t_a("+1234");
	t_a("+-1234");br();
	t_a("--1234");
	t_a("-+1234");br();
	t_a("1.234");
	t_a("  1234");br();
	t_a("\t1234");
	t_a("0x123");br();
	t_a("0001234");
	t_a("000000001234");br();
	br();hr();
	printf("! not needed ! overlimit tests\n");
	hr();
	t_a("4294967294");
	t_a("4294967295");br();
	t_a("4294967296");
	t_a("4294967297");br();
	t_a("4294967298");
	t_a("17179869183");br();
	t_a("17179869184");
	t_a("17179869185");br();
	t_a("9223372036854775805");
	t_a("9223372036854775806");br();
	t_a("9223372036854775807");
	t_a("9223372036854775808");br();
	t_a("9223372036854775809");
	t_a("-9223372036854775805");br();
	t_a("-9223372036854775806");
	t_a("-9223372036854775807");br();
	t_a("-9223372036854775808");
	t_a("-9223372036854775809");br();
	t_a("63410682753376583680");
	t_a("63410682753376583681");br();
	t_a("63410682753376583682");
	t_a("63410682753376583683");br();
}

void	t_others(){
	/* calloc*/
	/* strdup*/
}

void	t_add(){
	/* substr*/
/*
#include <stdio.h>

int main(void){
	char *r;
	char const *s = "1234567890";
	unsigned int st = 0;
	size_t l = 0;

	while (st < 15)
	{
		l = 0;
		while (l < 15)
		{
			r = ft_substr(s, st, l);
			printf("%s : (%s, %d, %zu)\n", r, s, st, l);
			l++;
		}
		st++;
	}
	return (0);
}
*/
	/* strjoin*/
/*
#include <stdio.h>

int main(void){
	char *s1 = "abcde";
	char *s2 = "ABCDE";
	char *s3 = ft_strjoin(s1, s2);
	printf("%p : %s", s3, s3);
	return (0);
}
*/
	/* strtrim*/
/*
#include <stdio.h>

int	main(void){
	char *s1 = "abcdebac";
	char *set = "cab";
	char *trim = ft_strtrim(s1, set);

	printf("%s", trim);
	return (0);
}
*/
}
	/* split*/
	/* itoa*/
/*
#include <stdio.h>

int main(void)
{
	int n = 0;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = 1234567890;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)12345678901;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)23456789012;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)21098765432;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)-12345678901;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)-123456789012;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)-234567890123;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = -2147483648;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = 2147483647;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	n = (int)2147483648;
	printf("n = %12d, ft_itoa(%12d) is %12s\n", n, n, ft_itoa(n));
	return (0);
}

*/

	/* strmapi*/
	/* putchar_fd*/
	/* outstr_fd*/
	/* putendl_fd*/
	/* putnbr_fd

#include <stdio.h>

int main(void)
{
	int n = 0;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)12345;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)-123456;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)23456789012;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)21098765432;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)-12345678901;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)-123456789012;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)-234567890123;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)-2147483648;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)2147483647;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	n = (int)2147483648;
	printf("\nn = %12d, ft_(%12d) is \n", n, n);
	ft_putnbr_fd(n, 1);

	return (0);
}
*/

void	t_lst(){
	/* ft_lstnew*/
	/* ft_lstadd_front*/
	/* ft_lstsize*/
	/* ft_lstlast*/
	/* ft_lstadd_back*/
	/* ft_lstdelone*/
	/* ft_lstclear*/
	/* ft_lstiter*/
	/* ft_lstmap*/
}

void	t_all(){
	t_mem();
	t_str();
	t_is();
	t_atoi();
	t_others();
	t_add();
	t_lst();
}

/* --- MAIN --- */

int	main(void)
{
	char c;
	while (1)
	{
		br();br();
		f_y();
		printf("--- --- --- --- ---\n");
		printf("this is the test each functions. \n");
		printf("--- --- --- --- ---\n");
		printf("0 : mem-\n1 : str-\n2 : is-\n3 : atoi\n4 : calloc, strdup\n");
		printf("5 : Part2. additionnals\n6 : Bonus\n7 : ALL\n");br();
		f_w();b_r();
		printf("Quit this test, press 'Ctrl + C'");
		f_def();b_def();br();br();
		f_g();
		printf("SELECT your test\n >> ");
		c = getchar();
		getchar();
		if (c == '0'){t_mem();}
		else if (c == '1'){t_str();}
		else if (c == '2'){t_is();}
		else if (c == '3'){t_atoi();}
		else if (c == '4'){t_others();}
		else if (c == '5'){t_add();}
		else if (c == '6'){t_lst();}
		else if (c == '7'){t_all();}
		else
		{
			printf("\x1b[31m! ! ! ! !\n\n");
			printf("wrong number input.\n\n! ! ! ! !\x1b[m\n\nTry again >>");
		}
	}
	return (0);
}
