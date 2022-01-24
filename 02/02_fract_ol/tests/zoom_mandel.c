#include "./minilibx-linux/mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

void	clear_img(t_img *img)
{
	int x, y;
	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			img->data[x + (y * 500)] = 0x000000;
			x++;
		}
		y++;
	}
}

void	draw_mb(t_img *img)
{
	int	x, y;
	y = 0;
	while (y < 500)
	{
		double	by = (((img->y_min + img->range - img->y_min) * y) / 500) + img->y_min;
		x = 0;
		while (x < 500)
		{
			double	ax = (((img->x_min + img->range - img->x_min) * x) / 500) + img->x_min;
			int i = 0;
			double a = 0;
			double b = 0;
			int	color = 0;
			while (i < img->lim)
			{
				double	tmp_a = (a * a) - (b * b) + ax;
				double	tmp_b = (2 * a * b) + by;
				a = tmp_a;
				b = tmp_b;
				if ((a * a) + (b * b) > 4)
				{
					color += (i % img->grd) * 30;
					color <<= 8;
					color += (i % img->grd) * 30;
					color <<= 8;
					color += (i % img->grd) * 30;
					img->data[x + (y * 500)] = color;
					break ;
				}
				i++;
			}
			x++;
		}
		y++;
	}
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->ptr, 0, 0);
}

int	func(int btn, int x, int y, t_img *img)
{
	double	scale;
	double	ax = ((img->x_min + img->range - img->x_min) * x) / 500 + img->x_min;
	double	by = ((img->y_min + img->range - img->y_min) * y) / 500 + img->y_min;

	printf("mouse hook\n");
	if (btn == 4)
	{
		clear_img(img);
		img->zoom += 1;
		img->range = 4 / pow(1.5, img->zoom);
		img->x_min = ax - (img->range / 2);
		img->y_min = by - (img->range / 2);
		printf("btn4 : ax %lf, by %lf, x_min %lf, y_min %lf\n", ax, by, img->x_min, img->y_min);
		img->lim += img->zoom / 4;
		draw_mb(img);
	}
	return (0);
}

int main(void)
{
	t_img	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 500, 500, "test window");
	img.ptr = mlx_new_image(img.mlx, 500, 500);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.spl, &img.e);
	int x = 0;
	int y = 0;
	int color = 0;
	img.x_min = -2;
	img.y_min = -2;
	img.range = 4;
	img.lim = 30;
	img.zoom = 0;
	img.grd = 8;

	draw_mb(&img);
	mlx_clear_window(img.mlx, img.win);
	mlx_put_image_to_window(img.mlx, img.win, img.ptr, 0, 0);
	mlx_mouse_hook(img.win, func, &img);
	mlx_loop(img.mlx);
	return (0);
}
