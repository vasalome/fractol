/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keyboard.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 18:46:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 13:45:04 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fractol/fractol.h"
#include "../includes_fractol/keys.h"

static void		key_color(int keycode, t_fractol *data_key)
{
	if (keycode == KEY_C)
		data_key->color = 1;
	else if (keycode == KEY_V)
		data_key->color = 2;
	else if (keycode == KEY_B)
		data_key->color = 3;
	else if (keycode == KEY_N)
		data_key->color = 4;
	else if (keycode == KEY_M)
		data_key->color_in++;
}

static void		key_choose(int keycode, t_fractol *data_key)
{
	if (keycode == KEY_1)
		data_key->name = "1";
	else if (keycode == KEY_2)
		data_key->name = "2";
	else if (keycode == KEY_3)
		data_key->name = "3";
	else if (keycode == KEY_4)
		data_key->name = "4";
	else if (keycode == KEY_5)
		data_key->name = "5";
	else if (keycode == KEY_6)
		data_key->name = "6";
	else if (keycode == KEY_7)
		data_key->name = "7";
	else if (keycode == KEY_8)
		data_key->name = "8";
	else if (keycode == KEY_9)
		data_key->name = "9";
	else if (keycode == KEY_0)
		data_key->name = "0";
}

static void		key_zoom(int keycode, t_fractol *data_key)
{
	if (keycode == KEY_ZOOM_IN)
	{
		data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom * 1.3));
		data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom * 1.3));
		data_key->zoom *= 1.3;
		data_key->nb_iter *= 1.3;
		data_key->zoom_info++;
	}
	else if (keycode == KEY_ZOOM_OUT)
	{
		if (data_key->zoom_info > 0)
		{
			data_key->x1 = (0 / data_key->zoom + data_key->x1) - (0 / (data_key->zoom / 1.3));
			data_key->y1 = (0 / data_key->zoom + data_key->y1) - (0 / (data_key->zoom / 1.3));
			data_key->zoom /= 1.3;
			data_key->nb_iter /= 1.3;
			data_key->zoom_info--;
		}
	}
}

static void		key_move(int keycode, t_fractol *data_key)
{
	double zr;

	zr = data_key->zoom * 20;
	if (keycode == KEY_UP)
	{
		//data_key->y1 += 0.001 * data_key->zoom;
		//data_key->y2 += 0.001 * data_key->zoom;
		data_key->y1 += 10 / zr;
	}
	else if (keycode == KEY_DOWN)
	{
		//data_key->y1 -= 0.001 * data_key->zoom;
		//data_key->y2 -= 0.001 * data_key->zoom;
		data_key->y1 -= 10 / zr;
	}
	else if (keycode == KEY_LEFT)
	{
		//data_key->x1 += 0.001 * data_key->zoom;
		//data_key->x2 += 0.001 * data_key->zoom;
		data_key->x1 += 10 / zr;
	}
	else if (keycode == KEY_RIGHT)
	{
		//data_key->x1 -= 0.001 * data_key->zoom;
		//data_key->x2 -= 0.001 * data_key->zoom;
		data_key->x1 -= 10 / zr;
	}
}

int			get_key(int key, t_fractol *data)
{
	static t_fractol	*data_key = NULL;

	if (data_key == NULL)
		data_key = data;
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_ITE_MORE)
		data_key->nb_iter += 20;
	else if (key == KEY_ITE_LESS)
		data_key->nb_iter -= 20;
	else if (key == 126 || key == 125 || key == 123 || key == 124)
		key_move(key, data_key);
	else if (key == 8 || key == 9 || key == 11 || \
			key == 45 || key == 46)
		key_color(key, data_key);
	else if (key == KEY_RESET)
		init_fract(data_key);
	else if (key == 6 || key == 7)
		key_zoom(key, data_key);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23 || \
			key == 22 || key == 26 || key == 28 || key == 25 || key == 29)
		key_choose(key, data_key);
	fractol(data_key);
	printf("keycode : %d\n", key);
	return (0);
}
