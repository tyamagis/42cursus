#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "fractol.h"
#include "mlx_int.h"

int	keypress(int i, t_win *win){printf("2 : keypress : %d, %d\n", i, win->w);return (0);}
int	keyrelease(int i, t_win *win){printf("3 : keyrelease : %d,  %d\n", i, win->w);return (0);}
int	btnpress(int i, int x, int y, t_win *win){printf("4 : btnpress : %d, %d, %d, %d\n", i, x, y, win->w);return (0);}
int	btnrelease(int i, int x, int y, t_win *win){printf("5 : btnrelease : %d, %d, %d, %d\n", i, x, y, win->w);return (0);}
int	mtn_ntf(t_win *win){printf("6 : Motion Notify : %d\n", win->w);return (0);}
int	ent_ntf(t_win *win){printf("7 : Enter Notify : %d\n", win->w);return (0);}
int	lev_ntf(t_win *win){printf("8 : Leave Notify : %d\n", win->w);return (0);}
int	fcs_in(t_win *win){printf("9 : Focus In : %d\n", win->w);return (0);}
int	fcs_out(t_win *win){printf("10 : Focus Out : %d\n", win->w);return (0);}
int	kmp_ntf(t_win *win){printf("11 : Keymap Notify : %d\n", win->w);return (0);}
int	expose(t_win *win){printf("12 : Expose : %d\n", win->w);return (0);}
int	grp_exp(t_win *win){printf("13 : Graphic Expose : %d\n", win->w);return (0);}
int	no_exp(t_win *win){printf("14 : No Expose : %d\n", win->w);return (0);}
int	vsb_ntf(t_win *win){printf("15 : Visibility Notify : %d\n", win->w);return (0);}
int	crt_ntf(t_win *win){printf("16 : Create Notify : %d\n", win->w);return (0);}
int	dst_ntf(t_win *win){printf("17 : Destroy Notify : %d\n", win->w);return (0);}
int	ump_ntf(t_win *win){printf("18 : Unmap Notify : %d\n", win->w);return (0);}
int	mp_ntf(t_win *win){printf("19 : Map Notify : %d\n", win->w);return (0);}
int	mp_rq(t_win *win){printf("20 : Map Request : %d\n", win->w);return (0);}
int	rpr_ntf(t_win *win){printf("21 : Reparent Notify : %d\n", win->w);return (0);}
int	cfg_ntf(t_win *win){printf("22 : Configure Notify : %d\n", win->w);return (0);}
int	cfg_rq(t_win *win){printf("23 : Configure Reauest : %d\n", win->w);return (0);}
int	gvt_ntf(t_win *win){printf("24 : Gravity Notify : %d\n", win->w);return (0);}
int	rsz_rq(t_win *win){printf("25 : Resize Request : %d\n", win->w);return (0);}
int	ccl_ntf(t_win *win){printf("26 : Circulate Notify : %d\n", win->w);return (0);}
int	ccl_rq(t_win *win){printf("27 : Circulate Request : %d\n", win->w);return (0);}
int	ppt_ntf(t_win *win){printf("28 : Property Notify : %d\n", win->w);return (0);}
int	slc_cla(t_win *win){printf("29 : Selection Clear : %d\n", win->w);return (0);}
int	slc_rq(t_win *win){printf("30 : Selection Reauest : %d\n", win->w);return (0);}
int	slc_ntf(t_win *win){printf("31 : Selection Notify : %d\n", win->w);return (0);}
int	clm_ntf(t_win *win){printf("32 : Colormap Notify : %d\n", win->w);return (0);}
int	cli_msg(t_win *win){printf("33 : Client Message : %d\n", win->w);return (0);}
int	mpg_ntf(t_win *win){printf("34 : Mapping Notify : %d\n", win->w);return (0);}
int	gnr_evt(t_win *win){printf("35 : Generic Event : %d\n", win->w);return (0);}
int	LAST_evt(t_win *win){printf("36 : LAST Event : %d\n", win->w);return (0);}

int	paint(t_win *win)
{
	printf("< PAINT !! >\n");
	int color = 0;
	for (int i = 0; i < 500; i++)
	{
		color += i / 2;
		color <<= 8;
		for (int j = 0; j < 500; j++)
		{
			color += j / 2;
			mlx_pixel_put(win->mlx, win->ptr, j, i, color);
		}
	}
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, 500, 500, "loop_hook");
	win.w = 500;
	paint(&win);
	mlx_expose_hook(win.ptr, paint, &win);
	mlx_hook(win.ptr, 2, 1L << 0, keypress, &win);
	mlx_hook(win.ptr, 3, 1L << 1, keyrelease, &win);
	mlx_hook(win.ptr, 4, 1L << 2, btnpress, &win);
	mlx_hook(win.ptr, 5, 1L << 3, btnrelease, &win);
	mlx_hook(win.ptr, 6, 0L, mtn_ntf, &win);
	mlx_hook(win.ptr, 7, 0L, ent_ntf, &win);
	mlx_hook(win.ptr, 8, 0L, lev_ntf, &win);
	mlx_hook(win.ptr, 9, 1L << 21, fcs_in, &win);
	mlx_hook(win.ptr, 10, 1L << 21, fcs_out, &win);
	mlx_hook(win.ptr, 11, 1L << 14, kmp_ntf, &win);
	mlx_hook(win.ptr, 12, 1L << 15, paint, &win);
	mlx_hook(win.ptr, 13, 0L, grp_exp, &win);
	mlx_hook(win.ptr, 14, 0L, no_exp, &win);
	mlx_hook(win.ptr, 15, 1L << 15, vsb_ntf, &win);
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
	mlx_hook(win.ptr, 34, 0L, mpg_ntf, &win);
	mlx_hook(win.ptr, 35, 0L, gnr_evt, &win);
	mlx_hook(win.ptr, 36, 0L, LAST_evt, &win);
	mlx_loop(win.mlx);
	return (0);
}
