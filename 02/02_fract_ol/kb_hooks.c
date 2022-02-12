/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:40:53 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/11 17:38:23 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	kb_hook_util(int k, t_win *w)
{
	if (k == 'c' && w->col->mode == 9)
		w->col->mode = 0;
	else if (k == 'c')
		w->col->mode++;
	else if (k == 'r')
		w->col->grad += 1;
	else if (k == 'f' && w->col->grad > 2)
		w->col->grad -= 1;
	set_color(w);
	return ;
}

void	kb_hook_color(int k, t_win *w)
{
	if (k == 'q' && w->col->base_h > 345)
		w->col->base_h = 0;
	else if (k == 'q')
		w->col->base_h += 15;
	else if (k == 'a' && w->col->base_h < 15)
		w->col->base_h = 360;
	else if (k == 'a')
		w->col->base_h -= 15;
	else if (k == 'w' && w->col->base_s < 240)
		w->col->base_s += 16;
	else if (k == 'w')
		w->col->base_s = 255;
	else if (k == 's' && w->col->base_s > 16)
		w->col->base_s -= 16;
	else if (k == 's')
		w->col->base_s = 1;
	else if (k == 'e' && w->col->base_b < 240)
		w->col->base_b += 16;
	else if (k == 'e')
		w->col->base_b = 255;
	else if (k == 'd' && w->col->base_b > 16)
		w->col->base_b -= 16;
	else if (k == 'd')
		w->col->base_b = 1;
	return ;
}

void	kb_hook_move(int k, t_win *w)
{
	if (k == 65361)
		w->frctl->min_x -= w->frctl->range / 10;
	else if (k == 65362)
		w->frctl->min_y -= w->frctl->range / 10;
	else if (k == 65363)
		w->frctl->min_x += w->frctl->range / 10;
	else if (k == 65364)
		w->frctl->min_y += w->frctl->range / 10;
	else if (k == 'x')
	{
		if (w->frctl->type != 2)
			w->frctl->type++;
		else
			w->frctl->type = 0;
	}
	draw(w);
	return ;
}

void	kb_hook_lim(int k, t_win *w)
{
	if (k == 't')
		w->frctl->lim += 1;
	else if (k == 'g' && w->frctl->lim > 7)
		w->frctl->lim -= 1;
	else if (k == 'y')
		w->frctl->lim += 10;
	else if (k == 'h' && w->frctl->lim > 17)
		w->frctl->lim -= 10;
	else if (k == 'u')
		w->frctl->lim += 100;
	else if (k == 'j' && w->frctl->lim > 107)
		w->frctl->lim -= 100;
	else if (k == 'i')
		w->frctl->lim += 1000;
	else if (k == 'k' && w->frctl->lim > 1007)
		w->frctl->lim -= 1000;
	else if (k == 'z')
		reset_params(w);
	draw(w);
	return ;
}

int	kb_hook(int k, t_win *w)
{
	if (k == 65307)
		destroy(w);
	else if ((k >= 65361 && k <= 65364) || k == 'x')
		kb_hook_move(k, w);
	else if ((k >= 'g' && k <= 'k') || k == 't' ||  k == 'y' || k == 'u' || k == 'z')
		kb_hook_lim(k, w);
	else if (k == 'q' || k == 'a' || k == 'w' || k == 's' || k == 'e' || k == 'd')
	{
		kb_hook_color(k, w);
		set_color(w);
	}
	else if (k == 'c' || k == 'r' || k == 'f')
		kb_hook_util(k, w);
//	printf("z : %d, l : %d, min_x, y : (%.20Lf, %.20Lf), range : %.60Lf \n", w->frctl->zoom, w->frctl->lim, w->frctl->min_x, w->frctl->min_y, w->frctl->range);
	return (0);
}
