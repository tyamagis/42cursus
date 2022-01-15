/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_size_each_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:13:57 by tyamagis          #+#    #+#             */
/*   Updated: 2022/01/07 02:55:24 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("# [ - GUACAMOLE ENV - ]\n\n");
	printf("## BASIC Types\n\n");
	printf("[char] is\t%lu Byte.\n", sizeof(char));
	printf("CHAR_min =\t%d\nCHAR_MAX =\t%d\n\n", CHAR_MIN, CHAR_MAX);

	printf("[short] is\t%lu Byte.\n", sizeof(short));
	printf("SHRT_min =\t%d\nSHRT_MAX =\t%d\n\n", SHRT_MIN, SHRT_MAX);

	printf("[int] is\t%lu Byte.\n", sizeof(int));
	printf("INT_min =\t%d\nINT_MAX =\t%d\n\n", INT_MIN, INT_MAX);

	printf("[long] is\t%lu Byte.\n", sizeof(long));
	printf("LONG_min =\t%ld\nLONG_MAX =\t%ld\n\n", LONG_MIN, LONG_MAX);

	printf("[long long] is\t%lu Byte.\n", sizeof(long long));
	printf("long long is the same as long.\n\n");

	printf("[float] is\t%lu Byte.\n", sizeof(float));
	printf("float_min =\t%f\nfloat_MAX =\t%f\n\n", FLT_MIN, FLT_MAX);

	printf("[double] is\t%lu Byte.\n", sizeof(double));
	printf("double_min =\t%lf\ndouble_MAX =\t%lf\n\n", DBL_MIN, DBL_MAX);

	printf("[long double] is\t%lu Byte.\n", sizeof(long double));
	printf("long double_min =\t%Lf\nlong double_MAX =\t%Lf\n\n", LDBL_MIN, LDBL_MAX);

	printf("[size_t] is\t%lu Byte.\n", sizeof(size_t));

	printf("[pointer] is \t%lu Byte.\n", sizeof(int*));
}
