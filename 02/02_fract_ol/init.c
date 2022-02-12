/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:48:05 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/12 10:45:06 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_params(t_win *w)
{
	t_frctl	*f;
	t_color	*c;

	f = w->frctl;
	c = w->col;
	f->min_x = -2;
	f->min_y = -2;
	f->range = 4;
	f->lim = 28;
	f->zoom = 0;
	c->base_h = 0;
	c->base_s = 255;
	c->base_b = 255;
	c->grad = 16;
	return ;
}

void	init_color(t_color *c)
{
	c->mode = 0;
	c->base_h = 0;
	c->base_s = 255;
	c->base_b = 255;
	c->grad = 16;
	c->hue_width = 120;
	return ;
}

void	init_frctl(t_win *w, t_frctl *f)
{
	f->real = (long double *)malloc(sizeof(long double) * w->size);
	f->imag = (long double *)malloc(sizeof(long double) * w->size);
	f->pow_r = (long double *)malloc(sizeof(long double) * w->size);
	f->pow_i = (long double *)malloc(sizeof(long double) * w->size);
	if (!(f->real && f->imag && f->pow_r && f->pow_i))
		destroy(w);
	f->min_x = -2;
	f->min_y = -2;
	f->range = 4;
	f->lim = 28;
	f->zoom = 0;
	return ;
}

int		init(t_win *win)
{
	t_img	*i;

	win->size = 500;
	win->mlx = mlx_init();
	// if (mlx_init fails)
	// destroy(win);
	win->ptr = mlx_new_window(win->mlx, win->size, win->size, "fract-ol");
	// if (mlx_new_window() fails)
	// destroy();
	win->pxl = (t_pixel *)malloc(sizeof(t_pixel) * win->size * win->size);
	if (win->pxl == NULL)
		destroy(win);
	i = win->img;
	i->ptr = mlx_new_image(win->mlx, win->size, win->size);
	i->data = (int *)mlx_get_data_addr(i->ptr, &i->bpp, &i->spl, &i->e);
	init_frctl(win, win->frctl);
	init_color(win->col);
	return (0);
}
