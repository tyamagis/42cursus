/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:40:53 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/13 19:43:05 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center_reset(int x, int y, t_win *win)
{
	t_frctl	*f;

	f = win->frctl;
	f->min_x = f->real[x] - (f->range / 2);
	f->min_y = f->imag[y] - (f->range / 2);
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
	return (0);
}
