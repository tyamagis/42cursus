/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:41:26 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/13 19:43:17 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_col_func	set_col_func(int c)
{
	if (c == 0)
		return (fullrange_hue);
	else if (c == 1)
		return (narrow_band_hue);
	else if (c == 2)
		return (mono_grad);
	else if (c == 3)
		return (wide_band_hue);
	else if (c == 4)
		return (single_grad);
	else if (c == 5)
		return (band_width_hue);
	else if (c == 6)
		return (xy_hsb);
	else if (c == 7)
		return (dvg_ri);
	else if (c == 8)
		return (chaos_a);
	else if (c == 9)
		return (chaos_b);
	else
		return (fullrange_hue);
}

int	to_rgb(int h, int s, int b)
{
	int		rgb;
	float	min;
	float	tmp;

	min = b - (s * b / 255);
	tmp = b - min;
	if (h < 60)
		rgb = (b << 16) + ((int)(h * tmp / 60 + min) << 8) + (int)min;
	else if (h < 120)
		rgb = ((int)((120 - h) * tmp / 60 + min) << 16) + (b << 8) + (int)min;
	else if (h < 180)
		rgb = ((int)min << 16) + (b << 8) + (int)((h - 120) * tmp / 60 + min);
	else if (h < 240)
		rgb = ((int)min << 16) + ((int)((240 - h) * tmp / 60 + min) << 8) + b;
	else if (h < 300)
		rgb = ((int)((h - 240) * tmp / 60 + min) << 16) + ((int)min << 8) + b;
	else
		rgb = (b << 16) + ((int)min << 8) + (int)((360 - h) * tmp / 60 + min);
	return (rgb);
}

void	set_color(t_win *win)
{
	int			*tgt;
	t_pixel		*pxl;
	int			x;
	int			y;
	t_col_func	col_func;

	tgt = win->img->data;
	pxl = win->pxl;
	col_func = set_col_func(win->col->mode);
	y = 0;
	while (y < win->size)
	{
		x = 0;
		while (x < win->size)
		{
			col_func(win, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx, win->ptr, win->img->ptr, 0, 0);
	return ;
}
