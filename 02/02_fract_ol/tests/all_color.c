#include "mlx.h"
#include <stdio.h>

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1024, 1024, "color");

	int x = 0;
	int y = 0;
	int color = 0;

	x = 0;
	color = 0;
	while (y < 1024)
	{
		x = 0;
		while (x < 1024)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			color += 32;
			x++;
		}
		y++;
		if (y % 16 == 0)
			printf("%x, \n", color);
	}
	mlx_loop(mlx);
	return (0);
}
