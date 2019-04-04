/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_choice2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 16:53:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 18:07:13 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"

void	ft_portail(t_fractol *data, double x, double y)
{
	data->c_r = 0;
	data->c_i = x * data->nzoom / WIDTH + data->x1;
	data->z_r = 0;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_tornado(t_fractol *data, double x, double y)
{
	data->c_r = 0.369697;
	data->c_i = 0.312121;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_virtualforest(t_fractol *data, double x, double y)
{
	data->c_r = -1.459091;
	data->c_i = 0;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_nenufar(t_fractol *data, double x, double y)
{
	data->c_r = 0.277273;
	data->c_i = 0.001515;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}

void	ft_needname(t_fractol *data, double x, double y)
{
	data->c_r = -0.74;
	data->c_i = -0.14;
	data->z_r = x * data->nzoom / WIDTH + data->x1;
	data->z_i = y * data->nzoom / HEIGHT + data->y1;
}
