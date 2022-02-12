/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:41:26 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/12 11:32:57 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_xymap(t_win *win)
{
	int			i;
	t_tmp		tmp;

	i = 0;
	tmp.r = win->frctl->real;
	tmp.i = win->frctl->imag;
	tmp.pow_r = win->frctl->pow_r;
	tmp.pow_i = win->frctl->pow_i;
	tmp.factor = win->frctl->range / win->size;
	while (i < win->size)
	{
		tmp.i_factor = i * tmp.factor;
		*win->frctl->real++ = tmp.i_factor + win->frctl->min_x;
		*win->frctl->imag++ = tmp.i_factor + win->frctl->min_y;
		*win->frctl->pow_r++ = *(win->frctl->real - 1) * *(win->frctl->real - 1);
		*win->frctl->pow_i++ = *(win->frctl->imag - 1) * *(win->frctl->imag - 1);
		i++;
	}
	win->frctl->real = tmp.r;
	win->frctl->imag = tmp.i;
	win->frctl->pow_r = tmp.pow_r;
	win->frctl->pow_i = tmp.pow_i;
	return ;
}

int		draw(t_win *win)
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
