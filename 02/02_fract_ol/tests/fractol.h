#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
	int		w;
	int		h;
	int		mx;
	int		my;
} t_win;
/*
typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*ptr;
	int		*data;
	int		bpp;
	int		spl;
	int		e;
	double	x_min;
	double	y_min;
	double	range;
	int		col;
	int		lim;
	int		grd;
	int		zoom;
} t_img;
*/
#endif
