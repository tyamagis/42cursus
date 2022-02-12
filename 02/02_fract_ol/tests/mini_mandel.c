#include <stdio.h>

int main(void)
{
	long double	min_x, min_y, range, mapx, mapy, real, imag, tmp_r, tmp_i;
	int size = 10;
	char	c[size][size];

	min_x = -2;
	min_y = -2;
	range = 4;
	int	lim = 30;

	int i, j, k;
	j = 0;
	while (j < size)
	{
		i = 0;
		mapy = min_y + (range * j / size);
		while (i < size)
		{
			mapx = min_x + (range * i / size);
			k = 0;
			real = mapx;
			imag = mapy;
			while (k < lim)
			{
				tmp_r = real * real - imag * imag + mapx;
				tmp_i = 2 * real * imag + mapy;
				if (tmp_r > 2 || tmp_i > 2)
				{
					if (tmp_r > 2 || tmp_i > 2)
						printf("[%d, %Lf, %Lf] ", k, tmp_r, tmp_i);
					break ;
				}
				if (tmp_r * tmp_r + tmp_i * tmp_i > 4)
				{
					printf("[%d, %Lf, %Lf] ", k, tmp_r, tmp_i);
					break ;
				}
				real = tmp_r;
				imag = tmp_i;
				k++;
				if (k == lim)
					printf("%d, %Lf, %Lf] ", k, tmp_r, tmp_i);
			}
			i++;
		}
		j++;
		printf("\n");
	}
	return (0);
}
