/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_frctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:41:26 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/12 11:55:05 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_orgnl(t_win *win, t_pixel *p, int x, int y)
{
	t_dvg	d;

	p->dvg = 0;
	d.r = win->frctl->real[x];
	d.i = win->frctl->imag[y];
	d.pow_r = win->frctl->pow_r[x];
	d.pow_i = win->frctl->pow_i[y];
	while (p->dvg < win->frctl->lim)
	{
		p->dvg_r = (d.r + d.i) * (d.r - d.i) + win->frctl->real[x];
		p->dvg_i = 2 * d.r * d.i + win->frctl->imag[y];
		if (p->dvg_r > 2 || p->dvg_i > 2)
			return ;
		d.pow_r = p->dvg_r * p->dvg_r;
		d.pow_i = p->dvg_i * p->dvg_i;
		if (d.pow_r / d.pow_i > 1)
			return ;
		d.r = p->dvg_r;
		d.i = p->dvg_i;
		p->dvg++;
	}
	p->dvg = -1;
	return ;
}

void	calc_julia(t_win *win, t_pixel *p, int x, int y)
{
	t_dvg	d;

	p->dvg = 0;
	d.r = win->frctl->real[x];
	d.i = win->frctl->imag[y];
	d.pow_r = win->frctl->pow_r[x];
	d.pow_i = win->frctl->pow_i[y];
	while (p->dvg < win->frctl->lim)
	{
		p->dvg_r = (d.r + d.i) * (d.r - d.i) + win->frctl->init_a;
		p->dvg_i = 2 * d.r * d.i + win->frctl->init_b;
		if (p->dvg_r > 2 || p->dvg_i > 2)
			return ;
		d.pow_r = p->dvg_r * p->dvg_r;
		d.pow_i = p->dvg_i * p->dvg_i;
		if (d.pow_r + d.pow_i > 4)
			return ;
		d.r = p->dvg_r;
		d.i = p->dvg_i;
		p->dvg++;
	}
	p->dvg = -1;
	return ;
}

void	calc_mandel(t_win *win, t_pixel *p, int x, int y)
{
	t_dvg	d;

	p->dvg = 0;
	d.r = win->frctl->real[x];
	d.i = win->frctl->imag[y];
	d.pow_r = win->frctl->pow_r[x];
	d.pow_i = win->frctl->pow_i[y];
	while (p->dvg < win->frctl->lim)
	{
		p->dvg_r = (d.r + d.i) * (d.r - d.i) + win->frctl->real[x];
		p->dvg_i = 2 * d.r * d.i + win->frctl->imag[y];
		if (p->dvg_r > 2 || p->dvg_i > 2)
			return ;
		d.pow_r = p->dvg_r * p->dvg_r;
		d.pow_i = p->dvg_i * p->dvg_i;
		if (d.pow_r + d.pow_i > 4)
			return ;
		d.r = p->dvg_r;
		d.i = p->dvg_i;
		p->dvg++;
	}
	p->dvg = -1;
	return ;
}
