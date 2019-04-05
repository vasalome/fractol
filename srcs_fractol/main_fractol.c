/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fractol.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:25:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 20:15:59 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void	put_pixel(t_fractol *data, int x, int y, int color)
{
	data->img_str[y * (int)WIDTH + x] = color;
}

void	init_fract(t_fractol *data)
{
	data->nb_iter = 100;
	data->color = 1;
	data->color_in = 1;
	data->x1 = -2.0;
	data->x2 = 2.0;
	data->y1 = -2.0;
	data->y2 = 2.0;
	data->nzoom = 4.0;
	data->zoom_info = 1.0;
	data->stop_move = 1;
	data->hide_txt = 1;
	data->zoom_txt = 1.0;
}

void	ft_choice(t_fractol *data, double x, double y)
{
	if (!(ft_strcmp(data->name, "1")))
		ft_mandelbrot(data, x, y);
	else if (!(ft_strcmp(data->name, "2")))
		ft_julia(data, x, y);
	else if (!(ft_strcmp(data->name, "3")))
		ft_douadyrabbit(data, x, y);
	else if (!(ft_strcmp(data->name, "4")))
		ft_deepturn(data, x, y);
	else if (!(ft_strcmp(data->name, "5")))
		ft_burningship(data, x, y);
	else if (!(ft_strcmp(data->name, "6")))
		ft_portail(data, x, y);
	else if (!(ft_strcmp(data->name, "7")))
		ft_tornado(data, x, y);
	else if (!(ft_strcmp(data->name, "8")))
		ft_virtualforest(data, x, y);
	else if (!(ft_strcmp(data->name, "9")))
		ft_nenufar(data, x, y);
	else if (!(ft_strcmp(data->name, "0")))
		ft_needname(data, x, y);
	else
	{
		ft_usage();
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_fractol	data;

	if (argc != 2)
	{
		ft_usage();
		exit(0);
	}
	data.name = argv[1];
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MANGE MA FRACTALE");
	data.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img_str = (unsigned int *)mlx_get_data_addr(data.img_ptr, &(data.bpp),\
		&(data.sl), &(data.end));
	init_fract(&data);
	fractol(&data);
	ft_whats_my_buttons();
	get_key(0, &data);
	get_my_mouse(0, 0, &data);
	mlx_hook(data.win, 17, 0, red_cross, (void *)0);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, \
			get_my_mouse, (void *)0);
	mlx_hook(data.win, 2, 0, get_key, (void *)data.win);
	mlx_loop(data.mlx);
	free(&data);
}
