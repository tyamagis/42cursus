#include "./minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_wdw_info
{
	void	*ptr;
	int		w;
	int		h;
} t_wdw_info;

typedef struct s_img_info
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		spl;
	int		e;
} t_img_info

int main(void)
{
	void	*mlx;
	t_wdw_info	w_info;
	t_img_info	i_info;

	w_info.width = 500;
	w_info.height = 500;
	mlx = mlx_init();
	w_info.ptr = mlx_new_window(mlx, width, height, "test window");
	i_info.ptr = mlx_new_image(mlx, w_info.w, w_info.h);
	mlx_loop(mlx);
	return (0);
}
