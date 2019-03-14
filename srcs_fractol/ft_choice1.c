/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_choice1.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:53:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 19:10:31 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void    ft_mandelbrot(t_fractol *data, double x, double y)
{
    data->c_r = x / data->zoom + data->x1;
    data->c_i = y / data->zoom + data->y1;
    data->z_r = 0;
    data->z_i = 0;
}

void    ft_julia(t_fractol *data, double x, double y)
{
    data->c_r = data->cmouse_r;
    data->c_i = data->cmouse_i;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_burningship(t_fractol *data, double x, double y)
{
    data->c_r = -0.123;
    data->c_i = 0.745;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_tapis(t_fractol *data, double x, double y)
{
    data->c_r = -0.772727;
    data->c_i = 0.086364;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
    /*
    int     i;

    i = 0;
    x *= data->zoom;
    y *= data->zoom;
    while (i < 100)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);*/
}

void    ft_triangle(t_fractol *data, double x, double y)
{
    data->c_r = -0.74;
    data->c_i = -0.14;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_portail(t_fractol *data, double x, double y)
{
    data->c_r = 0;
    data->c_i = x / data->zoom + data->x1;
    data->z_r = 0;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_tornado(t_fractol *data, double x, double y)
{
    data->c_r = 0.369697;
    data->c_i = 0.312121;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_perso3(t_fractol *data, double x, double y)
{
    data->c_r = -1.459091;
    data->c_i = 0;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}

void    ft_nenufar(t_fractol *data, double x, double y)
{
    data->c_r = 0.277273;
    data->c_i = 0.001515;
    data->z_r = x / data->zoom + data->x1;
    data->z_i = y / data->zoom + data->y1;
}
