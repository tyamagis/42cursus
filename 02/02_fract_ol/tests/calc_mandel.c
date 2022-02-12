#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void calc_long_double(long double r, long double i, int *dvg, long double *dvg_r, long double *dvg_i, int x, int y)
{
	long double	real;
	long double	imag;
	long double	pow_r;
	long double	pow_i;

	*dvg = 0;
	real = r;
	imag = i;
	pow_r = r * r;
	pow_i = i * i;
	while (*dvg < 1000)
	{
		*dvg_r = pow_r - pow_i + r;
		*dvg_i = 2 * real * imag + i;
		pow_r = *dvg_r * *dvg_r;
		pow_i = *dvg_i * *dvg_i;
		if (pow_r + pow_i > 4)
			return ;
		real = *dvg_r;
		imag = *dvg_i;
		(*dvg)++;
	}
	*dvg = -1;
	return ;
}

void calc_float(float r, float i, int *dvg, float *dvg_r, float *dvg_i, int x, int y)
{
	float	real;
	float	imag;
	float	pow_r;
	float	pow_i;

	*dvg = 0;
	real = r;
	imag = i;
	pow_r = r * r;
	pow_i = i * i;
	while (*dvg < 1000)
	{
		*dvg_r = pow_r - pow_i + r;
		*dvg_i = 2 * real * imag + i;
		pow_r = *dvg_r * *dvg_r;
		pow_i = *dvg_i * *dvg_i;
		if (pow_r + pow_i > 4)
			return ;
		real = *dvg_r;
		imag = *dvg_i;
		(*dvg)++;
	}
	*dvg = -1;
	return ;
}

void	start(struct timeval *tv){
	gettimeofday(&tv[0], NULL);
}

void	end(struct timeval *tv){
	gettimeofday(&tv[1], NULL);
	printf("%lu\n", (tv[1].tv_sec * 1000000 + tv[1].tv_usec) - (tv[0].tv_sec * 1000000 + tv[0].tv_usec));
}

int	main(void)
{
	struct timeval	tv[2];
	int				x, y;

	// Test number
	long double	range = 0.0000000000000012345;
	long double	min_x = 0.200003;
	long double	min_y = -0.00000000013;

	// calc with long double
	long double	*ld_real = (long double *)malloc(sizeof(long double) * 500);
	long double	*ld_imag = (long double *)malloc(sizeof(long double) * 500);
	int			*ld_dvg = (int *)malloc(sizeof(int) * 500 * 500);
	long double	*ld_dvg_r = (long double *)malloc(sizeof(long double) * 500 * 500);
	long double	*ld_dvg_i = (long double *)malloc(sizeof(long double) * 500 * 500);

	// xymap with long double
	printf("calc_xmap with long double : ");
	start(tv);
	int	i = 0;
	long double	factor = range / 500;
	long double	*tmp_r = ld_real;
	long double	*tmp_i = ld_imag;
	while (i < 500)
	{
		long double tmp = i * factor;
		*ld_real++ = tmp + min_x;
		*ld_imag++ = tmp + min_y;
		i++;
	}
	end(tv);

	// Time
	printf("calc_dvg with long double : ");
	start(tv);
	y = 0;
	long double *tmp_tmp_r = tmp_r;
	while (y < 500)
	{
		x = 0;
		tmp_r = tmp_tmp_r;
		while (x < 500)
		{
			calc_long_double(*tmp_r, *tmp_i, ld_dvg, ld_dvg_r, ld_dvg_i, x, y);
			tmp_r++;
			ld_dvg++;
			ld_dvg_r++;
			ld_dvg_i++;
			x++;
		}
		tmp_i++;
		y++;
	}
	end(tv);

	// calc with float
	float	*f_real = (float *)malloc(sizeof(float) * 500);
	float	*f_imag = (float *)malloc(sizeof(float) * 500);
	int		*f_dvg = (int *)malloc(sizeof(int) * 500 * 500);
	float	*f_dvg_r = (float *)malloc(sizeof(float) * 500 * 500);
	float	*f_dvg_i = (float *)malloc(sizeof(float) * 500 * 500);

	// xymap with float
	printf("calc_xmap with float : ");
	start(tv);
	i = 0;
	float	f_factor = range / 500;
	float	*f_tmp_r = f_real;
	float	*f_tmp_i = f_imag;
	while (i < 500)
	{
		float tmp = i * f_factor;
		*f_real++ = tmp + min_x;
		*f_imag++ = tmp + min_y;
		i++;
	}
	end(tv);

	// Time
	printf("calc_dvg with float : ");
	start(tv);
	y = 0;
	float *f_tmp_tmp_r = f_tmp_r;
	while (y < 500)
	{
		x = 0;
		f_tmp_r = f_tmp_tmp_r;
		while (x < 500)
		{
			calc_float(*f_tmp_r, *f_tmp_i, f_dvg, f_dvg_r, f_dvg_i, x, y);
			f_tmp_r++;
			f_dvg++;
			f_dvg_r++;
			f_dvg_i++;
			x++;
		}
		f_tmp_i++;
		y++;
	}
	end(tv);


	return (0);
}
