/* Part 1.
 *  - ft_strlen
 *  - ft_memcpy
 *  - ft_memset
 *  - ft_bzero
 *  - ft_memmove
 *  - ft_memcmp
 *  - ft_memchr
 */

#include <string.h>
#include <stdio.h>

// MOD printf() funcs

void	br(){printf("\n");}

void	hr(){printf("==========\n");}

void	h1(char	*s){
	br();
	hr();
	printf("    %s\n", s);
	hr();
	br();
}

// strlen()

void	run_strlen(char *s)
{
	printf("s = [%s]\n", s);
	printf("strlen() = %zu\n", strlen(s));
	// printf("ft_strlen() = %zu\n", ft_strlen(s));
}

void	test_strlen()
{
	h1("--- strlen ---");

	size_t	size = 0;
	printf("sizeof(size_t) : %zu\n\n", sizeof(size_t));

	run_strlen("");
	run_strlen("abcde");
	run_strlen("how long this string is ???");
}

// memcpy

void	run_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	ret = memcpy(dst, src, n);
	printf("memncpy(dst, src, %zu);\n", n);
	printf(">> dst = [%s] (%p)\n", dst, dst);
	printf(">> src = [%s] (%p)\n", src, src);
	printf(">> ret = [%s] (%p)\n\n", ret, ret);
}

void	init_dst(char *dst, int size)
{
	int i = 0;
	while (i++ < size)
		*dst++ = i + '0';
	*dst = '\0';
}

void	test_memcpy()
{
	void	*ret;
	char	dst_char[10] = "123456789";
	void	*dst = dst_char;
	void	*src = "abcde";

	h1("--- memcpy ---");

	printf("setting : [dst_len > src_len]\n");
	printf("void *dst = [%s](%p);\n", dst, dst);
	printf("void *src = [%s](%p)\n\n", src, src);

	int i = 0;
	while (i < 10)
	{
		init_dst(dst_char, 9);
		run_memcpy(dst, src, i++);
	}

	init_dst(dst_char, 3);
	hr();
	printf("setting : [dst_len < src_len]\n");
	printf("void *dst = [%s](%p);\n", dst, dst);
	printf("void *src = [%s](%p)\n\n", src, src);

	i = 0;
	while (i < 10)
	{
		init_dst(dst_char, 3);
		run_memcpy(dst, src, i++);
	}


}

// memset()

void	test_memset()
{
}

// bzero()

void	test_bzero()
{
}

// memmove()

void	test_memmove()
{
}

// memcmp()

void	test_memcmp()
{
}

// memchr()

void	test_memchr()
{
}

// main and memos

int main(void)
{
	/* WHAT SIZE is SIZE_T ?? */
	test_strlen();

	/* WHAT IS VOID POINTER ?? */
	/* WHAT IS CONST KEYWORD ?? */
	/* WHAT IS THE DIFFERENCE 
	 * 	1. char *s = "string";
	 * 	2. char s[7] = "string";
	 * 	3. char *s;
	 * 	   s = malloc(7);
	 * 	   s[0] = 's'; s[1] = 't'; .... s[6] = '\0'; */
	/* WHAT HAPPEN if s[7] = 'c'; in case of above */
	/* WHAT HAPPEN if s[6] != '\0' in case of above */
	test_memcpy();

	return (0);
}
