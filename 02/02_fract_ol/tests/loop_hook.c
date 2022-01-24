#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx_int.h"

int	loop(t_win *win)
{
	int	x, y;
	mlx_mouse_get_pos(win->mlx, win->ptr, &x, &y);
//	printf("%d, %d\n", x, y);
	return (0);
}

int	mouse(int btn, int x, int y, t_win *p)
{
	printf("btn %d (%d, %d)\n", btn, x, y);
	return (0);
}

int	kb(int key, t_win *p)
{
	printf("key %d\n", key);
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, 500, 500, "loop_hook");
	mlx_loop_hook(win.mlx, loop, &win);
	mlx_mouse_hook(win.ptr, mouse, &win);
	mlx_key_hook(win.ptr, kb, &win);
	mlx_loop(win.mlx);
	return (0);
}
