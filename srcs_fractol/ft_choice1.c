/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_choice1.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:53:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:18:35 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void	ft_mandelbrot(t_fractol *data, double x, double y)
{
	data->c_r = x * data->nzoom / WIDTH + data->x1;
	data->c_i = y * data->nzoom / HEIGHT + data->y1;
	data->z_r = 0;
	data->z_i = 0;
}

void	ft_julia(t_fractol *data, double x, double y)
{
	data->c_r = data->cmouse_r;
	data->c_i = data->cmouse_i;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_douadyrabbit(t_fractol *data, double x, double y)
{
	data->c_r = -0.123;
	data->c_i = 0.745;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_deepturn(t_fractol *data, double x, double y)
{
	data->c_r = -0.772727;
	data->c_i = 0.086364;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_burningship(t_fractol *data, double x, double y)
{
	data->c_r = x * data->nzoom / WIDTH + data->x1;
	data->c_i = y * data->nzoom / HEIGHT + data->y1;
	data->z_r = 0;
	data->z_i = 0;
}
