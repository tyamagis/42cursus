#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
#include <stdio.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int	mx;
	int	my;
} t_win;

int	func(int btn, int x, int y, t_win *p)
{
	mlx_mouse_get_pos(p->mlx, p->win, &p->mx, &p->my);
	printf("btn : [%d] (%d, %d)\n", btn, p->mx, p->my);
	if (btn == 1) // LEFT CLICK
		printf("click LEFT\n");
	else if (btn == 3) // RIGHT CLICK
		printf("click RIGHT\n");
	else if (btn == 4)
		printf("wheel up\n");
	else if (btn == 5)
		printf("wheel down\n");
	return (0);
}

int	main(void)
{
	t_win info;

	info.w = 500;
	info.h = 500;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.w, info.h, "mouse hook test");
	mlx_mouse_hook(info.win, func, &info);
	mlx_loop(info.mlx);
	return (0);
}
