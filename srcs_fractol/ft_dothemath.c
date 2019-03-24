/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dothemath.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:43:19 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 14:42:46 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

static void	calcul_burningship(t_fractol *data)
{
	data->tmp = data->z_r;
	data->z_r = fabs(data->z_r * data->z_r - data->z_i * data->z_i + data->c_r);
	data->z_i = fabs(2 * data->z_i * data->tmp + data->c_i);
}

static void	calcul_fractals(t_fractol *data)
{
	data->tmp = data->z_r;
	data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
	data->z_i = 2 * data->z_i * data->tmp + data->c_i;
}

static void	calcul_color_in(t_fractol *data, double x, double y)
{
	if (data->color_in % 2 == 1)
		mlx_pixel_put(data->mlx, data->win, x, y, 0);
	if (data->color_in % 2 == 0)
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

static void	calcul_fractol(t_fractol *data, double x, double y, double i)
{
	ft_choice(data, x, y);
	i = 0;
	while (((data->z_r * data->z_r + data->z_i * data->z_i)) < \
			4 && (i < data->nb_iter))
	{
		if (!(ft_strcmp(data->name, "5")))
			calcul_burningship(data);
		else
			calcul_fractals(data);
		i++;
	}
	if (i == data->nb_iter)
		calcul_color_in(data, x, y);
	else
		mlx_pixel_put(data->mlx, data->win, x, y, \
				color_rgb_get_key(i, data, data->z_i));
}

void		fractol(t_fractol *data)
{
	double	i;
	double	x;
	double	y;

	i = 0;
	x = 0;
	data->image_x = (data->x2 - data->x1) * data->zoom;
	data->image_y = (data->y2 - data->y1) * data->zoom;
	mlx_clear_window(data->mlx, data->win);
	while (x < data->image_x)
	{
		y = 0;
		while (y < data->image_y)
		{
			calcul_fractol(data, x, y, i);
			y++;
		}
		x++;
	}
}
