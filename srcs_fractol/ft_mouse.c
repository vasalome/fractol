/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:11:32 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 20:20:29 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
#include "../includes_fractol/keys.h"

int		get_my_mouse(int x, int y, t_fractol *data)
{
	static t_fractol	*data_mouse = NULL;
	double				x1;
	double				x2;

	if (data_mouse == NULL)
		data_mouse = data;
	if (!(ft_strcmp(data_mouse->name, "2")))
	{
		if (data_mouse->stop_move % 2 == 1)
		{
			x1 = x;
			x2 = y;
			data_mouse->cmouse_r = x1 / 660;
			data_mouse->cmouse_i = x2 / 660;
		}
		if (data_mouse->stop_move % 2 == 0)
		{
			x1 = data_mouse->cmouse_r;
			x2 = data_mouse->cmouse_i;
			data_mouse->cmouse_r = x1;
			data_mouse->cmouse_i = x2;
		}
		fractol(data_mouse);
	}
	return (0);
}

int		get_key_mouse(int m, int x, int y, t_fractol *data)
{
	if ((m == 4 || m == 1) && x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		data->nzoom /= 2.0;
		data->x1 = x * data->nzoom / WIDTH + data->x1;
		data->y1 = y * data->nzoom / HEIGHT + data->y1;
		data->nb_iter += 20;
		data->zoom_info = data->zoom_info / 2;
		data->zoom_txt = data->zoom_txt * 2;
	}
	else if (m == 5 || m == 2)
	{
		if (data->zoom_info <= 1)
		{
			data->nzoom *= 2.0;
			data->x1 = ((WIDTH / 2) * data->nzoom / WIDTH + data->x1) - \
						(6 * data->zoom_info);
			data->y1 = ((HEIGHT / 2) * data->nzoom / HEIGHT + data->y1) - \
						(6 * data->zoom_info);
			data->nb_iter -= 20;
			data->zoom_info = data->zoom_info * 2;
			data->zoom_txt = data->zoom_txt / 2;
		}
	}
	fractol(data);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fractol *data)
{
	get_key_mouse(button, x, y, data);
	fractol(data);
	return (0);
}
