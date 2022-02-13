/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:09:14 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/13 10:55:46 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

void	show_usage(void)
{
	printf(">> Invalid arguments. See below.\n\n");
	printf("\t[ Fract-ol ] tyamagis\n\n");
	printf("\trun \"./fractol [m / M / j / J / o / O] [0-2]\"\n");
	printf("\tm/M shows Mandelbrot set. j/J shows Julia set.\n\n");
	printf("\t---- KEY functions ----\n");
	printf("\t[Q, A](hue) [W, S](saturation) [E, D](brightness [R, F](grad)\n");
	printf("\t[T, G](1) [Y, H](10) [U, J](100) [I, K](1000) calc limit\n");
	printf("\t[C] color mode  [Z] reset\n\n");
	printf("\t---- MOUSE functions ----\n");
	printf("\tleft click : center reset, wheel : zoom in / out\n");
	printf("\tHAVE FUN !!\n");
	exit(0);
}

int		destroy(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img->ptr);
	mlx_destroy_window(win->mlx, win->ptr);
	mlx_destroy_display(win->mlx);
	if (win->frctl->real != NULL)
		free(win->frctl->real);
	if (win->frctl->imag != NULL)
		free(win->frctl->imag);
	if (win->frctl->pow_r != NULL)
		free(win->frctl->pow_r);
	if (win->frctl->pow_i != NULL)
		free(win->frctl->pow_i);
	if (win->pxl != NULL)
		free(win->pxl);
	exit(0);
	return (0);
}

void	check_args(int ac, char **av, t_win *win)
{
	char	c;

	if (ac == 2 && av[1][1] == '\0')
	{
		c = av[1][0];
		if (c == 'm' || c == 'M')
			win->frctl->type = 0;
		else if (c == 'j' || c == 'J')
		{
			win->frctl->type = 1;
			win->frctl->init_a = -0.1243;
			win->frctl->init_b = 0.7494;
		}
		else if (c == 'o' || c == 'O')
			win->frctl->type = 2;
		else
			show_usage();
	}
	else if (ac == 3 && av[1][0] == 'j')
		set_julia(ac, av, win->frctl);
	else
		show_usage();
	return ;
}

void	set_julia(int ac, char **av, t_frctl *f)
{
	if (ac == 3 && av[2][1] == '\0')
	{
		f->type = 1;
		if (av[2][0] == '0')
		{
			f->init_a = 0.32;
			f->init_b = 0.043;
		}
		else if (av[2][0] == '1')
		{
			f->init_a = -0.1562;
			f->init_b = 1.03225;
		}
		else if (av[2][0] == '2')
		{
			f->init_a = -0.76;
			f->init_b = 0.13;
		}
	}
	else
		show_usage();
	return ;
}

int	main(int ac, char **av)
{
	t_win	win;
	t_img	t_i;
	t_frctl	t_f;
	t_color	t_c;

	win.frctl = &t_f;
	win.img = &t_i;
	win.col = &t_c;
	check_args(ac, av, &win);
	init(&win);
	mlx_key_hook(win.ptr, kb_hook, &win);
	mlx_mouse_hook(win.ptr, ms_hook, &win);
	mlx_hook(win.ptr, 12, 1L << 15, draw, &win);
	mlx_hook(win.ptr, 17, 0L, destroy, &win);
	mlx_loop(win.mlx);
	return (0);
}
