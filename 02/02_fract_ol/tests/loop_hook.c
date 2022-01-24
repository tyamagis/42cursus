#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx_int.h"

int	loop(t_win *win)
{
	int	x, y;
	mlx_mouse_get_pos(win->mlx, win->ptr, &x, &y);
	printf("%d, %d\n", x, y);
	return (0);
}

int	mouse(int btn, int x, int y, int *p)
{
	printf("btn %d (%d, %d) p : %d\n", btn, x, y, *p);
	return (0);
}

int	kb(int key, int *p)
{
	printf("key %d p : %d\n", key, *p);
	(*p)++;
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, 500, 500, "loop_hook");
	mlx_loop_hook(win.mlx, loop, &win);
//	mlx_mouse_hook(win, mouse, &p);
//	mlx_key_hook(win, kb, &p);
	mlx_loop(win.mlx);
	return (0);
}
