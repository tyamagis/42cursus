/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:09:14 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/03 14:40:33 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

int	draw(void){printf("draw()\n");return(0);}
int	kb_hook(void){printf("kb_hook()\n");return(0);}
int	ms_hook(void){printf("ms_hook()\n");return(0);}

void	show_usage(void)
{
	printf("show_usage()\n");
	exit(0);
}

int		destroy(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img->ptr);
	mlx_destroy_window(win->mlx, win->ptr);
	mlx_destroy_display(win->mlx);
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
			printf("m\n"); // mandel
		else if (c == 'j' || c == 'J')
			printf("j\n"); // julia
		else if (c == 0 /* */ || c == 1 /* */)
			printf("3\n"); // 3rd FRACTAL
		else
			show_usage();
	}
	else
		show_usage();
}

int		init(t_win *win)
{
	t_img	*img;
	t_frctl	*frctl;

	win->size = 500;
	win->mlx = mlx_init();
	// if (mlx_init() fails)
	// exit;
	win->ptr = mlx_new_window(win->mlx, win->size, win->size, "fract-ol");
	// if (mlx_new_window() fails)
	// exit;
	img = win->img;
	img->ptr = mlx_new_image(win->mlx, win->size, win->size);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->spl, &img->e);
	frctl = win->frctl;
	frctl->min_x = -2;
	frctl->min_y = -2;
	frctl->range = 4;
	frctl->lim = 30;
	frctl->zoom = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_win	win;
	t_img	t_i;
	t_frctl	t_f;

	check_args(ac, av, &win);
	win.img = &t_i;
	win.frctl = &t_f;
	init(&win);
	mlx_key_hook(win.ptr, kb_hook, &win);
	mlx_mouse_hook(win.ptr, ms_hook, &win);
	mlx_hook(win.ptr, 12, 1L << 15, draw, &win);
	mlx_hook(win.ptr, 17, 0L, destroy, &win);
	/*
	draw();
	*/
	mlx_loop(win.mlx);
	return (0);
}
