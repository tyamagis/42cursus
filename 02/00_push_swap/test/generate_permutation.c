#include <stdio.h>
#include <stdlib.h>

int	*init_list(int num, int **digit_list)
{
	int	i;
	int	*ret;

	*digit_list = (int *)malloc(sizeof(int) * num);
	ret = (int *)malloc(sizeof(int) * num);
	if (*digit_list == NULL || ret == NULL)
		exit(EXIT_FAILURE);
	while (i < num)
	{
		*digit_list[i] = i;
		i++;
	}
	return (ret);
}

void	print_list(int num, int *digit_list)
{
	int i;
	
	i = 0;
	while (i < num)
	{
		printf("%d ", digit_list[i]);
		i++;
	}
	printf("\n");
	return ;
}

void	copy_list(int num, int *list, int *tmp)
{
	int i;
	
	i = 0;
	while (i < num)
	{
		tmp[i] = list[i];
		i++;
	}
	return ;
}

void	print_pmt(int i, int j, int num, int *digit_list, int *output)
{
	int tmp_digit[num];
	int tmp_output[num];
	int	n;

	copy_list(num, digit_list, tmp_digit);
	copy_list(num, output, tmp_output);
	tmp_digit[i] = -1;
	tmp_output[j] = i;
	if (j == num - 1)
	{
		print_list(num, tmp_output);
	}
	n = 0;
	while (i - n >= 0)
	{
		if (tmp_digit[i - n] != -1)
		{
			print_pmt(i - n, j + 1, num, tmp_digit, tmp_output);
		}
		n++;
	}
	n = 0;
	while (i + n != num)
	{
		if (tmp_digit[i + n] != -1)
		{
			print_pmt(i + n, j + 1, num, tmp_digit, tmp_output);
		}
		n++;
	}
}

int main(int ac, char **av)
{
	int		num;
	int		i;
	int		*digit_list;
	int		*output;

	if (ac == 1 || ac > 2)
	{
		dprintf(2, "arg err\n");
		exit(EXIT_FAILURE);
	}
	num = atoi(av[1]);
	output = init_list(num, &digit_list);
	i = 0;
	while (i < num)
	{
		print_pmt(i, 0, num, digit_list, output);
		i++;
	}
	return (0);
}