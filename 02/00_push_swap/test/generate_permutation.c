#include <stdio.h>
#include <stdlib.h>

int	permutation_count(int num)
{
	int res;

	res = 1;
	while (num-- > 0)
		res *= num;
	return (res);
}

void	set_digitlist(int num, int *digit_list)
{
	int i;

	i = 0;
	while (i < num)
	{
		digit_list[i] = i + 1;
		i++;
	}
	return ;
}

int	is_all_zero(int num, int *digit_list)
{
	int i;

	i = 0;
	while (i < num)
	{
		if (digit_list[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_permutatin(int digit, int num, int *digit_list)
{
	if (num == 0)
		printf();
	else
	{
		num--;
		digit_list[digit] = 0;
		printf()

}

void	set_permutation(int num, char **output)
{
	int	*digit_list;

	digit_list = (int *)malloc(sizeof(int) * num);
	if (digit_list == NULL)
		exit(EXIT_FAILURE);
	set_digitlist(num, digit_list);
	print_permutatin(0, num, digit_list);
}

int main(int ac, char **av)
{
	int		num;
	int		output_count;
	int		char_count;
	char	**output;
	int		i;
	
	num = atoi(av);
	output_count = permutation_count(num);
	output = (char **)malloc(sizeof(char) * output_count + 1);
	if (output == NULL)
		exit(EXIT_FAILURE);
	char_count = num * 2; // include '\0' size.
	i = 0;
	while (i < output_count)
	{
		output[i] = (char *)malloc(sizeof(char) * char_count);
		if (output[i] == NULL)
			exit(EXIT_FAILURE);
		i++;
	}
	set_permutation(num, output);
	print_output(output, output_count);
	return (0);
}