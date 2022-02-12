/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:40:53 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/11 16:46:39 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center_reset(int x, int y, t_win *win)
{
	t_frctl	*f;

	f = win->frctl;
	f->min_x = f->real[x] - (f->range / 2);
	f->min_y = f->imag[y] - (f->range / 2);
//	printf("x,y = (%d, %d)\treal,img = (%Lf, %Lf)\tdvg = %d\tdvg_r, i = (%Lf, %Lf)\tcolor(#%x)\n", x, y, win->frctl->real[x], win->frctl->imag[y], win->pxl[x + y *win->size].dvg, win->pxl[x + y * win->size].dvg_r, win->pxl[x + y * win->size].dvg_i, win->img->data[x + y*win->size]);
	return ;
}

void	zoom_up(int x, int y, t_win *win)
{
	long double	tmp;

	tmp = win->frctl->range * (1 - ZOOM) / win->size;
	win->frctl->min_x = win->frctl->min_x + (x * tmp);
	win->frctl->min_y = win->frctl->min_y + (y * tmp);
	win->frctl->range *= ZOOM;
	win->frctl->zoom++;
	win->frctl->lim += LIM_BAND * win->frctl->zoom + 7;
	return ;
}

void	zoom_down(int x, int y, t_win *win)
{
	long double	tmp;

	if (win->frctl->zoom != 0)
	{
		tmp = win->frctl->range * (1 - ZOOM) / (win->size * ZOOM);
		win->frctl->min_x = win->frctl->min_x - (x * tmp);
		win->frctl->min_y = win->frctl->min_y - (y * tmp);
		win->frctl->range /= ZOOM;
		win->frctl->zoom--;
		tmp = LIM_BAND * win->frctl->zoom + 7;
		if (win->frctl->lim > tmp)
		win->frctl->lim -= tmp;
	}
	else
		reset_params(win);
	return ;
}

int	ms_hook(int btn, int x, int y, t_win *win)
{
	if (btn == 1)
		center_reset(x, y, win);
	else if (btn == 4)
		zoom_up(x, y, win);
	else if (btn == 5)
		zoom_down(x, y, win);
	draw(win);
	//printf("z : %d, l : %d, min_x, y : (%.60Lf, %60Lf)\nmax_dvg : %d, range : %.60Lf \n", win->frctl->zoom, win->frctl->lim, win->frctl->min_x, win->frctl->min_y, win->frctl->max_dvg, win->frctl->range);
	return (0);
}
