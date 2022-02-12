/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:41:26 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/11 17:17:20 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fullrange_hue(t_win *win, int x, int y)
{
	float	tmp;
	int		dvg;
	int		*tgt;
	int		s;
	int		b;

	dvg = win->pxl[x + y * win->size].dvg;
	tgt = &win->img->data[x + y * win->size];
	tmp = 360.0 / win->frctl->lim;
	if (dvg == -1)
		*tgt = 0;
	else
		*tgt = to_rgb((int)(dvg * tmp), win->col->base_s, win->col->base_b);
	return ;
}

void	narrow_band_hue(t_win *w, int x, int y)
{
	int		tmp;
	int		s;
	int		b;
	int		h;
	t_pixel	*p;

	p = &w->pxl[x + y * w->size];
	h = p->dvg % 360;
	s = (p->dvg % w->col->grad + 1) * (w->col->base_s / w->col->grad);
	b = (p->dvg % w->col->grad + 1) * (w->col->base_b / w->col->grad);
	if (p->dvg == -1)
		w->img->data[x + y * w->size] = 0;
	else if (p->dvg % w->col->grad < w->col->grad / 2)
		w->img->data[x + y * w->size] = to_rgb(h, s, b);
	else
		w->img->data[x + y * w->size] = to_rgb(h, 255 - s, 255 - b);
	return ;
}

void	wide_band_hue(t_win *w, int x, int y)
{
	t_color	*c;
	int		base;
	int		d;
	int		*t;
	int		i;

	c = w->col;
	base = c->grad;
	i = x + y * w->size;
	d = w->pxl[i].dvg;
	t = &w->img->data[i];
	if (d == -1)
		*t = 0;
	else if (d < base)
		*t = to_rgb((360 * d / base), c->base_s, c->base_b);
	else if (d < base * base)
		*t = to_rgb((360 * d / (base * base)), c->base_s, c->base_b);
	else if (d < base * base * base)
		*t = to_rgb((360 * d / (base * base * base)), c->base_s, c->base_b);
	else if (d < base * base * base *base)
		*t = to_rgb((360 * d / (base * base * base * base)), c->base_s, c->base_b);
	else
		*t = 0xffffff;
	return ;
}

void	single_grad(t_win *w, int x, int y)
{
	int	i;
	int	tmp_s;
	int	tmp_b;

	i = x + y * w->size;
	if (w->pxl[x + y * w->size].dvg == -1)
		w->img->data[i] = 0;
	else
	{
		tmp_s = w->pxl[x + y * w->size].dvg % w->col->base_s;
		tmp_b = w->pxl[x + y * w->size].dvg % w->col->base_b;
		w->img->data[i] = to_rgb(w->col->base_h, tmp_s, tmp_b);
	}
	return ;
}

void	mono_grad(t_win *w, int x, int y)
{
	int	grd;
	int	tmp;
	int	i;

	i = x + y * w->size;
	grd = w->col->grad;
	tmp = (w->pxl[i].dvg % grd) * (0xff / grd);
	w->img->data[i] = (tmp << 16) + (tmp << 8) + tmp;
	return ;
}
