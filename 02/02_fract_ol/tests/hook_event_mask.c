#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx_int.h"

int	keypress(int i, t_win *win){printf("2 : keypress : %d, %d\n", i, win->w);return (0);}
int	keyrelease(int i, t_win *win){printf("3 : keyrelease : %d,  %d\n", i, win->w);return (0);}
int	btnpress(int i, int x, int y, t_win *win){printf("4 : btnpress : %d, %d, %d, %d\n", i, x, y, win->w);return (0);}
int	btnrelease(int i, int x, int y, t_win *win){printf("5 : btnrelease : %d, %d, %d, %d\n", i, x, y, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}
int	(int i, t_win *win){printf(" : : %d %d\n", i, win->w);return (0);}

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, 500, 500, "loop_hook");
	win.w = 500;
	mlx_hook(win.ptr, 2, 1L << 0, keypress, &win);
	mlx_hook(win.ptr, 3, 1L << 1, keyrelease, &win);
	mlx_hook(win.ptr, 4, 1L << 2, btnpress, &win);
	mlx_hook(win.ptr, 5, 1L << 3, btnrelease, &win);
	mlx_hook(win.ptr, 6, 0L, mtn_ntf, &win);
	mlx_hook(win.ptr, 7, 0L, ent_ntf, &win);
	mlx_hook(win.ptr, 8, 0L, lev_ntf, &win);
	mlx_hook(win.ptr, 9, 0L, fcs_in, &win);
	mlx_hook(win.ptr, 10, 0L, fcs_out, &win);
	mlx_hook(win.ptr, 11, 0L, kmp_ntf, &win);
	mlx_hook(win.ptr, 12, 0L, exp, &win);
	mlx_hook(win.ptr, 13, 0L, grp_exp, &win);
	mlx_hook(win.ptr, 14, 0L, no_exp, &win);
	mlx_hook(win.ptr, 15, 0L, vsb_ntf, &win);
	mlx_hook(win.ptr, 16, 0L, crt_ntf, &win);
	mlx_hook(win.ptr, 17, 0L, dst_ntf, &win);
	mlx_hook(win.ptr, 18, 0L, ump_ntf, &win);
	mlx_hook(win.ptr, 19, 0L, mp_ntf, &win);
	mlx_hook(win.ptr, 20, 0L, mp_rq, &win);
	mlx_hook(win.ptr, 21, 0L, rpr_ntf, &win);
	mlx_hook(win.ptr, 22, 0L, cfg_ntf, &win);
	mlx_hook(win.ptr, 23, 0L, cfg_rq, &win);
	mlx_hook(win.ptr, 24, 0L, gvt_ntf, &win);
	mlx_hook(win.ptr, 25, 0L, rsz_rq, &win);
	mlx_hook(win.ptr, 26, 0L, ccl_ntf, &win);
	mlx_hook(win.ptr, 27, 0L, ccl_rq, &win);
	mlx_hook(win.ptr, 28, 0L, ppt_ntf, &win);
	mlx_hook(win.ptr, 29, 0L, slc_cla, &win);
	mlx_hook(win.ptr, 30, 0L, slc_rq, &win);
	mlx_hook(win.ptr, 31, 0L, slc_ntf, &win);
	mlx_hook(win.ptr, 32, 0L, clm_ntf, &win);
	mlx_hook(win.ptr, 33, 0L, cli_msg, &win);
	mlx_hook(win.ptr, 34, 0L, mp_ntf, &win);
	mlx_hook(win.ptr, 35, 0L, gnr_evt, &win);
	mlx_hook(win.ptr, 36, 0L, LAST_evt, &win);
	mlx_loop(win.mlx);
	return (0);
}
