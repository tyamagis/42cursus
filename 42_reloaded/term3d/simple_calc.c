#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data
{
	int			start, end, lim, size;
	long double	min_x, min_y, range;
	long double	*ans;
} t_data;

void	*calc_th(void *arg)
{
	t_data		*data;
	int			i, x, y;
	long double	ax, by, ix, iy;

	data = (t_data *)arg;
	y = data->start;
	while (y < data->end)
	{
		x = 0;
		while (x < data->size)
		{
			i = 0;
			ax = (x * data->range / data->size) - data->min_x;
			by = (y * data->range / data->size) - data->min_y;
			ix = ax;
			iy = by;
			while (i < data->lim)
			{
				long double real = ix * ix - iy * iy + ax;
				long double imag = 2 * ix * iy + by;
				if (real * real + imag * imag > 4)
					i++;
				ix = real;
				iy = imag;
				i++;
			}
			data->ans[x + y * data->size] = ix * ix * iy * iy;
			x++;
		}
		y++;
	}
	return NULL;
}

long double	calc(int x, int y, t_data *data)
{
	int			i;
	long double	ax, by, ix, iy;

	i = 0;
	ax = (x * data->range / data->size) - data->min_x;
	by = (y * data->range / data->size) - data->min_y;
	ix = ax;
	iy = by;
	while (i < data->lim)
	{
		long double real = ix * ix - iy * iy + ax;
		long double imag = 2 * ix * iy + by;
		if (real * real + imag * imag > 4)
			i++;
		ix = real;
		iy = imag;
		i++;
	}
	return (ix *ix * iy * iy);
}

int	main(void)
{
	clock_t		start, end;
	int			num = 4; // thread vars 
	pthread_t	th[num];
	t_data		data[4];

	data[0].min_x = -0.72256774160258646601;
	data[0].min_y = -0.19197434060103114471;
	data[0].range = 0.000000000000363797881;
	data[0].lim = 200;
	data[0].size = 256;

	data[1].min_x = data[0].min_x;
	data[1].min_y = data[0].min_y;
	data[1].range = data[0].range;
	data[1].lim = data[0].lim;
	data[1].size = data[0].size;

	data[2].min_x = data[0].min_x;
	data[2].min_y = data[0].min_y;
	data[2].range = data[0].range;
	data[2].lim = data[0].lim;
	data[2].size = data[0].size;

	data[3].min_x = data[0].min_x;
	data[3].min_y = data[0].min_y;
	data[3].range = data[0].range;
	data[3].lim = data[0].lim;
	data[3].size = data[0].size;
	/*
	 * without threads -----
	 */
	printf("\ncalc without therads\n");
	int x = 0;
	int y = 0;
	long double *ans = (long double *)malloc(sizeof(long double) * (data[0].size * data[0].size));
	start = clock();
	while (y < data[0].size)
	{
		x = 0;
		while (x < data[0].size)
		{
			*ans = calc(x, y, &data[0]);
			ans++;
			x++;
		}
		y++;
	}
	end = clock();
	printf("Time : %lu\n", end - start);

	/*
	 * with threads -----
	 */
	printf("\ncalc with threads\n");

	start = clock();
	// create threads
	data[0].start = 0;
	data[0].end = data[0].size / 4;
	data[1].start = data[0].size / 4;
	data[1].end = data[0].size * 2 / 4;
	data[2].start = data[0].size * 2 / 4;
	data[2].end = data[0].size * 3 / 4;
	data[3].start = data[0].size * 3 / 4;
	data[3].end = data[0].size;

	end = clock();
	printf("Time : %lu\n", end - start);

	start = clock();
	data[0].ans = (long double *)malloc(sizeof(long double) * (data[0].size * data[0].size));
	data[1].ans = data[0].ans;
	data[2].ans = data[0].ans;
	data[3].ans = data[0].ans;
	pthread_create(&th[0], NULL, calc_th, &data[0]);
	pthread_create(&th[1], NULL, calc_th, &data[1]);
	pthread_create(&th[2], NULL, calc_th, &data[2]);
	pthread_create(&th[3], NULL, calc_th, &data[3]);
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);
	pthread_join(th[2], NULL);
	pthread_join(th[3], NULL);
	end = clock();
	printf("Time : %lu\n", end - start);

	return (0);
}
