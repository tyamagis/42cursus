#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		spl;
	int		e;
	char	*img_data;

	width = 500;
	height = 500;
	mlx = mlx_init();
	write(1, "init, ", 6);
	win = mlx_new_window(mlx, width, height, "test window");
	write(1, "newwindow, ", 11);
	mlx_string_put(mlx, win, 100, 250, 0xffffff, "Calculating....");
	img = mlx_new_image(mlx, width, height);
	img_data = mlx_get_data_addr(img, &bpp, &spl, &e);
	int	*int_data = (int *)img_data;
	int x = 0;
	int y = 0;
	int color = 0;
	int limit = 30;
	double min = -1.3;
	double max = 1.3;

	while (y < height)
	{
		double	by = (((max - min) * (double)y) / 500) + min;
		printf("%d, %lf\n", y, by);
		x = 0;
		while (x < width)
		{
			double	ax = (((max - min) * (double)x) / 500) + min;
			int i = 0;
			double a = 0;
			double b = 0;
			color = 0;
			while (i < limit)
			{
				double	tmp_a = (a * a) - (b * b) + ax;
				double	tmp_b = (2 * a * b) + by;
				a = tmp_a;
				b = tmp_b;
				if ((a * a) + (b * b) > 4)
				{
					color += (i % 8) * 30;
					color <<= 8;
					color += (i % 8) * 30;
					color <<= 8;
					color += (i % 8) * 30;
					int_data[x + (y * height)] = color;
					break ;
				}
				i++;
			}
			x++;
		}
		y++;
	}
	mlx_clear_window(mlx, win);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
