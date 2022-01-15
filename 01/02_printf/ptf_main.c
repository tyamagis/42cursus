#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i = 0;
	int i_max = 2147483647;
	unsigned int i_max_1 = i_max + 1; // INT_MIN
	int ret;
	char *s = "%s outputs string.";
	char *n = NULL;
	unsigned long p_max = 18446744073709551615;

	ret = printf("std : simple output\n");
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : simple output\n");
	printf("ret : %d\n", ret);

	ret = printf("std : %%d : %d, %d, %d\n", i, i_max, i_max_1);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%d : %d, %d, %d\n", i, i_max, i_max_1);
	printf("ret : %d\n", ret);

	ret = printf("std : %%u : %u, %u, %u, %u, %u\n", i, i_max, i_max_1, p_max, p_max + 1);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%u : %u, %u, %u, %u, %u\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);

	ret = printf("std : %%x : %x, %x, %x, %x, %x\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%x : %x, %x, %x, %x, %x\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);

	ret = printf("std : %%X : %X, %X, %X, %X, %X\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%X : %X, %X, %X, %X, %X\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);

	ret = printf("std : %%p : %p, %p, %p, %p, %p\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%p : %p, %p, %p, %p, %p\n", i, i_max, i_max_1, p_max, p_max+1);
	printf("ret : %d\n", ret);

	ret = printf("std : %%c : %c, %c, %c\n", 48, 65, 90);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%c : %c, %c, %c\n", 48, 65, 90);
	printf("ret : %d\n", ret);

	ret = printf("std : %%s : [%s]\n", s);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%s : [%s]\n", s);
	printf("ret : %d\n", ret);

	ret = printf("std : %%s : [%s], %%p : [%p]\n", n, n);
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%s : [%s], %%p : [%p]\n", n, n);
	printf("ret : %d\n", ret);

	ret = printf("std : %%s : [%s], %%p : [%p]\n", "", "");
	printf("ret : %d\n", ret);
	ret = ft_printf("ft_ : %%s : [%s], %%p : [%p]\n", "", "");
	printf("ret : %d\n", ret);

	printf("LONG_MAX, +1, +2 : %p, %p, %p\n", p_max, p_max+1, p_max+2);
	ft_printf("LONG_MAX, +1, +2 : %p, %p, %p\n", p_max, p_max+1, p_max+2);
	return (0);
}
