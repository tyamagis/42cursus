#include "mlx.h"
#include "fractol.h"

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, 500, 500, "string_put");

	int x = 0;
	int y = 0;

	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			mlx_pixel_put(win.mlx, win.ptr, x, y, 0xffffff);
			x++;
		}
		y += 50;
	}
	int	baseline = 10;
	while (baseline < 100)
	{
		mlx_string_put(win.mlx, win.ptr, 50, baseline, 0xffffff, "ZXT\nH,||");
		baseline += 12;
	}
	mlx_loop(win.mlx);
	return (0);
}
