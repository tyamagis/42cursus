/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:12:39 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/03 14:38:23 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_frctl
{
	double	min_x;
	double	min_y;
	double	range;
	int		lim;
	int		zoom;
} t_frctl;

typedef struct s_hsb
{
	int	h;
	int	s;
	int	b;
} t_hsb;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		spl;
	int		e;
} t_img;

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
	int		size;
	int		mouse_x;
	int		mouse_y;
	t_img	*img;
	t_frctl	*frctl;
} t_win;

int		draw_mndl();
int		draw_julia();

void	rgb_to_hsb(int rgb, t_hsb *hsb);
int		hsb_to_rgb(t_hsb *hsb);

int		set_center();
int		zoom_in();
int		zoom_out();
int		zoom_reset();
int		move();

int		exit_frctl();

#endif
