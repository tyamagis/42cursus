/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:42:36 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/13 01:14:03 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long	l;
	int				minus;

	l = 0;
	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		l *= 10;
		l += *str - '0';
		str++;
		if (minus == 1 && l > LONG_MAX)
			return (-1);
		if (minus == -1 && l > LONG_MIN * minus)
			return (0);
	}
	return ((int)l * minus);
}

int	main(void){
	char *s1 = "2147483647     ";
	char *s2 = "2147483648";
	char *s3 = "-2147483648";
	char *s4 = "-2147483649";
	char *s5 = "   483649";
	char *s6 = "-  483649";
	char *s7 = "-483649";
	char *s8 = "00000020";
	char *s9 = "-00000020";
	char *s10 = "0x4a";
	char *s11 = "----1234";
	char *s12 = "4294967295";
	char *s13 = "9223372036854775806";
	char *s14 = "9223372036854775807";
	char *s15 = "9223372036854775808";
	char *s16 = "-9223372036854775807";
	char *s17 = "-9223372036854775808";
	char *s18 = "-9223372036854775809";
	char *s19 = "+1234";
	char *s20 = "++1234";
	char *s21 = "-+1234";

	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s1, atoi(s1), ft_atoi(s1));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s2, atoi(s2), ft_atoi(s2));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s3, atoi(s3), ft_atoi(s3));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s4, atoi(s4), ft_atoi(s4));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s5, atoi(s5), ft_atoi(s5));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s6, atoi(s6), ft_atoi(s6));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s7, atoi(s7), ft_atoi(s7));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s8, atoi(s8), ft_atoi(s8));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s9, atoi(s9), ft_atoi(s9));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s10, atoi(s10), ft_atoi(s10));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s11, atoi(s11), ft_atoi(s11));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s12, atoi(s12), ft_atoi(s12));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s13, atoi(s13), ft_atoi(s13));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s14, atoi(s14), ft_atoi(s14));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s15, atoi(s15), ft_atoi(s15));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s16, atoi(s16), ft_atoi(s16));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s17, atoi(s17), ft_atoi(s17));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s18, atoi(s18), ft_atoi(s18));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s19, atoi(s19), ft_atoi(s19));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s20, atoi(s20), ft_atoi(s20));
	printf("s = \t%s\natoi(s) = \t%d\nft_atoi(s) = \t%d\n\n", s21, atoi(s21), ft_atoi(s21));

	return (0);
}
