#include <libc.h>

int	ft_ptf_s(va_list *l)
{
	char	*s;
	int		ret;

	s = va_arg(*l, char *);
	ret = 0;
	while (s[ret])
	{
		ret++;
		if (ret < 0)
			return (-1);
	}
	write(1, s, ret);
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	vl;
	int		ret;

	va_start(vl, fmt);
	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ret += ft_ptf_s(&vl);
		}
		else
			ret += write(1, fmt, 1);
		fmt++;
	}
	va_end(vl);
	return (ret);
}

int main(void)
{
	int i = 0;
	char *s = (char *)calloc(1, (size_t)INT_MAX + 10);
	memset(s, 'a', (size_t)INT_MAX + 5);
	i = ft_printf("%s\n", s);
//	i = printf("%s\n", s);
	printf("%d\n", i);
	return (0);
}
