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

	// 0x000000 - 0x0000ff - 0xffffff
	x = 0;
	color = 0;
	while (x < 512)
	{
		y = 0;
		while (y < 100)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		if (color < 0xff)
			color++;
		else
			color += 0x010100;
		x++;
	}

	// 0x000000 - (0x010104, 0x020208, ...)- 0xdfdfff
	x = 0;
	color = 0;
	while (x < 512)
	{
		y = 100;
		while (y < 200)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		if (x % 2)
		{
			color++;
			if (color % 4 == 0)
				color += 0x010100;
		}
		x++;
	}

	// 0x000000 - (0x010102, 0x020204, ...)- 0xdfdfff
	x = 0;
	color = 0;
	while (x < 512)
	{
		y = 200;
		while (y < 300)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		if (x % 2)
		{
			color++;
			if (color % 2 == 0)
				color += 0x010100;
		}
		x++;
	}

	// 0x000000 - (0x010103, 0x020206, ...)- 0xdfdfff
	x = 0;
	color = 0;
	while (x < 512)
	{
		y = 300;
		while (y < 400)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		if (x % 2 == 0)
		{
			color++;
			if (x % 6 == 0)
			{
				color += 0x010100;
				printf("%x, ", color);
			}
		}
		x++;
	}

	mlx_loop(mlx);
	return (0);
}
