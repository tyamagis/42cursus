#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

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
	long double	min_x = 0.2968456873;
	long double	min_y = -0.00000000013;

	// calc with long double
	long double	*ld_real = (long double *)malloc(sizeof(long double) * 500);
	long double	*ld_imag = (long double *)malloc(sizeof(long double) * 500);

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

	// calc with float
	float	*f_real = (float *)malloc(sizeof(float) * 500);
	float	*f_imag = (float *)malloc(sizeof(float) * 500);

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

	// compare result
	i = 0;
	while (i < 500)
	{
		printf("%d : %.20Lf, %.20f\n", i, tmp_r[i], f_tmp_r[i]);
		printf("%d : %.20Lf, %.20f\n", i, tmp_i[i], f_tmp_i[i]);
		i++;
	}


	return (0);
}
