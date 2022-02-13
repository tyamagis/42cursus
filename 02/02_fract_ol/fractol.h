/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:12:39 by tyamagis          #+#    #+#             */
/*   Updated: 2022/02/13 19:47:32 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

# define LIM_BAND 14
# define ZOOM 0.5

typedef struct s_dvg
{
	long double	r;
	long double	i;
	long double	pow_r;
	long double	pow_i;
}	t_dvg;

typedef struct s_tmp
{
	long double	factor;
	long double	i_factor;
	long double	*r;
	long double	*i;
	long double	*pow_r;
	long double	*pow_i;
}	t_tmp;

typedef struct s_pixel
{
	int			done;
	int			dvg;
	long double	dvg_r;
	long double	dvg_i;
}	t_pixel;

typedef struct s_color
{
	unsigned char	mode;
	int				base_h;
	unsigned char	base_s;
	unsigned char	base_b;
	unsigned char	grad;
	unsigned char	hue_width;
}	t_color;

typedef struct s_frctl
{
	int			type;
	long double	min_x;
	long double	min_y;
	long double	range;
	long double	*real;
	long double	*imag;
	long double	init_a;
	long double	init_b;
	long double	*pow_r;
	long double	*pow_i;
	int			lim;
	int			zoom;
	int			max_dvg;
}	t_frctl;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		spl;
	int		e;
}	t_img;

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
	int		size;
	int		mouse_x;
	int		mouse_y;
	t_img	*img;
	t_frctl	*frctl;
	t_pixel	*pxl;
	t_color	*col;
}	t_win;

typedef void	(*t_col_func)(t_win *w, int x, int y);

int			draw(t_win *win);

void		calc_mandel(t_win *win, t_pixel *p, int x, int y);
void		calc_julia(t_win *win, t_pixel *p, int x, int y);
void		calc_orgnl(t_win *win, t_pixel *p, int x, int y);

void		calc_dvg(t_win *win, t_pixel *p, int x, int y);
void		calc_xymap(t_win *win);

void		set_color(t_win *win);
t_col_func	set_col_func(int c);
int			to_rgb(int h, int s, int b);

void		narrow_band_hue(t_win *w, int x, int y);
void		fullrange_hue(t_win *w, int x, int y);
void		mono_grad(t_win *w, int x, int y);
void		wide_band_hue(t_win *w, int x, int y);
void		single_grad(t_win *w, int x, int y);
void		band_width_hue(t_win *w, int x, int y);
void		xy_hsb(t_win *w, int x, int y);
void		dvg_ri(t_win *w, int x, int y);
void		chaos_a(t_win *w, int x, int y);
void		chaos_b(t_win *w, int x, int y);
/*
void		rgb_to_hsb(int rgb, t_hsb *hsb);
*/

int			kb_hook(int k, t_win *w);
void		kb_hook_color(int k, t_win *w);
void		kb_hook_util(int k, t_win *w);
void		kb_hook_move(int k, t_win *w);
void		kb_hook_lim(int k, t_win *w);

int			ms_hook(int btn, int x, int y, t_win *win);

void		show_usage(void);
int			destroy(t_win *win);
void		check_args(int ac, char **av, t_win *win);
void		set_julia(int ac, char **av, t_frctl *f);

int			init(t_win *win);
void		init_frctl(t_win *win, t_frctl *f);
void		init_color(t_color *c);
void		reset_params(t_win *win);

#endif
