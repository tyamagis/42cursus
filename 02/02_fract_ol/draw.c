/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:41:26 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/13 13:01:27 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_xymap(t_win *win)
{
	int			i;
	t_tmp		tmp;
	t_frctl		*f;

	i = 0;
	f = win->frctl;
	tmp.r = f->real;
	tmp.i = f->imag;
	tmp.pow_r = f->pow_r;
	tmp.pow_i = f->pow_i;
	tmp.factor = f->range / win->size;
	while (i < win->size)
	{
		tmp.i_factor = i * tmp.factor;
		*f->real++ = tmp.i_factor + f->min_x;
		*f->imag++ = tmp.i_factor + f->min_y;
		*f->pow_r++ = *(f->real - 1) * *(f->real - 1);
		*f->pow_i++ = *(f->imag - 1) * *(f->imag - 1);
		i++;
	}
	f->real = tmp.r;
	f->imag = tmp.i;
	f->pow_r = tmp.pow_r;
	f->pow_i = tmp.pow_i;
	return ;
}

int	draw(t_win *win)
{
	int		x;
	int		y;
	t_pixel	*p;
	void	(*f[3])(t_win *win, t_pixel *p, int x, int y);

	calc_xymap(win);
	p = win->pxl;
	f[0] = calc_mandel;
	f[1] = calc_julia;
	f[2] = calc_orgnl;
	y = 0;
	while (y < win->size)
	{
		x = 0;
		while (x < win->size)
		{
			f[win->frctl->type](win, p, x, y);
			p++;
			x++;
		}
		y++;
	}
	set_color(win);
	return (0);
}
