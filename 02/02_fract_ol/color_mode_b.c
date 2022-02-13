/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:54:55 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/13 19:27:19 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	band_width_hue(t_win *w, int x, int y)
{
	int		i;
	int		h;
	int		d;
	t_color	*c;

	i = x + y * w->size;
	d = w->pxl[i].dvg;
	c = w->col;
	h = (c->base_h + (d % c->hue_width)) % 360;
	if (d == -1)
		w->img->data[i] = 0;
	else
		w->img->data[i] = to_rgb(h, 255 - (d % c->base_s), d % c->base_b);
	return ;
}

void	xy_hsb(t_win *w, int x, int y)
{
	int		i;
	int		h;
	int		d;
	t_color	*c;

	i = x + y * w->size;
	d = w->pxl[i].dvg;
	c = w->col;
	h = (c->base_h + (d + x - y) % c->hue_width) % 360;
	if (d == -1)
		w->img->data[i] = 0;
	else
		w->img->data[i] = to_rgb(h, (d - x) % c->base_s, (d + y) % c->base_b);
	return ;
}

void	dvg_ri(t_win *w, int x, int y)
{
	int		i;
	int		h;
	t_color	*c;
	t_pixel	*p;

	i = x + y * w->size;
	p = &w->pxl[i];
	c = w->col;
	h = (c->base_h + (p->dvg + 200 * (int)(p->dvg_r - p->dvg_i)) % 360);
	if (p->dvg == -1)
		w->img->data[i] = 0;
	else
		w->img->data[i] = to_rgb(h, c->base_s, c->base_b);
	return ;
}

void	chaos_a(t_win *w, int x, int y)
{
	int		i;
	int		h;
	int		s;
	int		b;
	t_pixel	*p;

	i = x + y * w->size;
	p = &w->pxl[i];
	h = (w->col->base_h + w->col->hue_width + w->col->grad * p->dvg) % 360;
	s = (int)(w->col->base_s * x * p->dvg_r) % (256 / w->col->grad);
	b = (int)(w->col->base_b * y * p->dvg_i) % (256 / w->col->grad);
	h = (h * s) % 360;
	s = (s * b) % 256;
	if (p->dvg == -1)
		w->img->data[i] = 0;
	else
		w->img->data[i] = to_rgb(h, s, b);
	return ;
}

void	chaos_b(t_win *w, int x, int y)
{
	int		i;
	int		h;
	int		s;
	int		b;
	t_pixel	*p;

	i = x + y * w->size;
	p = &w->pxl[i];
	h = (w->col->base_h * x * y * w->col->grad) % 360;
	s = (int)(w->col->base_s * p->dvg * p->dvg_r) % 256;
	b = ((int)(w->col->base_b * y * p->dvg_i) + s + 128) % 256;
	if (p->dvg == -1)
		w->img->data[i] = 0;
	else
		w->img->data[i] = to_rgb(h, s, b);
	return ;
}
