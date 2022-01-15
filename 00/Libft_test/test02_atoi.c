/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_original_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:13:31 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/25 00:39:03 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
	const int i_Max = 2147483647;
	const int i_min = -2147483648;
	const int i_zero = 0;
	int i = 0;
	char c = 0;
	char *str;

	printf("# atoi, is_funcs test cases\n");
/* ------------------ */
/* atoi               */
/* ------------------ */
	printf("## test15 : atoi\n");
	printf("#### int atoi(const char *str)\n\n");

	/* TEST */
	printf("### [test cases]\n");
	printf("#### [str,\tatoi(str)]\n");

	str = "2147483647";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-2147483648";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "2147483648";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-2147483649";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "   483649";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-  483649";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "   -483649";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "0000020";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-00000000000000020";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "0x4a";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-0x4a";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "+1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "++1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "+-1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-+1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "--1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "++++1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "----1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "++-+1234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "4294967294";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "4294967295";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "4294967296";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "4294967297";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "4294967298";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "17179869184";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "9223372036854775805";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "9223372036854775806";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "9223372036854775807";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "9223372036854775808";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "9223372036854775809";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-9223372036854775805";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-9223372036854775806";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-9223372036854775807";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-9223372036854775808";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "-9223372036854775809";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "1.234";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "18446744073709551616";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "184467440737095516160";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	str = "1844674407370955161600";
	printf("[%s,\t%d]\n\n", str, atoi(str));
	return (0);
}
