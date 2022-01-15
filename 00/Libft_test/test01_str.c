/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_original_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:13:31 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/24 21:04:42 by tyamagis         ###   ########.fr       */
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
	char c;

/* ------------------ */
/* strlen             */
/* ------------------ */
	printf("## test 8 : strlen");
	printf("#### size_t strlen(const char *s)");

	char *s1 = "";
	char *s2 = "a";
	char *s3 = " ";
	char *s4 = "abcdefghij";

	printf("s1 = \"%s\", strlen(s1) = %lu\n", s1, strlen(s1));
	printf("s2 = \"%s\", strlen(s2) = %lu\n", s2, strlen(s2));
	printf("s3 = \"%s\", strlen(s3) = %lu\n", s3, strlen(s3));
	printf("s4 = \"%s\", strlen(s4) = %lu\n", s4, strlen(s4));

/* ------------------ */
/* strlcpy            */
/* ------------------ */
	printf("## test 9 : strlcpy");
	printf("#### size_t strlcpy(char *dst, const char *src, size_t dstsize)");

/* test 1 abort ?? */
	char dst1[6] = "123";
	printf("set char dst1 = 123\n");

	const char *src1 = "1234567";
	printf("set const char src1 = 1234567\n");

	size_t dstsize1 = strlen(dst1);
	printf("set size_t dstsize1 = strlen(dst1) = (3)\n");

	printf("dst1_len = %lu, src1_len = %lu, dstsize = %zu \n", strlen(dst1), strlen(src1), dstsize1);

	size_t ret1 = strlcpy(dst1, src1, 3);
	printf("strlcpy done.\n");
	printf("test 1 : ret is %zu \n", ret1);

/* ------------------ */
/* strlcat            */
/* ------------------ */
	printf("## test10 : strlcat");
	printf("#### size_t strlcat(char *dst, const char *src, size_t dstsize)\n\n");
	
	char lcat_dst[5] = "abcd";
	char lcat_src[10] = "123456789";
	int lcat_ret = strlcat(lcat_dst, lcat_src, 3);
	printf("str = \"%s\", return = %d \n", lcat_dst, lcat_ret);

	char lcat_dst1[5] = "abcd";
	char lcat_src1[10] = "123456789";
	int lcat_ret1 = strlcat(lcat_dst1, lcat_src1, 4);
	printf("str = \"%s\", return = %d \n", lcat_dst1, lcat_ret1);

	char lcat_dst2[5] = "abcd";
	char lcat_src2[10] = "123456789";
	int lcat_ret2 = strlcat(lcat_dst2, lcat_src2, 5);
	printf("str = \"%s\", return = %d \n", lcat_dst2, lcat_ret2);

/* ------------------ */
/* strchr             */
/* ------------------ */
	printf("## test11 : strchr");
	printf("#### char *strchr(const char *s, int c)");

/* ------------------ */
/* strrchr            */
/* ------------------ */
	printf("## test12 : strrchr");
	printf("#### char *strrchr(const char *s, int c)");

/* ------------------ */
/* strnstr            */
/* ------------------ */
	printf("## test13 : strnstr");
	printf("#### char *strnstr(const char *haystack, const char *needle, size_t len)");

/* ------------------ */
/* strncmp            */
/* ------------------ */
	printf("## test14 : strncmp");
	printf("#### int strncmp(const char *s1, const char *s2, size_t n)");

	return (0);
}
