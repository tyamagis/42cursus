#include "mlx.h"
#include <stdio.h>

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 512, 512, "color");

	int x = 0;
	int y = 0;
	int color = 0;
	int step = 16;

	x = 0;
	color = 0xffff;
	while (x < 512)
	{
		y = 0;
		while (y < 400)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		x++;
	}

	mlx_loop(mlx);
	return (0);
}
